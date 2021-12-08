#include "Point.hpp"
/* Representing time (incremented per update) for scene 1 & 2 */
int timer = 0;
int timer2 = 0;
//first car and second car status (1 is moving 0 is not moving)
int carStatus = 1, carStatus1 = 0;
//clouds and sun status (1 is moving 0 is not moving)
int cloudsStatus = 1, sunStatus = 1;
//First car, second car, clouds and sun x & y position of screenspace
float carX = 0, carY = 0;
float carX1 = 1300, carY1 = 100;
float sunX = 0, sunY = 0;
float cloudX = 0, cloudY = 0;
//temporary movement & angle variable for scene 1 clock dots
float move, angle;
//x & y position of person & gift in scene 3
float tx = 0.0f, ty = 0.0f;
float giftTanslat = 0.0, giftMov = 0.00575;
float giftTanslat = 0.0, giftMov = 0.00575;
//forward move rate of person
float forwardIncrmt = 0.0015f;
//Backward move rate of person, maxTheta movTheta and incrementTheta of player locomotion system
float backwardIncrmt = 0.0013f, maxTheta = 35.0f, movTheta = 0.0f, incTheta = 1.5f;
//Is person is allowed to move forward
bool forwardMov = false;
//counter to handle events in Scene 3
int counter;
//Chopper position and increment amount in Scene 3
float Cx = 0.0f, Cincrmt = 0.03f;
int SCREEN_WIDTH = 640, SCREEN_HEIGHT = 480;
int BACKGROUND_SIZE = 10;
/* Center position of scene 1 clock */
Point clockOrigin = {1000, 750};
/* Radius of scene 1 clock */
int clockRadius = 400;

typedef struct
{
    int x, y;
    bool itouch, otouch;
    float angle, radius;
    Color color;
} Dot;
/* Dots appearing on the clock during scene 1 */
Dot dots[12] = {
    0, 0, true, false, 0, 1, 127, 0, 255,
    0, 0, false, true, 24, 200, 31, 0, 255,
    0, 0, true, false, 48, 1, 0, 63, 255,
    0, 0, false, true, 72, 200, 0, 159, 255,
    0, 0, true, false, 96, 1, 0, 255, 255,
    0, 0, false, true, 120, 200, 0, 255, 159,
    0, 0, true, false, 144, 1, 0, 255, 63,
    0, 0, false, true, 168, 200, 31, 255, 0,
    0, 0, true, false, 192, 1, 127, 255, 0,
    0, 0, false, true, 216, 200, 223, 255, 0,
    0, 0, true, false, 240, 1, 255, 191, 0,
    0, 0, false, true, 264, 200, 255, 95, 0};
//Current background R G B color
float curR = backgrounds[0].R, curG = backgrounds[0].G, curB = backgrounds[0].B;
/* Hour and minute current degree */
double hDegree = 0, mDegree = 0;
/* Temporary variable to store current background from the above array */
int curBackground = 0;
/* Radius of hour and minute hand of the clock */
int hourRadius = 200, minuteRadius = 250;
/* Dial radius of the clock */
float dRadius = 6.0f;
//If window for 3rd Scene has shown
bool shown = false;
#define drawOneLine(x1, y1, x2, y2) \
    glBegin(GL_LINES);              \
    glVertex3f((x1), (y1), (-5.0)); \
    glVertex3f((x2), (y2), (-5.0)); \
    glEnd();