#include <pic32mx.h>
#include "projcode.h"
#include <stdint.h>
#include <math.h>

struct Enemy enemy1;

void gameLoopEndless (void) {
    setupGame();
    int i = 0;
    for (i = 0; i < 512; i++)
    {
        toDisplay[i] = 0;
    }
    int j, k;
    for (j = 0; j < 128; j++)
    {
        for (k = 0; k < 32; k++)
        {
            trailmap[j][k] = 0;
        }
        
    }
    

    display_update();
    calculateNextOn == 1;
    initEnemy(&enemy1);
    drawEnemy();



    while(gameState == ENDLESSMODE) {
        updateEndless();
    }
    return;
}


void updateEndless() {
    if (calculateNextOn == 1)
    {
        updateEnemy(&enemy1);
        drawEnemy();
        // toDisplay[0]++;
        calculateNextOn = 0;
    }
    
    return;
}

void clearDisplay() {
    int i = 0;
    for (i = 0; i < 512; i++)
    {
        toDisplay[i] = 0;
    }
}