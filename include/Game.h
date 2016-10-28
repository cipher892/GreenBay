// Game class definitions
#ifndef GAME_H
#define GAME_H
#include <Ogre.h> // Ogre class definitions
#include <OISEvents.h> // OISEvents class definition
#include <OISInputManager.h> // OISInputManager class definition
#include <OISKeyboard.h> // OISKeyboard class definition
#include <OgreOverlaySystem.h>
#include <OgreOverlayElement.h>

using namespace Ogre;

class Halo; // forward declaration of Halo class
class Raptor; //forward declaration of Raptor class

class Game : public FrameListener, public OIS::KeyListener
{
   public:
      Game(); // constructor
      ~Game(); // destructor
      void run(); // run a Game instance

      // handle keyPressed and keyReleased events
      bool keyPressed(const OIS::KeyEvent &keyEventRef);
      bool keyReleased(const OIS::KeyEvent &keyEventRef);
      
      // move the game objects and control interactions between frames
      virtual bool frameStarted(const FrameEvent &frameEvent);
      virtual bool frameEnded(const FrameEvent &frameEvent);

   private:
      void createScene(); // create the scene to be rendered

      // Ogre objects
      Root* rootPtr; // pointer to Ogre's Root object
      SceneManager* sceneManagerPtr; // pointer to the SceneManager
      RenderWindow* windowPtr; // pointer to RenderWindow to render scene in
      Viewport* viewportPtr; // pointer to Viewport, area that a camera sees
      Camera* cameraPtr; // pointer to a Camera in the scene
      OverlaySystem* mOverlaySystem; //pointer to the OverlaySystem
      Overlay* pauseOverlayPtr; //pasue overlay
      Overlay* startOverlayPtr; //start overlay

      // OIS input objects
      OIS::InputManager *inputManagerPtr; // pointer to the InputManager
      OIS::Keyboard *keyboardPtr; // pointer to the Keyboard

      // game objects
      Halo* haloPtr; //pointer to the Halo ship
      Raptor* raptorPtr; //pointer to enemy ship
      
      // variables to control game states
      bool quit, pause, start; // did user quit,pause or start the game?

}; // end Game definitions

#endif // GAME_H