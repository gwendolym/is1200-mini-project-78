#include <stdint.h>
#include <pic32mx.h>
#include <math.h>


#define GAMESTART (0)
#define MODESELECT (1)
#define NORMALGAME (2)
#define ENDLESSMODE (3)
#define GAMEEND (4)
#define PI 3.14159265359


uint8_t writeByte (uint8_t byte);

void paintOnDisplay (uint8_t *map);

void update ();

void setupGame();


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
void gameEnd();
void modeSelect(void);
void updateEndless();
volatile int calculateNextOn;
uint8_t toDisplay[512];
uint8_t trailmap[128][32];



#define CELL_WIDTH 128
#define CELL_HEIGHT 32
#define MOVE_SPEED 1
#define TURN_SPEED 0.05
#define SENSOR_SIZE 2
#define SENSOR_ANGLE_OFFSET 0.4
#define SENSOR_OFFSET_DST 1
#define ENEMY_NUMBER 1
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
    uint8_t trailmap[CELL_WIDTH][CELL_HEIGHT];
    // Point sensorForward;
    // Point sensorLeft;
    // Point sensorRight;
    // double sensorpointsForward[SENSOR_SIZE*2+1][2];
    // double sensorpointsRight[SENSOR_SIZE*2+1][2];
    // double sensorpointsLeft[SENSOR_SIZE*2+1][2];
    // double senseForward;
    // double senseLeft;
    // double senseRight;
};

void initEnemy(struct Enemy *enemy);
void drawEnemy(struct Enemy *enemy);
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
    int Direction;

};
void drawPlayer(struct Player *player);
void initPlayerNormal(struct Player *player);
void updatePlayerNormal(struct Player *player);
void initPlayerEndless(struct Player *player);
void updatePlayerEndless(struct Player *player);
double randomDouble (int n);
double min(double a, double b);
double max (double a, double b);
