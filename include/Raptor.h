//Raptor class definitions.
#ifndef Raptor_H
#define Raptor_H
#include <Ogre.h> // Ogre class definitions
using namespace Ogre;

class Raptor
 {
	public:
		 Raptor(SceneManager* ptr); // constructor
		 ~Raptor(); // destructor
		 void addToScene(); // add the Raptor to the scene
    private:
		 SceneManager* sceneManagerPtr; // pointer to the SceneManager
		 SceneNode* nodePtr; // pointer to the SceneNode
 }; // end class Raptor

#endif // Raptor_H