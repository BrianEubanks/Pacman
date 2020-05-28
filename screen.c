/*
Brian Eubanks
 Pac Man Clone
*/

#include "screen.h"



void drawTile(int x, int y, int tileNumber){
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            gfx_setColor(tileData[tileNumber][j][i]);
            gfx_point(TILE*x+i,TILE*y+j);
        }
        
    }
    
}

void drawBoard( ){
    
    for(int tx = 0; tx<GRIDX; tx++){
        for(int ty = 0; ty<GRIDY;ty++){
            drawTile(tx,ty,newmaze[tx][ty]);
        }
    }
}
    /*
    // Set the current drawing color to blue.
    //gfx_color(0,0,255);
    gfx_color(0,255,0); //green for late night testing
    

    

    
    gfx_color(255,255,0); //TIlE test
    
    //BorderWall Lower Left Tunnel
    gfx_line(0,TILE*18+7,TILE*4+7,TILE*18+7);
    gfx_line(0,TILE*18+4,TILE*4+7,TILE*18+4);
    gfx_line(TILE*5,TILE*18+7,TILE*5,TILE*21+7);
    gfx_line(TILE*5+3,TILE*18+7,TILE*5+3,TILE*21+7);
    gfx_line(TILE,TILE*22,TILE*4+7,TILE*22);
    gfx_line(TILE,TILE*22+3,TILE*4+7,TILE*22+3);
    gfx_line(0,TILE*23,0,TILE*32+7);
    //BorderWall Bottom
    gfx_line(TILE,TILE*33+7,TILE*26+7,TILE*33+7);
    //BorderWall Lower Right Tunnel
    gfx_line(224,TILE*18+7,TILE*23,TILE*18+7);
    gfx_line(224,TILE*18+4,TILE*23,TILE*18+4);
    gfx_line(TILE*22+4,TILE*18+7,TILE*22+4,TILE*21+7);
    gfx_line(TILE*22+7,TILE*18+7,TILE*22+7,TILE*21+7);
    gfx_line(TILE*27,TILE*22,TILE*23,TILE*22);
    gfx_line(TILE*27,TILE*22+3,TILE*23,TILE*22+3);
    gfx_line(223,TILE*23,223,TILE*32+7);
    //BorderWall Bottom
    gfx_line(TILE,TILE*33+7,TILE*26+7,TILE*33+7);
    //BorderWall Upper Left Tunnel
    gfx_line(0,TILE*16,TILE*4+7,TILE*16);
    gfx_line(0,TILE*16+3,TILE*4+7,TILE*16+3);
    gfx_line(TILE*5,TILE*15+7,TILE*5,TILE*13);
    gfx_line(TILE*5+3,TILE*15+7,TILE*5+3,TILE*13);
    gfx_line(TILE,TILE*12+7,TILE*4+7,TILE*12+7);
    gfx_line(TILE,TILE*12+4,TILE*4+7,TILE*12+4);
    gfx_line(0,TILE*11+7,0,TILE*4);
    gfx_line(3,TILE*11+7,3,TILE*4);
    //BorderWall TOP
    gfx_line(TILE,TILE*3,TILE*26+7,TILE*3);
    //BorderWall Upper Right Tunnel
    gfx_line(228,TILE*16,TILE*23,TILE*16);
    gfx_line(228,TILE*16+3,TILE*23,TILE*16+3);
    gfx_line(TILE*22+7,TILE*15+7,TILE*22+7,TILE*13);
    gfx_line(TILE*22+4,TILE*15+7,TILE*22+4,TILE*13);
    gfx_line(TILE*27,TILE*12+7,TILE*23,TILE*12+7);
    gfx_line(TILE*27,TILE*12+4,TILE*23,TILE*12+4);
    gfx_line(223,TILE*11+7,223,TILE*4);
    gfx_line(220,TILE*11+7,220,TILE*4);
    //Top Left Corner Border Wall
    gfx_line(0,TILE*3+7,0,TILE*3+4);
    gfx_line(1,TILE*3+3,1,TILE*3+2);
    gfx_line(2,TILE*3+1,3,TILE*3+1);
    gfx_line(4,TILE*3,7,TILE*3);
    gfx_line(3,TILE*3+7,3,TILE*3+5);
    gfx_point(4,TILE*3+4);
    gfx_line(5,TILE*3+3,7,TILE*3+3);
    //Top Left Corner Border Wall-LowerPowerPellet
    gfx_line(0,TILE*22+7,0,TILE*22+4);
    gfx_line(1,TILE*22+3,1,TILE*22+2);
    gfx_line(2,TILE*22+1,3,TILE*22+1);
    gfx_line(4,TILE*22,7,TILE*22);
    gfx_line(3,TILE*22+7,3,TILE*22+5);
    gfx_point(4,TILE*22+4);
    gfx_line(5,TILE*22+3,7,TILE*22+3);
    //Top Right Corner Border Wall
    gfx_line(TILE*27,TILE*3,TILE*27+3,TILE*3);
    gfx_line(TILE*27+4,TILE*3+1,TILE*27+5,TILE*3+1);
    gfx_line(TILE*27+6,TILE*3+2,TILE*27+6,TILE*3+3);
    gfx_line(TILE*27+7,TILE*3+4,TILE*27+7,TILE*3+7);
    gfx_line(TILE*27,TILE*3+3,TILE*27+2,TILE*3+3);
    gfx_point(TILE*27+3,TILE*3+4);
    gfx_line(TILE*27+4,TILE*3+5,TILE*27+4,TILE*3+7);
    //Top Right Corner Border Wall-LowerPowerPellet
    gfx_line(TILE*27,TILE*22,TILE*27+3,TILE*22);
    gfx_line(TILE*27+4,TILE*22+1,TILE*27+5,TILE*22+1);
    gfx_line(TILE*27+6,TILE*22+2,TILE*27+6,TILE*22+3);
    gfx_line(TILE*27+7,TILE*22+4,TILE*27+7,TILE*22+7);
    gfx_line(TILE*27,TILE*22+3,TILE*27+2,TILE*22+3);
    gfx_point(TILE*27+3,TILE*22+4);
    gfx_line(TILE*27+4,TILE*22+5,TILE*27+4,TILE*22+7);
    //Bottom Left Corner Border Wall
    gfx_line(0,TILE*33+0,0,TILE*33+3);
    gfx_line(1,TILE*33+4,1,TILE*33+5);
    gfx_line(2,TILE*33+6,3,TILE*33+6);
    gfx_line(4,TILE*33+7,7,TILE*33+7);
    gfx_line(3,TILE*33,3,TILE*33+2);
    gfx_point(4,TILE*33+3);
    gfx_line(5,TILE*33+4,7,TILE*33+4);
    //Bottom Left Corner Border Wall-UpperPowerPellet
    gfx_line(0,TILE*12+0,0,TILE*12+3);
    gfx_line(1,TILE*12+4,1,TILE*12+5);
    gfx_line(2,TILE*12+6,3,TILE*12+6);
    gfx_line(4,TILE*12+7,7,TILE*12+7);
    gfx_line(3,TILE*12,3,TILE*12+2);
    gfx_point(4,TILE*12+3);
    gfx_line(5,TILE*12+4,7,TILE*12+4);
    //Bottom Right Corner Border Wall
    gfx_line(TILE*27+7,TILE*33,TILE*27+7,TILE*33+3);
    gfx_line(TILE*27+6,TILE*33+5,TILE*27+6,TILE*33+4);
    gfx_line(TILE*27+4,TILE*33+6,TILE*27+5,TILE*33+6);
    gfx_line(TILE*27,TILE*33+7,TILE*27+3,TILE*33+7);
    gfx_line(TILE*27,TILE*33+4,TILE*27+2,TILE*33+4);
    gfx_point(TILE*27+3,TILE*33+3);
    gfx_line(TILE*27+4,TILE*33,TILE*27+4,TILE*33+2);
    //Bottom Right Corner Border Wall-UpperPowerPellet
    gfx_line(TILE*27+7,TILE*12,TILE*27+7,TILE*12+3);
    gfx_line(TILE*27+6,TILE*12+5,TILE*27+6,TILE*12+4);
    gfx_line(TILE*27+4,TILE*12+6,TILE*27+5,TILE*12+6);
    gfx_line(TILE*27,TILE*12+7,TILE*27+3,TILE*12+7);
    gfx_line(TILE*27,TILE*12+4,TILE*27+2,TILE*12+4);
    gfx_point(TILE*27+3,TILE*12+3);
    gfx_line(TILE*27+4,TILE*12,TILE*27+4,TILE*12+2);
    
    //Draw Up Walls
    for(int i = 0; i < GRIDX;i++){
        for(int j = 0; j < GRIDY;j++){
            switch (maze[i][j]) {
                case PELLET:
                    gfx_color(255,255,255);
                    gfx_line(TILE*i+3,TILE*j+3,TILE*i+4,TILE*j+3);
                    gfx_line(TILE*i+3,TILE*j+4,TILE*i+4,TILE*j+4);
                    break;
                case POW_PELLET:
                    gfx_color(255,255,255);
                    gfx_line(TILE*i+2,TILE*j,TILE*i+5,TILE*j);
                    gfx_line(TILE*i+1,TILE*j+1,TILE*i+6,TILE*j+1);
                    gfx_line(TILE*i,TILE*j+2,TILE*i+7,TILE*j+2);
                    gfx_line(TILE*i,TILE*j+3,TILE*i+7,TILE*j+3);
                    gfx_line(TILE*i,TILE*j+4,TILE*i+7,TILE*j+4);
                    gfx_line(TILE*i,TILE*j+5,TILE*i+7,TILE*j+5);
                    gfx_line(TILE*i+1,TILE*j+6,TILE*i+6,TILE*j+6);
                    gfx_line(TILE*i+2,TILE*j+7,TILE*i+5,TILE*j+7);
                    break;
                case WALL_TOP:
                    gfx_line(TILE*i,TILE*j+3,TILE*i+7,TILE*j+3);
                    break;
                case WALL_BOTTOM:
                    gfx_line(TILE*i,TILE*j+4,TILE*i+7,TILE*j+4);
                    break;
                case WALL_LEFT:
                    gfx_line(TILE*i+3,TILE*j,TILE*i+3,TILE*j+7);
                    break;
                case WALL_RIGHT:
                    gfx_line(TILE*i+4,TILE*j,TILE*i+4,TILE*j+7);
                    break;
                case OUT_CORNER_TOPL:
                    gfx_line(TILE*i,TILE*j+3,TILE*i+1,TILE*j+3);
                    gfx_point(TILE*i+2,TILE*j+2);
                    gfx_line(TILE*i+3,TILE*j+1,TILE*i+3,TILE*j);
                    break;
                case OUT_CORNER_TOPR:
                    gfx_line(TILE*i+4,TILE*j,TILE*i+4,TILE*j+1);
                    gfx_point(TILE*i+5,TILE*j+2);
                    gfx_line(TILE*i+6,TILE*j+3,TILE*i+7,TILE*j+3);
                    break;
                case OUT_CORNER_BOTTOML:
                    gfx_line(TILE*i,TILE*j+4,TILE*i+1,TILE*j+4);
                    gfx_point(TILE*i+2,TILE*j+5);
                    gfx_line(TILE*i+3,TILE*j+6,TILE*i+3,TILE*j+7);
                    break;
                case OUT_CORNER_BOTTOMR:
                    gfx_line(TILE*i+4,TILE*j+7,TILE*i+4,TILE*j+6);
                    gfx_point(TILE*i+5,TILE*j+5);
                    gfx_line(TILE*i+6,TILE*j+4,TILE*i+7,TILE*j+4);
                    break;
                case IN_CORNER_TOPL:
                    gfx_line(TILE*i+3,TILE*j+7,TILE*i+3,TILE*j+5);
                    gfx_point(TILE*i+4,TILE*j+4);
                    gfx_line(TILE*i+5,TILE*j+3,TILE*i+7,TILE*j+3);
                    break;
                case IN_CORNER_TOPR:
                    gfx_line(TILE*i+4,TILE*j+7,TILE*i+4,TILE*j+5);
                    gfx_point(TILE*i+3,TILE*j+4);
                    gfx_line(TILE*i,TILE*j+3,TILE*i+2,TILE*j+3);
                    break;
                case IN_CORNER_BOTTOML:
                    gfx_line(TILE*i+3,TILE*j,TILE*i+3,TILE*j+2);
                    gfx_point(TILE*i+4,TILE*j+3);
                    gfx_line(TILE*i+5,TILE*j+4,TILE*i+7,TILE*j+4);
                    break;
                case IN_CORNER_BOTTOMR:
                    gfx_line(TILE*i,TILE*j+4,TILE*i+2,TILE*j+4);
                    gfx_point(TILE*i+3,TILE*j+3);
                    gfx_line(TILE*i+4,TILE*j+2,TILE*i+4,TILE*j);
                    break;
                default:
                    break;
            }
            gfx_color(0,255,255);
        }
    }
    //Draw Ghost Home
    //left
    gfx_line(TILE*10+4,TILE*15+4,TILE*10+4,TILE*19+3);
    gfx_line(TILE*10+7,TILE*15+7,TILE*10+7,TILE*19);
    //right
    gfx_line(TILE*17+3,TILE*15+4,TILE*17+3,TILE*19+3);
    gfx_line(TILE*17,TILE*15+7,TILE*17,TILE*19);
    //bottom
    gfx_line(TILE*10+4,TILE*19+3,TILE*17+3,TILE*19+3);
    gfx_line(TILE*10+7,TILE*19,TILE*17,TILE*19);
    //topleft
    gfx_line(TILE*10+7,TILE*15+7,TILE*12+7,TILE*15+7);
    gfx_line(TILE*10+4,TILE*15+4,TILE*12+7,TILE*15+4);
    gfx_line(TILE*12+7,TILE*15+4,TILE*12+7,TILE*15+7);
    //topRight
    gfx_line(TILE*17+3,TILE*15+4,TILE*15,TILE*15+4);
    gfx_line(TILE*17,TILE*15+7,TILE*15,TILE*15+7);
    gfx_line(TILE*15,TILE*15+4,TILE*15,TILE*15+7);
    //DrawDoor
    gfx_color(255,0,0);
    gfx_line(TILE*13,TILE*15+5,TILE*14+7,TILE*15+5);
    gfx_line(TILE*13,TILE*15+6,TILE*14+7,TILE*15+6);
    */

void drawGhost(){
    int x = blinky.x-7;
    int y = blinky.y-8;
    //printf("%d",x);
    //printf("%d",y);
    
    for(int i =0; i<16; i++){
        for(int j=0; j<16; j++){
            gfx_color(255,0,0);
            if(blinky.moveDirection==RIGHT){
                if (ghostSprite[i][j]==1) {
                    gfx_point(x+j,y+i);
                }
            }
            else if(blinky.moveDirection==LEFT){
                if (ghostSprite[15-i][15-j]==1) {
                    gfx_point(x+j,y+i);
                }
            }
            else if(blinky.moveDirection==UP){
                if (ghostSprite[15-j][15-i]==1) {
                    gfx_point(x+j,y+i);
                }
            }
            else if(blinky.moveDirection==DOWN){
                if (ghostSprite[j][i]==1) {
                    gfx_point(x+j,y+i);
                }
            }
        }
    }
}

void drawPac(){
    int x = p.x-7;
    int y = p.y-8;
    //printf("%d",x);
    //printf("%d",y);
    
    for(int i =0; i<16; i++){
        for(int j=0; j<16; j++){
            gfx_color(255,255,0);
            if(p.moveDirection==RIGHT){
                if (pacSprite[p.ps][i][j]==1) {
                    gfx_point(x+j,y+i);
                }
            }
            else if(p.moveDirection==LEFT){
                if (pacSprite[p.ps][15-i][15-j]==1) {
                    gfx_point(x+j,y+i);
                }
            }
            else if(p.moveDirection==UP){
                if (pacSprite[p.ps][15-j][15-i]==1) {
                    gfx_point(x+j,y+i);
                }
            }
            else if(p.moveDirection==DOWN){
                if (pacSprite[p.ps][j][i]==1) {
                    gfx_point(x+j,y+i);
                }
            }
        }
    }
}

void openScreen(int xsize,int ysize, int r){
    // Open a new window for drawing.
    gfx_open(xsize*r,ysize*r,"Pacman");
    
}

void updateScreen(){
    drawBoard();
    drawPac();
    drawGhost();
    gfx_flush();
    gfx_sync();
}


int screenEventCheck(){ // Check if Event
    return gfxEventCheck();
}

char screenGetKey(){  // Return Key
    return gfxGetKey();
}

