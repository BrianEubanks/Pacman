/*
Brian Eubanks
 Pacman
*/
#ifndef DEFS_H
#define DEFS_H
<<<<<<< HEAD
#include <stdbool.h>
=======
>>>>>>> c08019c7524e3c039562becfea741c85cf7f8159

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

#define INTERSECT = -1
//#define HALL = 0
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

extern int tileData[26][8][8];

extern int pacSprite[3][16][16];

extern int ghostSprite[16][16];

extern int maze[GRIDX][GRIDY];

extern int dotCount;

extern int newmaze[GRIDX][GRIDY];


struct tile{
    int x, y; //GRIDX GRIDY component
    int grid; //MAP[GRIDX][GRIDY]
};

struct pac{
    int x, y, xdir, ydir;
    struct tile currentTile,nextTile,targetTile;
    char turnDirection,moveDirection;
    int* sprites;
    int ps;
    int psIncrement;
    int chew;
};


struct ghost{
    int x, y, xdir, ydir;
    int mode;
<<<<<<< HEAD
    struct tile currentTile,prevTile,targetTile;
    char turnDirection,moveDirection;
    int* sprites;
    bool turnCheck;
=======
    struct tile currentTile,nextTile,targetTile;
    char turnDirection,moveDirection;
    int* sprites;
>>>>>>> c08019c7524e3c039562becfea741c85cf7f8159
};

struct fruit{
    int x,y;
    struct tile currentTile;
    int* sprites;
};

#endif
