/**
* @file main.cpp
* @author Erik Sandrén
* @date 30-08-2016
* @brief [Description Goes Here]
*/

#include <omp.h>
#include <glm/glm.hpp>
#include <iostream>

#include "scene.h"
#include "camera.h"
#include "pixel.h"

#define WIDTH 512
#define HEIGHT 512
#define SUB_PIXEL_SAMPLES 1

void savePPM(const char* fileName, Pixel p[WIDTH][HEIGHT], double maxR, double maxG, double maxB) {
  FILE *f = fopen(fileName, "w");
  fprintf(f, "P3\n%d %d\n%d\n", WIDTH, HEIGHT, 255);

  for (unsigned int y = 0; y < HEIGHT; ++y) {
    for (unsigned int x = 0; x < WIDTH; ++x) {
      fprintf(f, "%d %d %d ",
          int(p[x][y].color.r * 255.99 / maxR),
          int(p[x][y].color.g * 255.99 / maxG),
          int(p[x][y].color.b * 255.99 / maxB));
    }
  }
  fclose(f);
}



int main() {
  static Pixel pixels[WIDTH][HEIGHT];

  Camera camera( glm::vec3(-2.9f, 0.0f, 0.0f), WIDTH, HEIGHT,
      glm::perspective(float(M_PI/2), float(WIDTH)/float(HEIGHT), 0.01f, 1000.0f));

  Scene scene;

  double begin = omp_get_wtime();

  //#pragma omp parallel for collapse(2)
  for (unsigned int y = 0; y < HEIGHT; ++y) {
    for (unsigned int x = 0; x < WIDTH; ++x) {
      for(unsigned int s = 0; s < SUB_PIXEL_SAMPLES; ++s) {
        Pixel &p = pixels[x][y];
        Ray ray = camera.castRay(x,y);
        Color color = scene.trace(ray, 0);
        p.setColor(color);
      }
    }
  }
  double end = omp_get_wtime();
  double elapsed_secs = double(end - begin);

  std::cout << "Done: " << elapsed_secs  << std::endl;
  double maxR = 1.0, maxG = 1.0, maxB = 1.0;
  for (unsigned int y = 0; y < HEIGHT; ++y) {
    for (unsigned int x = 0; x < WIDTH; ++x) {
      maxR = std::max(pixels[x][y].color.r, maxR);
      maxG = std::max(pixels[x][y].color.g, maxG);
      maxB = std::max(pixels[x][y].color.b, maxB);
    }
  }
  savePPM("result.ppm", pixels, maxR, maxG, maxB);

  return 0;
 }
