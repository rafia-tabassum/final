#include <iostream>
#include <stdlib.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
using namespace std;

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	gluOrtho2D(0,1600,0,800);

	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_COLOR_MATERIAL);   //lets us use the glcolor3f.
//	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

//	glEnable(GL_LIGHT1); //Enable lighting
//	glEnable(GL_NORMALIZE); //Automatically normalize normals

//	glShadeModel(GL_SMOOTH); //Enable smooth shading
}

//Called when the window is resized
//void handleResize(int w, int h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
//}

void update(int value) {
	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 15 milliseconds
	glutTimerFunc(15, update, 0);// msecs, function, value
}

double bus_move =  -1.0;
double bus2_move = -1.2;
double bus3_move = -1.9;
double car_move = -1.0;
double car1_move = -1.6;
double frog_movex=0.01;
double frog_movey=0.0;
int coun =0;




void specialKeys(int key, int x, int y) {
    switch (key) {
      case GLUT_KEY_UP:
          frog_movey+=0.10;// frog jumping distance
          break;
      case GLUT_KEY_DOWN:
          frog_movey-=0.10;

          break;
           case GLUT_KEY_RIGHT:
          frog_movex+=0.05;
          break;
      case GLUT_KEY_LEFT:
          frog_movex-=0.05;

          break;

    }
}



void circle(float x, float y, double r )//for cloud1
{
    float x1,y1;
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/25;
		float x1 = x+((r-.07) * cos(A) );
		float y1 = y+((r) * sin(A) );
		glVertex2f(x1,y1);
	}
	glEnd();
}

void drawcircle(float x, float y, double r )//for cloud2
{
    float x1,y1;
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/25;
		float x1 = x+((r-.09) * cos(A) );
		float y1 = y+((r) * sin(A) );
		glVertex2f(x1,y1);
	}
	glEnd();
}

void drawCircle(float x, float y, double r )
{
    float x1,y1;
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/25;
		float x1 = x+((r-.03) * cos(A) );
		float y1 = y+((r) * sin(A) );
		glVertex2f(x1,y1);
	}
	glEnd();
}

void Building1()
{
     glColor3f(0.38f,0.19f,0.0f);
    glBegin(GL_POLYGON);    //roof
    glVertex2f(0.90,0.36);
    glVertex2f(0.89,0.44);
    glVertex2f(0.70,0.44);
    glVertex2f(0.69,0.36);
    glEnd();

    glColor3f(0.72f,0.91f,0.73f);
    glBegin(GL_QUADS);      // Window 1
    glVertex2f(0.87,0.25);
    glVertex2f(0.87,0.15);
    glVertex2f(0.81,0.15);
    glVertex2f(0.81,0.25);
    glEnd();

    glColor3f(0.72f,0.91f,0.73f);
    glBegin(GL_QUADS);      // Window 2
    glVertex2f(0.78,0.25);
    glVertex2f(0.78,0.15);
    glVertex2f(0.72,0.15);
    glVertex2f(0.72,0.25);
    glEnd();

    glColor3f(0.72f,0.91f,0.73f);
    glBegin(GL_QUADS);      // Window 3
    glVertex2f(0.85,0.40);
    glVertex2f(0.85,0.30);
    glVertex2f(0.74,0.30);
    glVertex2f(0.74,0.40);
    glEnd();

    glColor3f(.19,0.61,0.22);
    glBegin(GL_QUADS);
    glVertex2f(0.89,0.10);
    glVertex2f(0.89,0.45);
    glVertex2f(0.70,0.45);
    glVertex2f(0.70,0.10);
    glEnd();
}

void Building2()
{
    glColor3f(0.38f,0.19f,0.0f);
    glBegin(GL_POLYGON);    //roof
    glVertex2f(0.76,0.27);
    glVertex2f(0.75,0.33);
    glVertex2f(0.55,0.33);
    glVertex2f(0.54,0.27);
    glEnd();

    glColor3f(0.38f,0.19f,0.0f);
    glBegin(GL_POLYGON);    //roof2
    glVertex2f(0.77,0.67);
    glVertex2f(0.76,0.73);
    glVertex2f(0.54,0.73);
    glVertex2f(0.53,0.67);
    glEnd();

    glColor3f(0.72f,0.91f,0.73f);
    glBegin(GL_QUADS);      // Window 2
    glVertex2f(0.88,0.25);
    glVertex2f(0.88,0.15);
    glVertex2f(0.66,0.15);
    glVertex2f(0.66,0.25);
    glEnd();

    glColor3f(0.72f,0.91f,0.73f);
    glBegin(GL_QUADS);      // Window 3
    glVertex2f(0.63,0.25);
    glVertex2f(0.63,0.15);
    glVertex2f(0.58,0.15);
    glVertex2f(0.58,0.25);
    glEnd();


    glColor3f(0.72f,0.91f,0.73f);
    glBegin(GL_QUADS);      // Window 4
    glVertex2f(0.72,0.65);
    glVertex2f(0.72,0.55);
    glVertex2f(0.58,0.55);
    glVertex2f(0.58,0.65);
    glEnd();


    glColor3f(0.72f,0.91f,0.73f);
    glBegin(GL_QUADS);      // Window 4
    glVertex2f(0.72,0.50);
    glVertex2f(0.72,0.40);
    glVertex2f(0.58,0.40);
    glVertex2f(0.58,0.50);
    glEnd();

    glColor3f(0.25,0.50,0.50);
    glBegin(GL_QUADS);
    glVertex2f(0.75,0.10);
    glVertex2f(0.75,0.67);
    glVertex2f(0.55,0.67);
    glVertex2f(0.55,0.10);
    glEnd();
}

void Building3()
{
    glColor3f(0.28f,0.14f,0.14f);
    glBegin(GL_POLYGON);    //roof
    glVertex2f(0.57,0.49);
    glVertex2f(0.56,0.59);
    glVertex2f(0.28,0.59);
    glVertex2f(0.27,0.49);
    glEnd();


    glBegin(GL_POLYGON);// window 6
    glColor3f(1.0f,1.0f,0.61f);
    glVertex2f(0.47,.30);
    glVertex2f(0.47,0.09);
    glVertex2f(0.38,0.09);
    glVertex2f(0.38,0.30);
    glEnd();

     glBegin(GL_POLYGON); // Window 7
    glVertex2f(0.52,0.45);
    glVertex2f(0.52,0.35);
    glVertex2f(0.44,0.35);
    glVertex2f(0.44,0.45);
    glEnd();

     glBegin(GL_POLYGON); // Window 8
     glVertex2f(0.40,0.45);
    glVertex2f(0.40,0.35);
    glVertex2f(0.32,0.35);
    glVertex2f(0.32,0.45);
    glEnd();

     glColor3f(1.0,0.36,0.05);
     glBegin(GL_QUADS);
     glVertex2f(0.54,0.50);
    glVertex2f(0.54,0.09);
    glVertex2f(0.30,0.09);
    glVertex2f(0.30,0.50);
    glEnd();
}

void Building4()
{
    glColor3f(0.38f,0.19f,0.0f);
    glBegin(GL_POLYGON);    //roof
    glVertex2f(-0.36,-0.13);
    glVertex2f(-0.35,-0.07);
    glVertex2f(-0.20,-0.07);
    glVertex2f(-0.20,-0.13);
 glEnd();

 glColor3f(0.,0.65,0.42);
     glBegin(GL_QUADS);
    glVertex2f(-0.35,-0.40);
    glVertex2f(-0.35,-0.13);
    glVertex2f(-0.20,-0.13);
    glVertex2f(-0.20,-0.40);
 glEnd();
}

void Building5()
{
    glColor3f(0.38f,0.19f,0.0f);
    glBegin(GL_POLYGON);    //roof
    glVertex2f(0.30,0.80);
    glVertex2f(0.33,0.70);
    glVertex2f(.02,0.70);
    glVertex2f(.05,0.80);
    glEnd();

    glColor3f(0.0f,0.18f,0.350f);
    glBegin(GL_POLYGON); // window 1
     glVertex2f(0.19,0.72);
    glVertex2f(0.19,0.28);
    glVertex2f(0.16,0.28);
    glVertex2f(0.16,0.72);
    glEnd();

     glBegin(GL_POLYGON); // Door 1
    glVertex2f(0.20,0.10);
    glVertex2f(0.20,0.25);
    glVertex2f(0.15,0.25);
    glVertex2f(0.15,0.10);
    glEnd();


    glBegin(GL_POLYGON); // Window 7
    glVertex2f(0.21,0.27);
    glVertex2f(0.21,0.17);
    glVertex2f(0.27,0.17);
    glVertex2f(0.27,0.27);
    glEnd();

    glBegin(GL_POLYGON); // window 8
    glVertex2f(0.08,0.27);
    glVertex2f(0.08,0.17);
    glVertex2f(0.14,0.17);
    glVertex2f(0.14,0.27);
    glEnd();

    glBegin(GL_POLYGON); // Window 9
    glVertex2f(0.21,0.42);
    glVertex2f(0.21,0.32);
    glVertex2f(0.27,0.32);
    glVertex2f(0.27,0.42);
    glEnd();

    glBegin(GL_POLYGON); // window 10
    glVertex2f(0.08,0.42);
    glVertex2f(0.08,0.32);
    glVertex2f(0.14,0.32);
    glVertex2f(0.14,0.42);
    glEnd();

    glBegin(GL_POLYGON); // Window 11
    glVertex2f(0.21,0.57);
    glVertex2f(0.21,0.47);
    glVertex2f(0.27,0.47);
    glVertex2f(0.27,0.57);
    glEnd();

    glBegin(GL_POLYGON); // window 12
    glVertex2f(0.08,0.57);
    glVertex2f(0.08,0.47);
    glVertex2f(0.14,0.47);
    glVertex2f(0.14,0.57);
    glEnd();

    glBegin(GL_POLYGON); // Window 13
    glVertex2f(0.21,0.72);
    glVertex2f(0.21,0.62);
    glVertex2f(0.27,0.62);
    glVertex2f(0.27,0.72);
    glEnd();

     glBegin(GL_POLYGON); // Window 14
     glVertex2f(0.08,0.72);
    glVertex2f(0.08,0.62);
    glVertex2f(0.14,0.62);
    glVertex2f(0.14,0.72);
    glEnd();

    glColor3f(0.35,0.31,0.92);
     glBegin(GL_POLYGON);
     glVertex2f(0.05,0.10);
    glVertex2f(0.05,0.75);
    glVertex2f(0.30,0.75);
    glVertex2f(0.30,0.10);
    glEnd();
}

void Building7()
{
    glColor3f(0.87f,0.28f,0.0f);
    glBegin(GL_POLYGON);    //roof
    glVertex2f(-.25,0.50);
    glVertex2f(-.20,0.64);
    glVertex2f(-.05,0.64);
    glVertex2f(-.001,0.50);
    glEnd();

    glColor3f(1.0f,1.0f,0.70f);
    glBegin(GL_POLYGON); // 1st floor window 1
    glVertex2f(-.165,.16);
    glVertex2f(-.165,.22);
    glVertex2f(-.22,.22);
    glVertex2f(-.22,.16);
    glEnd();

     glBegin(GL_POLYGON); // Door 1
    glVertex2f(-0.15,.10);
    glVertex2f(-0.15,.23);
    glVertex2f(-0.09,.23);
    glVertex2f(-0.09,.10);
    glEnd();

     glBegin(GL_POLYGON); // 1st floor Window 2
     glVertex2f(-.022,.16);
    glVertex2f(-.022,.22);
    glVertex2f(-.078,.22);
    glVertex2f(-.078,.16);
    glEnd();

    glColor3f(1.0f,1.0f,0.70f);
    glBegin(GL_POLYGON); // 2nd floor window 1
    glVertex2f(-.15,.25);
    glVertex2f(-.15,.33);
    glVertex2f(-.22,.33);
    glVertex2f(-.22,.25);
    glEnd();

     glBegin(GL_POLYGON); // 2nd floor Window 2
     glVertex2f(-.022,.25);
    glVertex2f(-.022,.33);
    glVertex2f(-.09,.33);
    glVertex2f(-.09,.25);
    glEnd();

    glColor3f(1.0f,1.0f,0.70f);
    glBegin(GL_POLYGON); // 3rd floor window 1
    glVertex2f(-.15,.36);
    glVertex2f(-.15,.44);
    glVertex2f(-.22,.44);
    glVertex2f(-.22,.36);
    glEnd();

     glBegin(GL_POLYGON); // 3rd floor Window 2
     glVertex2f(-.022,.36);
    glVertex2f(-.022,.44);
    glVertex2f(-.09,.44);
    glVertex2f(-.09,.36);
    glEnd();

    glBegin(GL_POLYGON); // Door 1
    glVertex2f(-0.13,.25);
    glVertex2f(-0.13,.45);
    glVertex2f(-0.11,.45);
    glVertex2f(-0.11,.25);
    glEnd();

     glColor3f(0.50f,0.0f,0.0f);
     glBegin(GL_POLYGON);  // building body
     glVertex3f (-.24,.10, 0.0);
     glVertex3f (-.24,0.50, 0.0);
     glVertex3f (-.01,0.50, 0.0);
     glVertex3f (-.01,.10, 0.0);
    glEnd();
}

void Building8()
{
     glColor3f(0.38f,0.19f,0.0f);
    glBegin(GL_POLYGON);    //roof
    glVertex2f(-.52,0.64);
    glVertex2f(-.51,0.74);
    glVertex2f(-.25,0.74);
    glVertex2f(-.24,0.64);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);      // Window 1
    glVertex2f(-.42,.15);
    glVertex2f(-.42,.30);
    glVertex2f(-.34,.30);
    glVertex2f(-.34,.15);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);      // Window 2
    glVertex2f(-.42,.35);
    glVertex2f(-.42,.50);
    glVertex2f(-.34,.50);
    glVertex2f(-.34,.35);
    glEnd();


    glColor3f(0.25,0.50,0.50); //body
    glBegin(GL_POLYGON);
    glVertex2f(-.48,.10);
    glVertex2f(-.48,.70);
    glVertex2f(-.28,.70);
    glVertex2f(-.28,.10);
 glEnd();
}

void Building9()
{

    glColor3f(0.0f,0.31f,0.31f);
    glBegin(GL_QUADS);      // Window 1
    glVertex2f(-.80,.15);
    glVertex2f(-.80,.25);
    glVertex2f(-.74,.25);
    glVertex2f(-.74,.15);
    glEnd();

    glColor3f(0.0f,0.31f,0.31f);
    glBegin(GL_QUADS);      // Window 2
    glVertex2f(-.72,.15);
    glVertex2f(-.72,.25);
    glVertex2f(-.66,.25);
    glVertex2f(-.66,.15);
    glEnd();

    glBegin(GL_POLYGON); // window 3
     glVertex2f(-.80,.30);
    glVertex2f(-.80,.40);
    glVertex2f(-.74,.40);
    glVertex2f(-.74,.30);
    glEnd();

    glBegin(GL_POLYGON); // Window 4
     glVertex2f(-.72,.30);
    glVertex2f(-.72,.40);
    glVertex2f(-.66,.40);
    glVertex2f(-.66,.30);
    glEnd();


    glColor3f(1.0,0.65,0.42);//body
    glBegin(GL_POLYGON);
     glVertex2f(-.82,.10);
    glVertex2f(-.82,.45);
    glVertex2f(-.64,.45);
    glVertex2f(-.64,.10);
    glEnd();
}


void Building10()
{
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);      // Window 1
    glVertex2f(-.62,.15);
    glVertex2f(-.62,.25);
    glVertex2f(-.57,.25);
    glVertex2f(-.57,.15);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);      // Window 2
    glVertex2f(-.53,.15);
    glVertex2f(-.53,.25);
    glVertex2f(-.48,.25);
    glVertex2f(-.48,.15);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);      // Window 3
    glVertex2f(-.62,.30);
    glVertex2f(-.62,.40);
    glVertex2f(-.57,.40);
    glVertex2f(-.57,.30);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);      // Window 4
    glVertex2f(-.53,.30);
    glVertex2f(-.53,.40);
    glVertex2f(-.48,.40);
    glVertex2f(-.48,.30);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);      // Window 5
    glVertex2f(-.62,.45);
    glVertex2f(-.62,.55);
    glVertex2f(-.57,.55);
    glVertex2f(-.57,.45);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);      // Window 6
    glVertex2f(-.53,.45);
    glVertex2f(-.53,.55);
    glVertex2f(-.48,.55);
    glVertex2f(-.48,.45);
    glEnd();


    glColor3f(0.0,0.0,0.25);
    glBegin(GL_POLYGON);//body
    glVertex2f(-.64,.10);
    glVertex2f(-.64,.60);
    glVertex2f(-.46,.60);
    glVertex2f(-.46,.10);
 glEnd();
}


void Grass()
{
    glColor3f(0.0,0.43,0.0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0,.01);
    glVertex2f(-1.0,.05);
    glVertex2f(1.0,.05);
    glVertex2f(1.0,0.01);
 glEnd();
}

void Cloud1()
{
   glColor3f(0.50,0.50,0.50);
   circle(-0.85,0.77,0.15);
   circle(-0.79,0.70,0.15);
   circle(-0.70,0.70,0.15);
   circle(-0.75,0.77,0.15);
}

void Cloud2()
{
   glColor3f(0.80,0.80,0.80);
   drawcircle(0.35,0.77,0.15);
   circle(0.45,0.70,0.15);
   drawcircle(0.55,0.75,0.15);
   circle(0.45,0.80,0.15);
}

void Sun()
{
    glColor3f(1.0, 0.50, 0.0);
	circle(0.25,0.85,0.15);
}

void Sky()
{
    glColor3f(0.73, 0.73, 1);
	glBegin(GL_QUADS);
    glVertex2f(-1.0,.10);
    glVertex2f(-1.0,1.0);
    glVertex2f(1.0,1.0);
    glVertex2f(1.0,0.10);
 glEnd();
}

void Bus()
{
 glColor3f(0.98,0.83,0.84);
    glBegin(GL_POLYGON); // bus window 1
    glVertex2f(-0.35,-.74);
    glVertex2f(-0.35,-.63);
    glVertex2f(-0.30,-.63);
    glVertex2f(-0.30,-.74);
glEnd();

    glBegin(GL_POLYGON);// bus window 2
    glVertex2f(-0.29,-.74);
    glVertex2f(-0.29,-.63);
    glVertex2f(-0.24,-.63);
    glVertex2f(-0.24,-.74);
glEnd();

    glBegin(GL_POLYGON);// bus window 3
    glVertex2f(-0.23,-.74);
    glVertex2f(-0.23,-.63);
    glVertex2f(-0.18,-.63);
    glVertex2f(-0.18,-.74);
glEnd();

    glBegin(GL_POLYGON);// bus window 4
    glVertex2f(-0.17,-.74);
    glVertex2f(-0.17,-.63);
    glVertex2f(-0.12,-.63);
    glVertex2f(-0.12,-.74);
glEnd();

    glBegin(GL_POLYGON);// bus window 5
    glVertex2f(-0.09,-.74);
    glVertex2f(-0.09,-.63);
    glVertex2f(-0.07,-.63);
    glVertex2f(-0.02,-.74);
glEnd();

    glColor3f(0.11, 0.11, 0.11);    // bus wheel
    drawcircle(-0.29,-0.84,0.05);
    drawcircle(-0.09,-0.84,0.05);


 glColor3f(1.0, 0.50, 0.0);// bus body
    glBegin(GL_POLYGON);
    glVertex2f(-0.37,-.85);
    glVertex2f(-0.37,-.60);
    glVertex2f(-0.07,-.60);
    glVertex2f(0.0,-.75);
    glVertex2f(0.0,-.85);
glEnd();

}


void Bus2()
{
 glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON); // bus window 1
    glVertex2f(-.17,-.42);
    glVertex2f(-.17,-.35);
    glVertex2f(-.22,-.35);
    glVertex2f(-.22,-.42);
glEnd();

    glBegin(GL_POLYGON);// bus window 2
    glVertex2f(-.16,-.42);
    glVertex2f(-.16,-.35);
    glVertex2f(-.11,-.35);
    glVertex2f(-.11,-.42);
glEnd();

    glBegin(GL_POLYGON);// bus window 3
    glVertex2f(-.10,-.42);
    glVertex2f(-.10,-.35);
    glVertex2f(-.05,-.35);
    glVertex2f(-.05,-.42);
glEnd();

    glColor3f(0.11, 0.11, 0.11);    // bus wheel
    drawcircle(-.18,-.50,0.05);
    drawcircle(-.07,-.50,0.05);

 glColor3f(0.95, 0.0, 0.0);// bus body
    glBegin(GL_POLYGON);
    glVertex2f(-.24,-.52);
    glVertex2f(-.24,-.30);
    glVertex2f(0.0,-.30);
    glVertex2f(0.0,-.52);
glEnd();
}

void Bus3()
{
 glColor3f(0.0,0.80,0.90);
    glBegin(GL_POLYGON); // bus window 1
    glVertex2f(-.23,-.75);
    glVertex2f(-.23,-.64);
    glVertex2f(-.18,-.64);
    glVertex2f(-.18,-.75);
glEnd();

    glBegin(GL_POLYGON);// bus window 2
    glVertex2f(-.17,-.75);
    glVertex2f(-.17,-.64);
    glVertex2f(-.12,-.64);
    glVertex2f(-.12,-.75);
glEnd();

    glBegin(GL_POLYGON);// bus window 3
    glVertex2f(-.11,-.75);
    glVertex2f(-.11,-.64);
    glVertex2f(-.07,-.64);
    glVertex2f(-.04,-.75);
glEnd();

    glColor3f(0.11, 0.11, 0.11);    // bus wheel
    drawcircle(-.19,-0.836,0.05);
    drawcircle(-.08,-0.836,0.05);

 glColor3f(0.68, 0.0, 0.68);// bus body
    glBegin(GL_POLYGON);
    glVertex2f(-.25,-.85);
    glVertex2f(-.25,-.60);
    glVertex2f(-.05,-.60);//slope
    glVertex2f(0.0,-.78);
    glVertex2f(0.0,-.85);
glEnd();
}

void Car()
{
     glBegin(GL_POLYGON);// car window 1
    glColor3f(0.98,0.83,0.84);
    glVertex2f(0.01,-.05);
    glVertex2f(0.014,-.00);
    glVertex2f(0.04,-.00);
    glVertex2f(0.04,-.05);
 glEnd();

    glBegin(GL_POLYGON);// car window 2
    glVertex2f(0.05,-.05);
    glVertex2f(0.05,-.00);
    glVertex2f(0.086,-.00);
    glVertex2f(0.11,-.05);
 glEnd();

	glColor3f(0.11, 0.11, 0.11);  //// car wheel
	drawcircle(0.04,-0.14,0.06);
    drawcircle(0.11,-0.14,0.06);

    glBegin(GL_POLYGON);
    glColor3f(1.0,.30,1.0); // car body
    glVertex2f(-0.0,-.12);
    glVertex2f(-0.0,-.05);
    glVertex2f(0.15,-.05);
    glVertex2f(0.15,-.12);
    glVertex2f(0.09,.01);
    glVertex2f(0.01,.01);
    glVertex2f(-0.0,-.10);


    glEnd();
}
////////////////////////////////////// Car1
   void Car1()
{
    glBegin(GL_POLYGON);// car window 1
    glColor3f(0.98,0.83,0.84);;
    glVertex2f(0.01,-.05);
    glVertex2f(0.014,-.00);
    glVertex2f(0.04,-.00);
    glVertex2f(0.04,-.05);
 glEnd();

    glBegin(GL_POLYGON);// car window 2
    glVertex2f(0.05,-.05);
    glVertex2f(0.05,-.00);
    glVertex2f(0.086,-.00);
    glVertex2f(0.11,-.05);
 glEnd();

	glColor3f(0.11, 0.11, 0.11);  //// car wheel
	drawcircle(0.04,-0.14,0.06);
    drawcircle(0.11,-0.14,0.06);

 glBegin(GL_POLYGON);
    glColor3f(0.0,.10,0.90); // car body
    glVertex2f(-0.0,-.12);
    glVertex2f(-0.0,-.05);
    glVertex2f(0.16,-.05);
    glVertex2f(0.16,-.12);
    glVertex2f(0.10,.01);
    glVertex2f(0.01,.01);
    glVertex2f(-0.0,-.10);

    glEnd();
}




void Footpath()
{
 glLineWidth(2);//border
    glColor3f(0.35f,0.35f,0.35f);
    glBegin(GL_LINES);
    glVertex2f(-1.0,.02);
   glVertex2f(1.0,.02);
glEnd();

    glColor3f(0.5,0.5,0.52);
    glBegin(GL_QUADS);
    glVertex2f(-1.0,.02);
    glVertex2f(-1.0,0.40);
    glVertex2f(1.0,0.40);
    glVertex2f(1.0,0.02);
glEnd();
}

void Footpath1()
{
 glLineWidth(2);//border
    glColor3f(0.35f,0.35f,0.35f);
    glBegin(GL_LINES);
    glVertex2f(-1.0,-.99);
   glVertex2f(1.0,-.99);
glEnd();

    glColor3f(0.5,0.5,0.52);
    glBegin(GL_QUADS);
    glVertex2f(-1.0,-.99);
    glVertex2f(-1.0,-.89);
    glVertex2f(1.0,-.89);
    glVertex2f(1.0,-.99);
glEnd();
}

void frog(){


    glColor3f(0.0,1.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.02,-.97);
    glVertex2f(-0.02,-.92);
    glVertex2f(0.02,-.92);
    glVertex2f(0.02,-.97);
    glVertex2f(-0.01,-.97);
    glVertex2f(0.01,-.97);
    glVertex2f(0.008,-.90);
    glVertex2f(-0.008,-.90);
    glEnd();

}

 void Road_line()
 {
    glLineWidth(6);
    glColor3f(1.000, 0.843, 0.000);
    glBegin(GL_LINES);
    glVertex2f(-1.0,-.60);
    glVertex2f(1.0,-.60);
glEnd();
 }

 void Road_line1()
 {
    glLineWidth(6);
    glColor3f(1.000, 0.843, 0.000);
    glBegin(GL_LINES);
    glVertex2f(-1.0,-.25);
    glVertex2f(1.0,-.25);
glEnd();
 }


 void Road()
 {
    glColor3f(0.21f,0.21f,0.21f);
   glBegin(GL_QUADS);
   glVertex2f(-1.0,-1.0);
   glVertex2f(-1.0,.10);
   glVertex2f(1.0,.10);
   glVertex2f(1.0,-1.0);
glEnd();
 }


void Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
	glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);

    Building1();
    Building3();
    Building5();
    Building7();   //resturent

    Grass();
    Building2();
    Building8();
    Building9();
    Building10();
   // frog();

/////////cloud 1


    Cloud1();
    glPopMatrix();

    Cloud2();
    glPopMatrix();

///////////////////////////////////// Frog move
    glPushMatrix();
    glTranslatef(frog_movex,frog_movey, 0.0);
    frog();
    glPopMatrix();



/////////////////////////////////////////////// moving Bus
if((float)bus_move == (float)frog_movex && ((float)frog_movey == 0.1f  || (float)frog_movey == 0.2f || (float)frog_movey == 0.3f)){
            cout<<"Game Over Your Score is "<<coun<<endl;
            exit(0);
        }
    glPushMatrix();

    //cout<<frog_movey<<endl;
	glTranslatef(bus_move, 0.0f, 0.0f);
    Bus();
    glPopMatrix();




     bus_move +=0.01;

        if(bus_move > 1.8)
        {
            bus_move =  -1.0;
        }


/////////////////////////////////////////////// moving blue BUs2
    glPushMatrix();
	glTranslatef(bus2_move, 0.0f, 0.0f);
    Bus2();
    glPopMatrix();



    bus2_move += .01;
    if(bus2_move > 1.8)
    {
        bus2_move =  -1.2;
    }
 if((float)bus2_move == (float)frog_movex && ((float)frog_movey == 0.4f  || (float)frog_movey == 0.5f || (float)frog_movey == 0.6f)){
            cout<<"Game Over Your Score is "<<coun<<endl;
            exit(0);
        }

//////////////////////////////////////////BUS3
glPushMatrix();
	glTranslatef(bus3_move, 0.0f, 0.0f);
    Bus3();
    glPopMatrix();


    bus3_move += .01;
    if(bus3_move > 1.8)
    {
        bus3_move =  -1.0;

    }

    if((float)bus3_move == (float)frog_movex && ((float)frog_movey == 0.1f  || (float)frog_movey == 0.2f || (float)frog_movey == 0.3f)){
            cout<<"Game Over Your Score is "<<coun<<endl;
            exit(0);
        }





 //////////////////////////////moving car
    glPushMatrix();
    glTranslatef(car_move, 0.0f, 0.0f);
    Car();
    glPopMatrix();



    car_move += .01;
    if(car_move > 1.8)
    {
        car_move =  -1.0;

    }


  /*if((float)car_move == (float)frog_movex && ((float)frog_movey == 0.8f  || (float)frog_movey == 0.9f)){
            cout<<"Game Over Your Score is "<<endl;
            exit(0);
        }*/
    if((float)car_move == (float)frog_movex && ((float)frog_movey ==0.8f  || (float)frog_movey == 0.9f) ){
            cout<<"Game Over Your Score is "<<coun<<endl;
            exit(0);
        }

            if((float)frog_movey == 1.0f){
               cout<<"Score"<<coun<<endl;
                        coun++;
                        frog_movey=0.0;
               }


//////////////////////////////////////////////moving car1

glPushMatrix();
    glTranslatef(car1_move, 0.0f, 0.0f);
    Car1();
    glPopMatrix();



    car1_move += .01;
    if(car1_move > 1.8)
    {
        car1_move =  -1.0;

    }


    if((float)car1_move == (float)frog_movex && ((float)frog_movey == 0.8f  || (float)frog_movey == 0.9f) ){
            cout<<"Game Over Your Score is "<<coun<<endl;
            exit(0);
        }

            if((float)frog_movey == 1.0f){
               cout<<"Score"<<coun<<endl;
                        coun++;
                        frog_movey=0.0;
               }

    Sky();
    Footpath();
    Footpath1();
    Road_line();
    Road_line1();
    Road();
    //glFlush();
	glutSwapBuffers();
}



int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1600,900);

	glutCreateWindow("frog game");
	initRendering();

	glutDisplayFunc(Display);
//	glutReshapeFunc(handleResize);

	glutSpecialFunc(specialKeys);
//	glutKeyboardFunc(keyboard);
//	glutMouseFunc(mouse);

	glutTimerFunc(15, update, 0); //Add a timer
	glutMainLoop();
	return 0;
}
