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

int randomNumbers[] = {720, 401, 50, 458, 811, 918, 212, 846, 849, 565, 105, 291, 309, 670, 638, 787, 128, 998, 834, 4, 183, 834, 949, 405, 235, 9, 406, 802, 646, 405, 468, 951, 466, 212, 500, 464, 900, 235, 192, 269, 425, 801, 208, 653, 417, 21, 428, 76, 829, 386, 229, 96, 565, 353, 801, 252, 335, 455, 359, 484, 52, 496, 32, 443, 273, 222, 779, 370, 187, 489, 158, 855, 44, 919, 47, 533, 256, 97, 434, 30, 712, 91, 364, 94, 315, 983, 188, 3, 931, 159, 36, 758, 500, 717, 920, 849, 632, 358, 141, 112, 169, 219, 568, 504, 206, 90, 66, 129, 173, 604, 541, 337, 702, 367, 140, 72, 167, 471, 556, 683, 710, 759, 380, 801, 701, 198, 177, 466, 245, 520, 918, 166, 127, 730, 386, 856, 142, 397, 290, 818, 363, 821, 267, 635, 291, 409, 662, 434, 915, 257, 733, 129, 439, 340, 924, 738, 562, 527, 2, 360, 659, 135, 931, 244, 920, 220, 489, 413, 745, 275, 918, 768, 94, 755, 901, 649, 445, 309, 843, 488, 669, 950, 106, 320, 661, 316, 563, 506, 394, 859, 889, 340, 389, 294, 39, 905, 263, 824, 560, 337, 947, 789, 487, 628, 479, 127, 163, 767, 690, 481, 505, 588, 823, 872, 851, 987, 213, 79, 760, 749, 189, 866, 441, 912, 346, 655, 696, 990, 767, 869, 845, 52, 809, 693, 304, 375, 60, 158, 6, 133, 859, 801, 236, 746, 639, 950, 949, 141, 294, 912, 881, 714, 833, 170, 365, 961, 345, 629, 642, 525, 292, 761, 162, 47, 859, 359, 95, 880, 887, 287, 460, 877, 91, 500, 550, 120, 136, 573, 325, 699, 341, 962, 802, 253, 624, 761, 165, 520, 965, 445, 116, 792, 887, 160, 606, 404, 336, 82, 321, 667, 520, 137, 206, 179, 244, 247, 294, 110, 654, 762, 178, 544, 451, 528, 685, 915, 695, 287, 368, 937, 773, 669, 498, 525, 795, 874, 341, 455, 423, 384, 740, 304, 607, 588, 129, 806, 944, 731, 480, 840, 608, 60, 923, 337, 862, 225, 76, 283, 263, 101, 856, 162, 179, 554, 260, 126, 885, 231, 739, 63, 66, 252, 960, 222, 256, 884, 606, 966, 421, 998, 774, 184, 581, 929, 752, 250, 901, 103, 511, 186, 646, 704, 30, 119, 818, 144, 151, 82, 862, 233, 181, 545, 911, 32, 730, 482, 425, 346, 516, 639, 551, 998, 187, 950, 86, 767, 410, 219, 677, 947, 227, 721, 415, 126, 407, 547, 38, 938, 833, 73, 238, 399, 7, 444, 827, 347, 152, 524, 403, 943, 212, 581, 701, 90, 693, 654, 762, 888, 381, 75, 999, 208, 487, 905, 812, 776, 462, 831, 719, 828, 581, 348, 289, 920, 841, 852, 438, 110, 635, 556, 621, 596, 977, 731, 881, 761, 962, 431, 827, 75, 265, 998, 735, 488, 687, 855, 885, 759, 932, 100, 449, 449, 178, 256, 448, 678, 236, 77, 107, 990, 643, 631, 325, 168, 621, 107, 521, 129, 659, 364, 304, 280, 409, 314, 826, 863, 997, 546, 97, 162, 990, 894, 488, 424, 427, 120, 656, 73, 725, 510, 181, 737, 484, 433, 942, 538, 53, 132, 226, 809, 777, 124, 111, 349, 765, 401, 646, 20, 82, 762, 98, 850, 808, 50, 111, 642, 24, 46, 467, 265, 9, 586, 413, 378, 170, 513, 98, 796, 942, 966, 994, 837, 33, 268, 603, 591, 943, 554, 547, 434, 923, 577, 67, 871, 438, 640, 791, 243, 940, 809, 511, 499, 195, 481, 281, 158, 238, 579, 990, 126, 937, 842, 969, 928, 778, 590, 56, 484, 372, 210, 730, 262, 55, 361, 729, 888, 500, 131, 62, 121, 948, 427, 784, 836, 517, 239, 103, 474, 218, 194, 415, 228, 204, 461, 83, 380, 340, 934, 184, 677, 240, 911, 620, 606, 928, 130, 141, 994, 942, 643, 898, 260, 523, 905, 434, 180, 464, 184, 541, 44, 851, 168, 708, 95, 262, 991, 82, 98, 550, 148, 983, 298, 690, 464, 189, 381, 584, 115, 170, 4, 813, 242, 714, 314, 121, 115, 675, 88, 790, 412, 498, 653, 389, 161, 849, 677, 461, 948, 551, 648, 521, 461, 578, 160, 54, 347, 161, 904, 48, 576, 762, 937, 919, 891, 251, 833, 677, 786, 960, 346, 611, 177, 5, 512, 450, 78, 757, 883, 275, 162, 589, 720, 625, 226, 164, 752, 914, 840, 736, 908, 115, 835, 374, 42, 292, 232, 829, 929, 699, 745, 338, 685, 288, 510, 610, 373, 745, 197, 799, 196, 650, 729, 823, 49, 923, 634, 534, 691, 7, 968, 510, 172, 219, 739, 775, 345, 168, 917, 877, 677, 580, 896, 293, 675, 54, 297, 579, 774, 705, 592, 505, 746, 406, 242, 113, 845, 49, 442, 80, 861, 369, 871, 182, 579, 977, 897, 707, 138, 749, 926, 554, 381, 976, 498, 146, 920, 591, 708, 865, 908, 281, 612, 706, 732, 590, 433, 402, 333, 129, 214, 721, 960, 967, 301, 347, 270, 233, 403, 39, 802, 860, 48, 730, 201, 887, 904, 936,556, 601, 182, 702, 548, 15, 499, 989, 538, 121, 590, 705, 94, 742, 11, 365, 749, 191, 519, 129, 787, 211, 257, 130, 284, 711, 198, 509, 112, 265, 155, 699, 595, 491, 753, 1000, 950, 421, 438, 85, 871, 306, 624, 513, 533, 288, 58, 915, 695, 852, 323, 606, 609, 437, 848, 362, 891, 434, 377, 347, 336, 700, 694, 826, 241, 711, 981, 638, 395, 759, 139, 190, 995, 249, 995, 668, 329, 927, 624, 18, 872, 742, 751, 392, 773, 870, 981, 757, 711, 981, 541, 208, 865, 383, 200, 76, 581, 969, 145, 402, 991, 325, 987, 866, 837, 78, 972, 704, 22, 602, 346, 216, 997, 35, 88, 493, 314, 30, 705, 558, 412, 477, 483, 111, 141, 713, 70, 81, 88, 909, 834, 853, 320, 268, 879, 164, 793, 183, 315, 183, 401, 995, 69, 875, 203, 883, 703, 753, 206, 455, 693, 417, 928, 824, 168, 464, 267, 965, 921, 317, 736, 172, 632};

double randomDouble (int n) {
    return (double) randomNumbers[n % 1000]/1000;
}

double min (double a, double b) {
    if (a<b)
    {
        return a;
    }
    return b;
}
double max (double a, double b) {
    if (a>b)
    {
        return a;
    }
    return b;
}

// uint8_t iMin(uint8_t a, uint8_t b) {
//     if (a<b)
//     {
//         return a;
//     }
//     return b;
// }
// uint8_t iMax (uint8_t a, uint8_t b) {
//     if (a>b)
//     {
//         return a;
//     }
//     return b;
// }
    
double lerp (double a, double b, double f) {
    return a * (1.0 - f) + (b * f);
}

