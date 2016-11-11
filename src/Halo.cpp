//Halo.cpp
//Halo class member-function definitions.
#include <Ogre.h> //Ogre class definitions
#include <OgreAL.h> //OgreAL class definitions
#include <OgreOde_Core.h> //OgreOde definitions
#include "../include/Halo.h" //Halo class definition
#include "../include/CollisionTestedObject.h"
#include <iostream>
using namespace Ogre;
using namespace OgreOde;

Halo::Halo(World* world)
{
  worldptr = world;
  soundManagerPtr = new OgreAL::SoundManager(world->getSceneManager());//create SoundManager
  speed = 100; //speed of the Halo
  direction = Vector3(0, 0, -1); //direction of the Halo
} 

Halo::~Halo()
{
  delete soundManagerPtr;
  soundManagerPtr = 0;

  delete haloSoundPtr;
  haloSoundPtr = 0;
} 
 
void Halo::addToScene()
{
  //create Entity and attach it to a node in the scene
  Entity* entityPtr = worldptr->getSceneManager()->createEntity("Halo", "raptor.mesh");
  nodePtr = worldptr->getSceneManager()->getRootSceneNode()->createChildSceneNode("Halo"); //create a SceneNode
  nodePtr->attachObject(entityPtr); //attach the Entity to SceneNode
  nodePtr->setScale(5, 5, 5); //scale SceneNode

  //attach geom for collision 
  body = new Body(worldptr, "Halo");
  nodePtr->attachObject(body);
  geom = new SphereGeometry(5, worldptr, worldptr->getDefaultSpace());
  geom->setBody(body);
  geom->setUserAny(Any(static_cast<CollisionTestedObject*>(this)));   

  addCams();
  addMovables();
} 

void Halo::addCams()
{
  SceneNode* camNodePtr1 = worldptr->getSceneManager()->getRootSceneNode()->createChildSceneNode("GameCam1"); 
  camNodePtr1->attachObject(worldptr->getSceneManager()->getCamera("GameCam1")); 
  camNodePtr1->setPosition(0, 17, 150);
  camBody1 = new Body(worldptr, "GameCam1");
  camNodePtr1->attachObject(camBody1);

  SceneNode* camNodePtr2 = worldptr->getSceneManager()->getRootSceneNode()->createChildSceneNode("GameCam2"); 
  camNodePtr2->attachObject(worldptr->getSceneManager()->getCamera("GameCam2")); 
  camNodePtr2->setPosition(0, 17, -150);
  camBody2 = new Body(worldptr, "GameCam2");
  camNodePtr2->attachObject(camBody2);
}

void Halo::addMovables()
{
  //attach light 
  Light* lightPtr = worldptr->getSceneManager()->createLight("SpotLight"); 
  lightPtr->setType(Light::LT_SPOTLIGHT);
  lightPtr->setDirection(-1, -1, 0);
  lightPtr->setPosition(150, 150, 0);   
  nodePtr->attachObject(lightPtr);

  //attach sound
  haloSoundPtr = soundManagerPtr->createSound("halo", "halosound.wav", false);
  nodePtr->attachObject(haloSoundPtr); 
}


void Halo::fly(Real time)
{
}
  

void Halo::moveShip(Vector3 dir)
{
  direction = dir; 
  body->setLinearVelocity(17.5 * direction * (speed * 0.07));
  camBody1->setLinearVelocity(17.5 * Vector3(0, 0, -1) * (speed * 0.07));
  camBody2->setLinearVelocity(17.5 * Vector3(0, 0, -1) * (speed * 0.07));
} 

void Halo::stop()
{
  body->setLinearVelocity(Vector3(0, 0, 0));
  camBody1->setLinearVelocity(Vector3(0, 0, 0));
  camBody2->setLinearVelocity(Vector3(0, 0, 0));
} 

void Halo::collide(Contact* contact)
{
  LogManager::getSingleton().logMessage("Collide Halo");
}
