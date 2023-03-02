#include <stdint.h>
#include <pic32mx.h>
#include <math.h>


#define GAMESTART (0)
#define MODESELECT (1)
#define NORMALGAME (2)
#define ENDLESSMODE (3)
#define GAMEENDEND (4)
#define GAMEENDNORM (5)
#define HIGHSCOREEND (6)
#define HIGHSCORENORM (7)
#define HIGHSCORES (8)


#define DISPLAY_CHANGE_TO_COMMAND_MODE (PORTFCLR = 0x10)
#define DISPLAY_CHANGE_TO_DATA_MODE (PORTFSET = 0x10)

#define DISPLAY_ACTIVATE_RESET (PORTGCLR = 0x200)
#define DISPLAY_DO_NOT_RESET (PORTGSET = 0x200)

#define DISPLAY_ACTIVATE_VDD (PORTFCLR = 0x40)
#define DISPLAY_ACTIVATE_VBAT (PORTFCLR = 0x20)

#define DISPLAY_TURN_OFF_VDD (PORTFSET = 0x40)
#define DISPLAY_TURN_OFF_VBAT (PORTFSET = 0x20)

#define PI 3.14159265359


uint8_t writeByte (uint8_t byte);

void paintOnDisplay (uint8_t *map);

void update ();

void setupGame();

extern const uint8_t const font[128*8];

void user_isr(void);

int pressSw();
int pressBt();

void startDisplay();
void display_update(void);
void enable_interrupt(void);
void gameStart(void);
int gameState;
int *pGameState;
void runGame(void);
void gameLoopNorm(void);
void gameLoopEndless(void);
void gameEndEndless();
void gameEndNorm();
void highScoreEnd();
void highScoreNorm();
void highscoreShow();

void modeSelect(void);
void updateEndless();
void updateNormal();
volatile int calculateNextOn;
uint8_t toDisplay[512];
uint8_t trailmap[128][32];
uint8_t evaporateSpeed;

void randomTimer();


#define CELL_WIDTH 128
#define CELL_HEIGHT 32
#define MOVE_SPEED 1
#define TURN_SPEED 0.25
#define SENSOR_SIZE 4
#define SENSOR_ANGLE_OFFSET 0.4
#define SENSOR_OFFSET_DST 1
#define ENEMY_NUMBER 5
#define DIFFUSE_SPEED 0.75
#define EVAPORATE_SPEED 2

typedef struct Highscore {
    char name0;
    char name1;
    char name2;

    int score;
} Highscore;

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Point2D {
    double x;
    double y;
} Point2D;

struct Enemy {
    Point2D positionDouble;
    Point positionInt;
    double angle;
    Point sensorForward;
    Point sensorLeft;
    Point sensorRight;
    double sensorpointsForward[SENSOR_SIZE*2+1][2];
    double sensorpointsRight[SENSOR_SIZE*2+1][2];
    double sensorpointsLeft[SENSOR_SIZE*2+1][2];
    double senseForward;
    double senseLeft;
    double senseRight;
};

void initEnemy(struct Enemy *enemy);
void drawEnemy();
void updateEnemy(struct Enemy *enemy);

int randomInt ();
double sin(double x);
double cos(double x);

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

struct Player {
    Point positionInt;
    Point direction;
    
};

struct Fruit {
    Point positionInt;
    
};
void drawPlayer(struct Player *player);
void initPlayerNormal(struct Player *player);
void updatePlayerNormal(struct Player *player);
void initPlayerEndless(struct Player *player);
void updatePlayerEndless(struct Player *player);
void drawFruit(struct Fruit *fruit);
void initFruit(struct Fruit *fruit);
void updateFruit(struct Fruit *fruit, struct Player *player);
double randomDouble (int n);
double min(double a, double b);
double max (double a, double b);

uint8_t iMin(uint8_t a, uint8_t b);
uint8_t iMax (uint8_t a, uint8_t b);
double lerp (double a, double b, double f);
void processTrailMap();
void clearDisplay();
void tick( unsigned int * timep );
void time2string( char *, int );
int mytime;
int* pMyTime;



void display_string(int line, char *s);
void display_update_text(void);
struct Highscore highscoresEND[3];
struct Highscore highscoresNORM[3];

void sw4Enable();
void sw3Enable();
void sw2Enable();
void sw1Enable();
void sw4Disable();
void sw3Disable();
void sw2Disable();
void sw1Disable();
void quicksleep(int cyc);
int gameEndCount;
int currentScore;
int *pcurrentSc;
int power(int x, int n);
void setHighscore(struct Highscore *highscore, char *name, int *score);
volatile int highSCount;
volatile int canReturn;