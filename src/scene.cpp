/**
* @file scene.cpp
* @author Erik Sandrén
* @date 05-09-2016
* @brief [Description Goes Here]
*/

#include <iostream>

#include "scene.h"
#include "color.h"
#include "quad.h"
#include "sphere.h"

Scene::Scene() : engine(std::random_device()()), rng(0.0f, 1.0f) {
  mObjects.push_back(
      new Sphere(1.0f,glm::vec3(5.0f, 4.0f, -1.0f),
        new Surface(Color(1.0,1.0, 1.0), Surface::eReflectionType::kLambert) )
  );

  mObjects.push_back(
      new Sphere(1.0f,glm::vec3(5.0f, -2.0f, -1.0f),
        new Surface(Color(1.0,1.0, 1.0), Surface::eReflectionType::kOrenNayar) )
  );
  mObjects.at(mObjects.size()-1)->surface->sigma2 = 100.0f;


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
        new Surface(Color(1.0, 1.0, 1.0)) ) );

  mObjects.push_back(
      new Quad(
        glm::vec3(13.0f, 0.0f, -5.0f),
        glm::vec3(-3.0f, 0.0f, -5.0f),
        glm::vec3(0.0f, -6.0f, -5.0f),
        glm::vec3(10.0f, -6.0f, -5.0f),
        new Surface(Color(1.0, 1.0, 1.0)) ) );

  //Ceiling
  mObjects.push_back(
      new Quad(
        glm::vec3(10.0f, 6.0f, 5.0f),
        glm::vec3(0.0f, 6.0f, 5.0f),
        glm::vec3(-3.0f, 0.0f, 5.0f),
        glm::vec3(13.0f, 0.0f, 5.0f),
        new Surface(Color(1.0, 1.0, 1.0)) ) );
  mObjects.push_back(
      new Quad(
        glm::vec3(13.0f, 0.0f, 5.0f),
        glm::vec3(-3.0f, 0.0f, 5.0f),
        glm::vec3(0.0f, -6.0f, 5.0f),
        glm::vec3(10.0f, -6.0f, 5.0f),
        new Surface(Color(1.0, 1.0, 1.0)) ) );

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
        new Surface(Color(1.0, 1.0, 1.0)) ) );

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
        new Surface(Color(1.0, 1.0, 1.0)) ) );

  mObjects.push_back(
      new Quad(
        glm::vec3(-3.0f, 0.0f, 5.0f),
        glm::vec3(0.0f, -6.0f, 5.0f),
        glm::vec3(0.0f, -6.0f, -5.0f),
        glm::vec3(-3.0f, 0.0f,-5.0f),
        new Surface(Color(1.0, 1.0, 1.0)) ) );

  //Lights
  SceneObject* topLight = new Sphere(10.0f,glm::vec3(8.0f, 0.0f, 14.9f),
        new Surface(Color(1.0,1.0, 1.0), Color(1.0, 1.0, 1.0)) );

  mObjects.push_back(topLight);
  mLights.push_back(topLight);
}

Scene::~Scene() {
  for(unsigned int i = 0; i < mObjects.size() ; i++)
    delete mObjects[i];
  mObjects.clear();
}

bool Scene::intersect(Ray &ray, float &tOut, Intersectable* &object, bool skipGlas) const {
  SceneIterator it = mObjects.begin();
  float tCurrent = tOut =  FLT_MAX;
  for(; it < mObjects.end(); it++) {
    if((*it)->rayIntersection(&ray, tCurrent) && tCurrent < tOut) {
      if(skipGlas && (*it)->surface->reflectionType == Surface::eReflectionType::kRefraction)
        continue;
      tOut = tCurrent;
      object = (*it);
    }
  }
  return tOut < FLT_MAX;
}

Color Scene::trace(Ray &ray, unsigned int depth) {
  float t = 0.0f;
  Intersectable* intersect;

  if(this->intersect(ray, t, intersect)) {
    float termination_probability = RUSSIAN_DEPTH * 0.8/depth;
    if(depth >= RUSSIAN_DEPTH && rng(engine) > termination_probability) {
      return intersect->surface->emission;
    }

    glm::vec3 intersectionPoint = ray.start + ray.direction * t;
    glm::vec3 normal = intersect->getNormal(intersectionPoint);
    glm::vec3 normalL = glm::dot(normal, ray.direction) < 0 ? normal : -normal;

    Surface* surface = intersect->surface;

    if(surface->reflectionType == Surface::eReflectionType::kLambert || surface->reflectionType == Surface::eReflectionType::kOrenNayar) {

      Color lightContribution;
      for(int i = 0; i < mLights.size(); i++) {
        //FIXME: hardcoded light vector
        Ray shadowRay = Ray(intersectionPoint, glm::vec3(8.0f, 0.0f, 5.0f) - intersectionPoint);
        Intersectable* light;
        if(this->intersect(shadowRay, t, light, true)) {
          Color lightEmission = light->surface->emission;
          //make sure light emission is not zero and
          //surface doesnt emit light
          if( (lightEmission.r != 0 || lightEmission.g != 0 || lightEmission.r != 0) &&
              (surface->emission.r < 1.0f || surface->emission.g < 1.0f || surface->emission.b < 1.0f)) {
            lightContribution = lightContribution + surface->emission + surface->evaluateBRDF(ray, shadowRay, normalL) * lightEmission * glm::dot(normalL, -ray.direction);
          }
        }
      }
      float u1 = rng(engine);
      float u2 = rng(engine);
      ray.start = intersectionPoint;
      Ray mcRay = Ray::sampleHemisphere(ray, normalL, u1, u2);
      return surface->emission + lightContribution + surface->evaluateBRDF(ray, mcRay, normalL) * trace(mcRay, ++depth);
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

      float incidence = glm::dot(normalL, ray.direction);

      float n1 = 1.0f;
      float n2 = 1.5f;
      float refractionIndex = n2;
      if(entering) refractionIndex = n1/n2;

      float internalReflection = (1 - refractionIndex * refractionIndex * ( 1 - incidence * incidence));

      if(internalReflection < 0) {
        ray.start = intersectionPoint;
        ray.direction = reflected;
        return trace(ray, ++depth);
      }

      glm::vec3 refractPoint = ray.start + ray.direction * t;
      glm::vec3 refractionDirection = ray.direction * refractionIndex - normal * (float)((entering ? 1.0 : -1.0f) * (refractionIndex * incidence + sqrt(internalReflection)));
      refractionDirection = glm::normalize(refractionDirection);

      //Schlick's approximation
      float R = ((n1 - n2) * (n1 - n2)) / ((n1 + n2) * (n1 + n2));
      float cosTheta = glm::dot(-ray.direction, normalL);
      float Rs = R + (1 - R) * std::pow((1 - cosTheta), 5);

      Ray reflectedRay = Ray(intersectionPoint, reflected);
      Ray refractedRay = Ray(refractPoint, refractionDirection);

      return trace(reflectedRay, depth + 1) * Rs +  trace(refractedRay, depth + 1) * (1-Rs);
    }
  }
  return Color();
}
