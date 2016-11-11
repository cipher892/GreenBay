// Game class member-function definitions.
#include <sstream>
#include <stdexcept>
#include <Ogre.h> // Ogre class definitions
#include <OgreOverlayManager.h>
#include <OgreAL.h> // OgreAL class definitions
#include <OISEvents.h> // OISEvents class definition
#include <OISInputManager.h> // OISInputManager class definition
#include <OISKeyboard.h> // OISKeyboard class definition
#include <OgreOde_Core.h> //OgreOde definitions
#include "../include/Game.h" // Game class definition
#include "../include/Halo.h"
#include "../include/Raptor.h"
#include "../include/CollisionTestedObject.h"

using namespace std;
using namespace Ogre;
using namespace OgreOde;

const Vector3 RIGHT = Vector3(1, 0, -1);
const Vector3 LEFT = Vector3(-1, 0, -1);
const Vector3 STRAIGHT = Vector3(0, 0, -1);

Game::Game()
{
   rootPtr = new Root();// initialize Root object

   // Restdefault setting use the Ogre Config Dialog Box to choose the settings
   if (!rootPtr->restoreConfig())
   {
      if(!(rootPtr->showConfigDialog()))
        throw runtime_error("Setup Dialog box canceled");
   }

   // get a pointer to the RenderWindow
   windowPtr = rootPtr->initialise(true, "GreenBay");

   // create the SceneManager
   sceneManagerPtr = rootPtr->createSceneManager(ST_GENERIC);
   mOverlaySystem = new OverlaySystem();
   sceneManagerPtr->addRenderQueueListener(mOverlaySystem);

   // create Cameras
   camPtr1 = sceneManagerPtr->createCamera("GameCam1");
   camPtr1->lookAt(Vector3(0, 0, 0)); // set where Camera looks
   camPtr1->setNearClipDistance(5); // near distance Camera can see
   camPtr1->setFarClipDistance(1000); // far distance Camera can see

   camPtr2 = sceneManagerPtr->createCamera("GameCam2");
   camPtr2->setPosition(0, 17, -150);
   camPtr2->lookAt(Vector3(0, 0, 0)); 
   camPtr2->setNearClipDistance(5); 
   camPtr2->setFarClipDistance(1000); 

   // create the Viewport
   viewportPtr1 = windowPtr->addViewport(camPtr1);
   viewportPtr1->setBackgroundColour(ColourValue(0, 0, 0));
   
   /*
   split screen, 2 viewports
   viewportPtr1 = windowPtr->addViewport(camPtr1, 1, 0, 0, 1, 0.5);
   Viewport* viewportPtr2 = windowPtr->addViewport(camPtr2, 2, 0, 0.5, 1, 0.5);
   viewportPtr2->setBackgroundColour(ColourValue(0.2, 0.2, 0.2));
   camPtr2->setAspectRatio(Real(viewportPtr2->getActualWidth()) / (viewportPtr2->getActualHeight()));
   */

   // set the Cameras aspect ratios
   camPtr1->setAspectRatio(Real(viewportPtr1->getActualWidth()) / (viewportPtr1->getActualHeight()));
   camPtr2->setAspectRatio(Real(viewportPtr1->getActualWidth()) / (viewportPtr1->getActualHeight()));

   // set the scene's ambient light
   sceneManagerPtr->setAmbientLight(ColourValue(0, 0, 0));

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
   
   //create ode world for collision mgt
   world = new World(sceneManagerPtr);
   world->setGravity(Vector3(0, 0, 0));
   world->setCFM(10e-5);
   world->setERP(0.8);
   world->setAutoSleep(true);
   world->setAutoSleepAverageSamplesCount(10);
   world->setContactCorrectionVelocity(1.0);
   world->setCollisionListener(this);

   Real step_size = Real(0.01);
   Real max_interval = Real(1.0 / 4);
   Real time_scale = Real(1);
   stepper = new StepHandler(world, StepHandler::BasicStep, step_size, max_interval, time_scale);
   stepper->setAutomatic(StepHandler::AutoMode_PostFrame, rootPtr);  

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
   haloPtr = new Halo(world); //new HaloShip
   haloPtr->addToScene(); // add Haloship to scene

   //make first enemy
   raptorPtr = new Raptor(world);
   raptorPtr->addToScene();
 } // end function createScene


 // start a game of Game
 void Game::run()
 {
   createScene(); // create the scene
   rootPtr->startRendering(); // start rendering frames
 } // end function run

bool Game::collision(Contact* contact)
{
  Geometry* const g1 = contact->getFirstGeometry();
  Geometry* const g2 = contact->getSecondGeometry();
   if (g1 && g2)
   {
      const Body* const b1 = g1->getBody();
      const Body* const  b2 = g2->getBody();
      if (b1 && b2 && Joint::areConnected(b1, b2))
          return false;
   }  
  any_cast<CollisionTestedObject*>(g1->getUserAny())->collide(contact);
  any_cast<CollisionTestedObject*>(g2->getUserAny())->collide(contact);
  return false;
}


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
           haloPtr->moveShip(STRAIGHT);
           break;
        case OIS::KC_ESCAPE: // escape key hit:quit
           quit = true;
           break;
        case OIS::KC_1: // hit key 2: switch camera 1
           viewportPtr1->setCamera(camPtr1);
           break;
        case OIS::KC_2: // hit key 1: switch camera 2
           viewportPtr1->setCamera(camPtr2);
           break;
       	case OIS::KC_LEFT: // left-arrow key hit: move ship left
 		       haloPtr->moveShip(LEFT);
		       break;
        case OIS::KC_RIGHT: //right-arrow key hit: move ship right
           haloPtr->moveShip(RIGHT);
           break;
        case OIS::KC_P: // P key hit: pause the game
          haloPtr->stop();
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
         haloPtr->moveShip(STRAIGHT);
        } // end if
    } // end else
  return true;
} // end function keyPressed

// process key released events
bool Game::keyReleased(const OIS::KeyEvent &keyEventRef)
{
    if (!pause)
    {
      // process KeyEvents that apply when the game is not paused
      switch (keyEventRef.key)
      {
        case OIS::KC_LEFT: // up-arrow key released: move ship straight
           haloPtr->moveShip(STRAIGHT);
           break;
        case OIS::KC_RIGHT: //down-arrow key released: move ship straight
           haloPtr->moveShip(STRAIGHT);
           break;
      } // end switch
    } // end if
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