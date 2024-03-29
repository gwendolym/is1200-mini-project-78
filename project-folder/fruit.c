#include <stdint.h>
#include <pic32mx.h>
#include "projcode.h"

#include <stdlib.h>
#include <math.h>

int fruitEaten(struct Fruit *fruit, struct Player *player) {
    int eaten = 0;
    int pPosx = player->positionInt.x;
    int pPosy = player->positionInt.y;
    int fPosx = fruit->positionInt.x;
    int fPosy = fruit->positionInt.y;
    int distance = power((pPosx-fPosx), 2) + power((pPosy-fPosy), 2);
    if (distance <=  5)
    {
        eaten = 1;
    }
    
    return eaten;
}

void initFruit(struct Fruit *fruit){
    fruit->positionInt.x = (TMR1 % 126) + 1;
    fruit->positionInt.y = (TMR1 % 30) + 1;

}

void updateFruit(struct Fruit *fruit, struct Player *player, int* score){
    
    
    if (fruitEaten(fruit, player))
    {
        initFruit(fruit);
        drawFruit(fruit);
        (*score)++;
    }
    
    
}



void drawFruit(struct Fruit *fruit) {
    int posX = fruit->positionInt.x;
    int posY = fruit->positionInt.y;
    
    
    toDisplay[(posY / 8) * 128 + (posX % 128)] |= (1 << (posY % 8));
    posX++;
    toDisplay[(posY / 8) * 128 + (posX % 128)] |= (1 << (posY % 8));
    posY++;
    posX--;
    toDisplay[(posY / 8) * 128 + (posX % 128)] |= (1 << (posY % 8));
    posX--;
    posY--;
    toDisplay[(posY / 8) * 128 + (posX % 128)] |= (1 << (posY % 8));
    posX++;
    posY--;
    toDisplay[(posY / 8) * 128 + (posX % 128)] |= (1 << (posY % 8));


}