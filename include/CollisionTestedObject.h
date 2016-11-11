// Collision tested objects base class.
#ifndef COLLISIONTESTEDOBJECT_H
#define COLLISIONTESTEDOBJECT_H

#include <OgreOde_Core.h>
using namespace OgreOde;

class CollisionTestedObject 
{
    public:
       //Base class for all collision tested objects  	
       virtual void collide(Contact* contact) = 0;
       Body* body;
       SphereGeometry* geom;
};

#endif //COLLISIONTESTEDOBJECT_H