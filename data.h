/*
Brian Eubanks
 Pacman
*/
#ifndef DATA_H
#define DATA_H

#include "defs.h"



//Data Load Methods

void initData();

void readTileData(); //8x8

void readBoardData(); //GRIDX x GRIDY 28x36

void readSpriteData();//16x16

void makeNewMaze();

//Returns the tile value of the nextTile based on the currentTile and turnDir
int getNextPacTile(char turnDir);

void setCurrentPacTileGrid();
void setCurrentGhostTileGrid();

//Sets the nextTile in pac based on currentTile and turnDir
void setNextPacTile(char turnDir);
//Gets next ghosttile based on current tile and moveDir
struct tile getNextGhostTile(char moveDir);

struct pac p;

struct ghost blinky;

#endif
