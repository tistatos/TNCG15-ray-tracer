/**
* @file scene.h
* @author Erik Sandrén
* @date 05-09-2016
* @brief [Description Goes Here]
*/

#ifndef __SCENE_H__
#define __SCENE_H__

#include "sceneObject.h"
#include <vector>
#include <random>

#define SceneIterator std::vector<SceneObject*>::const_iterator

#define RUSSIAN_DEPTH 5


class Scene {
public:
  Scene();
  ~Scene();
  bool intersect(Ray &ray, float &tOut, Intersectable* &object, bool skipGlas = false) const;
  Color trace(Ray &ray, unsigned int depth);

private:
  std::vector<SceneObject*> mObjects;
  std::vector<SceneObject*> mLights;
  std::mt19937 engine;
  std::uniform_real_distribution<float> rng;
};



#endif
