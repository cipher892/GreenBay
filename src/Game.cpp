// Game class member-function definitions.
#include <sstream>
#include <stdexcept>
#include <Ogre.h> // Ogre class definitions
#include <OgreOverlayManager.h>
#include <OgreAL.h> // OgreAL class definitions
#include <OISEvents.h> // OISEvents class definition
#include <OISInputManager.h> // OISInputManager class definition
#include <OISKeyboard.h> // OISKeyboard class definition
#include "../include/Game.h" // Game class definition
#include "../include/Halo.h"
#include "../include/Raptor.h"
using namespace std;
using namespace Ogre;

const Vector3 RIGHT = Vector3(15, 0, 0);
const Vector3 LEFT = Vector3(-15, 0, 0);

Game::Game()
{
   rootPtr = new Root();// initialize Root object

   // use the Ogre Config Dialog Box to choose the settings
   if (!(rootPtr->showConfigDialog())) // user canceled the dialog box
      throw runtime_error("User Canceled Ogre Setup Dialog Box.");

   // get a pointer to the RenderWindow
   windowPtr = rootPtr->initialise(true, "GreenBay");

   // create the SceneManager
   sceneManagerPtr = rootPtr->createSceneManager(ST_GENERIC);
   mOverlaySystem = new OverlaySystem();
   sceneManagerPtr->addRenderQueueListener(mOverlaySystem);

   // create Camera
   cameraPtr = sceneManagerPtr->createCamera("GameCam");
   cameraPtr->setPosition(Vector3(0, 35, 150)); // set Camera position
   cameraPtr->lookAt(Vector3(0, 0, 0)); // set where Camera looks
   cameraPtr->setNearClipDistance(5); // near distance Camera can see
   cameraPtr->setFarClipDistance(1000); // far distance Camera can see

   // create the Viewport
   viewportPtr = windowPtr->addViewport(cameraPtr);
   viewportPtr->setBackgroundColour(ColourValue(0, 0, 0));

   // set the Camera's aspect ratio
   cameraPtr->setAspectRatio(Real(viewportPtr->getActualWidth()) / (viewportPtr->getActualHeight()));

   // set the scene's ambient light
   sceneManagerPtr->setAmbientLight(ColourValue(0, 0, 0));

   // create the Light
   Light* lightPtr = sceneManagerPtr->createLight("Light"); // a Light
   lightPtr->setPosition(0, 0, 50); // set the Light's position
   
   //initialise OIS
   unsigned long hWnd; // variable to hold the window handle retrieved from the render window
   windowPtr->getCustomAttribute("WINDOW", &hWnd); // get window handle and populate handle variable
   OIS::ParamList paramList; // create an OIS ParamList, used to pass parameters to classes
   //insert the string "WINDOW" and <str>hwnd into the parameter list
   paramList.insert(OIS::ParamList::value_type("WINDOW",Ogre::StringConverter::toString(hWnd)));
   inputManagerPtr = OIS::InputManager::createInputSystem(paramList); //create the OIS input system
   /*create a Keyboard,cast because inputmanager returns ois object true/false if you want input to be buffered/not */
   keyboardPtr = static_cast< OIS::Keyboard* >(inputManagerPtr->createInputObject(OIS::OISKeyboard, true)); 
   keyboardPtr->setEventCallback(this); // add a KeyListener

   rootPtr->addFrameListener(this);  // add game as a FrameListener

   // load resources for game
   ResourceGroupManager::getSingleton().addResourceLocation("../../Media/Scripts", "FileSystem", "Scipts");
   ResourceGroupManager::getSingleton().addResourceLocation("../../Media/Materials", "FileSystem", "Materials");
   ResourceGroupManager::getSingleton().addResourceLocation("../../Media/Sounds", "FileSystem", "Sounds");
   ResourceGroupManager::getSingleton().addResourceLocation("../../Media/Meshes", "FileSystem", "Meshes");
   ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

   quit = pause = start = false; // game not quit or paused or started

   //overlays
   pauseOverlayPtr = OverlayManager::getSingleton().getByName("PauseOverlay");
   startOverlayPtr = OverlayManager::getSingleton().getByName("StartOverlay");

 } // end game constructor

// Game destructor 
Game::~Game()
{
   // free dynamically allocated memory for Keyboard
   inputManagerPtr->destroyInputObject(keyboardPtr);
   OIS::InputManager::destroyInputSystem(inputManagerPtr);

   // free dynamically allocated memory for Root
   delete rootPtr; // release memory pointer points to
   rootPtr = 0; // point pointer at 0

   // free dynamically allocated memory for haloship
   delete haloPtr; // release memory pointer points to
   haloPtr = 0; // point pointer at 0
 } //end Game destructor


void Game::createScene()
 {
   startOverlayPtr->show(); // show the Overlay

   // make haloship
   haloPtr = new Halo(sceneManagerPtr); //new HaloShip
   haloPtr->addToScene(); // add Haloship to scene

   //make first enemy
   raptorPtr = new Raptor(sceneManagerPtr);
   raptorPtr->addToScene();
 } // end function createScene


 // start a game of Game
 void Game::run()
 {
   createScene(); // create the scene
   rootPtr->startRendering(); // start rendering frames
 } // end function run


 // respond to user keyboard input
bool Game::keyPressed(const OIS::KeyEvent &keyEventRef)
{
   // if the game is not paused
  if (!pause)
    {
      // process KeyEvents that apply when the game is not paused
      switch (keyEventRef.key)
      {
        case OIS::KC_S: //S key hit:start game
           start = true;
           startOverlayPtr->hide(); //hide the start overlay
           break;
        case OIS::KC_ESCAPE: // escape key hit:quit
           quit = true;
           break;
       	case OIS::KC_LEFT: // up-arrow key hit: move the right Paddle up
 		       haloPtr->moveShip(LEFT);
		       break;
        case OIS::KC_RIGHT: //down-arrow key hit: move the right Paddle down
           haloPtr->moveShip(RIGHT);
           break;
        case OIS::KC_P: // P key hit: pause the game
           pause = true; // set pause to true
           pauseOverlayPtr->show(); // show the pause Overlay
           break;
      } // end switch
    } // end if
  else // game is paused
    {
      // user hit 'R' on the keyboard
      if (keyEventRef.key == OIS::KC_R)
       {
         pause = false; // set pause to false when user resumes the game
         pauseOverlayPtr->hide(); // hide the pause Overlay
        } // end if
    } // end else
  return true;
} // end function keyPressed

// process key released events
bool Game::keyReleased(const OIS::KeyEvent &keyEventRef)
 {
    return true;
 } // end function keyReleased

// return true if the program should render the next frame
bool Game::frameEnded(const FrameEvent &frameEvent)
 {
   return !quit; // quit = false if the user hasn't quit yet
 } // end function frameEnded

 // process game logic, return true if the next frame should be rendered
bool Game::frameStarted(const FrameEvent &frameEvent)
  {
    keyboardPtr->capture(); // get keyboard events
    
    // the game is not paused and is started, move ship
    if (start && !pause)
      haloPtr->fly(frameEvent.timeSinceLastFrame);

  return !quit; // quit = false
 }