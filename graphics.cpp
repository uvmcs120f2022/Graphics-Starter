#include "graphics.h"
#include <iostream>
#include <vector>
using namespace std;

GLdouble width, height;
int wd;

void init() {
    width = 700;
    height = 700;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.7f, 0.5f, 0.0f, 1.0f); // Black and opaque
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
    glColor3f(0.7,0.0,0.9);
    glBegin(GL_QUADS);
    glVertex2i(60, 100);
    glColor3f(0.0,1.0,0.0);
    glVertex2i(60, 140);
    glColor3f(0.0,0.0,1.0);
    glVertex2i(100, 100);
    glColor3f(0.2,0.3,0.4);
    glVertex2i(100, 140);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(0,0);
    glVertex2i(50,400);
    glVertex2i(50,100);
//    glVertex2i(60,10);
//    glVertex2i(600,400);
//    glVertex2i(500,100);
    glEnd();

    glColor3f(0.9,0.4,0.3);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2i(200,30);
    glVertex2i(180,90);
    glVertex2i(200,170);
    glVertex2i(230,210);
    glVertex2i(300,320);
    glEnd();

    glColor3f(0.3,0.0,0.9);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(400,60);
    glColor3f(0.0,0.3,0.6);
    glVertex2i(360,180);
    glColor3f(0.7,0.2,0.9);
    glVertex2i(400,340);
    glVertex2i(460,420);
    glColor3f(0.2,0.8,0.2);
    glVertex2i(600,640);
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
    wd = glutCreateWindow("Graphics are Fun, Wooo!" /* title */ );
    
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
