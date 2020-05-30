/*
Brian Eubanks
 Pac Man Clone
 Using "gfx.h"
 Library
*/

#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
#include <stdbool.h>
=======
>>>>>>> c08019c7524e3c039562becfea741c85cf7f8159
#include <unistd.h>


#include "game.h"


//#include "data.h"

//#include "pacman.h"







void updateGhost(){
    
    
    //Update Blinky Tile Based on XY coords
<<<<<<< HEAD
    blinky.currentTile.x = (int)blinky.x/TILE;
    blinky.currentTile.y = (int)blinky.y/TILE;
    setCurrentGhostTileGrid();
    

    
    

    
    
    //Check for Intersections
    
    if(blinky.currentTile.grid<0&&blinky.turnCheck){
        
        
        blinky.turnCheck=false;
        
        //Distance between Pac and Blinky
        
        int xdif = p.currentTile.x - blinky.currentTile.x;
        int ydif = p.currentTile.y - blinky.currentTile.y;
        
        
        // Absolute Value
        char furthestAxis = 'y';

        if(abs(xdif)>abs(ydif)){
            furthestAxis = 'x';
        }
        
        
        //Get Necessary X and Y directions
        //Preferred Turn directions
        // if d var = 0 pac is in line on the axis
        
        char dx=0;
        char dy=0;

        if(xdif<0){
            dx=LEFT;
        }
        else if(xdif>0){
            dx=RIGHT;
        }
        if(ydif<0){
            dy=UP;
        }
        else if(ydif>0){
            dy=DOWN;
        }
        
        //See which way Blinky can turn
        
        // He Can't do a 180
        int turnCount=0;
        bool up=false;
        bool down=false;
        bool left=false;
        bool right=false;
        
        
        if(newmaze[blinky.x/TILE][blinky.y/TILE+1]<=2){
            if(blinky.moveDirection!=UP){
                //blinky.turnDirection=DOWN;
                down=1;
                turnCount++;
            }
        }
        if(newmaze[blinky.x/TILE][blinky.y/TILE-1]<=2){
            if(blinky.moveDirection!=DOWN){
                //blinky.turnDirection=UP;
                up=1;
                turnCount++;
            }
        }
        //Check for Horizontal Intersections
        if(newmaze[blinky.x/TILE+1][blinky.y/TILE]<=2){
            if(blinky.moveDirection!=LEFT){
                //blinky.turnDirection=RIGHT;
                right=1;
                turnCount++;
            }
        }
        if(newmaze[blinky.x/TILE-1][blinky.y/TILE]<=2){
            if(blinky.moveDirection!=RIGHT){
                //blinky.turnDirection=LEFT;
                left=1;
                turnCount++;
            }
        }
        
        
        //Set TurnDirection
        /*
        if(dx==LEFT&&left){
            blinky.turnDirection=LEFT;
        }
        else if(dx==RIGHT&&right){
            blinky.turnDirection=RIGHT;
        }
        if(dy==UP&&up){
            blinky.turnDirection=UP;
        }
        else if(dy==DOWN&&down){
            blinky.turnDirection=DOWN;
        }
        */
        if(furthestAxis=='y'){
            if(dx==LEFT&&left){
                blinky.turnDirection=LEFT;
            }
            if(dx==RIGHT&&right){
                blinky.turnDirection=RIGHT;
            }
            if(dy==UP&&up){
                blinky.turnDirection=UP;
            }
            if(dy==DOWN&&down){
                blinky.turnDirection=DOWN;
            }
        }
        if(furthestAxis=='x'){
            if(dy==UP&&up){
                blinky.turnDirection=UP;
            }
            if(dy==DOWN&&down){
                blinky.turnDirection=DOWN;
            }
            if(dx==LEFT&&left){
                blinky.turnDirection=LEFT;
            }
            if(dx==RIGHT&&right){
                blinky.turnDirection=RIGHT;
            }
        }

        /*
        printf("TurnBlinky\n");
        printf("xdif: %d - %d = %d\n",p.currentTile.x,blinky.currentTile.x,xdif);
        printf("ydif: %d - %d = %d\n",p.currentTile.y,blinky.currentTile.y,ydif);
        printf("up: %d\n",up);
        printf("down: %d\n",down);
        printf("left: %d\n",left);
        printf("right: %d\n\n\n\n",right);
        */
        
    }
=======
    blinky.currentTile.x = (int)p.x/TILE;
    blinky.currentTile.y = (int)p.y/TILE;
>>>>>>> c08019c7524e3c039562becfea741c85cf7f8159
    
    
    //Wall
    //Check for Horizontal Wall
    if(newmaze[blinky.x/TILE+blinky.xdir][blinky.y/TILE]>2){
        //Check for vertical wall
        blinky.turnDirection=UP;
        if(newmaze[blinky.x/TILE][blinky.y/TILE-1]>2){
            //up wall
            blinky.turnDirection=DOWN;
            //blinky.xdir=0;
            //blinky.ydir=1;
        }
    }
    
    //Check for Vertical Wall
    else if(newmaze[blinky.x/TILE][blinky.y/TILE+blinky.ydir]>2){
        //Check for horizontal wall
        blinky.turnDirection=RIGHT;
        if(newmaze[blinky.x/TILE+1][blinky.y/TILE]>2){
            //RIGHT WALL
            blinky.turnDirection=LEFT;
            //blinky.xdir=-1;
            //blinky.ydir=0;
        }
    }
    
<<<<<<< HEAD
=======
    
    //Check for Intersections
    
    if(blinky.currentTile.grid==-1){
        if(newmaze[blinky.x/TILE][blinky.y/TILE+1]<=2&&blinky.y<p.y){
            if(blinky.moveDirection!=UP){
                blinky.turnDirection=DOWN;
            }
        }
        else if(newmaze[blinky.x/TILE][blinky.y/TILE-1]<=2&&blinky.y>p.y){
            if(blinky.moveDirection!=DOWN){
                blinky.turnDirection=UP;
            }
        }
        //Check for Horizontal Intersections
        if(newmaze[blinky.x/TILE+1][blinky.y/TILE]<=2&&blinky.x<p.x){
            if(blinky.moveDirection!=LEFT){
                blinky.turnDirection=RIGHT;
            }
        }
        else if(newmaze[blinky.x/TILE-1][blinky.y/TILE]<=2&&blinky.x>p.x){
            if(blinky.moveDirection!=RIGHT){
                blinky.turnDirection=LEFT;
            }
        }
    }
    
>>>>>>> c08019c7524e3c039562becfea741c85cf7f8159

    //Change dir for turns based on turnDirection

    if(blinky.x%TILE==3&&blinky.turnDirection!=blinky.moveDirection){
        if(blinky.turnDirection==DOWN){
            blinky.ydir=1;
            blinky.xdir=0;
        }
        else if(blinky.turnDirection==UP){
            blinky.ydir=-1;
            blinky.xdir=0;
        }
        //chew=false;
        //p.ydir=0;
    }
        
        
    if(blinky.y%TILE==4&&blinky.turnDirection!=blinky.moveDirection){
        //blinky.ydir=0;
        if(blinky.turnDirection==LEFT){
            blinky.xdir=-1;
            blinky.ydir=0;
        }
        else if(blinky.turnDirection==RIGHT){
            blinky.xdir=1;
            blinky.ydir=0;
        }

    }

    //Set Move Direction if not Cornering
<<<<<<< HEAD
    if(blinky.xdir==1){
=======
    else if(blinky.xdir==1){
>>>>>>> c08019c7524e3c039562becfea741c85cf7f8159
        blinky.moveDirection=RIGHT;
    }
    else if(blinky.xdir==-1){
        blinky.moveDirection=LEFT;
    }
    else if(blinky.ydir==1){
        blinky.moveDirection=DOWN;
    }
    else if(blinky.ydir==-1){
        blinky.moveDirection=UP;
    }
    else{
        //chew=false;
    }

    
    
    blinky.x+=blinky.xdir;
    blinky.y+=blinky.ydir;
    
}

void updatePac(){
    

    //Update Tile based on xy coords
    
    p.currentTile.x = (int)p.x/TILE;
    p.currentTile.y = (int)p.y/TILE;
    
    setCurrentPacTileGrid();
   
    

     //Wall Checking
    
    //Horizontal
    if(newmaze[p.x/TILE+p.xdir][p.y/TILE]>2){
        if(p.x%TILE==3){
            p.xdir=0;
        }
    }
    //Vertical
    if(newmaze[p.x/TILE][p.y/TILE+p.ydir]>2){
        if(p.y%TILE==4){
            p.ydir=0;
        }

    }


    //Cornering
        //If there is no wall in the xdir or ydir,
        //neither xdir and ydir will be set to 0
        //Handle Cornering

    if((p.xdir!=0&&p.ydir!=0)){
            
        p.moveDirection=p.turnDirection; //Set Move Direction for Cornering
        if(p.turnDirection==DOWN||p.turnDirection==UP){
            if(p.x%TILE>3){
                p.xdir=-1;
            }
            else if(p.x%TILE<3){
                p.xdir=1;
            }
            else if(p.x%TILE==3){
                p.xdir=0;
            }
        }
        else if(p.turnDirection==LEFT||p.turnDirection==RIGHT){
            if(p.y%TILE>4){
                p.ydir=-1;
            }
            else if(p.y%TILE<4){
                p.ydir=1;
            }
            else if(p.y%TILE==4){
                p.ydir=0;
            }
        }
    }
    //Set Move Direction if not Cornering
    else if(p.xdir==1){
        p.moveDirection=RIGHT;
    }
    else if(p.xdir==-1){
        p.moveDirection=LEFT;
    }
    else if(p.ydir==1){
        p.moveDirection=DOWN;
    }
    else if(p.ydir==-1){
        p.moveDirection=UP;
    }
    else{
        p.chew=0;
    }
        
    //Set Sprite Chew
    //Don't Chew if stopped
    if(p.chew){
        if(p.psIncrement<3){
            p.ps=0;
        }
        else if(p.psIncrement<6){
            p.ps=1;
        }
        else if(p.psIncrement<9){
            p.ps=2;
        }
        else{
            p.ps=0;
            p.psIncrement=1;
        }
        p.psIncrement++;
    }
    p.chew=1;
   
    //move Pacman Coords after checking for walls and turning
    
    p.x+=p.xdir;
    p.y+=p.ydir;
        


    //Check Pac Status
    //Based on his Tile
    
    //EAT DOT
    if(newmaze[p.x/TILE][p.y/TILE]==1){
        newmaze[p.x/TILE][p.y/TILE]=0;
        dotCount--;
        p.x-=p.xdir;//Slow Down When Eating dots
        p.y-=p.ydir;
            //score
            //sound
    }
        
    //EAT POWER DOT
    if(newmaze[p.x/TILE][p.y/TILE]==2){
        newmaze[p.x/TILE][p.y/TILE]=0;
        dotCount--;
        p.x-=p.xdir;//Slow Down When Eating dots
        p.y-=p.ydir;
        //score
        //sound
        //GHOST MODE
    }
        

        
    //Board Clear?
    if(dotCount==0){
        //flash screen
        resetBoard();
    }
<<<<<<< HEAD
    
    if(p.currentTile.x==blinky.currentTile.x&&p.currentTile.y==blinky.currentTile.y){
        die();
    }
=======
>>>>>>> c08019c7524e3c039562becfea741c85cf7f8159
        
    //printf("%d\n",dotCount);

}

    


void tick(int t){
    usleep(t);
}

char handleInput(){
    char c = screenGetKey();
    //p.turnDirection=c;
    //blinky.turnDirection=c;
    if(c=='a'){
        p.xdir=-1;
        p.turnDirection=c;
    }
    if(c=='d'){
        p.xdir=1;
        p.turnDirection=c;
    }
    if(c=='w'){
        p.ydir=-1;
        p.turnDirection=c;
    }
    if(c=='s'){
        p.ydir=1;
        p.turnDirection=c;
    }
    if(c=='j'){
        blinky.xdir=-1;
        blinky.turnDirection=LEFT;
    }
    if(c=='l'){
        blinky.xdir=1;
        blinky.turnDirection=RIGHT;
    }
    if(c=='i'){
        blinky.ydir=-1;
        blinky.turnDirection=UP;
    }
    if(c=='k'){
        blinky.ydir=1;
        blinky.turnDirection=DOWN;
    }
    if(c=='p'){
        pauseGame();
    }
    if(c=='q'){
        return c;
    }
    else{
        return c;
    }
    return c;
}
void resetBoard(){
    
    dotCount=0;
    makeNewMaze();
    
    p.currentTile.x=14;
    p.currentTile.y=26;

    
    p.xdir=-1;
    p.ydir=0;
    
    p.x = TILE*p.currentTile.x;
    p.y = TILE*p.currentTile.y+4;
    
    
    p.turnDirection=LEFT;
    p.moveDirection=LEFT;
    
    //setNextPacTile(p.turnDirection);
    
    
    blinky.currentTile.x=14;
    blinky.currentTile.y=14;
    
<<<<<<< HEAD
    blinky.prevTile.x=14;
    blinky.prevTile.y=14;
    
    blinky.x = TILE*blinky.currentTile.x;
    blinky.y = TILE*blinky.currentTile.y+4;
    
    blinky.xdir=-1;
    blinky.ydir=0;
    
    blinky.turnDirection=LEFT;
    blinky.moveDirection=LEFT;
  
}

void die(){
    
    //dotCount=0;
    //makeNewMaze();
    
    p.currentTile.x=14;
    p.currentTile.y=26;

    
    p.xdir=-1;
    p.ydir=0;
    
    p.x = TILE*p.currentTile.x;
    p.y = TILE*p.currentTile.y+4;
    
    
    p.turnDirection=LEFT;
    p.moveDirection=LEFT;
    
    //setNextPacTile(p.turnDirection);
    
    
    blinky.currentTile.x=14;
    blinky.currentTile.y=14;
    
    blinky.prevTile.x=14;
    blinky.prevTile.y=14;
    
=======
>>>>>>> c08019c7524e3c039562becfea741c85cf7f8159
    blinky.x = TILE*blinky.currentTile.x;
    blinky.y = TILE*blinky.currentTile.y+4;
    
    blinky.xdir=-1;
    blinky.ydir=0;
    
    blinky.turnDirection=LEFT;
    blinky.moveDirection=LEFT;
  
}

int startGame(int x, int y, int t, int r)
{
    //printf("startGame");
    //initialize data
    
    openScreen(x,y,r);
    
    //initialize screen
    resetBoard();
    updateScreen();
    
    char c;
    while(1) {
        // Wait for the user to press a character.
        if(screenEventCheck()){
            c = screenGetKey();

            // Quit if it is the letter q.
            if(c=='q')
                return 1;
            if(c=='k')
                return runGame();

        }
    }
    //set tick
    //return 0;
    
}

int runGame(){
    printf("runGame");
    char c;
	while(1) {
		// Wait for the user to press a character.
        if(screenEventCheck()){
            if(handleInput()=='q'){
                return 1;
            }
        }
        tick(5000);
        updateScreen();
        updateGhost();
        updatePac();
        
    }

	return 0;
}

void pauseGame(){
    printf("\nPAUSE\n");
    printf("Pac x,y: %d, %d\n",p.x,p.y);
    printf("PacTile x,y,g: %d,%d,%d\n",p.currentTile.x,p.currentTile.y,p.currentTile.grid);
    while(1){
        if(screenEventCheck()){
            break;
        }
    }
}
