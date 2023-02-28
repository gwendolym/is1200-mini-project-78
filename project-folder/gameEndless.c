#include <pic32mx.h>
#include "projcode.h"
#include <stdint.h>

struct Agent agent1;

void gameLoopEndless (void) {
    setupGame();
    int i = 0;
    for (i = 0; i < 512; i++)
    {
        toDisplay[i] = 0;
    }
    display_update();
    calculateNextOn == 1;
    int j;
    initAgent(&agent1);
    drawAgent(&agent1);


    while(gameState == ENDLESSMODE) {
        updateEndless();
     }
    return;
}


void updateEndless() {
    if (calculateNextOn == 1)
    {
        updateAgent(&agent1);
        drawAgent(&agent1);
        toDisplay[0]++;
        calculateNextOn = 0;
    }
    
    return;
}