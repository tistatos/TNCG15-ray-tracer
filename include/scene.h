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

#define SceneIterator std::vector<SceneObject*>::const_iterator

class Scene {
public:
  Scene();
  ~Scene();
  bool intersect(Ray &ray, float &tOut, Intersectable* &object) const;
  Color trace(Ray ray, unsigned int depth) const;

private:
  std::vector<SceneObject*> mObjects;

};



#endif
