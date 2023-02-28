#include <stdint.h>
#include <pic32mx.h>
#include "projcode.h"

#include <stdlib.h>
#include <math.h>



void initPlayerNormal(struct Player *player){
    player->positionInt.x = 32;
    player->positionInt.y = 20;
    player->direction.x = 0;
    player->direction.y = 0;

}

void updatePlayerNormal(struct Player *player){
    if(pressBt() & 0x8)   //UP
        player->direction.x=LEFT;
    if(pressBt() & 0x4)   //RIGHT
        player->direction.y=UP;
    if(pressBt() & 0x2)  //DOWN
        player->direction.x=RIGHT;
    if(pressBt() & 0x1)   //LEFT
        player->direction.y=DOWN;
   
    if((player->direction.y==UP) && (player->positionInt.y > 0))    //UP
        player->positionInt.y=player->positionInt.y-1;
    if((player->direction.x==RIGHT) && (player->positionInt.x < 126)) //RIGHT
        player->positionInt.x=player->positionInt.x+1;
    if((player->direction.y==DOWN) && (player->positionInt.y < 30))  //DOWN
        player->positionInt.y=player->positionInt.y+1;
    if((player->direction.x==LEFT) && (player->positionInt.x > 0))  //LEFT
        player->positionInt.x=player->positionInt.x-1;
    
        player->direction.x = 0;
        player->direction.y = 0;

    
}

void initPlayerEndless(struct Player *player) {
    player->positionInt.x = 32;
    player->positionInt.y = 20;
    player->direction.x=RIGHT;
    player->direction.y=0;
}

void updatePlayerEndless(struct Player *player){
    
    int posXbegin = player->positionInt.x;
    int posYbegin = player->positionInt.y;

    int buttonPressedx = 0;
    int buttonPressedy = 0;
    if(pressBt() & 0x8)   
        buttonPressedx = LEFT;
    if(pressBt() & 0x4)  
        buttonPressedy = UP;
    if(pressBt() & 0x2)   
        buttonPressedx = RIGHT;
    if(pressBt() & 0x1) 
        buttonPressedy = DOWN;

    if (buttonPressedx && buttonPressedy)
    {
        if((buttonPressedy==UP) && (player->positionInt.y > 0))    //UP
            player->direction.y = UP;
        if((buttonPressedx==RIGHT) && (player->positionInt.x < 126)) //RIGHT
            player->direction.x = RIGHT;
        if((buttonPressedy==DOWN) && (player->positionInt.y < 30))  //DOWN
            player->direction.y = DOWN;
        if((buttonPressedx==LEFT) && (player->positionInt.x > 0))  //LEFT
            player->direction.x = LEFT;
    }
    else if (buttonPressedy)
    {
        if((buttonPressedy==UP) && (player->positionInt.y > 0))    //UP
            player->direction.y = UP;
        if((buttonPressedy==DOWN) && (player->positionInt.y < 30))  //DOWN
            player->direction.y = DOWN;
        player->direction.x = 0;
    }
    else if (buttonPressedx)
    {
        if((buttonPressedx==RIGHT) && (player->positionInt.x < 126)) //RIGHT
            player->direction.x = RIGHT;
        if((buttonPressedx==LEFT) && (player->positionInt.x > 0))  //LEFT
            player->direction.x = LEFT;
        player->direction.y = 0;

    }   
    
    if((player->direction.y==UP) && (player->positionInt.y > 0))    //UP
        player->positionInt.y=player->positionInt.y-1;
    if((player->direction.x==RIGHT) && (player->positionInt.x < 126)) //RIGHT
        player->positionInt.x=player->positionInt.x+1;
    if((player->direction.y==DOWN) && (player->positionInt.y < 30))  //DOWN
        player->positionInt.y=player->positionInt.y+1;
    if((player->direction.x==LEFT) && (player->positionInt.x > 0))  //LEFT
        player->positionInt.x=player->positionInt.x-1;
    
    if ((posXbegin == player->positionInt.x) && (posYbegin == player->positionInt.y))
        gameState = GAMEEND;
    
    

}

void drawPlayer(struct Player *player) {
    int posX = player->positionInt.x;
    int posY = player->positionInt.y;
    
    
    toDisplay[(posY / 8) * 128 + (posX % 128)] |= (1 << (posY % 8));
    posX++;
    toDisplay[(posY / 8) * 128 + (posX % 128)] |= (1 << (posY % 8));
    posY++;
    toDisplay[(posY / 8) * 128 + (posX % 128)] |= (1 << (posY % 8));
    posX--;
    toDisplay[(posY / 8) * 128 + (posX % 128)] |= (1 << (posY % 8));


}