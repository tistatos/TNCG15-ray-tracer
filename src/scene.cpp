/**
* @file scene.cpp
* @author Erik Sandrén
* @date 05-09-2016
* @brief [Description Goes Here]
*/

#include "scene.h"
#include "vertex.h"
#include "color.h"
#include "quad.h"
#include "sphere.h"

Scene::Scene() {
  //Floor
  mObjects.push_back(
      new Quad(
        Vertex(10.0f, 6.0f, -5.0f),
        Vertex(0.0f, 6.0f, -5.0f),
        Vertex(-3.0f, 0.0f, -5.0f),
        Vertex(13.0f, 0.0f, -5.0f),
        new Surface(Color(0.4, 0.4, 0.4)) ) );

  mObjects.push_back(
      new Quad(
        Vertex(13.0f, 0.0f, -5.0f),
        Vertex(-3.0f, 0.0f, -5.0f),
        Vertex(0.0f, -6.0f, -5.0f),
        Vertex(10.0f, -6.0f, -5.0f),
        new Surface(Color(0.4, 0.4, 0.4)) ) );

  //Ceiling
  mObjects.push_back(
      new Quad(
        Vertex(10.0f, 6.0f, 5.0f),
        Vertex(0.0f, 6.0f, 5.0f),
        Vertex(-3.0f, 0.0f, 5.0f),
        Vertex(13.0f, 0.0f, 5.0f),
        new Surface(Color(0.4, 0.4, 0.4)) ) );
  mObjects.push_back(
      new Quad(
        Vertex(13.0f, 0.0f, 5.0f),
        Vertex(-3.0f, 0.0f, 5.0f),
        Vertex(0.0f, -6.0f, 5.0f),
        Vertex(10.0f, -6.0f, 5.0f),
        new Surface(Color(0.4, 0.4, 0.4)) ) );
  ////Walls
  mObjects.push_back(
      new Quad(
        Vertex(0.0f, 6.0f, 5.0f),
        Vertex(-3.0f, 0.0f, 5.0f),
        Vertex(-3.0f, 0.0f, -5.0f),
        Vertex(0.0f, 6.0f,-5.0f),
        new Surface(Color(1.0, 0.0, 0.0)) ) );

  mObjects.push_back(
      new Quad(
        Vertex(10.0f, 6.0f, 5.0f),
        Vertex(0.0f, 6.0f, 5.0f),
        Vertex(0.0f, 6.0f, -5.0f),
        Vertex(10.0f, 6.0f,-5.0f),
        new Surface(Color(0.0, 1.0, 0.0)) ) );

  mObjects.push_back(
      new Quad(
        Vertex(13.0f, 0.0f, 5.0f),
        Vertex(10.0f, 6.0f, 5.0f),
        Vertex(10.0f, 6.0f, -5.0f),
        Vertex(13.0f, 0.0f,-5.0f),
        new Surface(Color(0.0, 0.0, 1.0)) ) );

  mObjects.push_back(
      new Quad(
        Vertex(10.0f, -6.0f, 5.0f),
        Vertex(13.0f, 0.0f, 5.0f),
        Vertex(13.0f, 0.0f, -5.0f),
        Vertex(10.0f, -6.0f,-5.0f),
        new Surface(Color(0.0, 1.0, 1.0)) ) );

  mObjects.push_back(
      new Quad(
        Vertex(0.0f, -6.0f, 5.0f),
        Vertex(10.0f, -6.0f, 5.0f),
        Vertex(10.0f, -6.0f, -5.0f),
        Vertex(0.0f, -6.0f,-5.0f),
        new Surface(Color(1.0, 1.0, 0.0)) ) );

  mObjects.push_back(
      new Quad(
        Vertex(-3.0f, 0.0f, 5.0f),
        Vertex(0.0f, -6.0f, 5.0f),
        Vertex(0.0f, -6.0f, -5.0f),
        Vertex(-3.0f, 0.0f,-5.0f),
        new Surface(Color(1.0, 0.0, 1.0)) ) );

  mObjects.push_back(
      new Sphere(5.0f,Vertex(3.0f, 0.0f, 0.0f),
        new Surface(Color(1.0,1.0, 0)) )

      );
  mObjects.push_back(
      new Sphere(4.0f,Vertex(3.0f, 0.0f, 7.0f),
        new Surface(Color(1.0,1.0, 1.0), Vertex(1.0f, 1.0f, 1.0f) ) )
      );
}

Scene::~Scene() {
  for(unsigned int i = 0; i < mObjects.size() ; i++)
    delete mObjects[i];
  mObjects.clear();
}
std::vector<SceneObject*> Scene::getObjects() {
  return mObjects;
}
