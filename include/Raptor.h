//Raptor class definitions.
#ifndef Raptor_H
#define Raptor_H
#include <Ogre.h> // Ogre class definitions
#include <OgreOde_Core.h> //OgreOde definitions
#include "../include/CollisionTestedObject.h"

using namespace Ogre;
using namespace OgreOde;

class Raptor : public CollisionTestedObject 
{
	public:
		 Raptor(World* world); // constructor
		 ~Raptor(); // destructor
		 void addToScene(); // add the Raptor to the scene
		 void collide(Contact* contact);
    private:
        World* worldptr;
        SceneNode* nodePtr; // pointer to the SceneNode
        void addGeom();
}; // end class Raptor

#endif // Raptor_H