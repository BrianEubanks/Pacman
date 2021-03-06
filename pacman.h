/*
Brian Eubanks
 Pacman
*/

#include "gfx.h"


#define GRIDX  28
#define GRIDY  36

#define TILE  8

#define YLW 0xFFFF00
#define NEONB 0x1919A6
#define BLUEB 0x2121DE
#define TW 0xDEA185
#define RED 0xFD0000
#define EGN 0x00FF00

#define PINK 0xFFb8FF
#define INK 0x00FFFF
#define TIM 0xFFB852


#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

#define PELLET 1
#define POW_PELLET 2
#define WALL_TOP 3
#define WALL_BOTTOM 4
#define WALL_LEFT 5
#define WALL_RIGHT 6
#define OUT_CORNER_TOPL 7
#define OUT_CORNER_TOPR 8
#define OUT_CORNER_BOTTOML 9
#define OUT_CORNER_BOTTOMR 10
#define IN_CORNER_TOPL 11
#define IN_CORNER_TOPR 12
#define IN_CORNER_BOTTOML 13
#define IN_CORNER_BOTTOMR 14
#define DOOR_HOME 15
#define TOP_HOME 16
#define BOTTOM_HOME 17
#define LEFT_HOME 18
#define RIGHT_HOME 19
#define TOP_LEFT_CORNER_HOME 20
#define BOTTOM_LEFT_CORNER_HOME 21
#define TOP_RIGHT_CORNER_HOME 22
#define BOTTOM_RIGHT_CORNER_HOME 23
#define TOP_HOME_LHINGE 24
#define TOP_HOME_RHINGE 25

struct pac{
    int x, y, xdir, ydir, xTile, yTile,xTileNEXT,yTileNEXT;
    int* sprites;
};


struct ghost{
    int x, y, xdir, ydir;
    int* sprites;
};

int tileData[26][8][8]={
    {//0 nothing
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    },{//PELLET
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,1,1,0,0,0},
        {0,0,0,1,1,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    },{//POW_PELLET
        {0,0,1,1,1,1,0,0},
        {0,1,1,1,1,1,1,0},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,0},
        {0,0,1,1,1,1,0,0}
    },{//WALL_TOP
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    },{//WALL_BOTTOM
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    },{//WALL_LEFT
        {0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0}
    },{//WALL_RIGHT
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0}
    },{//OUT_CORNER_TOPL
        {0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {0,0,1,0,0,0,0,0},
        {1,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    },{//OUT_CORNER_TOPR
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    },{//OUT_CORNER_BOTTOML
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0}
    },{//OUT_CORNER_BOTTOMR
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0}
    },{//IN_CORNER_TOPL
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,1},
        {0,0,0,0,1,0,0,0},
        {0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0}
    },{//IN_CORNER_TOPR
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {1,1,1,0,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0}
    },{//IN_CORNER_BOTTOML
        {0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,0,1,1,1},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    },{//IN_CORNER_BOTTOMR
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,1,0,0,0,0},
        {1,1,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    },{//DOOR_HOME
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0},
    },{//TOP_HOME
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1}
    },{//BOTTOM_HOME
        {1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    },{//LEFT_HOME
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,1,0,0,1}
    },{//RIGHT_HOME
        {1,0,0,1,0,0,0,0},
        {1,0,0,1,0,0,0,0},
        {1,0,0,1,0,0,0,0},
        {1,0,0,1,0,0,0,0},
        {1,0,0,1,0,0,0,0},
        {1,0,0,1,0,0,0,0},
        {1,0,0,1,0,0,0,0},
        {1,0,0,1,0,0,0,0}
    },{//TOP_LEFT_CORNER_HOME
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,1,1},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,1}
    },{//BOTTOM_LEFT_CORNER_HOME
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,1,1,1},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    },{//TOP_RIGHT_CORNER_HOME
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {1,0,0,1,0,0,0,0}
    },{//BOTTOM_RIGHT_CORNER_HOME
        {1,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    },{//TOP_HOME_LHINGE
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1}
    },{//TOP_HOME_RHINGE
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1}
    }
    
    
    
};


int pacSprite[3][16][16]={
{   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},///
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
},
{   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
    {0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},///
    {0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
},
{   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},///
    {0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
}}
;

int ghostSprite[16][16]=
{   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},///
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,1,0,1,1,1,0,0,1,1,1,0,1,1,0},
    {0,1,0,0,0,1,1,0,0,1,1,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

int maze[GRIDX][GRIDY]=
{   {0,0,0,11,5,5,5,5,5,5,5,5,13,0,0,0,3,0,4,0,0,0,11,5,5,5,5,13,11,5,5,5,5,13,0,0},
    {0,0,0,3,1,1,2,1,1,1,1,1,4,0,0,0,3,0,4,0,0,0,3,1,1,1,2,4,3,1,1,1,1,4,0,0},
    {0,0,0,3,1,10,6,8,1,10,8,1,4,0,0,0,3,0,4,0,0,0,3,1,10,8,1,9,7,1,10,8,1,4,0,0},
    {0,0,0,3,1,4,0,3,1,4,3,1,4,0,0,0,3,0,4,0,0,0,3,1,4,3,1,1,1,1,4,3,1,4,0,0},
    {0,0,0,3,1,4,0,3,1,4,3,1,4,0,0,0,3,0,4,0,0,0,3,1,4,12,6,6,8,1,4,3,1,4,0,0},
    {0,0,0,3,1,9,5,7,1,9,7,1,9,5,5,5,7,0,9,5,5,5,7,1,9,5,5,5,7,1,4,3,1,4,0,0},
    {0,0,0,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,3,1,4,0,0},
    {0,0,0,3,1,10,6,8,1,10,6,6,6,6,6,6,8,0,10,6,6,6,8,1,10,8,1,10,6,6,14,3,1,4,0,0},
    {0,0,0,3,1,4,0,3,1,9,5,5,13,11,5,5,7,0,9,5,5,5,7,1,4,3,1,9,5,5,13,3,1,4,0,0},
    {0,0,0,3,1,4,0,3,1,1,1,1,4,3,0,0,0,0,0,0,0,0,0,1,4,3,1,1,1,1,4,3,1,4,0,0},
    {0,0,0,3,1,4,0,3,1,10,8,1,4,3,0,20,18,18,18,21,0,10,8,1,4,3,1,10,8,1,4,3,1,4,0,0},
    {0,0,0,3,1,9,5,7,1,4,3,1,9,7,0,16,0,0,0,17,0,4,3,1,9,7,1,4,3,1,9,7,1,4,0,0},
    {0,0,0,3,1,1,1,1,1,4,3,1,0,0,0,24,0,0,0,17,0,4,3,1,1,1,1,4,3,1,1,1,1,4,0,0},
    {0,0,0,12,6,6,6,8,1,4,12,6,6,8,0,15,0,0,0,17,0,4,12,6,6,8,0,4,12,6,6,8,1,4,0,0},
    //flip horizontals
    //Theres a better way to do this to save half the data space
    //explains 256 level glitch only half the screen appears correctly
    {0,0,0,11,5,5,5,7,1,4,11,5,5,7,0,15,0,0,0,17,0,4,11,5,5,7,0,4,11,5,5,7,1,4,0,0},
    {0,0,0,3,1,1,1,1,1,4,3,1,0,0,0,25,0,0,0,17,0,4,3,1,1,1,1,4,3,1,1,1,1,4,0,0},
    {0,0,0,3,1,10,6,8,1,4,3,1,10,8,0,16,0,0,0,17,0,4,3,1,10,8,1,4,3,1,10,8,1,4,0,0},
    {0,0,0,3,1,4,0,3,1,9,7,1,4,3,0,22,19,19,19,23,0,9,7,1,4,3,1,9,7,1,4,3,1,4,0,0},
    {0,0,0,3,1,4,0,3,1,1,1,1,4,3,0,0,0,0,0,0,0,0,0,1,4,3,1,1,1,1,4,3,1,4,0,0},
    {0,0,0,3,1,4,0,3,1,10,6,6,14,12,6,6,8,0,10,6,6,6,8,1,4,3,1,10,6,6,14,3,1,4,0,0},
    {0,0,0,3,1,9,5,7,1,9,5,5,5,5,5,5,7,0,9,5,5,5,7,1,9,7,1,9,5,5,13,3,1,4,0,0},
    {0,0,0,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,3,1,4,0,0},
    {0,0,0,3,1,10,6,8,1,10,8,1,10,6,6,6,8,0,10,6,6,6,8,1,10,6,6,6,8,1,4,3,1,4,0,0},
    {0,0,0,3,1,4,0,3,1,4,3,1,4,0,0,0,3,0,4,0,0,0,3,1,4,11,5,5,7,1,4,3,1,4,0,0},
    {0,0,0,3,1,4,0,3,1,4,3,1,4,0,0,0,3,0,4,0,0,0,3,1,4,3,1,1,1,1,4,3,1,4,0,0},
    {0,0,0,3,1,9,5,7,1,9,7,1,4,0,0,0,3,0,4,0,0,0,3,1,9,7,1,10,8,1,9,7,1,4,0,0},
    {0,0,0,3,1,1,2,1,1,1,1,1,4,0,0,0,3,0,4,0,0,0,3,1,1,1,2,4,3,1,1,1,1,4,0,0},
    {0,0,0,12,6,6,6,6,6,6,6,6,14,0,0,0,3,0,4,0,0,0,12,6,6,6,6,14,12,6,6,6,6,14,0,0},
};






//Draw the Game Board
void drawTile();

void draw_board();

void reset();


