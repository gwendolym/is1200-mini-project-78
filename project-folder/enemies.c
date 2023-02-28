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

// struct Agent {
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

void initAgent(struct Agent *agent) {
    agent->positionDouble.x = CELL_WIDTH / 2 + ((double)randomInt(0, 10000) / 10000 - 0.5) * CELL_WIDTH / 1.5;
    agent->positionDouble.y = CELL_HEIGHT / 2 + ((double)randomInt(0, 10000) / 10000 - 0.5) * CELL_HEIGHT / 1.5;
    agent->positionInt.x = (int)agent->positionDouble.x;
    agent->positionInt.y = (int)agent->positionDouble.y;
    agent->angle = (double)randomInt(0, 1000) / 1000 * 2 * PI;
    agent->trailmap[agent->positionInt.x][agent->positionInt.y] = 1;
}

// double sense(struct Agent *agent, double sensorAngleInput);

void updateAgent(struct Agent *agent) {

    // Steering
    // double senseForward, senseLeft, senseRight;
    // senseForward = sense(0);
    // senseLeft = sense(SENSOR_ANGLE_OFFSET);
    // senseRight = sense(-SENSOR_ANGLE_OFFSET);

    // double randomSteerStrength = (double)rand() / RAND_MAX;
    // if (senseForward > senseLeft && senseForward > senseRight) {
    //     agent->angle += 0;
    // } else if (senseRight > senseLeft) {
    //     agent->angle -= randomSteerStrength * 1.5 * TURN_SPEED ;
    // } else if (senseLeft > senseRight) {
    //     agent->angle += randomSteerStrength * 1.5 * TURN_SPEED;
    // } else {
    //     agent->angle += (randomSteerStrength - 0.5) * TURN_SPEED;
    // }

    Point2D direction = {cos(agent->angle), sin(agent->angle)};
    Point2D newpos = {agent->positionDouble.x + direction.x * MOVE_SPEED , agent->positionDouble.y + direction.y * MOVE_SPEED};
    
    // Wall Checks
    // if (newpos.x < 0 || newpos.y < 0) {
    //     newpos.x = max(0, newpos.x);
    //     newpos.y = max(0, newpos.y);
    //     agent->angle = (double)rand() / RAND_MAX * 2 * M_PI;
    // }

    // if (newpos.x >= CELL_WIDTH || newpos.y >= CELL_HEIGHT) {
    //     newpos.x = min(newpos.x, CELL_WIDTH - 1);
    //     newpos.y = min(newpos.y, CELL_HEIGHT - 1);
    //     agent->angle = (double)rand() / RAND_MAX * 2 * M_PI;
    // }

    // Add new position and trail
    agent->positionDouble = newpos;
    agent->positionInt.x = (int) agent->positionDouble.x;
    agent->positionInt.y = (int) agent->positionDouble.y;
    agent->trailmap[agent->positionInt.x][agent->positionInt.y] = 1;
}

// double sense (Agent* agent, double sensorAngleInput) {
//     double sensorAngle = agent->angle + sensorAngleInput;
//     Point2D sensorDirection;
//     sensorDirection.x = cos(sensorAngle);
//     sensorDirection.y = sin(sensorAngle);

//     Point2D sensorCenterDouble;
//     sensorCenterDouble.x = agent->positionDouble.x + sensorDirection.x * SENSOR_OFFSET_DST;
//     sensorCenterDouble.y = agent->positionDouble.y + sensorDirection.y * SENSOR_OFFSET_DST;
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

void drawAgent(struct Agent *agent) {
    int posX = agent->positionInt.x;
    int posY = agent->positionInt.y;
    toDisplay[(posY / 8) * 128 + (posX % 128)] = (1 << (posY % 8));
}
