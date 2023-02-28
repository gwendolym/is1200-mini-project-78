/*
    This file handles everything that has to do with the snake enemies

*/

#include <stdint.h>
#include <pic32mx.h>
#include "projcode.h"

#include <stdlib.h>
#include <math.h>


// #define CELL_WIDTH 128
// #define CELL_HEIGHT 32
// #define MOVE_SPEED 1
// #define TURN_SPEED 0.05
// #define SENSOR_SIZE 2
// #define SENSOR_ANGLE_OFFSET 0.4
// #define SENSOR_OFFSET_DST 1

// typedef struct Point {
//     int x;
//     int y;
// } Point;

// typedef struct Point2D {
//     double x;
//     double y;
// } Point2D;

// struct Enemy {
//     Point2D positionDouble;
//     Point positionInt;
//     double angle;
//     // Point sensorForward;
//     // Point sensorLeft;
//     // Point sensorRight;
//     // double sensorpointsForward[SENSOR_SIZE*2+1][2];
//     // double sensorpointsRight[SENSOR_SIZE*2+1][2];
//     // double sensorpointsLeft[SENSOR_SIZE*2+1][2];
//     // double senseForward;
//     // double senseLeft;
//     // double senseRight;
// };

void initEnemy(struct Enemy *enemy) {
    enemy->positionDouble.x = CELL_WIDTH / 2 + (randomDouble(TMR2+1) - 0.5) * CELL_WIDTH / 1.5;
    enemy->positionDouble.y = CELL_HEIGHT / 2 + (randomDouble(TMR2+1) - 0.5) * CELL_HEIGHT / 1.5;
    enemy->positionInt.x = (int)enemy->positionDouble.x;
    enemy->positionInt.y = (int)enemy->positionDouble.y;
    enemy->angle = (double) randomDouble(TMR2+1) * 2 * PI;
    trailmap[enemy->positionInt.x][enemy->positionInt.y] = 1;
}

// double sense(struct enemy *enemy, double sensorAngleInput);

void updateEnemy(struct Enemy *enemy) {

    // Steering
    // double senseForward, senseLeft, senseRight;
    // senseForward = sense(0);
    // senseLeft = sense(SENSOR_ANGLE_OFFSET);
    // senseRight = sense(-SENSOR_ANGLE_OFFSET);

    // double randomSteerStrength = (double)rand() / RAND_MAX;
    // if (senseForward > senseLeft && senseForward > senseRight) {
    //     enemy->angle += 0;
    // } else if (senseRight > senseLeft) {
    //     enemy->angle -= randomSteerStrength * 1.5 * TURN_SPEED ;
    // } else if (senseLeft > senseRight) {
    //     enemy->angle += randomSteerStrength * 1.5 * TURN_SPEED;
    // } else {
    //     enemy->angle += (randomSteerStrength - 0.5) * TURN_SPEED;
    // }

    Point2D direction = {cos(enemy->angle), sin(enemy->angle)};
    Point2D newpos = {enemy->positionDouble.x + direction.x * MOVE_SPEED , enemy->positionDouble.y + direction.y * MOVE_SPEED};
    
    // Wall Checks
    if (newpos.x < 0 || newpos.y < 0) {
        newpos.x = max(0, newpos.x);
        newpos.y = max(0, newpos.y);
        enemy->angle = randomDouble(TMR2+1) * 2 * PI;
    }

    if (newpos.x >= CELL_WIDTH || newpos.y >= CELL_HEIGHT) {
        newpos.x = min(newpos.x, CELL_WIDTH - 1);
        newpos.y = min(newpos.y, CELL_HEIGHT - 1);
        enemy->angle = randomDouble(TMR2+1) * 2 * PI;
    }

    // Add new position and trail
    enemy->positionDouble = newpos;
    enemy->positionInt.x = (int) enemy->positionDouble.x;
    enemy->positionInt.y = (int) enemy->positionDouble.y;
    trailmap[enemy->positionInt.x][enemy->positionInt.y] = 1;
}

// double sense (enemy* enemy, double sensorAngleInput) {
//     double sensorAngle = enemy->angle + sensorAngleInput;
//     Point2D sensorDirection;
//     sensorDirection.x = cos(sensorAngle);
//     sensorDirection.y = sin(sensorAngle);

//     Point2D sensorCenterDouble;
//     sensorCenterDouble.x = enemy->positionDouble.x + sensorDirection.x * SENSOR_OFFSET_DST;
//     sensorCenterDouble.y = enemy->positionDouble.y + sensorDirection.y * SENSOR_OFFSET_DST;
//     Point sensorCenterInt;
//     sensorCenterInt.x = (int) sensorCenterDouble.x;
//     sensorCenterInt.y = (int) sensorCenterDouble.y;
//     double sum = 0;

//     for (int offsetX = -SENSOR_SIZE; offsetX <= SENSOR_SIZE; offsetX++) {
//         for (int offsetY = -SENSOR_SIZE; offsetY <= SENSOR_SIZE; offsetY++) {
//             int Xpos = sensorCenterInt.x + offsetX;
//             int Ypos = sensorCenterInt.y + offsetY;
            
//             if (Xpos >= 0 && Xpos < CELL_WIDTH && Ypos >= 0 && Ypos < CELL_HEIGHT) {
//                 sum += Panel.trailmap[Xpos][Ypos];
//             }
//         }
//     }

//     return sum;
// }

void drawEnemy(struct Enemy *enemy) {
    int xPos = enemy->positionInt.x;
    int yPos = enemy->positionInt.y;
    int i;
    for (i = 0; i < 512; i++)
    {
        toDisplay[(yPos / 8) * 128 + (xPos % 128)] |= (1 << (yPos % 8));
    }
    

    

}
