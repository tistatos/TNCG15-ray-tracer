/**
* @file camera.cpp
* @author Erik Sandrén
* @date 05-09-2016
* @brief [Description Goes Here]
*/

#include "camera.h"
#include "sceneObject.h"

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cmath>

void savePPM(const char* fileName, Pixel* p) {
  FILE *f = fopen(fileName, "w");
  fprintf(f, "P3\n%d %d\n%d\n", CAMERA_RESOLUTION, CAMERA_RESOLUTION, 255);

  for (unsigned int i = 0; i < CAMERA_RESOLUTION*CAMERA_RESOLUTION; ++i) {
    fprintf(f, "%d %d %d ", int(p[i].color.r *255), int(p[i].color.g * 255), int(p[i].color.b * 255));
  }

  fclose(f);
}

Camera::Camera(Vertex leftEye, Vertex rightEye)
  : mLeftEye(leftEye), mRightEye(rightEye) {
    mPixels = new Pixel[CAMERA_RESOLUTION*CAMERA_RESOLUTION];
}


Camera::~Camera() {
  delete mPixels;
}

void Camera::render(Scene scene) {
  std::vector<SceneObject*> sceneObjects = scene.getObjects();
  for(unsigned int y = 0; y < CAMERA_RESOLUTION; ++y) {
    for(unsigned int x = 0; x < CAMERA_RESOLUTION; ++x) {
      Pixel p = mPixels[x+CAMERA_RESOLUTION*y];

      Ray* r = new Ray(
            mRightEye,
            Vertex(-0.9f, 0.999-x*0.002, 0.999-y*0.002),
            Color(1.0, 1.0, 1.0));

      p.ray = r;
      std::vector<SceneObject*>::iterator it = sceneObjects.begin();
      for(; it != sceneObjects.end(); it++) {
        float tOut = 0.0f;
        if((*it)->rayIntersection(p.ray, tOut)) {
          mPixels[x+y*CAMERA_RESOLUTION].setColor(
              (*it)->getColor());
          break;
        }
      }
      delete r;
    }
  }
}

void Camera::createImage(const char* fileName) {
  savePPM(fileName, mPixels);
}
