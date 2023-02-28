// #include <stdint.h>
// #include <pic32mx.h>
// #include "projcode.h"

// #include <stdlib.h>
// #include <math.h>

// void drawPlayer(struct Player *player) {
//     int posX = player->positionInt.x;
//     int posY = player->positionInt.y;
//     toDisplay[(posY / 8) * 128 + (posX % 128)] = (1 << (posY % 8));
// }

// void initPlayerNormal(struct Player *player){
//     player.positionInt()=(32, 20)
//     player.direction()=0;
// }

// void updatePlayerNormal(struct Player *player){
//     if(pressBt & 0x8)   //UP
//         player->Direction=UP;
//     if(pressBt & 0x4)   //RIGHT
//         player->Direction=RIGHT;
//     if(pressBt & 0x2)   //DOWN
//         player->Direction=DOWN;
//     if(pressBt & 0x1)   //LEFT
//         player->Direction=LEFT;
   
//     if(player->Direction=UP)    //UP
//         player->positionInt.y=player->positionInt.y+1;
//     if(player->Direction=RIGHT) //RIGHT
//         player->positionInt.x=player->positionInt.y+1;
//     if(player->Direction=DOWN)  //DOWN
//         player->positionInt.y=player->positionInt.y-1;
//     if(player->Direction=LEFT)  //LEFT
//         player->positionInt.x=player->positionInt.y-1;

//     player->Direction=0
// }

// void initPlayerEndless(struct Player *player) {
//     player.positionInt()=(32, 20);
//     player.direction()=RIGHT;
// }

// void updatePlayerEndless(struct Player *player){
//     if(pressBt & 0x8)   //UP
//         player->Direction=UP;
//     if(pressBt & 0x4)   //RIGHT
//         player->Direction=RIGHT;
//     if(pressBt & 0x2)   //DOWN
//         player->Direction=DOWN;
//     if(pressBt & 0x1)   //LEFT
//         player->Direction=LEFT;
   
//     if(player->Direction=UP)    //UP
//         player->positionInt.y=player->positionInt.y+1;
//     if(player->Direction=RIGHT) //RIGHT
//         player->positionInt.x=player->positionInt.y+1;
//     if(player->Direction=DOWN)  //DOWN
//         player->positionInt.y=player->positionInt.y-1;
//     if(player->Direction=LEFT)  //LEFT
//         player->positionInt.x=player->positionInt.y-1;
// }