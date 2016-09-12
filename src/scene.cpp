/**
* @file scene.cpp
* @author Erik Sandrén
* @date 05-09-2016
* @brief [Description Goes Here]
*/

#include "scene.h"
#include "vertex.h"
#include "color.h"
#include "surface.h"

Scene::Scene() {
  //Floor
  mObjects.push_back(
      new Surface(
        Vertex(10.0f, 6.0f, -5.0f),
        Vertex(0.0f, 6.0f, -5.0f),
        Vertex(-3.0f, 0.0f, -5.0f),
        Vertex(13.0f, 0.0f, -5.0f),
        Color(1.0, 1.0, 1.0) ) );

  mObjects.push_back(
      new Surface(
        Vertex(13.0f, 0.0f, -5.0f),
        Vertex(-3.0f, 0.0f, -5.0f),
        Vertex(0.0f, -6.0f, -5.0f),
        Vertex(10.0f, -6.0f, -5.0f),
        Color(1.0, 1.0, 1.0) ) );

  //Ceiling
  mObjects.push_back(
      new Surface(
        Vertex(10.0f, 6.0f, 5.0f),
        Vertex(0.0f, 6.0f, 5.0f),
        Vertex(-3.0f, 0.0f, 5.0f),
        Vertex(13.0f, 0.0f, 5.0f),
        Color(1.0, 1.0, 1.0) ) );
  mObjects.push_back(
      new Surface(
        Vertex(13.0f, 0.0f, 5.0f),
        Vertex(-3.0f, 0.0f, 5.0f),
        Vertex(0.0f, -6.0f, 5.0f),
        Vertex(10.0f, -6.0f, 5.0f),
        Color(1.0, 1.0, 1.0) ) );
  ////Walls
  mObjects.push_back(
      new Surface(
        Vertex(0.0f, 6.0f, 5.0f),
        Vertex(-3.0f, 0.0f, 5.0f),
        Vertex(-3.0f, 0.0f, -5.0f),
        Vertex(0.0f, 6.0f,-5.0f),
        Color(1.0, 0.0, 0.0) ) );

  mObjects.push_back(
      new Surface(
        Vertex(10.0f, 6.0f, 5.0f),
        Vertex(0.0f, 6.0f, 5.0f),
        Vertex(0.0f, 6.0f, -5.0f),
        Vertex(10.0f, 6.0f,-5.0f),
        Color(0.0, 1.0, 0.0) ) );

  mObjects.push_back(
      new Surface(
        Vertex(13.0f, 0.0f, 5.0f),
        Vertex(10.0f, 6.0f, 5.0f),
        Vertex(10.0f, 6.0f, -5.0f),
        Vertex(13.0f, 0.0f,-5.0f),
        Color(0.0, 0.0, 1.0) ) );

  mObjects.push_back(
      new Surface(
        Vertex(10.0f, -6.0f, 5.0f),
        Vertex(13.0f, 0.0f, 5.0f),
        Vertex(13.0f, 0.0f, -5.0f),
        Vertex(10.0f, -6.0f,-5.0f),
        Color(0.0, 1.0, 1.0) ) );

  mObjects.push_back(
      new Surface(
        Vertex(0.0f, -6.0f, 5.0f),
        Vertex(10.0f, -6.0f, 5.0f),
        Vertex(10.0f, -6.0f, -5.0f),
        Vertex(0.0f, -6.0f,-5.0f),
        Color(1.0, 0.0, 0.0) ) );

  mObjects.push_back(
      new Surface(
        Vertex(-3.0f, 0.0f, 5.0f),
        Vertex(0.0f, -6.0f, 5.0f),
        Vertex(0.0f, -6.0f, -5.0f),
        Vertex(-3.0f, 0.0f,-5.0f),
        Color(1.0, 0.0, 1.0) ) );
}

std::vector<SceneObject*> Scene::getObjects() {
  return mObjects;
}