/*
Brian Eubanks
 Pac Man Clone
 Using "gfx.h"
 Library
*/

#include <stdio.h>
#include "game.h"

int main()
{
    printf("mainStart");

    
	int ysize = 288;
	int xsize = 224;
    
    int tick = 5000;
    
    int ratio=1;


	while(1) {
		//Exit if startGame returns 1
        if(startGame(xsize,ysize,tick,ratio)){
            break;
        }
    }

	return 0;
}
