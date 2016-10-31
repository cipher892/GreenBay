//Raptor.cpp
//Raptor class member-function definitions.
#include <Ogre.h> //Ogre class definitions
#include <OgreAL.h> //OgreAL class definitions
#include "../include/Raptor.h" //Raptor class definition
using namespace Ogre;

//Raptor constructor
Raptor::Raptor(SceneManager* ptr)
  {
    sceneManagerPtr = ptr; //set pointer to the SceneManager
  } //end Raptor constructor


//Raptor destructor
Raptor::~Raptor()
  {
    
  } //end Raptor destructor
 
//add the Raptor to the scene
void Raptor::addToScene()
  {
    //create Entity and attach it to a node in the scene
    Entity* entityPtr = sceneManagerPtr->createEntity("Raptor", "j-13.mesh");
    nodePtr = sceneManagerPtr->getRootSceneNode()->createChildSceneNode("Raptor"); //create a SceneNode
    nodePtr->attachObject(entityPtr); //attach the Entity to SceneNode
    nodePtr->setScale(5, 5, 5); //scale SceneNode
    nodePtr->setPosition(Vector3(-75, -75, -1000));
  } //end function addToScene

