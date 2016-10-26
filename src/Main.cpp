//Main program for the GreenBay game
#include <iostream>
#include "../include/Game.h" // Pong class definition
using namespace std;

int main()
 {
   try
     {
       Game game; // create a game object
       game.run(); // start the GreenBay game
     } // end try
    catch (runtime_error &error)
     {
      cerr <<"Exception Thrown: "<< error.what() << endl;
     } // end catch
 } // end main