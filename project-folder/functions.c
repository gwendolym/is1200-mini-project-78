#include <pic32mx.h>
#include "projcode.h"
#include <stdint.h>




uint8_t startPicture[] = {0,0,0,64,64,64,192,128,0,0,0,192,64,64,64,128,0,192,64,64,64,64,0,64,64,192,64,64,0,192,0,0,0,192,0,192,64,64,64,128,0,192,0,0,0,192,0,0,0,128,64,64,64,128,0,192,64,64,64,64,0,0,0,64,64,192,64,64,0,192,0,0,0,192,0,192,64,64,64,64,0,0,0,128,64,64,64,64,0,192,0,0,0,192,0,128,64,64,64,128,0,192,0,0,128,64,0,192,64,64,64,64,0,128,64,64,64,64,64,64,192,128,0,0,0,0,0,0,0,0,0,128,128,192,96,57,15,0,0,31,2,6,10,17,0,31,18,18,18,16,0,0,0,31,0,0,0,15,16,16,16,15,0,31,2,6,10,17,0,31,1,2,4,31,0,0,0,15,16,16,16,15,0,31,2,2,2,0,0,0,0,0,0,31,0,0,0,31,2,2,2,31,0,31,18,18,18,16,0,0,0,17,18,18,18,12,0,31,1,2,4,31,0,31,2,2,2,31,0,31,2,5,8,16,0,31,18,18,18,16,0,17,18,18,18,12,0,0,240,155,14,0,0,0,0,0,0,252,7,1,0,248,40,40,16,0,248,40,104,144,0,248,168,168,136,0,144,168,168,72,0,144,168,168,72,0,0,0,240,40,40,240,0,248,16,32,248,0,24,32,224,32,24,0,0,0,248,168,168,80,0,120,128,128,120,0,8,8,248,8,8,0,8,8,248,8,8,0,112,136,136,112,0,248,16,32,248,0,0,0,8,8,248,8,8,0,112,136,136,112,0,0,0,144,168,168,72,0,8,8,248,8,8,0,240,40,40,240,0,248,40,104,144,0,8,8,248,9,9,3,2,6,252,0,0,3,14,8,24,16,48,32,32,96,64,64,64,64,64,64,64,64,64,64,64,64,96,32,32,32,16,24,8,12,4,4,4,4,4,4,4,4,4,4,12,8,8,24,16,48,32,32,96,64,64,64,64,64,64,64,64,96,32,32,48,16,24,8,8,12,4,4,4,4,6,2,2,6,4,4,12,8,8,24,16,16,32,32,32,96,64,64,64,64,64,64,64,64,64,96,32,32,48,24,8,12,4,4,4,4,4,4,4,12,8,8,24,48,32,32,96,64,64,64,64,96,32,48,24,14,3,0};

uint8_t gameModeSelect[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,48,72,72,72,136,0,248,72,72,72,8,0,248,0,0,0,0,0,248,72,72,72,8,224,16,8,8,8,8,0,8,8,248,8,8,0,0,0,240,8,136,136,136,0,240,72,72,72,240,0,248,16,32,16,248,0,248,72,72,72,8,0,248,16,32,16,248,0,240,8,8,8,240,0,248,8,8,16,224,0,248,72,72,72,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,1,0,3,2,2,2,2,0,195,66,66,130,2,64,67,194,66,66,2,192,129,2,194,2,130,192,0,0,3,128,0,0,0,0,129,66,66,130,1,128,67,64,128,0,195,0,3,0,0,192,3,0,3,2,194,66,66,64,3,128,64,64,131,0,65,66,194,66,65,0,3,2,2,1,0,0,3,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,135,133,133,2,0,128,128,135,128,128,0,135,0,1,135,0,4,135,132,0,0,2,0,0,0,0,3,4,132,130,128,3,132,4,3,128,7,132,132,132,0,7,132,4,4,0,135,5,133,132,128,3,132,4,2,0,128,0,7,128,128,0,0,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,10,10,5,0,0,0,15,0,0,0,15,1,2,15,0,9,12,10,9,0,0,5,0,0,0,0,9,10,10,4,0,7,8,8,7,0,15,2,6,9,0,1,6,8,6,1,0,8,15,8,0,1,6,8,6,1,0,15,2,2,15,0,15,8,8,8,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


#define DISPLAY_CHANGE_TO_COMMAND_MODE (PORTFCLR = 0x10)
#define DISPLAY_CHANGE_TO_DATA_MODE (PORTFSET = 0x10)

#define DISPLAY_ACTIVATE_RESET (PORTGCLR = 0x200)
#define DISPLAY_DO_NOT_RESET (PORTGSET = 0x200)

#define DISPLAY_ACTIVATE_VDD (PORTFCLR = 0x40)
#define DISPLAY_ACTIVATE_VBAT (PORTFCLR = 0x20)

#define DISPLAY_TURN_OFF_VDD (PORTFSET = 0x40)
#define DISPLAY_TURN_OFF_VBAT (PORTFSET = 0x20)


uint8_t writeByte (uint8_t byte) {

    // wait until transmit buffer is empty (1 = empty, 0 = not empty)
    while ((SPI2STAT & 0x8) == 0); // SPITBE
    
    SPI2BUF = byte;

    //wait until Receive Buffer is full (1 = full, 0 = not full)
    while ((SPI2STAT & 0x1) == 0); //SPITBF
    return SPI2BUF;
}

// void paintOnDisplay (uint8_t *map) {
//     // paint every bit in map to display 
//     for (int i = 0; i < 512; i++ ) {
//         writeByte(map[i]);
//     }

// }
void quicksleep(int cyc) {
	int i;
	for(i = cyc; i > 0; i--);
}
void startDisplay(void) {
    DISPLAY_CHANGE_TO_COMMAND_MODE;
	quicksleep(10);
	DISPLAY_ACTIVATE_VDD;
	quicksleep(1000000);
	
	writeByte(0xAE);
	DISPLAY_ACTIVATE_RESET;
	quicksleep(10);
	DISPLAY_DO_NOT_RESET;
	quicksleep(10);
	
	writeByte(0x8D);
	writeByte(0x14);
	
	writeByte(0xD9);
	writeByte(0xF1);
	
	DISPLAY_ACTIVATE_VBAT;
	quicksleep(10000000);
	
	writeByte(0xA1);
	writeByte(0xC8);
	
	writeByte(0xDA);
	writeByte(0x20);
	
	writeByte(0xAF);
}

void display_update(void) {
	int i, j, k;
	int c;
	for(i = 0; i < 4; i++) {
		DISPLAY_CHANGE_TO_COMMAND_MODE;
		writeByte(0x22);
		writeByte(i);
		
		writeByte(0x0);
		writeByte(0x10);
		
		DISPLAY_CHANGE_TO_DATA_MODE;
		
		for(j = 0; j < 128; j++) {
			writeByte(toDisplay[i * 128 + j]);
		}
	}
}



void setupGame() {
    // Timer with prescaling of 256, update 20 times per second 
    T2CON = 0x70; //0111 0000 (111) means prescale 256
    TMR2 = 0; //start at 0
    PR2 = ((80000000/256)/10);  //prescale to 256 


    // Buttons and Switches to input
    TRISD = TRISD | (0xfe0);
    TRISFSET = 1;
    
    IFSCLR(0) = 0x100; //T2 interupt flag reset
    IPC(2) = IPC(2) | 0x1f; // 000(1 11) (11)
    IEC(0) = 0x100;
    
    T2CONSET = 0x8000; //start timer igore all other bits 1000 0000 0000 0000

    enable_interrupt();
}
int timeout = 0;

void gameStart() {
    int i = 0;
    for (i = 0; i < 512; i++) {toDisplay[i] = startPicture[i];}
    setupGame();

    display_update();
    volatile int pressBut = (volatile) pressBt();
    if (pressBut & 0x8) {
        gameState = MODESELECT;
    }
    if (gameState != GAMESTART)
    {
        return;
    }
    

}

void modeSelect () {

        int i = 0;
        for (i = 0; i < 512; i++) {toDisplay[i] = gameModeSelect[i];}
        setupGame();
        display_update();
        volatile int press = pressBt();
        if (press & 0x1) {
            gameState = NORMALGAME;
            return;
        }

        if (press & 0x2) {
            gameState = ENDLESSMODE;
            return;
        }
    
    
}

void runGame() {
    switch (gameState)
    {
    case GAMESTART:
        gameStart();
        break;
    case MODESELECT:
        modeSelect();
        break;
    case NORMALGAME:
        gameLoopNorm();
        break;
    case ENDLESSMODE:
        gameLoopEndless();
        break;
    case GAMEEND:
        gameEnd();
        break;
    default:
        break;
    }
}



void gameLoopNorm () {
    int i = 0;
    for (i = 0; i < 512; i++)
    {
        toDisplay[i] = 4;
    }
    display_update();
}
// void gameLoopEndless () {
//         int i = 0;
//     for (i = 0; i < 512; i++)
//     {
//         toDisplay[i] = 7;
//     }
// }
void gameEnd() {

}
volatile int calculateNextOn;
void user_isr( void )
{
    if (((IFS(0) & 0x100) != 0 ) & (gameState == ENDLESSMODE)) {
        IFSCLR(0) = 0x100;
        while (calculateNextOn);
        display_update();
        calculateNextOn = 1;
    }
    

}


// double pow(double x, int n) {
//     double res = x;
//     if (n == 0)
//     {
//         return 1;
//     }
//     int i;
//     for (i = 1; i < n; i++)
//     {
//         res *= x;
//     }
//     return res;
// }
// int fact(int x) {
//     if (x == 0)
//     {
//         return 1;
//     }
//     else
//     {
//         return (x * fact(x-1));
//     }   
// }

// double sin(double x) {
//     int n;
//     double res = 0;
//     for (n = 0; n < 10; n++)
//     {
//         pow(-1, n) / fact(2 * n + 1) * pow(x, 2 * n + 1);
//     }
// }
// double cos(double x) {
//     int n;
//     double res = 0;
//     for (n = 0; n < 10; n++)
//     {
//         pow(-1, n) / fact(2 * n) * pow(x, 2 * n);
//     }
    
// }
double sin(double x)
{
    double res=0, pow=x, fact=1;
    int i;
    for(i=0; i<10; ++i) {
        res+=pow/fact;
        pow*=-1*x*x;
        fact*=(2*(i+1))*(2*(i+1)+1);
    }

    return res;
}
double cos(double x)
{
    double res=0, pow=1, fact=1;
    int i;
    for(i=0; i<10;i++) {
        res+=pow/fact;
        pow*=-1*x*x;
        fact*=(2*(i+1))*(2*(i+1)-1);
    }

    return res;
}