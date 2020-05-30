/*
Brian Eubanks
 Pacman
*/

#include <stdio.h>
#include "data.h"

//Data Load Methods

//Hard coded for now
//Add file read


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
<<<<<<< HEAD
        {0,0,0,3,1,1,2,1,-1,1,1,1,4,0,0,0,3,0,4,0,0,0,3,1,1,1,2,4,3,1,1,1,1,4,0,0},
        {0,0,0,3,1,10,6,8,1,10,8,1,4,0,0,0,3,0,4,0,0,0,3,1,10,8,1,9,7,1,10,8,1,4,0,0},
        {0,0,0,3,1,4,0,3,1,4,3,1,4,0,0,0,3,0,4,0,0,0,3,1,4,3,1,1,1,-1,4,3,1,4,0,0},
        {0,0,0,3,1,4,0,3,1,4,3,1,4,0,0,0,3,0,4,0,0,0,3,1,4,12,6,6,8,1,4,3,1,4,0,0},
        {0,0,0,3,1,9,5,7,1,9,7,1,9,5,5,5,7,0,9,5,5,5,7,1,9,5,5,5,7,1,4,3,1,4,0,0},
        {0,0,0,3,-1,1,1,1,-1,1,1,-1,1,1,1,1,1,-1,1,1,1,1,1,-1,1,1,-1,1,1,1,4,3,1,4,0,0},
        {0,0,0,3,1,10,6,8,1,10,6,6,6,6,6,6,8,0,10,6,6,6,8,1,10,8,1,10,6,6,14,3,1,4,0,0},
        {0,0,0,3,1,4,0,3,1,9,5,5,13,11,5,5,7,0,9,5,5,5,7,1,4,3,1,9,5,5,13,3,1,4,0,0},
        {0,0,0,3,1,4,0,3,-1,1,1,1,4,3,0,0,0,-1,0,0,-1,0,0,-1,4,3,-1,1,1,1,4,3,1,4,0,0},
        {0,0,0,3,1,4,0,3,1,10,8,1,4,3,0,20,18,18,18,21,0,10,8,1,4,3,1,10,8,1,4,3,1,4,0,0},
        {0,0,0,3,1,9,5,7,1,4,3,1,9,7,0,16,0,0,0,17,0,4,3,1,9,7,1,4,3,1,9,7,1,4,0,0},
        {0,0,0,3,1,1,1,1,-1,4,3,1,0,0,-2,24,0,0,0,17,0,4,3,1,1,1,-2,4,3,1,1,1,-1,4,0,0},
=======
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
>>>>>>> c08019c7524e3c039562becfea741c85cf7f8159
        {0,0,0,12,6,6,6,8,1,4,12,6,6,8,0,15,0,0,0,17,0,4,12,6,6,8,0,4,12,6,6,8,1,4,0,0},
        //flip horizontals
        //Theres a better way to do this to save half the data space
        {0,0,0,11,5,5,5,7,1,4,11,5,5,7,0,15,0,0,0,17,0,4,11,5,5,7,0,4,11,5,5,7,1,4,0,0},
<<<<<<< HEAD
        {0,0,0,3,1,1,1,1,-1,4,3,1,0,0,-2,25,0,0,0,17,0,4,3,1,1,1,-2,4,3,1,1,1,-1,4,0,0},
        {0,0,0,3,1,10,6,8,1,4,3,1,10,8,0,16,0,0,0,17,0,4,3,1,10,8,1,4,3,1,10,8,1,4,0,0},
        {0,0,0,3,1,4,0,3,1,9,7,1,4,3,0,22,19,19,19,23,0,9,7,1,4,3,1,9,7,1,4,3,1,4,0,0},
        {0,0,0,3,1,4,0,3,-1,1,1,1,4,3,0,0,0,-1,0,0,-1,0,0,-1,4,3,-1,1,1,1,4,3,1,4,0,0},
        {0,0,0,3,1,4,0,3,1,10,6,6,14,12,6,6,8,0,10,6,6,6,8,1,4,3,1,10,6,6,14,3,1,4,0,0},
        {0,0,0,3,1,9,5,7,1,9,5,5,5,5,5,5,7,0,9,5,5,5,7,1,9,7,1,9,5,5,13,3,1,4,0,0},
        {0,0,0,3,-1,1,1,1,-1,1,1,-1,1,1,1,1,1,-1,1,1,1,1,1,-1,1,1,-1,1,1,1,4,3,1,4,0,0},
        {0,0,0,3,1,10,6,8,1,10,8,1,10,6,6,6,8,0,10,6,6,6,8,1,10,6,6,6,8,1,4,3,1,4,0,0},
        {0,0,0,3,1,4,0,3,1,4,3,1,4,0,0,0,3,0,4,0,0,0,3,1,4,11,5,5,7,1,4,3,1,4,0,0},
        {0,0,0,3,1,4,0,3,1,4,3,1,4,0,0,0,3,0,4,0,0,0,3,1,4,3,1,1,1,-1,4,3,1,4,0,0},
        {0,0,0,3,1,9,5,7,1,9,7,1,4,0,0,0,3,0,4,0,0,0,3,1,9,7,1,10,8,1,9,7,1,4,0,0},
        {0,0,0,3,1,1,2,1,-1,1,1,1,4,0,0,0,3,0,4,0,0,0,3,1,1,1,2,4,3,1,1,1,1,4,0,0},
=======
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
>>>>>>> c08019c7524e3c039562becfea741c85cf7f8159
        {0,0,0,12,6,6,6,6,6,6,6,6,14,0,0,0,3,0,4,0,0,0,12,6,6,6,6,14,12,6,6,6,6,14,0,0},
    };


int dotCount;

int newmaze[GRIDX][GRIDY];


void readTileData(){} //8x8

void readBoardData(){} //GRIDX x GRIDY 28x36

void readSpriteData(){}//16x16

void makeNewMaze(){
    for(int i = 0;i<GRIDX;i++){
        for(int j = 0;j<GRIDY;j++){
            newmaze[i][j]=maze[i][j];
            if(newmaze[i][j]==1||newmaze[i][j]==2){
                dotCount++;
            }
        }
        
    }
}

int getNextPacTile(char turnDir){
    switch(p.turnDirection){
        case UP:
            return newmaze[p.currentTile.x][p.currentTile.y-1];
        case DOWN:
            return newmaze[p.currentTile.x][p.currentTile.y+1];
        case LEFT:
            return newmaze[p.currentTile.x-1][p.currentTile.y];
        case RIGHT:
            return newmaze[p.currentTile.x+1][p.currentTile.y];
    }
    //error
    printf("error: entity 24");
    return 0;
}

void setNextPacTile(char turnDir){
    
    p.nextTile.x=p.currentTile.x;
    p.nextTile.y=p.currentTile.y;
    switch(p.turnDirection){
        case UP:
            p.nextTile.y--;
            break;
        case DOWN:
            p.nextTile.y++;
            break;
        case LEFT:
            p.nextTile.x--;
            break;
        case RIGHT:
            p.nextTile.x++;
            break;
        default:
            //error
            printf("error: entity 44");
    }
    p.nextTile.grid=newmaze[p.nextTile.x][p.nextTile.y];
    
}

void setCurrentPacTileGrid(){

    p.currentTile.grid=newmaze[p.x/TILE][p.nextTile.y/TILE];
    
}

void setCurrentGhostTileGrid(){
<<<<<<< HEAD
    blinky.currentTile.grid=newmaze[blinky.x/TILE][blinky.y/TILE];
    if(blinky.currentTile.x!=blinky.prevTile.x || blinky.currentTile.y!=blinky.prevTile.y){
        blinky.prevTile.x=blinky.currentTile.x;
        blinky.prevTile.y=blinky.currentTile.y;
        blinky.turnCheck=true;
    }
=======
    blinky.currentTile.grid=newmaze[p.x/TILE][p.nextTile.y/TILE];
>>>>>>> c08019c7524e3c039562becfea741c85cf7f8159
}

struct tile getNextGhostTile(char moveDir){
    return p.currentTile;
}
