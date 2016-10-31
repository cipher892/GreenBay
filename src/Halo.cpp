//Halo.cpp
//Halo class member-function definitions.
#include <Ogre.h> //Ogre class definitions
#include <OgreAL.h> //OgreAL class definitions
#include "../include/Halo.h" //Halo class definition
using namespace Ogre;

//Halo constructor
Halo::Halo(SceneManager* ptr)
  {
    sceneManagerPtr = ptr; //set pointer to the SceneManager
    soundManagerPtr = new OgreAL::SoundManager(sceneManagerPtr);//create SoundManager
    speed = 100; //speed of the Halo
    direction = Vector3(0, 0, -1); //direction of the Halo
  } //end Halo constructor


//Halo destructor
Halo::~Halo()
  {
    delete soundManagerPtr;
    soundManagerPtr = 0;

    delete haloSoundPtr;
    haloSoundPtr = 0;
  } //end Halo destructor
 
//add the Halo to the scene
void Halo::addToScene()
  {
    //create Entity and attach it to a node in the scene
    Entity* entityPtr = sceneManagerPtr->createEntity("Halo", "raptor.mesh");
    nodePtr = sceneManagerPtr->getRootSceneNode()->createChildSceneNode("Halo"); //create a SceneNode
    nodePtr->attachObject(entityPtr); //attach the Entity to SceneNode
    nodePtr->setScale(5, 5, 5); //scale SceneNode
    addMovables();
  } //end function addToScene

void Halo::addMovables()
{
   Light* lightPtr = sceneManagerPtr->createLight("SpotLight"); // a Light
   lightPtr->setType(Light::LT_SPOTLIGHT);
   lightPtr->setDirection(-1, -1, 0);
   lightPtr->setPosition(150, 150, 0);   

   //attach light and camera to raptor ship
   nodePtr->attachObject(lightPtr);
   nodePtr->attachObject(sceneManagerPtr->getCamera("GameCam"));

   //attach sound to halo
    haloSoundPtr = soundManagerPtr->createSound("halo", "halosound.wav", false);
    nodePtr->attachObject(haloSoundPtr); //attach a sound to SceneNode
}

void Halo::fly(Real time)
  {
    nodePtr->translate((direction * (speed * time))); //move Halo
  } //end function moveHalo

void Halo::moveShip(Vector3 pos)
  {
    //nodePtr->translate((direction * (speed * time))); //move Halo
  } //end function moveHalo
