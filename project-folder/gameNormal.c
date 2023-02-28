#include <pic32mx.h>
#include "projcode.h"
#include <stdint.h>

// #include <pic32mx.h>
// #include "projcode.h"
// #include <stdint.h>
// #include <math.h>

struct Enemy enemy1;
struct Enemy enemies[1];
struct Player player;

// uint8_t evaporateSpeed = 64;

void gameLoopNorm (void) {
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
    int l;
    

    display_update();
    calculateNextOn == 1;
    // initEnemy(&enemy1);
    drawEnemy();
    for (l = 0; l < 1; l++)
    {
       initEnemy(&(enemies[l]));
    }
    initPlayerNormal(&player);



    while(gameState == NORMALGAME) {
        updateNormal();
    }
    return;
}

void updateNormal() {
    if (calculateNextOn == 1)
    {
        evaporateSpeed = 4;
        int i;
        for (i = 0; i < 1; i++)
        {
            updateEnemy(&(enemies[i]));
        }
        updatePlayerNormal(&player);
        
        // updateEnemy(&enemy1);
        drawEnemy();
        drawPlayer(&player);
        // toDisplay[0]++;
        calculateNextOn = 0;
    }
    
    return;
}


