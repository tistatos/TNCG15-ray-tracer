/**
* @file main.cpp
* @author Erik Sandrén
* @date 30-08-2016
* @brief Main file for Monte Carlo raytracer
*/

#include <omp.h>
#include <glm/glm.hpp>
#include <iostream>
#include <iomanip>

#include "scene.h"
#include "camera.h"
#include "pixel.h"

#define WIDTH 64
#define HEIGHT 64
#define SUB_PIXEL_SAMPLES 6 // value x value sub samples
#define USE_OMP true

void savePPM(const char* fileName, Pixel p[WIDTH][HEIGHT], double maxR, double maxG, double maxB) {
  FILE *f = fopen(fileName, "w");
  fprintf(f, "P3\n%d %d\n%d\n", WIDTH, HEIGHT, 255);

  for (unsigned int y = 0; y < HEIGHT; ++y) {
    for (unsigned int x = 0; x < WIDTH; ++x) {
      fprintf(f, "%d %d %d ",
          int(glm::clamp(pow(p[x][y].color.r, 1/1), 0.0, 1.0) * 255),
          int(glm::clamp(pow(p[x][y].color.g, 1/1), 0.0, 1.0) * 255),
          int(glm::clamp(pow(p[x][y].color.b, 1/1), 0.0, 1.0) * 255));
          //(maxR > 0 ? int(glm::clamp(pow(p[x][y].color.r, 1/2.2), 0.0, 1.0) * 255.99 / maxR) : 0),
          //(maxG > 0 ? int(glm::clamp(pow(p[x][y].color.g, 1/2.2), 0.0, 1.0) * 255.99 / maxG) : 0),
          //(maxB > 0 ? int(glm::clamp(pow(p[x][y].color.b, 1/2.2), 0.0, 1.0) * 255.99 / maxB) : 0));
    }
  }
  fclose(f);
}

int main() {
  static Pixel pixels[WIDTH][HEIGHT];

  Camera camera( glm::vec3(-2.9f, 0.0f, 0.0f), WIDTH, HEIGHT,
      glm::perspective(float(M_PI/2), float(WIDTH)/float(HEIGHT), 0.01f, 1000.0f));

  Scene scene;

  std::cout << "Start of rendering" << std::endl;

  double begin = omp_get_wtime();

  unsigned int pixels_completed = 0;
#if USE_OMP
  std::cout << "Using MP..." << std::endl;
  #pragma omp parallel for collapse(2)
#endif
  for (unsigned int y = 0; y < HEIGHT; ++y) {
    for (unsigned int x = 0; x < WIDTH; ++x) {
      Color color;
      Pixel &p = pixels[x][y];
      for(unsigned int sy = 0; sy < SUB_PIXEL_SAMPLES; ++sy)
        for(unsigned int sx = 0; sx < SUB_PIXEL_SAMPLES; ++sx) {

        Ray ray = camera.castRay(x,y, sx, sy, SUB_PIXEL_SAMPLES);
        color = color + scene.trace(ray, 0);
      }
      color = color / (SUB_PIXEL_SAMPLES*SUB_PIXEL_SAMPLES);
      p.setColor(color);
#pragma omp atomic
    ++pixels_completed;
    if(pixels_completed % ((WIDTH*HEIGHT)/50) == 1)
#pragma omp critical
      std::cout << "Progress: "<< std::fixed << std::setprecision(1) << 100.0*pixels_completed/(WIDTH*HEIGHT) << "%" << std::setprecision(10) << std::endl;
    }
  }
  double end = omp_get_wtime();
  double elapsed_secs = double(end - begin);

  std::cout << "Done: " << elapsed_secs  << std::endl;
  double maxR = 0.0, maxG = 0.0, maxB = 0.0;
  for (unsigned int y = 0; y < HEIGHT; ++y) {
    for (unsigned int x = 0; x < WIDTH; ++x) {
      maxR = std::max(pixels[x][y].color.r, maxR);
      maxG = std::max(pixels[x][y].color.g, maxG);
      maxB = std::max(pixels[x][y].color.b, maxB);
    }
  }
  std::cout << "Max values: " << std::endl;
  std::cout << maxR << " " << maxG << " " << maxB  << std::endl;
  savePPM("result.ppm", pixels, maxR, maxG, maxB);

  return 0;
 }
