
#include <stdint.h>
#include <pic32mx.h>
#include "projcode.h"

#include <stdlib.h>

uint8_t endPicture[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,64,128,0,128,64,0,128,64,64,64,128,0,192,0,0,0,192,0,0,0,192,0,0,0,0,0,128,64,64,64,128,0,128,64,64,64,64,0,192,64,64,64,64,0,0,0,128,0,0,128,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,31,0,0,0,15,16,16,16,15,0,15,16,16,16,15,0,0,0,31,16,16,16,16,0,15,16,16,16,15,0,17,18,18,18,12,0,31,18,18,18,16,0,0,0,8,0,7,8,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,124,20,20,8,0,124,20,52,72,0,124,84,84,68,0,72,84,84,36,0,72,84,84,36,0,0,0,124,84,84,40,0,4,4,124,4,4,0,124,8,16,124,0,72,124,64,0,0,4,4,124,4,4,0,56,68,68,56,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,17,17,10,0,14,17,17,14,0,31,2,4,31,0,1,1,31,1,1,0,17,31,17,0,31,2,4,31,0,15,16,16,15,0,31,21,21,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void gameEndEndless() {
    int i;
    for (i = 0; i < 512; i++) {toDisplay[i] = endPicture[i];}
    display_update();
    gameEndCount = 0;

    setupGame();
    volatile int pressBut = (volatile) pressBt();
    while (1)
    {
    
    if ((pressBt() & 1) && (gameEndCount > 10)) {
        gameState = HIGHSCOREEND;
    }
    if (gameState != GAMEENDEND) {
        return;
    }
    }
    
    
    
}


void gameEndNorm() {
    int i;
    for (i = 0; i < 512; i++) {toDisplay[i] = endPicture[i];}

    display_update();
    gameEndCount = 0;

    setupGame();
    volatile int pressBut = (volatile) pressBt();
    while (1)
    {
    
    if ((pressBt() & 1) && (gameEndCount > 10)) {
        gameState = HIGHSCORENORM;
    }

    if (gameState != GAMEENDNORM)
    {
        return;
    }
    }
}