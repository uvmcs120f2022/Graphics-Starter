#include "graphics.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

GLdouble width, height;
int wd;

void init() {
    width = 840;
    height = 600;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(1.0f, 1.0f, 0.5f, 1.0f); // Black and opaque
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
    
    glColor3f(0.8f, 0.2f, 0.5f);
    glBegin(GL_QUADS);

    glVertex2i(10 + 50, 50 + 50);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(10 + 50, 90 + 50);
    glColor3f(0.2f, 0.9f, 0.4f);
    glVertex2i(50 + 50, 90 + 50);
    glColor3f(1.0f, 0.1f, 0.6f);
    glVertex2i(50 + 50, 50 + 50);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(100, 150);
    glVertex2i(125, 100);
    glVertex2i(150, 150);
    glVertex2i(175, 100);
    glVertex2i(200, 150);
    glVertex2i(225, 100);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glVertex2i(100, 250);
    glVertex2i(125, 200);
    glVertex2i(150, 250);
    glVertex2i(175, 200);
    glVertex2i(200, 250);
    glVertex2i(225, 200);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    int maxVert = 24;
    glColor3f(0.6f, 0.1f, 0.242231f);
    glVertex2i(500, 500);
    for (int i = 0; i <= maxVert; ++i) {
        glVertex2f(500 + 50 * std::cos((float(i) * 6.283f) / maxVert), 500 + 50 * std::sin(i * 6.283f / maxVert));
    }

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
    glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Funyuns with Drawing!" /* title */ );
    
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
