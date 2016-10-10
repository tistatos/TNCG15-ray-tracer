/**
* @file scene.cpp
* @author Erik Sandrén
* @date 05-09-2016
* @brief [Description Goes Here]
*/

#include <iostream>
#include <random>

#include "scene.h"
#include "color.h"
#include "quad.h"
#include "sphere.h"

Scene::Scene() {
  mObjects.push_back(
      new Sphere(1.0f,glm::vec3(8.0f, 0.0f, 0.0f),
        new Surface(Color(0.0,1.0, 1.0)) )
  );

  mObjects.push_back(
      new Sphere(1.0f,glm::vec3(3.0f, 2.0f, -3.0f),
        new Surface(Color(0.0,1.0, 1.0), Surface::eReflectionType::kRefraction) )
  );

  mObjects.push_back(
      new Sphere(1.0f,glm::vec3(3.0f, -4.0f, -3.0f),
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
        new Surface(Color(0.0, 1.0, 1.0)) ) );


  mObjects.push_back(
      new Sphere(10.0f,glm::vec3(8.0f, 0.0f, 14.9f),
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

Color Scene::trace(Ray &ray, unsigned int depth) const {
  //FIXME: double instead of float for t?
  float t = 0.0f;
  Intersectable* intersect;

  if(this->intersect(ray, t, intersect)) {
    if(depth == 5) return intersect->surface->emission;

    glm::vec3 intersectionPoint = ray.start + ray.direction * t;
    glm::vec3 normal = intersect->getNormal(intersectionPoint);

    //normal in same orientation of the ray
    glm::vec3 normalL = glm::dot(normal, ray.direction) < 0 ? normal : -normal;

    Surface* surface = intersect->surface;
    Color sColor = surface->color;

    if(surface->reflectionType == Surface::eReflectionType::kDiffuse) {
      //FIXME: hardcoded light vector
      Ray shadowRay = Ray(intersectionPoint, glm::vec3(8.0f, 0.0f, 5.0f) - intersectionPoint);
      Intersectable* light;
      if(this->intersect(shadowRay, t, light)) {
        Color emission = light->surface->emission;
        if(emission.r != 0 && emission.g != 0 && emission.r != 0) {

          Color lightContribution = emission * glm::dot(normalL, -ray.direction);

          return surface->emission + sColor * lightContribution;
        }
        return surface->emission;
      }
    }
    else if(surface->reflectionType == Surface::eReflectionType::kSpecular) {
      //Perfect reflection
      glm::vec3 reflected = glm::normalize(ray.direction - 2.0f * glm::dot(normal, ray.direction) * normal);
      ray.start = intersectionPoint;
      ray.direction = reflected;
      return trace(ray, ++depth);
    }
    else if(surface->reflectionType == Surface::eReflectionType::kRefraction) {
      glm::vec3 reflected = glm::normalize(ray.direction - 2.0f * glm::dot(normal, ray.direction) * normal);

      bool entering = glm::dot(normal, normalL) > 0;

      //FIXME: rename this
      float ddn = glm::dot(normalL, ray.direction);

      float n1 = 1.0f;
      float n2 = 1.5;
      float refractionIndex = n2;
      if(entering) refractionIndex = n1/n2;

      float internalReflection = (1 - refractionIndex * refractionIndex * ( 1 - ddn * ddn));

      if(internalReflection < 0) {
        ray.start = intersectionPoint;
        ray.direction = reflected;
        return trace(ray, ++depth);
      }

      glm::vec3 refractPoint = ray.start + ray.direction * t;
      glm::vec3 refractionDirection = ray.direction * refractionIndex - normal * (float)((entering ? 1.0 : -1.0f) * (refractionIndex * ddn + sqrt(internalReflection)));
      refractionDirection = glm::normalize(refractionDirection);

      //Schlick's approximation
      float R = ((n1 - n2) * (n1 - n2)) / ((n1 + n2) * (n1 + n2));
      float cosTheta = glm::dot(refractionDirection, normal);
      float Rs = R + (1 - R) * std::pow((1 - cosTheta), 5);

      Ray reflectedRay = Ray(intersectionPoint, reflected, ray.importance * Rs);
      Ray refractedRay = Ray(refractPoint, refractionDirection, ray.importance * (1- Rs));

      return trace(refractedRay, ++depth);
    }
  }
  return Color();
}
