/*
Brian Eubanks
 Pacman
*/

#include "gfx.h"
#include "data.h"


//Methods for drawing the screen

void openScreen(int xsize, int ysize, int r);
void updateScreen();

//Used by update screen
void drawBoard();
void drawTile();
//void drawGhost();
void drawPac();

//Event Checking
int screenEventCheck(); // Check if Event
char screenGetKey();  // Return Key





