//Halo class definitions.
#ifndef Halo_H
#define Halo_H
#include <Ogre.h> // Ogre class definitions
#include <OgreAL.h> // OgreAL class definitions
using namespace Ogre;

class Halo
 {
	public:
		 Halo(SceneManager* ptr); // constructor
		 ~Halo(); // destructor
		 void addToScene(); // add the Halo to the scene
		 void fly(Real time); //start flying ship
		 void moveShip(Vector3 pos); //change direction of ship
    private:
		 SceneManager* sceneManagerPtr; // pointer to the SceneManager
		 SceneNode* nodePtr; // pointer to the SceneNode
		 OgreAL::SoundManager* soundManagerPtr; // pointer to the SoundManager
		 OgreAL::Sound* haloSoundPtr; // sound played when Halo shoots
         int speed; // speed of the Halo
         Vector3 direction; // direction of the Halo
 }; // end class Halo

#endif // Halo_H