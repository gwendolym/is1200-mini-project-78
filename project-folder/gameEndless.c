#include <pic32mx.h>
#include "projcode.h"
#include <stdint.h>
#include <math.h>

struct Enemy enemy1;
struct Enemy enemies[10];
uint8_t evaporateSpeed = 64;
struct Player player;

void gameLoopEndless (void) {
    setupGame();
    int i = 0;
    for (i = 0; i < 512; i++)
    {
        toDisplay[i] = 0;
    }
    *pMyTime = 0;
    int j, k;
    for (j = 0; j < 128; j++)
    {
        for (k = 0; k < 32; k++)
        {
            trailmap[j][k] = 0;
        }
        
    }
    int l;
    
    display_update();
    calculateNextOn == 1;
    // initEnemy(&enemy1);
    drawEnemy();
    for (l = 0; l < 10; l++)
    {
       initEnemy(&(enemies[l]));
    }
    initPlayerEndless(&player);



    while(gameState == ENDLESSMODE) {
        updateEndless();
    }
    return;
}
int timer;

void updateEndless() {
    if (calculateNextOn == 1)
    {
        timer++;
        if (timer%10 == 0 && evaporateSpeed >= 2) {
            evaporateSpeed /=1.001;
        }
        
        int i;
        for (i = 0; i < 10; i++)
        {
            updateEnemy(&(enemies[i]));
        }
        updatePlayerEndless(&player);

        // updateEnemy(&enemy1);
        drawEnemy();
        drawPlayer(&player);
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