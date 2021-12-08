#include <iostream>
#include <cmath>
#include <string.h>
#include <GL/glut.h>
#include "Color.hpp"
#include "globalVariable.hpp"
// #include "Method.cpp"
using namespace std;
void print(float x, float y, float z, char *string);
void renderBitmapString(float x, float y, void *font, const char *string)
{
    // Render font on screen
    const char *c;
    glRasterPos2f(x, y);

    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
void resetPerspectiveProjection()
{
    //Reset to perspective projection for depth
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}
void drawClockCircle()
{
    glBegin(GL_POINTS);
    glColor3f(0.2, 0.2, 0.3);
    for (float theta = 0; theta <= 360; theta += 1 / (float)clockRadius)
    {
        glVertex2i(clockOrigin.x + (clockRadius * cos(theta)),
                   clockOrigin.y + (clockRadius * sin(theta)));
    }
}
void calc()
{
    //calculates movement for dots in scene 1
    for (int i = 0; i <= 11; i++)
    {
        dots[i].x = clockOrigin.x + dots[i].radius * cos(dots[i].angle);
        dots[i].y = clockOrigin.y + dots[i].radius * sin(dots[i].angle);

        if (dots[i].itouch == true)
            dots[i].radius += dRadius;
        else if (dots[i].otouch == true)
            dots[i].radius -= dRadius;

        if (dots[i].radius <= 0)
        {
            dots[i].itouch = true;
            dots[i].otouch = false;
        }
        else if (dots[i].radius >= 200)
        {
            dots[i].otouch = true;
            dots[i].itouch = false;
        }
    }
}
void sky()
{
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.5, 1.0);
    glVertex2i(0, 1500);
    glVertex2i(2000, 1500);
    glColor3f(0.7, 0.7, 1.0);
    glVertex2i(2000, 0);
    glVertex2i(0, 0);
    glEnd();
}
void moveSun()
{
    if (sunStatus == 1)
    {
        if (sunY >= 350)
            sunY = 350;
        else
            sunY += .5;
    }
    glPushMatrix();
    glTranslatef(sunX, sunY, 0);
    drawSun(1);
    glPopMatrix();
}
void hills()
{
    glColor3f(0.4, 0.4, 0.2);
    DrawCircle(200, 600, 500, 2000);
    glColor3f(0.4, 0.4, 0.2);
    DrawCircle(800, 600, 500, 2000);
    glColor3f(0.4, 0.4, 0.2);
    DrawCircle(1400, 600, 500, 2000);
    glColor3f(0.4, 0.4, 0.2);
    DrawCircle(2000, 600, 500, 2000);
}
void road()
{
    glBegin(GL_POLYGON);
    glColor3f(98, 131, 110);
    glVertex2i(0, 400);
    glVertex2i(2000, 400);
    glVertex2i(2000, 900);
    glVertex2i(0, 900);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(0, 450);
    glVertex2i(2000, 450);
    glVertex2i(2000, 850);
    glVertex2i(0, 850);
    glEnd();
}

void house()
{
    //Middle Ground
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.8, 0.0);
    glVertex2i(0, 0);
    glVertex2i(2000, 0);
    glVertex2i(2000, 400);
    glVertex2i(0, 400);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.2, 0.1);
    glVertex2i(100, 100);
    glVertex2i(350, 100);
    glVertex2i(350, 670);
    glVertex2i(100, 670);
    glEnd();

    //DOOR
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(200, 100);
    glVertex2i(250, 100);
    glVertex2i(250, 200);
    glVertex2i(200, 200);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(125, 200);
    glVertex2i(150, 200);
    glVertex2i(150, 240);
    glVertex2i(125, 240);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(125, 300);
    glVertex2i(150, 300);
    glVertex2i(150, 340);
    glVertex2i(125, 340);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(125, 400);
    glVertex2i(150, 400);
    glVertex2i(150, 440);
    glVertex2i(125, 440);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(125, 500);
    glVertex2i(150, 500);
    glVertex2i(150, 540);
    glVertex2i(125, 540);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(125, 600);
    glVertex2i(150, 600);
    glVertex2i(150, 640);
    glVertex2i(125, 640);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(300, 200);
    glVertex2i(325, 200);
    glVertex2i(325, 240);
    glVertex2i(300, 240);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(300, 300);
    glVertex2i(325, 300);
    glVertex2i(325, 340);
    glVertex2i(300, 340);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(300, 400);
    glVertex2i(325, 400);
    glVertex2i(325, 440);
    glVertex2i(300, 440);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(300, 500);
    glVertex2i(325, 500);
    glVertex2i(325, 540);
    glVertex2i(300, 540);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(300, 600);
    glVertex2i(325, 600);
    glVertex2i(325, 640);
    glVertex2i(300, 640);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.2, 0.1);
    glVertex2i(700, 100);
    glVertex2i(950, 100);
    glVertex2i(950, 670);
    glVertex2i(700, 670);
    glEnd();

    //Door
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(800, 100);
    glVertex2i(850, 100);
    glVertex2i(850, 200);
    glVertex2i(800, 200);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(725, 200);
    glVertex2i(750, 200);
    glVertex2i(750, 240);
    glVertex2i(725, 240);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(725, 300);
    glVertex2i(750, 300);
    glVertex2i(750, 340);
    glVertex2i(725, 340);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(725, 400);
    glVertex2i(750, 400);
    glVertex2i(750, 440);
    glVertex2i(725, 440);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(725, 500);
    glVertex2i(750, 500);
    glVertex2i(750, 540);
    glVertex2i(725, 540);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(725, 600);
    glVertex2i(750, 600);
    glVertex2i(750, 640);
    glVertex2i(725, 640);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(900, 200);
    glVertex2i(925, 200);
    glVertex2i(925, 240);
    glVertex2i(900, 240);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(900, 300);
    glVertex2i(925, 300);
    glVertex2i(925, 340);
    glVertex2i(900, 340);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(900, 400);
    glVertex2i(925, 400);
    glVertex2i(925, 440);
    glVertex2i(900, 440);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(900, 500);
    glVertex2i(925, 500);
    glVertex2i(925, 540);
    glVertex2i(900, 540);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(900, 600);
    glVertex2i(925, 600);
    glVertex2i(925, 640);
    glVertex2i(900, 640);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.2, 0.1);
    glVertex2i(1300, 100);
    glVertex2i(1550, 100);
    glVertex2i(1550, 670);
    glVertex2i(1300, 670);
    glEnd();

    //HOUSE DOOR
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(1400, 100);
    glVertex2i(1450, 100);
    glVertex2i(1450, 200);
    glVertex2i(1400, 200);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(1325, 200);
    glVertex2i(1350, 200);
    glVertex2i(1350, 240);
    glVertex2i(1325, 240);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(1325, 300);
    glVertex2i(1350, 300);
    glVertex2i(1350, 340);
    glVertex2i(1325, 340);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(1325, 400);
    glVertex2i(1350, 400);
    glVertex2i(1350, 440);
    glVertex2i(1325, 440);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(1325, 500);
    glVertex2i(1350, 500);
    glVertex2i(1350, 540);
    glVertex2i(1325, 540);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(1325, 600);
    glVertex2i(1350, 600);
    glVertex2i(1350, 640);
    glVertex2i(1325, 640);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(1500, 200);
    glVertex2i(1525, 200);
    glVertex2i(1525, 240);
    glVertex2i(1500, 240);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(1500, 300);
    glVertex2i(1525, 300);
    glVertex2i(1525, 340);
    glVertex2i(1500, 340);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(1500, 400);
    glVertex2i(1525, 400);
    glVertex2i(1525, 440);
    glVertex2i(1500, 440);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(1500, 500);
    glVertex2i(1525, 500);
    glVertex2i(1525, 540);
    glVertex2i(1500, 540);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.1);
    glVertex2i(1500, 600);
    glVertex2i(1525, 600);
    glVertex2i(1525, 640);
    glVertex2i(1500, 640);
    glEnd();

    /* TREES */
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.3, 0.0);
    glVertex2i(450, 100);
    glVertex2i(480, 100);
    glVertex2i(480, 300);
    glVertex2i(450, 300);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.2, 0.1);
    glVertex2i(380, 200);
    glVertex2i(560, 200);
    glVertex2i(460, 400);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.2, 0.1);
    glVertex2i(380, 250);
    glVertex2i(560, 250);
    glVertex2i(460, 450);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.2, 0.1);
    glVertex2i(380, 300);
    glVertex2i(560, 300);
    glVertex2i(460, 500);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.3, 0.0);
    glVertex2i(1070, 100);
    glVertex2i(1100, 100);
    glVertex2i(1100, 300);
    glVertex2i(1070, 300);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.2, 0.1);
    glVertex2i(1000, 200);
    glVertex2i(1180, 200);
    glVertex2i(1080, 400);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.2, 0.1);
    glVertex2i(1000, 250);
    glVertex2i(1180, 250);
    glVertex2i(1080, 450);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.2, 0.1);
    glVertex2i(1000, 300);
    glVertex2i(1180, 300);
    glVertex2i(1080, 500);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.3, 0.0);
    glVertex2i(1680, 100);
    glVertex2i(1710, 100);
    glVertex2i(1710, 300);
    glVertex2i(1680, 300);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.2, 0.1);
    glVertex2i(1610, 200);
    glVertex2i(1790, 200);
    glVertex2i(1690, 400);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.2, 0.1);
    glVertex2i(1610, 250);
    glVertex2i(1790, 250);
    glVertex2i(1690, 450);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.2, 0.1);
    glVertex2i(1610, 300);
    glVertex2i(1790, 300);
    glVertex2i(1690, 500);
    glEnd();

    /* GRASS */
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.6, 0.3);
    glVertex2i(50, 110);
    glVertex2i(45, 130);
    glVertex2i(25, 140);
    glVertex2i(45, 130);
    glVertex2i(35, 160);
    glVertex2i(45, 130);
    glVertex2i(50, 180);
    glColor3f(0.8, 0.8, 0.1);
    glVertex2i(55, 140);
    glVertex2i(75, 160);
    glVertex2i(65, 130);
    glVertex2i(75, 140);
    glVertex2i(65, 130);
    glVertex2i(60, 110);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.6, 0.3);
    glVertex2i(495, 110);
    glVertex2i(480, 130);
    glVertex2i(470, 140);
    glVertex2i(490, 130);
    glVertex2i(480, 160);
    glVertex2i(500, 130);
    glVertex2i(505, 180);
    glColor3f(0.8, 0.8, 0.1);
    glVertex2i(510, 140);
    glVertex2i(530, 160);
    glVertex2i(520, 130);
    glVertex2i(540, 140);
    glVertex2i(530, 130);
    glVertex2i(515, 110);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.6, 0.1);
    glVertex2i(635, 100);
    glVertex2i(620, 120);
    glVertex2i(610, 130);
    glVertex2i(630, 120);
    glVertex2i(620, 150);
    glVertex2i(640, 130);
    glVertex2i(645, 170);
    glColor3f(0.8, 0.8, 0.1);
    glVertex2i(650, 130);
    glVertex2i(670, 150);
    glVertex2i(660, 120);
    glVertex2i(680, 130);
    glVertex2i(670, 120);
    glVertex2i(655, 100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.6, 0.1);
    glVertex2i(935, 100);
    glVertex2i(920, 120);
    glVertex2i(910, 130);
    glVertex2i(930, 120);
    glVertex2i(920, 150);
    glVertex2i(940, 130);
    glVertex2i(945, 170);
    glColor3f(0.8, 0.8, 0.1);
    glVertex2i(950, 130);
    glVertex2i(970, 150);
    glVertex2i(960, 120);
    glVertex2i(980, 130);
    glVertex2i(970, 120);
    glVertex2i(955, 100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.6, 0.1);
    glVertex2i(1135, 100);
    glVertex2i(1120, 120);
    glVertex2i(1110, 130);
    glVertex2i(1130, 120);
    glVertex2i(1120, 150);
    glVertex2i(1140, 130);
    glVertex2i(1145, 170);
    glColor3f(0.8, 0.8, 0.1);
    glVertex2i(1150, 130);
    glVertex2i(1170, 150);
    glVertex2i(1160, 120);
    glVertex2i(1180, 130);
    glVertex2i(1170, 120);
    glVertex2i(1155, 100);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.6, 0.1);
    glVertex2i(1835, 100);
    glVertex2i(1820, 120);
    glVertex2i(1810, 130);
    glVertex2i(1830, 120);
    glVertex2i(1820, 150);
    glVertex2i(1840, 130);
    glVertex2i(1845, 170);
    glColor3f(0.8, 0.8, 0.1);
    glVertex2i(1850, 130);
    glVertex2i(1870, 150);
    glVertex2i(1860, 120);
    glVertex2i(1880, 130);
    glVertex2i(1870, 120);
    glVertex2i(1855, 100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.6, 0.1);
    glVertex2i(1935, 100);
    glVertex2i(1920, 120);
    glVertex2i(1910, 130);
    glVertex2i(1930, 120);
    glVertex2i(1920, 150);
    glVertex2i(1940, 130);
    glVertex2i(1945, 170);
    glColor3f(0.8, 0.8, 0.1);
    glVertex2i(1950, 130);
    glVertex2i(1970, 150);
    glVertex2i(1960, 120);
    glVertex2i(1980, 130);
    glVertex2i(1970, 120);
    glVertex2i(1955, 100);
    glEnd();

    /* Renders fire after some time */
    if (timer > 1600)
    {
        glBegin(GL_POLYGON);
        glColor3f(1.0, 0.2, 0.0);
        glVertex2i(1405, 830);
        glVertex2i(1390, 850);
        glVertex2i(1380, 860);
        glVertex2i(1400, 850);
        glVertex2i(1390, 880);
        glVertex2i(1410, 860);
        glVertex2i(1415, 900);
        glColor3f(0.8, 0.2, 0.1);
        glVertex2i(1420, 860);
        glVertex2i(1440, 880);
        glVertex2i(1430, 850);
        glVertex2i(1450, 860);
        glVertex2i(1440, 850);
        glVertex2i(1425, 830);
        glEnd();

        carStatus = 0;
    }
}
void car()
{
    if (carStatus == 1)
        carX += 1;
    if (carX > 2000)
        carX = -600;
    glPushMatrix();
    glTranslatef(carX, carY, 0);
    movecar(1);
    glPopMatrix();
}
void car1()
{
    if (carStatus1 == 1)
        carX1 += 0.5;
    if (carX1 > 2000)
        carX1 = -600;
    glPushMatrix();
    glTranslatef(carX1, carY1, 0);
    movecar1(1);
    glPopMatrix();
}
void movemegh()
{
    if (cloudsStatus == 1)
        cloudX += .5;
    if (cloudX > 2000)
        cloudX = -200;
    glPushMatrix();
    glTranslatef(cloudX, cloudY, 0);
    megh(1);
    glPopMatrix();
}
void display2()
{
    ++timer2;
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(1.0, 0.25, 0.0);
    glScalef(5.5, 1.0, 1.0);
    road2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.0f, 0.05f, 0.5f);
    glScalef(2.0f, 2.0f, 2.0f);
    front();
    Door();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.45f, 0.02f, 0.5f);
    giftBoxMov();
    giftBox();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6.8f, -1.77f, 0.0f);
    glScalef(0.7, 0.7, 1.0);
    drawStickman();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.0f, 0.05f, 0.5f);
    glScalef(2.0f, 2.0f, 2.0f);
    drawHouse();
    logo();
    glPopMatrix();

    //cloud
    glPushMatrix();
    cloudMov();
    think();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 0.5, 1.0);
    glTranslatef(-3.0, 3.0, 0.0);
    chopperMovement();
    chopper();
    ads();
    glPopMatrix();

    /* Draws that person has got 100% compensation */
    if (timer2 > 2000 && timer2 < 2500)
        think2();

    /* Draws final insurance ad */
    if (timer2 > 2500)
    {
        glColor3d(1.0, 0.0, 0.0);
        setOrthographicProjection();
        glPushMatrix();
        glLoadIdentity();
        const int font = (int)GLUT_BITMAP_TIMES_ROMAN_24;
        renderBitmapString(100, 200, (void *)font, "Insurance 4 U");
        if (timer2 > 2550)
        {
            glColor3d(0.0, 0.0, 1.0);
            renderBitmapString(130, 250, (void *)font, "The Best");
        }
        if (timer2 > 2600)
            renderBitmapString(130, 280, (void *)font, "The Cheapest");
        if (timer2 > 2650)
        {
            glColor3d(1.0, 0.0, 0.0);
            renderBitmapString(100, 330, (void *)font, "Call: 0123, 4678");
        }
        glPopMatrix();
        resetPerspectiveProjection();
        glutSwapBuffers();
    }

    roadMark();

    glFlush();
}

void handleResize(int w, int h)
{
    //Handle resize of GLUT window
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
void drawSun(int x)
{
    glColor3f(3.0, 1.0, 0.5);
    DrawCircle(800, 1000, 70, 1000);
}
void DrawCircle(float cx, float cy, float r, int num_segments)
{
    //Draws circle with maximum num_segments
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
void movecar(int x)
{
    /* WHEELS */
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(110, 790);
    glVertex2i(120, 790);
    glVertex2i(120, 800);
    glVertex2i(110, 800);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(180, 790);
    glVertex2i(190, 790);
    glVertex2i(190, 800);
    glVertex2i(180, 800);
    glEnd();

    /* CARS */
    glBegin(GL_QUADS);
    glColor3f(1.9, 0.0, 0.0);
    glVertex2i(100, 800);
    glVertex2i(200, 800);
    glVertex2i(200, 850);
    glVertex2i(100, 850);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.8, 0.5);
    glVertex2i(120, 850);
    glVertex2i(180, 850);
    glVertex2i(180, 890);
    glVertex2i(120, 890);
    glEnd();
}
void movecar1(int x)
{
    /* WHEELS */
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(110, 690);
    glVertex2i(120, 690);
    glVertex2i(120, 700);
    glVertex2i(110, 700);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(180, 690);
    glVertex2i(190, 690);
    glVertex2i(190, 700);
    glVertex2i(180, 700);
    glEnd();

    /* CARS */
    glBegin(GL_QUADS);
    glColor3f(1.9, 0.0, 0.0);
    glVertex2i(100, 700);
    glVertex2i(200, 700);
    glVertex2i(200, 750);
    glVertex2i(100, 750);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.8, 0.5);
    glVertex2i(120, 750);
    glVertex2i(180, 750);
    glVertex2i(180, 790);
    glVertex2i(120, 790);
    glEnd();
}
void megh(int x)
{
    glColor3f(1.0, 1.0, 1.0);
    DrawCircle(100, 1300, 60, 2000);
    DrawCircle(200, 1300, 80, 2000);
    DrawCircle(300, 1300, 55, 2000);
    DrawCircle(700, 1300, 60, 2000);
    DrawCircle(800, 1300, 80, 2000);
    DrawCircle(900, 1300, 55, 2000);
    DrawCircle(1100, 1300, 60, 2000);
    DrawCircle(1200, 1300, 80, 2000);
    DrawCircle(1300, 1300, 55, 2000);
    DrawCircle(1700, 1300, 60, 2000);
    DrawCircle(1800, 1300, 80, 2000);
    DrawCircle(1900, 1300, 55, 2000);
}
void road2()
{
    glColor3ub(0, 0, 0);
    glLineWidth(5.0);
    glBegin(GL_QUADS);
    glVertex3f(-1.5f, -1.8f, -5.0f);
    glVertex3f(-1.6f, -2.1f, -5.0f);
    glVertex3f(0.5f, -2.1f, -5.0f);
    glVertex3f(0.6f, -1.80f, -5.0f);
    glEnd();
}
void front()
{
    /* Front of the company */
    glColor3ub(153, 0, 76);
    glLineWidth(5.0);
    glBegin(GL_QUADS);
    glVertex3f(-0.7f, -1.5f, -5.0f);
    glVertex3f(0.1f, -1.5f, -5.0f);
    glVertex3f(0.1f, -0.5f, -5.0f);
    glVertex3f(-0.7f, -0.5f, -5.0f);
    glEnd();
}
void Door()
{
    glColor3ub(223, 255, 214);
    glLineWidth(5.0);
    glBegin(GL_QUADS);
    glVertex3f(-0.65f, -1.5f, -5.0f);
    glVertex3f(0.05f, -1.5f, -5.0f);
    glVertex3f(0.05f, -1.0f, -5.0f);
    glVertex3f(-0.65f, -1.0f, -5.0f);
    glEnd();
    glColor3f(0.80, 0.70, 0.60);
    glLineWidth(5.0);
    glBegin(GL_QUADS);
    glVertex3f(-0.65f, -1.5f, -5.0f);
    glVertex3f(-0.45f, -1.4f, -5.0f);
    glVertex3f(-0.45f, -1.1f, -5.0f);
    glVertex3f(-0.65f, -1.0f, -5.0f);
    glEnd();
    glColor3f(0.80, 0.70, 0.60);
    glLineWidth(5.0);
    glBegin(GL_QUADS);
    glVertex3f(0.05f, -1.5f, -5.0f);
    glVertex3f(-0.15f, -1.4f, -5.0f);
    glVertex3f(-0.15f, -1.1f, -5.0f);
    glVertex3f(0.05f, -1.0f, -5.0f);
    glEnd();
}
void giftBoxMov()
{
    if (counter < 16400)
    {
        glTranslatef(giftTanslat, 0.0, 0.0);
        counter++;
    }
    else
    {
        glTranslatef(giftTanslat, 0.0, 0.0);
        giftTanslat = giftTanslat - giftMov;
    }
}
void giftBox()
{
    //giftBox
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(0.15, -1.1, -5.0);
    glVertex3f(0.15, -1.2, -5.0);
    glVertex3f(0.25, -1.2, -5.0);
    glVertex3f(0.25, -1.1, -5.0);
    glEnd();

    glColor3f(1.0, 0.2, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(0.15, -1.1, -5.0);
    glVertex3f(0.2, -1.05, -5.0);
    glVertex3f(0.3, -1.05, -5.0);
    glVertex3f(0.25, -1.1, -5.0);
    glEnd();
    glColor3f(1.1, 0.1, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(0.25, -1.1, -5.0);
    glVertex3f(0.25, -1.2, -5.0);
    glVertex3f(0.3, -1.15, -5.0);
    glVertex3f(0.3, -1.05, -5.0);
    glEnd();
}
void drawStickman()
{
    //body
    glPushMatrix();
    bodyMovement();
    body();
    head();
    neck();
    glPopMatrix();
    //leftHand
    glPushMatrix();
    bodyMovement();
    leftHandMovement();
    leftHand();
    glPopMatrix();
    //leftArm
    glPushMatrix();
    bodyMovement();
    leftHandMovement();
    leftArmMovement();
    leftArm();
    glPopMatrix();

    //rightHand
    glPushMatrix();
    bodyMovement();
    rightHandMovement();
    rightHand();
    glPopMatrix();

    //rightarm
    glPushMatrix();
    bodyMovement();
    rightHandMovement();
    rightArmMovement();
    rightArm();
    glPopMatrix();

    //leftLeg
    glPushMatrix();
    bodyMovement();
    leftLegMovement();
    leftLeg();
    leftShin();
    glPopMatrix();

    //rightLeg
    glPushMatrix();
    bodyMovement();
    rightLegMovement();
    rightLeg();
    rightShine();
    glPopMatrix();

    angleTheta();
}
void drawHouse()
{
    glColor3f(0.1, 0.1, 1.0);
    glLineWidth(5.0);
    glBegin(GL_QUADS);
    glVertex3f(0.1f, -0.5f, -5.0f);
    glVertex3f(0.1f, -1.5, -5.0f);
    glVertex3f(1.5f, -1.5f, -5.0f);
    glVertex3f(1.5f, -0.5f, -5.0f);
    glEnd();

    //roof
    glLineWidth(5.0);
    glColor3ub(229.0, 229.0, 214.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.8f, -0.5f, -5.0f);
    glVertex3f(-0.3f, 0.5f, -5.0f);
    glVertex3f(0.10f, -0.5f, -5.0f);
    glEnd();
    //roof2
    glLineWidth(5.0);
    glColor3ub(98.0, 98.0, 8.0);
    glBegin(GL_QUADS);
    glVertex3f(-0.3f, 0.5f, -5.0f);
    glVertex3f(0.15f, -0.6f, -5.0f);
    glVertex3f(1.60f, -0.6f, -5.0f);
    glVertex3f(1.10f, 0.5f, -5.0f);
    glEnd();

    //window1
    glColor3f(0.80, 0.70, 0.60);
    glBegin(GL_QUADS);
    glVertex3f(0.35, -0.8, -5.0);
    glVertex3f(0.35, -1.1, -5.0);
    glVertex3f(0.75, -1.1, -5.0);
    glVertex3f(0.75, -0.8, -5.0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.35, -0.8, -5.0);
    glVertex3f(0.75, -1.1, -5.0);
    glEnd();
    //window2
    glColor3f(0.80, 0.70, 0.60);
    glBegin(GL_QUADS);
    glVertex3f(0.85, -0.8, -5.0);
    glVertex3f(0.85, -1.1, -5.0);
    glVertex3f(1.25, -1.1, -5.0);
    glVertex3f(1.25, -0.8, -5.0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.85, -0.8, -5.0);
    glVertex3f(1.25, -1.1, -5.0);
    glEnd();
}
void logo()
{
    /* Logo on top of company building */
    glColor3ub(10, 10, 9);
    char str[] = "INSURANCE";
    print(-0.60, -0.3, -5.0, str);
    glRasterPos3f(-0.75, 0.0, -5.0);
}
void cloudMov()
{
    if (counter < 5500)
    {
        glTranslatef(15, 25, -5.0);
    }
    else if (counter > 5000 && counter <= 7800)
    {

        glTranslatef(-2.9, -0.80, 0.0);
        glScalef(0.4, 0.4, 1.0);
    }

    else
    {
        glTranslatef(-2.9, -0.80, 0.0);
        glTranslatef(0.0, ty, 0.0);
        glScalef(0.4, 0.4, 1.0);
        ty = ty + 0.005;
    }
}
void think()
{
    /* Think bubble of person from scene 3 */
    glColor3f(1.1, 1.1, 1.1);
    cloud(0.4, -0.90f, 0.97f);
    cloud(0.4, -1.4f, 0.97f);
    cloud(0.4, -2.0f, 0.97f);
    cloud(0.4, -1.5f, 0.67f);
    cloud(0.2, -1.3, 0.1);
    cloud(0.1, -1.0, -0.1);
    cloud(0.05, -0.8, -0.3);
    glColor3ub(25, 10, 91);
    char str[] = "..good deals???..";
    print(-2.4, 0.95, -5.0, str);
    glRasterPos3f(-3.5, 1.5, -5.0);
}
void chopperMovement()
{
    /* Movement of the chopper from Scene 3 */
    glTranslatef(Cx, 0.0, 0.0);
    Cx = Cx + Cincrmt;
    counter++;
    //If chopper hit scree bring it again to the start
    if (Cx >= 15.5)
        Cx = -6;
}
void chopper()
{
    drawEllipse(1.0f, 0.5f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex3f(1.0f, 0.0f, -5.0f);
    glVertex3f(-0.30f, 0.0f, -5.0f);
    glEnd();
    //perpendicular line
    glBegin(GL_LINES);
    glVertex3f(-0.30f, 0.0f, -5.0f);
    glVertex3f(-0.30f, 0.5f, -5.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-1.0f, 0.1f, -5.0f);
    glVertex3f(-1.50f, 0.1f, -5.0f);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-1.0f, -0.1f, -5.0f);
    glVertex3f(-1.50f, -0.1f, -5.0f);
    glEnd();
    //wing stand
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(-0.1f, 0.5f, -5.0f);
    glVertex3f(-0.1f, 0.7f, -5.0f);
    glEnd();
    //wing
    glBegin(GL_LINES);
    glVertex3f(-0.6f, 0.7f, -5.0f);
    glVertex3f(0.4f, 0.7f, -5.0f);
    glEnd();

    //tail
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.5f, 0.1f, -5.0f);
    glVertex3f(-1.7f, 0.2f, -5.0f);
    glVertex3f(-1.7f, -0.2f, -5.0f);
    glVertex3f(-1.5f, -0.1f, -5.0f);
    glEnd();
    //banner-
    glBegin(GL_LINES);
    glVertex3f(-1.7f, 0.0f, -5.0f);
    glVertex3f(-2.1f, 0.0f, -5.0f);
    glEnd();
    //banner
    glColor3f(1.2, 1.2, 0.1);
    glLineWidth(2.0);

    glBegin(GL_LINE_LOOP);
    glVertex3f(-2.1f, 0.3f, -5.0f);
    glVertex3f(-4.8f, 0.3f, -5.0f);
    glVertex3f(-4.8f, -0.3f, -5.0f);
    glVertex3f(-2.1f, -0.3f, -5.0f);
    glEnd();
}

void ads()
{
    /* Claim now ad that chopper is showing */
    glColor3f(1.0, 0.0, 0.0);
    char str[] = "Claim Now!";
    print(-4.50, 0.0, -5.0, str);
}
void think2()
{
    /* Think bubble of person from scene 3 when he comes out from the insurance company */
    glColor3f(1.1, 1.1, 1.1);
    cloud(0.4, -0.90f, 0.97f);
    cloud(0.4, -1.4f, 0.97f);
    cloud(0.4, -2.0f, 0.97f);
    cloud(0.4, -1.5f, 0.67f);
    cloud(0.2, -1.3, 0.1);
    cloud(0.1, -1.0, -0.1);
    cloud(0.05, -0.8, -0.3);
    glColor3ub(25, 10, 91);
    char str[] = "I got 100% compasation!";
    print(-2.4, 0.95, -5.0, str);
    glRasterPos3f(-3.5, 1.5, -5.0);
}
void setOrthographicProjection()
{
    //Set orthographic projection of screen width & height size
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
    glScalef(1, -1, 1);
    glTranslatef(0, -SCREEN_HEIGHT, 0);
    glMatrixMode(GL_MODELVIEW);
}
void roadMark()
{

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(3.0);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(5, 0x1C47); /*  draw dash/dot/dash lines  */
    drawOneLine(-5.95, -1.70, 5.50, -1.70);
    glDisable(GL_LINE_STIPPLE);
}

/* Stick man figure */
void neck()
{
    glColor3f(1.1, 0.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.0f, 0.9f, -5.0f);
    glVertex3f(-1.0f, 0.8f, -5.0f);
    glEnd();
}

void body()
{
    glColor3f(0.1, 1.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.0f, 0.8f, -5.0f);
    glVertex3f(-1.0f, 0.5f, -5.0f);
    glEnd();
}

void leftHand()
{
    glColor3f(1.1, 1.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.0f, 0.8f, -5.0f);
    glVertex3f(-1.01f, 0.6f, -5.0f);
    glEnd();
}

void rightHand()
{
    glColor3f(1.1, 1.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.0f, 0.8f, -5.0f);
    glVertex3f(-0.99f, 0.6f, -5.0f);
    glEnd();
}

void leftArm()
{
    glColor3f(1.1, 0.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.01f, 0.6f, -5.0f);
    glVertex3f(-1.02f, 0.5f, -5.0f);
    glEnd();
}

void rightArm()
{
    glColor3f(1.1, 0.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-0.99f, 0.6f, -5.0f);
    glVertex3f(-0.98f, 0.5f, -5.0f);
    glEnd();
}

void leftLeg()
{
    glColor3f(1.1, 0.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.0f, 0.5f, -5.0f);
    glVertex3f(-1.01f, 0.4f, -5.0f);
    glEnd();
}
void rightLeg()
{
    glColor3f(1.1, 0.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.0f, 0.5f, -5.0f);
    glVertex3f(-0.99f, 0.4f, -5.0f);
    glEnd();
}

void leftShin()
{
    glColor3f(1.1, 0.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.0f, 0.4f, -5.0f);
    glVertex3f(-1.01f, 0.3f, -5.0f);
    glEnd();
}

void rightShine()
{
    glColor3f(1.1, 0.1, 0.0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1.0f, 0.4f, -5.0f);
    glVertex3f(-0.99f, 0.3f, -5.0f);
    glEnd();
}

void drawEllipse(float radX, float radY)
{
    int i;
    glColor3ub(24, 236, 66);
    glLineWidth(4.0);
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < 360; i++)
    {
        float rad = i * (3.14159 / 180);
        glVertex3f(cos(rad) * radX, sin(rad) * radY, -5.0f);
    }
    glEnd();
}
void bodyMovement()
{
    /* Body movement of the person based on counter from each update */

    //Increment forward
    if (counter <= 5500)
    {
        glTranslatef(tx, 0.0, 0.0);
        tx = tx + forwardIncrmt;
        counter++;
    }
    //Stop for a moment since person is thinking about good deals?
    else if (counter > 5500 && counter <= 9000)
    {
        glTranslatef(tx, 0.0, 0.0);
        counter++;
    }
    //Continue moving forward
    else if (counter > 9000 && counter <= 15000)
    {
        glTranslatef(tx, 0.0, 0.0);
        tx = tx + forwardIncrmt;
        counter++;
    }
    //Person is inside the building
    else if (counter > 15000 && counter <= 16500)
    {
        glTranslatef(tx, 0.0, 0.0);
        counter++;
    }
    //Person is coming out of the building so increment backward
    else
    {
        glTranslatef(tx, 0.0, 0.0);
        tx = tx - backwardIncrmt;
    }
}

void leftHandMovement()
{
    /* Hand movements of the person */
    if (counter <= 5500)
    {
        glTranslatef(-1.0, 0.8, -5.0);
        glRotatef(movTheta, 0.0, 0.0, 1.0);
        glTranslatef(1.0, -0.8, 5.0);
    }
    else if (counter > 5500 && counter <= 9000)
    {
        glTranslatef(-1.0, 0.8, -5.0);
        glRotatef(-15, 0.0, 0.0, 1.0);
        glTranslatef(1.0, -0.8, 5.0);
    }
    else if (counter > 9000 && counter <= 15000)
    {
        glTranslatef(-1.0, 0.8, -5.0);
        glRotatef(movTheta, 0.0, 0.0, 1.0);
        glTranslatef(1.0, -0.8, 5.0);
    }
    else if (counter > 15000)
    {
        glTranslatef(-1.0f, 0.8f, -5.0f);
        glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.0f, -0.8f, 5.0f);
    }
}
void rightHandMovement()
{
    if (counter <= 5500)
    {
        glTranslatef(-1.0f, 0.8f, -5.0f);
        glRotatef(-movTheta, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.0f, -0.8f, 5.0f);
    }
    else if (counter > 5500 && counter <= 9000)
    {
        glTranslatef(-1.0, 0.8, -5.0);
        glRotatef(120, 0.0, 0.0, 1.0);
        glTranslatef(1.0, -0.8, 5.0);
    }

    else if (counter > 9000 && counter <= 15000)
    {
        glTranslatef(-1.0f, 0.8f, -5.0f);
        glRotatef(-movTheta, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.0f, -0.8f, 5.0f);
    }
    else if (counter > 15000)
    {
        glTranslatef(-1.0f, 0.8f, -5.0f);
        glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.0f, -0.8f, 5.0f);
    }
}
void leftArmMovement()
{
    if (counter <= 5500)
    {
        glTranslatef(-1.01f, 0.6f, -5.0f);
        glRotatef(-movTheta, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.01f, -0.6f, 5.0f);
    }
    else if (counter > 5500 && counter <= 9000)
    {
        glTranslatef(-1.01f, 0.6f, -5.0f);
        glRotatef(15, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.01f, -0.6f, 5.0f);
    }
    else if (counter > 9000 && counter <= 15000)
    {
        glTranslatef(-1.01f, 0.6f, -5.0f);
        glRotatef(-movTheta, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.01f, -0.6f, 5.0f);
    }
    else if (counter > 15000)
    {
        glTranslatef(-1.01f, 0.6f, -5.0f);
        glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.01f, -0.6f, 5.0f);
    }
}
void rightArmMovement()
{
    if (counter <= 5500)
    {
        glTranslatef(-0.99f, 0.6f, -5.0f);
        glRotatef(-movTheta, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.99f, -0.6f, 5.0f);
    }
    else if (counter > 5500 && counter <= 7800)
    {

        glTranslatef(-0.99f, 0.6f, -5.0f);
        glRotatef(120, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.99f, -0.6f, 5.0f);
    }
    else if (counter > 7800 && counter <= 9000)
    {
        glTranslatef(-0.99f, 0.6f, -5.0f);
        glRotatef(180, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.99f, -0.6f, 5.0f);
    }

    else if (counter > 9000 && counter <= 15000)
    {
        glTranslatef(-0.99f, 0.6f, -5.0f);
        glRotatef(-movTheta, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.99f, -0.6f, 5.0f);
    }
    else if (counter > 15000)
    {
        glTranslatef(-0.99f, 0.6f, -5.0f);
        glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.99f, -0.6f, 5.0f);
    }
}
void leftLegMovement()
{
    if (counter <= 5500)
    {
        glTranslatef(-1.0, 0.5, -5.0);
        glRotatef(-movTheta, 0.0, 0.0, 1.0);
        glTranslatef(1.0, -0.5, 5.0);
    }
    else if (counter > 5500 && counter <= 9000)
    {
        glTranslatef(-1.0, 0.5, -5.0);
        glRotatef(15, 0.0, 0.0, 1.0);
        glTranslatef(1.0, -0.5, 5.0);
    }
    else
    {
        glTranslatef(-1.0, 0.5, -5.0);
        glRotatef(-movTheta, 0.0, 0.0, 1.0);
        glTranslatef(1.0, -0.5, 5.0);
    }
}

void rightLegMovement()
{
    if (counter <= 5500)
    {
        glTranslatef(-1.0f, 0.5f, -5.0f);
        glRotatef(movTheta, 0.0, 0.0, 1.0);
        glTranslatef(1.0f, -0.5f, 5.0f);
    }
    else if (counter > 5500 && counter <= 9000)
    {
        glTranslatef(-1.0, 0.5, -5.0);
        glRotatef(-15, 0.0, 0.0, 1.0);
        glTranslatef(1.0, -0.5, 5.0);
    }
    else
    {
        glTranslatef(-1.0f, 0.5f, -5.0f);
        glRotatef(movTheta, 0.0, 0.0, 1.0);
        glTranslatef(1.0f, -0.5f, 5.0f);
    }
}
void head()
{
    circle(0.08, -1.0f, 0.97f);
}
void angleTheta()
{
    if (forwardMov)
    {
        movTheta += incTheta;
        if (movTheta > maxTheta)
            forwardMov = false;
    }
    else if (!forwardMov)
    {
        movTheta -= incTheta;
        if (movTheta < -maxTheta)

            forwardMov = true;
    }
}
void print(float x, float y, float z, char *string)
{
    /* Print text in perspective projection */
    glRasterPos3f(x, y, z);
    int len = (int)strlen(string);
    for (int i = 0; i < len; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
}
void cloud(float rad, float xx, float yy)
{
    /* Scene 3 clouds */
    float thetha = 2 * 3.1415 / 20;
    float x, y;
    glColor3f(1.1, 1.1, 1.10);
    glLineWidth(1.0);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 20; i++)
    {
        x = rad * cos(i * thetha) + xx;
        y = rad * sin(i * thetha) + yy;
        float z = -5.0f;
        glVertex3f(x, y, z);
    }
    glEnd();
}
void circle(float rad, float xx, float yy)
{
    /* Draws the circle based on radians measurement */
    float thetha = 2 * 3.1415 / 20;
    float x, y;
    glColor3f(1.1, 1.1, 1.10);
    glLineWidth(1.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 20; i++)
    {
        x = rad * cos(i * thetha) + xx;
        y = rad * sin(i * thetha) + yy;
        float z = -5.0f;
        glVertex3f(x, y, z);
    }
    glEnd();
}
void Timer(int)
{
    timer++;

    glutTimerFunc(10, Timer, 0);
    glutPostRedisplay();
}
void init()
{
    // initialize scene
    glClearColor(backgrounds[0].R, backgrounds[0].G, backgrounds[0].B, 0.0);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 2000, 0.0, 1500.0);
}
void init2(void)
{
    //Initialize second window for scene 3
    glClearColor(0.505, 0.784, 0.847, 1.0);
    glShadeModel(GL_FLAT);
}
void display(void)
{
    /* SCENE 1 */
    if (timer < 1000)
    {
        /* Render the final text from scene 1 */
        if (timer > 800)
        {
            glColor3d(1.0, 0.0, 0.0);
            setOrthographicProjection();
            glPushMatrix();
            glLoadIdentity();
            const int font = ((long)GLUT_BITMAP_9_BY_15);
            renderBitmapString(170, 400, (void *)&font, "Menjalankan animasi");
            glPopMatrix();
            resetPerspectiveProjection();
            glutSwapBuffers();
        }
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINT);
        for (int i = 0; i <= 11; i++)
        {
            glColor3f(dots[i].color.R / 255, dots[i].color.G / 255, dots[i].color.B / 255);
            glVertex2f(dots[i].x, dots[i].y);
        }
        glEnd();
        /* Increment the current color to the nearest background color */
        if (curR > backgrounds[(curBackground + 1)].R)
        {
            curR -= 0.001f;
        }
        if (curR < backgrounds[(curBackground + 1)].R)
        {
            curR += 0.001f;
        }
        if (curG > backgrounds[(curBackground + 1)].G)
        {
            curG -= 0.001f;
        }
        if (curG < backgrounds[(curBackground + 1)].G)
        {
            curG += 0.001f;
        }
        if (curB > backgrounds[(curBackground + 1)].B)
        {
            curB -= 0.001f;
        }
        if (curB < backgrounds[(curBackground + 1)].B)
        {
            curB += 0.001f;
        }
        /* If current color matches from the background color list increment the current background */
        if (abs(curR - backgrounds[(curBackground + 1)].R) < 0.01f && abs(curG - backgrounds[(curBackground + 1)].G) < 0.01f && abs(curB - backgrounds[(curBackground + 1)].B) < 0.01f)
        {
            curBackground = (curBackground + 1) % BACKGROUND_SIZE;
        }
        glClearColor(curR, curG, curB, 0.0);
        /* Renders Clock */
        Point hour{clockOrigin.x + (hourRadius * cos(hDegree)), clockOrigin.y + (hourRadius * sin(hDegree))};
        Point minute{clockOrigin.x + (minuteRadius * cos(mDegree)), clockOrigin.y + (minuteRadius * sin(mDegree))};
        /* Draws the clock circle outline */
        drawClockCircle();
        /* Calculates movement for hour and minute hand with respect to origin */
        glColor3f(0.2, 0.5, 0.6);
        float x1 = clockOrigin.x, y1 = clockOrigin.y, step1 = 0;
        if (abs(hour.x - clockOrigin.x) > abs(hour.y - clockOrigin.y))
            step1 = abs(hour.x - clockOrigin.x);
        else
            step1 = abs(hour.y - clockOrigin.y);
        for (float i = 1; i <= step1; i++)
        {
            glVertex2i(x1, y1);
            x1 += (hour.x - clockOrigin.x) / step1;
            y1 += (hour.y - clockOrigin.y) / step1;
        }

        glColor3f(0.3, 0.4, 0.1);
        float x2 = clockOrigin.x, y2 = clockOrigin.y, step2 = 0;
        if (abs(minute.x - clockOrigin.x) > abs(minute.y - clockOrigin.y))
            step2 = abs(minute.x - clockOrigin.x);
        else
            step2 = abs(minute.y - clockOrigin.y);
        for (float i = 1; i <= step2; i++)
        {
            glVertex2i(x2, y2);
            x2 += (minute.x - clockOrigin.x) / step2;
            y2 += (minute.y - clockOrigin.y) / step2;
        }
        /* Renders dots */
        if (timer > 400 && timer <= 800)
        {
            calc();
            glClear(GL_COLOR_BUFFER_BIT);
            glBegin(GL_POINTS);
            for (int i = 0; i <= 11; i++)
            {
                glColor3f(dots[i].color.R / 255, dots[i].color.G / 255, dots[i].color.B / 255);
                glVertex2i(dots[i].x, dots[i].y);
            }
        }
        mDegree -= 0.001333, hDegree -= 0.000273;
    }
    /* ----END OF SCENE 1---- */
    /* ----SCENE 2---- */
    if (timer > 1000)
    {
        /* Render all individual elements */
        glClear(GL_COLOR_BUFFER_BIT);
        sky();
        moveSun();
        hills();
        road();
        car();
        car1();
        house();
        movemegh();
    }
    /* ----END OF SCENE 2----*/

    /* ----SCENE 3---- */
    if (timer > 1700 && !shown)
    {
        /* Show the new window for 3rd scene */
        shown = true;
        glutCreateWindow("OpenGL - Animation");
        glutDisplayFunc(display2);
        glutReshapeFunc(handleResize);
        init2();
    }
    /* ----END OF SCENE 3---- */

    glEnd();
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
}
int main(int argc, char **argv)
{
    /* code */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(200, 0);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Fire Head Animation");
    Timer(0);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
