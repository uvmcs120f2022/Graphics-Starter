#include "graphics.h"
#include <iostream>
#include <vector>
using namespace std;

GLdouble width, height;
int wd;

void init() {
    width = 500;
    height = 500;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.5f, 0.6f, 0.8f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you're on a Mac running Catalina)
    
    // Do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE
    
    /*
     * Draw here
     */

    // Set the color to draw
// Note: you can change this at any time during the drawing process
    glColor3f(0.5, 0.0, 0.6);//range of values is 0-1
    glBegin(GL_QUADS);
// glVertex2i takes a 2-D (x, y) coordinate
    glVertex2i(60, 0);
    glColor3f(0.8, 0.8, 0.3);
    glVertex2i(60, 40);
    glColor3f(0.6, 0.2, 0.5);
    glVertex2i(100, 40);
    glColor3f(0.1, 0.8, 0.5);
    glVertex2i(100, 0);
    glEnd();


//    glBegin(GL_TRIANGLES);
//    glColor3f(0.8, 0.8, 0.3);
//    glVertex2i(100, 100);
//    glColor3f(0.6, 0.2, 0.5);
//    glVertex2i(100, 200);
//    glColor3f(0.1, 0.8, 0.5);
//    glVertex2i(200, 100);
//    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.8, 0.3);
    glVertex2i(600, 800);
    glColor3f(0.6, 0.2, 0.5);
    glVertex2i(1000, 2000);
    glColor3f(0.1, 0.8, 0.5);
    glVertex2i(800, 100);

    glColor3f(0.8, 0.8, 0.3);
    glVertex2i(100, 100);
    glColor3f(0.6, 0.2, 0.5);
    glVertex2i(100, 200);
    glColor3f(0.1, 0.8, 0.5);
    glVertex2i(200, 100);

    glColor3f(0.8, 0.8, 0.3);
    glVertex2i(200, 100);
    glColor3f(0.6, 0.2, 0.5);
    glVertex2i(500, 200);
    glColor3f(0.1, 0.8, 0.5);
    glVertex2i(700, 100);
    glEnd();




    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.8, 0.8, 0.3);
    glVertex2i(200, 80);
    glColor3f(0.6, 0.2, 0.5);
    glVertex2i(500, 80);
    glColor3f(0.1, 0.8, 0.5);
    glVertex2i(900, 400);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.8, 0.8, 0.3);
    glVertex2i(200, 50);
    glColor3f(0.6, 0.2, 0.5);
    glVertex2i(500, 50);
    glColor3f(0.1, 0.8, 0.5);
    glVertex2i(900, 400);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.8, 0.8, 0.3);
    glVertex2i(20, 200);
    glColor3f(0.6, 0.2, 0.5);
    glVertex2i(100, 300);
    glColor3f(0.1, 0.8, 0.5);
    glVertex2i(150, 260);
    glColor3f(0.6, 0.9, 0.3);
    glVertex2i(120, 270);
    glColor3f(0.9, 0.4, 0.1);
    glVertex2i(110, 265);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.8, 0.8, 0.3);
    glVertex2i(400, 300);
    glColor3f(0.6, 0.2, 0.5);
    glVertex2i(400, 350);
    glColor3f(0.1, 0.8, 0.5);
    glVertex2i(405, 340);
    glColor3f(0.6, 0.9, 0.3);
    glVertex2i(410, 350);
    glColor3f(0.9, 0.4, 0.1);
    glVertex2i(415, 360);
    glColor3f(0.8, 0.8, 0.3);
    glVertex2i(410, 370);
    glColor3f(0.6, 0.2, 0.5);
    glVertex2i(415, 380);
    glColor3f(0.1, 0.8, 0.5);
    glVertex2i(410, 390);
    glColor3f(0.6, 0.9, 0.3);
    glVertex2i(405, 400);
    glColor3f(0.9, 0.4, 0.1);
    glVertex2i(400, 410);
    glEnd();





    
    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }
    
    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            
            break;
        case GLUT_KEY_LEFT:
            
            break;
        case GLUT_KEY_RIGHT:
            
            break;
        case GLUT_KEY_UP:
            
            break;
    }
    
    glutPostRedisplay();
}

void cursor(int x, int y) {
    
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    
    glutPostRedisplay();
}

void timer(int dummy) {
    
    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    
    init();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(200, 100); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Fun with Drawing with Caroline!" /* title */ );
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    
    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // handles timer
    glutTimerFunc(0, timer, 0);
    
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
