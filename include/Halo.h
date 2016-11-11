//Halo class definitions.
#ifndef Halo_H
#define Halo_H
#include <Ogre.h> // Ogre class definitions
#include <OgreAL.h> // OgreAL class definitions
#include <OgreOde_Core.h> //OgreOde definitions
#include "../include/CollisionTestedObject.h"

using namespace Ogre;
using namespace OgreAL;
using namespace OgreOde;

class Halo : public CollisionTestedObject 
 {
	public:
		 Halo(World* world); // constructor
		 ~Halo(); // destructor
		 void addToScene(); // add the Halo to the scene
		 void fly(Real time); //start flying ship
		 void moveShip(Vector3 pos); //change direction of ship
		 void stop(); //rotate ship
		 void collide(Contact* contact);

    private:
    	void addMovables();
    	void addCams();
        World* worldptr;
        Body* camBody1;
        Body* camBody2;
        SceneNode* nodePtr; // pointer to the SceneNode
	    SoundManager* soundManagerPtr; // pointer to the SoundManager
	    Sound* haloSoundPtr; // sound played when Halo shoots
        int speed; // speed of the Halo
        Vector3 direction; // direction of the Halo
 }; // end class Halo

#endif // Halo_H