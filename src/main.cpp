/**
* @file main.cpp
* @author Erik Sandrén
* @date 30-08-2016
* @brief [Description Goes Here]
*/

#include "scene.h"
#include "camera.h"

int main() {
  Camera camera(
    Vertex(-2.0f, 0.0f, 0.0f),
    Vertex(-1.0f, 0.0f, 0.0f)
  );

  Scene scene;

  camera.render(scene);
  camera.createImage("result.ppm");

  return 0;
}
