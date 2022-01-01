#pragma once
#include <vcclr.h>
#include <fstream>
using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class Maze
{
public:
   //-----------------------------------------------------------------
   // Maze constructor
   // Reads in the map.
   // Sets valid to true if there are no invalid characters found and
   // the size of the map is valid
   //-----------------------------------------------------------------
   Maze(Panel^ drawingPanel, ifstream& ifs);
   // Maze destructor – clean up dynamically allocated 2D arrays!
   ~Maze();
   //-----------------------------------------------------------------
   // Returns true if the maze is valid, false otherwise
   //-----------------------------------------------------------------
   bool IsValid() const { return valid; }
   //-----------------------------------------------------------------
   // Returns true if the exit of the maze was found, false otherwise
   //-----------------------------------------------------------------
   bool IsFree() const { return free; }
   //-----------------------------------------------------------------
   // First checks if the mouse clicked a deadend or the exit and
   // returns if either is true.
   // Otherwise, it establishes the starting cell, colors it red,
   // and calls RecSolve with the row and column of the clicked
   // cell as parameters.
   //-----------------------------------------------------------------
   void Solve(int xPixel, int yPixel);
   //-----------------------------------------------------------------
   // Calls Show with the original maze 2d array as parameter
   //-----------------------------------------------------------------
   void ShowOriginal() { Show(orig); }
   //-----------------------------------------------------------------
   // Calls Show with the solved maze 2d array as parameter
   //-----------------------------------------------------------------
   void ShowSolved() { Show(solved); }
private:
   static const int CELLSIZE = 16;
   static const int MAXSIZE = 30;
   static const char OPEN = 'O';
   static const char DEADEND = '+';
   static const char EXIT = 'E';
   static const char START = 'S';
   static const char VISITED = 'X';
   int width, height; // width and height of the maze
   bool free; // Did RecSolve reach the exit?
   bool valid; // Is Maze Valid?
   gcroot<Panel^> panel; // Panel on which to show the Maze.
   // start with statically allocated arrays!
   //char orig[MAXSIZE][MAXSIZE]; // Original Maze Data
   //char solved[MAXSIZE][MAXSIZE]; // "Solved" Maze Data
   // Once your program is working – comment the statically
   // allocated arrays above, and un-comment the pointers below.
   // You will need to dynamically allocate the 2D arrays like
   // we discussed in class – keep in mind, once the arrays are
   // correctly allocated, they may be used exactly like the
   // statically allocated arrays above – that means, very little
   // of your working code needs to change, just add dynamic allocation
   // in the right place!
    char** orig;
    char** solved;
   //-----------------------------------------------------------------
   // Solves the maze recursively.
   // First, as a base case, it checks if the current cell is the exit.
   // If the cell is not the exit, it then checks if any adjacent cells
   // are the exit if the exit is adjacent, RecSolve is called with
   // the location of the exit as parameters.
   // Otherwise, it checks for adjacent open cells and makes calls
   // to RecSolve to move to said open cells.
   //-----------------------------------------------------------------
   void RecSolve(int row, int col);
   //-----------------------------------------------------------------
   // Displays the given data as a maze with deadends represented by
   // black squares, open cells by white squares, and the exit by
   // a green square.
   //-----------------------------------------------------------------
   //void Show(char cells[][MAXSIZE]);
   // when you are ready to use dynamic allocation of the 2D arrays
   // uncomment this version of Show and comment the one above!
   void Show(char** cells);
};
