/**
* @file camera.h
* @author Erik Sandrén
* @date 05-09-2016
* @brief [Description Goes Here]
*/

#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "vertex.h"
#include "pixel.h"
#include "scene.h"

const int CAMERA_RESOLUTION = 1000;

class Camera {
public:
  Camera(Vertex leftEye, Vertex rightEye);
  ~Camera();

  void render(Scene* scene);
  void createImage(const char* fileName);

private:
  Vertex mLeftEye;
  Vertex mRightEye;
  Pixel* mPixels;
};



#endif
