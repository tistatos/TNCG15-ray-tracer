/**
* @file scene.cpp
* @author Erik Sandrén
* @date 05-09-2016
* @brief [Description Goes Here]
*/

#include "scene.h"
#include "color.h"
#include "quad.h"
#include "sphere.h"

Scene::Scene() {
  mObjects.push_back(
      new Sphere(2.0f,glm::vec3(8.0f, 0.0f, 0.0f),
        new Surface(Color(0.0,1.0, 1.0)) )
  );

  mObjects.push_back(
      new Sphere(2.0f,glm::vec3(8.0f, 2.0f, -3.0f),
        new Surface(Color(0.0,1.0, 1.0), Surface::eReflectionType::kSpecular) )
  );

  //Floor
  mObjects.push_back(
      new Quad(
        glm::vec3(10.0f, 6.0f, -5.0f),
        glm::vec3(0.0f, 6.0f, -5.0f),
        glm::vec3(-3.0f, 0.0f, -5.0f),
        glm::vec3(13.0f, 0.0f, -5.0f),
        new Surface(Color(0.8, 0.8, 0.8)) ) );

  mObjects.push_back(
      new Quad(
        glm::vec3(13.0f, 0.0f, -5.0f),
        glm::vec3(-3.0f, 0.0f, -5.0f),
        glm::vec3(0.0f, -6.0f, -5.0f),
        glm::vec3(10.0f, -6.0f, -5.0f),
        new Surface(Color(0.8, 0.8, 0.8)) ) );

  //Ceiling
  mObjects.push_back(
      new Quad(
        glm::vec3(10.0f, 6.0f, 5.0f),
        glm::vec3(0.0f, 6.0f, 5.0f),
        glm::vec3(-3.0f, 0.0f, 5.0f),
        glm::vec3(13.0f, 0.0f, 5.0f),
        new Surface(Color(0.4, 0.4, 0.4)) ) );
  mObjects.push_back(
      new Quad(
        glm::vec3(13.0f, 0.0f, 5.0f),
        glm::vec3(-3.0f, 0.0f, 5.0f),
        glm::vec3(0.0f, -6.0f, 5.0f),
        glm::vec3(10.0f, -6.0f, 5.0f),
        new Surface(Color(0.4, 0.4, 0.4)) ) );

  //Walls
  /**    2
   *     __
   * 1 /    \ 3
   * 6 \ __ / 4
   *     5
   */
  mObjects.push_back(
      new Quad(
        glm::vec3(0.0f, 6.0f, 5.0f),
        glm::vec3(-3.0f, 0.0f, 5.0f),
        glm::vec3(-3.0f, 0.0f, -5.0f),
        glm::vec3(0.0f, 6.0f,-5.0f),
        new Surface(Color(1.0, 1.0, 0.0)) ) );

  mObjects.push_back(
      new Quad(
        glm::vec3(10.0f, 6.0f, 5.0f),
        glm::vec3(0.0f, 6.0f, 5.0f),
        glm::vec3(0.0f, 6.0f, -5.0f),
        glm::vec3(10.0f, 6.0f,-5.0f),
        new Surface(Color(1.0, 0.0, 0.0)) ) );

  mObjects.push_back(
      new Quad(
        glm::vec3(13.0f, 0.0f, 5.0f),
        glm::vec3(10.0f, 6.0f, 5.0f),
        glm::vec3(10.0f, 6.0f, -5.0f),
        glm::vec3(13.0f, 0.0f,-5.0f),
        new Surface(Color(0.0, 1.0, 0.0)) ) );

  mObjects.push_back(
      new Quad(
        glm::vec3(10.0f, -6.0f, 5.0f),
        glm::vec3(13.0f, 0.0f, 5.0f),
        glm::vec3(13.0f, 0.0f, -5.0f),
        glm::vec3(10.0f, -6.0f,-5.0f),
        new Surface(Color(0.0, 0.0, 1.0)) ) );

  mObjects.push_back(
      new Quad(
        glm::vec3(0.0f, -6.0f, 5.0f),
        glm::vec3(10.0f, -6.0f, 5.0f),
        glm::vec3(10.0f, -6.0f, -5.0f),
        glm::vec3(0.0f, -6.0f,-5.0f),
        new Surface(Color(1.0, 0.0, 1.0)) ) );

  mObjects.push_back(
      new Quad(
        glm::vec3(-3.0f, 0.0f, 5.0f),
        glm::vec3(0.0f, -6.0f, 5.0f),
        glm::vec3(0.0f, -6.0f, -5.0f),
        glm::vec3(-3.0f, 0.0f,-5.0f),
        new Surface(Color(1.0, 0.0, 1.0)) ) );


  mObjects.push_back(
      new Sphere(10.0f,glm::vec3(8.0f, 0.0f, 7.7f),
        new Surface(Color(1.0,1.0, 1.0), Color(1.0f, 1.0f, 1.0f)) )
      );
}

Scene::~Scene() {
  for(unsigned int i = 0; i < mObjects.size() ; i++)
    delete mObjects[i];
  mObjects.clear();
}

bool Scene::intersect(Ray &ray, float &tOut, Intersectable* &object) const {
  SceneIterator it = mObjects.begin();
  tOut = FLT_MAX;
  float tCurrent = FLT_MAX;
  for(; it < mObjects.end(); it++) {
    if((*it)->rayIntersection(&ray, tCurrent) && tCurrent < tOut) {
      tOut = tCurrent;
      object = (*it);
    }
  }
  return tOut < FLT_MAX;
}
