//Raptor.cpp
//Raptor class member-function definitions.
#include <Ogre.h> //Ogre class definitions
#include <OgreAL.h> //OgreAL class definitions
#include <OgreOde_Core.h> //OgreOde definitions
#include "../include/Raptor.h" //Raptor class definition
#include "../include/CollisionTestedObject.h"

using namespace Ogre;
using namespace OgreOde;

//Raptor constructor
Raptor::Raptor(World* world)
{
  worldptr = world; //set pointer to the world
} //end Raptor constructor


//Raptor destructor
Raptor::~Raptor()
{
    
} //end Raptor destructor
 
//add the Raptor to the scene
void Raptor::addToScene()
{
  //create Entity and attach it to a node in the scene
  Entity* entityPtr = worldptr->getSceneManager()->createEntity("Raptor", "j-13.mesh");
  nodePtr = worldptr->getSceneManager()->getRootSceneNode()->createChildSceneNode("Raptor"); //create a SceneNode
  nodePtr->attachObject(entityPtr); //attach the Entity to SceneNode
  nodePtr->setScale(5, 5, 5); //scale SceneNode
  //nodePtr->setPosition(Vector3(0, 0, -1000));
  nodePtr->setPosition(Vector3(-75, -75, -1000));
  addGeom();
} //end function addToScene

void Raptor::addGeom()
{
  body = new Body(worldptr, "Raptor");
  nodePtr->attachObject(body);
  geom = new SphereGeometry(5, worldptr, worldptr->getDefaultSpace());
  geom->setBody(body);
  geom->setUserAny(Any(static_cast<CollisionTestedObject*>(this))); 
}

void Raptor::collide(Contact* contact)
{
  LogManager::getSingleton().logMessage("Collide Raptor");
}

