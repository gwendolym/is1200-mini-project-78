
#include <stdint.h>
#include <pic32mx.h>
#include "projcode.h"

#include <stdlib.h>


void highScoreEnd() {
    int i;
    for (i = 0; i < 512; i++)
    {
        toDisplay[i] = 4;
    }
    display_update();
    
    // display_string(0, "Highscores");
    // display_string(1, "Highscores");
    // display_string(2, "Highscores");
    // display_string(3, "Highscores");
    // display_update_text();
}
void highScoreNorm() {

}