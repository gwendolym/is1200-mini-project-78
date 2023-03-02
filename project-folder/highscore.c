
#include <stdint.h>
#include <pic32mx.h>
#include "projcode.h"

#include <stdlib.h>

const uint8_t const tooLow[512] = {0,0,0,0,0,134,8,56,8,134,0,28,162,162,28,0,158,32,32,158,0,190,138,154,164,0,0,0,164,170,170,18,128,156,162,162,148,0,28,34,34,156,128,62,10,154,36,0,190,42,42,34,128,128,128,190,144,8,144,62,0,188,10,138,188,128,164,42,42,18,128,0,0,2,2,190,130,130,128,28,34,162,156,0,28,162,162,156,0,0,128,190,160,160,32,128,156,162,34,28,128,190,144,8,16,62,128,128,0,2,2,190,130,2,0,156,162,162,28,0,128,128,128,0,0,0,0,0,0,0,0,0,0,15,1,2,1,15,0,15,2,2,15,0,15,2,5,8,0,15,10,10,8,0,0,0,8,15,8,0,0,0,15,0,0,0,0,0,7,8,8,7,0,15,1,2,15,0,0,0,0,0,15,0,0,0,15,2,2,15,0,15,10,10,8,0,0,0,15,8,8,8,0,15,10,10,8,0,15,2,2,15,0,15,8,8,7,0,15,10,10,8,0,15,2,6,9,0,15,10,10,5,0,7,8,8,7,0,15,2,2,15,0,15,2,6,9,0,15,8,8,7,0,0,0,0,0,0,0,0,0,129,65,95,1,1,64,223,69,13,210,0,3,4,220,4,195,64,64,64,30,5,5,222,0,14,209,21,204,64,94,133,5,94,64,81,159,17,0,31,130,68,95,64,1,213,5,6,0,192,0,146,85,85,137,0,31,8,4,8,31,0,18,31,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,4,5,3,0,4,7,4,0,0,3,4,3,0,0,7,5,5,4,0,0,0,3,4,4,3,0,7,1,1,0,0,0,5,1,1,0,0,0,4,5,5,2,0,7,2,1,2,7,0,4,6,5,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

const uint8_t const viewSelectHight[512] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,120,128,0,128,120,0,8,8,248,8,8,0,248,72,72,72,8,0,248,0,192,0,248,0,0,0,248,64,64,64,248,0,8,8,248,8,8,0,240,8,136,136,8,0,248,64,64,64,248,0,48,72,72,72,136,0,240,8,8,8,8,0,240,8,8,8,240,0,248,72,200,72,48,0,248,72,72,72,8,0,48,72,72,72,136,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,1,0,0,2,2,3,2,2,0,195,66,66,130,2,64,65,194,65,66,1,192,128,0,195,0,128,192,3,0,2,130,3,2,2,0,129,66,67,128,3,128,67,64,128,0,195,0,2,2,2,194,1,0,1,2,194,66,66,64,1,130,66,66,129,0,67,64,192,65,66,0,3,2,2,2,2,0,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,135,133,133,2,0,128,128,135,128,128,0,135,0,1,135,0,4,135,132,0,0,2,0,0,0,0,3,4,132,130,128,3,132,4,3,128,7,132,132,132,0,7,132,4,4,0,135,5,133,132,128,3,132,4,2,0,128,0,7,128,128,0,0,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,10,10,5,0,0,0,15,0,0,0,15,1,2,15,0,9,12,10,9,0,0,5,0,0,0,0,9,10,10,4,0,7,8,8,7,0,15,2,6,9,0,1,6,8,6,1,0,8,15,8,0,1,6,8,6,1,0,15,2,2,15,0,15,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


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

void setHighscore(struct Highscore *highscore, char *name, int* score) {
    highscore->name0 = *(name++);
    highscore->name1 = *(name++);
    highscore->name2 = *(name);

    highscore->score = *score;
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
    int j;
    int arr[6];
    
 
    int count = 0;    
    int n = highscore->score;//highscore->score;

    if  (n < 10) {
        int i;
        for (i = 1; i < 6; i++)
        {
            arr[i] = 0;
        }
        arr[0] = n;
        
    }
    else
    {
        int i=0;
        while(n>0){
        arr[i] = n % 10;
        n = n/10;
        i++;
    }
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
    string[9] = ' ';
    string[10] = ' ';
    string[14] = ' ';
    string[11] = arr[2] + 48;
    string[12] = arr[1] + 48;
    string[13] = arr[0] + 48;
    string[15] = ' ';

    

    display_strings(string, line);
}

void insertHighscore(int line) {
    char name[3] = {65, 65, 65};
    int pos = 0;
    calculateNextOn == 1;
    
    while (pos < 3) {
        if (calculateNextOn == 1)
        {
            volatile int pressBut = (volatile int) pressBt();
            if ((pressBut & 0x8) && (name[pos] < 91))
                name[pos]++;
            if ((pressBut & 0x8) && (name[pos] == 91))
                name[pos] = 65;    
            if ((pressBut & 0x4) && (name[pos] > 65))
                name[pos]--;
            if ((pressBut & 0x4) && (name[pos] == 65))
                name[pos] = 90;
            if (pressBut & 0x2) {
                pos++; 
                
            }
            setHighscore(&highscores[line], name, pMyTime);
            display_strings("-Highscores-Sur-", 0);
            display_highscore_end(&highscores[0], 1, 1);
            display_highscore_end(&highscores[1], 2, 2);
            display_highscore_end(&highscores[2], 3, 3);
            calculateNextOn = 0;
        }
    }
     

gameState = MODESELECT;
display_update();
return;

}

void insertHighscoreNORM(int line) {
    char name[3] = {65, 65, 65};
    int pos = 0;
    calculateNextOn == 1;
    
    while (pos < 3) {
        if (calculateNextOn == 1)
        {
            volatile int pressBut = (volatile int) pressBt();
            if ((pressBut & 0x8) && (name[pos] < 91))
                name[pos]++;
            if ((pressBut & 0x8) && (name[pos] == 91))
                name[pos] = 65;    
            if ((pressBut & 0x4) && (name[pos] > 65))
                name[pos]--;
            if ((pressBut & 0x4) && (name[pos] == 65))
                name[pos] = 90;
            if (pressBut & 0x2) {
                pos++; 
                
                }
            setHighscore(&highscoresNORM[line], name, &gameScore);
            display_strings("-Highscores-Col-", 0);
            display_highscore_norm(&highscoresNORM[0], 1, 1);
            display_highscore_norm(&highscoresNORM[1], 2, 2);
            display_highscore_norm(&highscoresNORM[2], 3, 3);
            calculateNextOn = 0;
        }
    }
     

gameState = MODESELECT;
display_update();
return;

}

void highScoreEnd() {
    int i;
    
    for (i = 0; i < 512; i++)
    {
        toDisplay[i] = 0;
    }

    setupGame();
    if (*pMyTime > getScore(&highscores[0]))
    {
        highscores[2] = highscores[1];
        highscores[1] = highscores[0];
        insertHighscore(0);
        return;
    }
    else {
        if (*pMyTime > getScore(&highscores[1]))
        {
        highscores[2] = highscores[1];
        insertHighscore(1);
        return;
        }
        else
        {
            if (*pMyTime > getScore(&highscores[0]))
            {
                insertHighscore(2);
                return;
            }
            else
            {
                int i;
                for (i = 0; i < 512; i++)
                {
                    toDisplay[i] = tooLow[i];
                }
                gameState = MODESELECT;
                return;

            }
            
        }
        
    }

    highSCount = 0;
    canReturn = 0;
    while (!canReturn);


    
    display_update();
}
int getScore (struct Highscore *highscore) {
    return highscore->score;
}
void highScoreNorm() {
    int i;
    
    for (i = 0; i < 512; i++)
    {
        toDisplay[i] = 0;
    }

    setupGame();
    if (gameScore > getScore(&highscoresNORM[0]))
    {
        highscoresNORM[2] = highscoresNORM[1];
        highscoresNORM[1] = highscoresNORM[0];
        insertHighscoreNORM(0);
        return;
    }
    else {
        if (gameScore > getScore(&highscoresNORM[1]))
        {
        highscoresNORM[2] = highscoresNORM[1];
        insertHighscoreNORM(1);
        return;
        }
        else
        {
            if (gameScore > getScore(&highscoresNORM[0]))
            {
                insertHighscoreNORM(2);
                return;
            }
            else
            {
                int i;
                for (i = 0; i < 512; i++)
                {
                    toDisplay[i] = tooLow[i];
                }
                gameState = MODESELECT;
                return;

            }
            
        }
        
    }

    highSCount = 0;
    canReturn = 0;
    while (!canReturn);


    
    display_update();
}





void highscoreShow() {
    int i = 0;
        for (i = 0; i < 512; i++) {toDisplay[i] = viewSelectHight[i];}
        setupGame();
        display_update();

        highSCount =0;
        canReturn = 0;
        while (!canReturn);
        while(1) {

        volatile int press = pressBt();
        if (press & 0x1) {
            display_strings("-Highscores-Col-", 0);
            display_highscore_norm(&highscoresNORM[0], 1, 1);
            display_highscore_norm(&highscoresNORM[1], 2, 2);
            display_highscore_norm(&highscoresNORM[2], 3, 3);
            display_update();
            
            
        }

        if (press & 0x2) {
            display_strings("-Highscores-Sur-", 0);
            display_highscore_end(&highscores[0], 1, 1);
            display_highscore_end(&highscores[1], 2, 2);
            display_highscore_end(&highscores[2], 3, 3);
            display_update();
            
        
        }
        if (press & 0x8) {
            gameState = MODESELECT;
            display_update();
            return;
        
        }
        }
        
}