#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>


void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}
 
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glLoadIdentity();
    glBegin(GL_TRIANGLES); // es muy importante el orden en que indicamos los vertices, siempre se tienen que indicar en sentido antihorario
      glVertex3f(-1,-1,0);
      glVertex3f(1,-1,0);
      glVertex3f(0,1,0);
    glEnd();
    glFlush();
}
 
void init()
{
    glClearColor(0,0,0,0);
}
 
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Hello OpenGL");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}