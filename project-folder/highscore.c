
#include <stdint.h>
#include <pic32mx.h>
#include "projcode.h"

#include <stdlib.h>


void display_char(char c, int line, int row) {
    
    int k;
    for(k = 0; k < 8; k++)
		toDisplay[line*128 + 8 * row + k] = (font[c*8 + k]);

}

void display_strings(char* string, int line) {
    int i;
    for (i = 0; i < 16; i++)
    {
        if (*string == 0)
        {
            return;
        }
        display_char(*string, line, i);
        string++;
    }
    
}

void setHighscore(struct Highscore *highscore, char *name, int score) {
    highscore->name0 = *(name++);
    highscore->name1 = *(name++);
    highscore->name2 = *(name);

    highscore->score = score;
}

void display_highscore_end(struct Highscore *highscore, int line, int place) {
    char string[16];
    char time[6]; 
    time2string(time, highscore->score);
    string[0] = hexasc(place);
    string[1] = '.';
    string[2] = ' ';
    string[3] = highscore->name0;
    string[4] = highscore->name1;
    string[5] = highscore->name2;
    string[6] = ' ';
    string[7] = ' ';
    string[8] = ' ';
    int i;
    for ( i = 0; i < 6; i++)
    {
        string[9+i] = (time[i]); 
    }
    

    display_strings(string, line);
}
void display_highscore_norm(struct Highscore *highscore, int line, int place) {
    char string[16];
    char score[6];
    int j;
    for (j = 5; j = 0; j--)
    {
        score[j] = 48 + j;//hexasc(highscore->score % 10);
    }
    
    string[0] = hexasc(place);
    string[1] = '.';
    string[2] = ' ';
    string[3] = highscore->name0;
    string[4] = highscore->name1;
    string[5] = highscore->name2;
    string[6] = ' ';
    string[7] = ' ';
    string[8] = ' ';
    int i;
    int bigger = 0;
    for (i = 0; i < 6; i++)
    {
        string[9+i] = - bigger *(power(10,5-i)) + (highscore->score / power(10, 5-i)) + 48; 
        bigger = highscore->score / power(10, 5-i);
    }
    

    display_strings(string, line);
}

void highScoreEnd() {
    int i;
    
    for (i = 0; i < 512; i++)
    {
        toDisplay[i] = 0;
    }
    // display_strings("AHello", 0);
    // display_strings("BAHello", 1);
    // display_strings("CBAHello", 2);

    // display_strings("DCBAHello", 3);
    setHighscore(&highscores[0], "HAN", 0x1234);
    display_highscore_norm(&highscores[0], 1, 1);

    display_update();
}

void highScoreNorm() {
    int i;
    
    for (i = 0; i < 512; i++)
    {
        toDisplay[i] = 0;
    }
    // display_strings("AHello", 0);
    // display_strings("BAHello", 1);
    // display_strings("CBAHello", 2);

    // display_strings("DCBAHello", 3);
    setHighscore(&highscores[0], "HAN", 123456);
    display_highscore_norm(&highscores[0], 1, 1);

    display_update();
}
