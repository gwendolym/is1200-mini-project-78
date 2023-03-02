#include <pic32mx.h>
#include "projcode.h"
#include <stdint.h>

// #include <pic32mx.h>
// #include "projcode.h"
// #include <stdint.h>
// #include <math.h>

struct Enemy enemy1;
struct Enemy enemies[5];
struct Player player;
struct Fruit fruit;




// uint8_t evaporateSpeed = 64;

int gameScore;


void gameLoopNorm (void) {
    setupGame();
        gameScore = 0;

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
    for (l = 0; l < 5; l++)
    {
        initEnemy(&(enemies[l]));
    }
    initPlayerNormal(&player);
    initFruit(&fruit);
    drawFruit(&fruit);

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
        for (i = 0; i < 5; i++)
        {
            updateEnemy(&(enemies[i]));
        }
        updatePlayerNormal(&player);
        updateFruit(&fruit, &player, &gameScore);
        
        // updateEnemy(&enemy1);
        drawEnemy();
        drawPlayer(&player);
        drawFruit(&fruit);
        // toDisplay[0]++;
        calculateNextOn = 0;
    }
    
    return;
}


