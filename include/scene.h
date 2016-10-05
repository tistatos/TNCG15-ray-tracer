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

#define SceneIterator std::vector<SceneObject*>::iterator

class Scene {
public:
  Scene();
  ~Scene();
  void addObject(SceneObject* object);
  std::vector<SceneObject*> getObjects();

private:
  std::vector<SceneObject*> mObjects;

};



#endif
