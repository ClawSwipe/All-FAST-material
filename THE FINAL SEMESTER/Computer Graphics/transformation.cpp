//===================================================================
// File: Lab07\triangle_rotate.cpp
// By  : Mr. KC Lee
// Date: 12 October 2002
// Task: Draws one triangle, and rotate it (about the z-axis) with 
// the LEFT or RIGHT arrow keys. Reset with the HOME key.
//===================================================================

#include <GL/glut.h>


float TORSO_RADIUS=0.1;
float HEIGHT=0.4;
float UPPER_ARM_HEIGHT=0.2;
float UPPER_ARM_WIDTH=0.07;

float LOWER_ARM_HEIGHT=0.2;
float LOWER_ARM_WIDTH=0.05;

float UPPER_LEG_HEIGHT=0.2;
float UPPER_LEG_WIDTH=0.08;

float LOWER_LEG_HEIGHT=0.2;
float LOWER_LEG_WIDTH=0.06;

float SHOLDER_WIDTH = 0.2;
float HIP_WIDTH = 0.2;

float HEADX=0.1;
float HEADY=0.9;
float RUAY;
float RLAY;
float RULY;
float RLLY;
float LUAX=-1.0 * SHOLDER_WIDTH / 2;
float RUAX=SHOLDER_WIDTH / 2;
float LUAY= RUAY=0.9;
float LLAY=RLAY=LOWER_ARM_HEIGHT;

float LULX=-1.0 * HIP_WIDTH / 2;
float RULX=HIP_WIDTH / 2;
float LULY=RULY=0;
float LLLY=RLLY=LOWER_LEG_HEIGHT;

float t0=0.0;
float t1=0.0;
float t2=0.0;
float t3=90.0;
float t4=0.0;
float t5=90.0;
float t6=0.0;
float t7=180.0;
float t8=0.0;
float t9=180.0;
float t10=0.0;

//Body
void torso()
{
  GLUquadricObj *p=gluNewQuadric();
  gluQuadricDrawStyle(p, GLU_LINE);
  glPushMatrix();
  glRotatef(15.0, 1.0, 0.0, 0.0);
  gluCylinder(p, TORSO_RADIUS, TORSO_RADIUS, HEIGHT, 10, 10);
  glPopMatrix();

}
void head()
{

  glPushMatrix();
  glRotatef(-90.0, 1.0, 0.0, 0.0);
  glutSolidSphere(0.04, 20, 10);
  glPopMatrix();
}
void upper_arm()
{

  glPushMatrix();
  glTranslatef(0.0, 0.5*UPPER_ARM_HEIGHT, 0.0);
  glScalef(UPPER_ARM_WIDTH, UPPER_ARM_HEIGHT, UPPER_ARM_WIDTH);
  glutSolidCube(1.0);
  glPopMatrix();
}

void lower_arm()
{

  glPushMatrix();
  glTranslatef(0.0, 0.5*UPPER_ARM_HEIGHT, 0.0);
  glScalef(LOWER_ARM_WIDTH, LOWER_ARM_HEIGHT, LOWER_ARM_WIDTH);
  glutSolidCube(1.0);
  glPopMatrix();
}

void upper_leg()
{

  glPushMatrix();
  glTranslatef(0.0, 0.5*LOWER_ARM_HEIGHT, 0.0);
  glScalef(UPPER_LEG_WIDTH, UPPER_LEG_HEIGHT, UPPER_LEG_WIDTH);
  glutSolidCube(1.0);
  glPopMatrix();
}

void lower_leg()
{

  glPushMatrix();
  glTranslatef(0.0, 0.5*LOWER_ARM_HEIGHT, 0.0);
  glScalef(LOWER_LEG_WIDTH, LOWER_LEG_HEIGHT, LOWER_LEG_WIDTH);
  glutSolidCube(1.0);
  glPopMatrix();
}
//------------------------------------------------------------------- 
void drawTriangle(void) 
{ 
  glBegin(GL_TRIANGLES); 
    glColor3f ( 1.0, 0.0, 0.0); 
    glVertex2f( 250.0, 100.0); 

    glColor3f ( 0.0, 1.0, 0.0); 
    glVertex2f( 400.0, 300.0); 

    glColor3f ( 0.0, 0.0, 1.0); 
    glVertex2f( 500.0, 100.0); 
  glEnd();
} 

//------------------------------------------------------------------- 
void myDisplay(void)
{
  
  glMatrixMode(GL_MODELVIEW);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glColor3f(0.5,0.5,0.5);
  torso();
  glPushMatrix();

  //HEAD
  glColor3f(0.0,1.0,1.0);
//  glTranslatef(0.0, HEADX, 0.0);
//  glRotatef(t1, 1.0, 0.0, 0.0);
//  glRotatef(t2, 0.0, 1.0, 0.0);
//  glTranslatef(0.0, HEADY, 0.0);
  head();

  //LEFT UPPER ARM
  glPopMatrix();
  glPushMatrix();
   glColor3f(1.0,0.0,0.0);
  glTranslatef(LUAX, LUAY, 0.0);
  glRotatef(t3, 1.0, 0.0, 0.0);
  upper_arm();

  //LEFT LOWER ARM
  glColor3f(0.0,1.0,0.0);
  glTranslatef(0.0, LLAY, 0.0);
  glRotatef(t4, 1.0, 0.0, 0.0);
  lower_arm();

  //RIGHT UPPER ARM
  glPopMatrix();
  glPushMatrix();
  glColor3f(0.0,0.0,1.0);
  glTranslatef(RUAX, RUAY, 0.0);
  glRotatef(t5, 1.0, 0.0, 0.0);
  upper_arm();

  //RIGHT UPPER ARM
  glColor3f(0.0,1.0,1.0);
  glTranslatef(0.0, RLAY, 0.0);
  glRotatef(t6, 1.0, 0.0, 0.0);
  lower_arm();

  //LEFT UPPER LEG
  glPopMatrix();
  glPushMatrix();
  glColor3f(1.0,0.0,1.0);
  glTranslatef(LULX, LULY, 0.0);
  glRotatef(t7, 1.0, 0.0, 0.0);
  upper_leg();

  //LEFT LOWER LEG
  glColor3f(1.0,1.0,0.0);
  glTranslatef(0.0, LLLY, 0.0);
  glRotatef(t8, 1.0, 0.0, 0.0);
  lower_leg();

  //RIGHT UPPER LEG
  glPopMatrix();
  glPushMatrix();
  glColor4f(0.5,0.0,0.0,0.3);
  glTranslatef(RULX, RULY, 0.0);
  glRotatef(t9, 1.0, 0.0, 0.0);
  upper_leg();

  //RIGHT LOWER LEG
  glColor3f(0.5,0.5,0.5);
  glTranslatef(0.0, RLLY, 0.0);
  glRotatef(t10, 1.0, 0.0, 0.0);
  lower_leg();

  glPopMatrix();
//  glPushMatrix();
// 	
// 	glTranslatef(-300, -150.0, 0.0);	
//  	glScalef(1.5,1.0,1.0);
//  	glRotatef(15.0, 0.0, 0.0, 1.0);
//  	glTranslatef(1.0*300, 1.0*150, 0.0);
//  
//   drawTriangle();
//   glPopMatrix();
//   
//	glPushMatrix();
// 
//  glScalef(1.5,1.0,1.0);
//  glRotatef(15.0, 0.0, 0.0, 1.0);
//  glTranslatef(-200.0, 100.0, 0.0);
//   drawTriangle();
//   glPopMatrix();
//   
  
  glFlush();
 // glutSwapBuffers();
}


//-------------------------------------------------------------------
void myInit(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0); // set the background to black
  glColor3f(1.0f, 1.0f, 1.0f);      // set the drawing color to white
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 0.0, 0.0, 0.0);
}

//-------------------------------------------------------------------
int main( int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB ); 
  glutInitWindowSize(640,500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("One Triangle");
  
  glutDisplayFunc(myDisplay);
  myInit();
  glutMainLoop();
}
