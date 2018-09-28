//#ingure -clude <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

char estado[50];

void handle_key(unsigned char key, int mousex, int mousey)
{

    switch(key)
    {
    }
    glutPostRedisplay();
}

void desenhaTexto()
{
    char iniciar[50];

	glColor3d(1, 1, 1);

    sprintf(iniciar, "INICIAR");
    glPushMatrix();
	    glRasterPos2f(220, 270);
        for (char *i = iniciar; *i != 0; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *i);
	glPopMatrix();

    sprintf(iniciar, "00");
    glPushMatrix();
	    glRasterPos2f(130, 400);
        for (char *i = iniciar; *i != 0; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *i);
	glPopMatrix();

    sprintf(iniciar, "30");
    glPushMatrix();
	    glRasterPos2f(240, 400);
        for (char *i = iniciar; *i != 0; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *i);
	glPopMatrix();

    sprintf(iniciar, "60");
    glPushMatrix();
	    glRasterPos2f(350, 400);
        for (char *i = iniciar; *i != 0; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *i);
	glPopMatrix();

    glPushMatrix();
	    glRasterPos2f(180, 130);
        for (char *i = estado; *i != 0; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *i);
	glPopMatrix();

	glFlush();
}

void menu()
{
    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(100, 450);
        glVertex2f(180, 450);
        glVertex2f(180, 380);
        glVertex2f(100, 380);
    glEnd();   
    glBegin(GL_POLYGON);
        glVertex2f(210, 450);
        glVertex2f(290, 450);
        glVertex2f(290, 380);
        glVertex2f(210, 380);
    glEnd();   
    glBegin(GL_POLYGON);
        glVertex2f(320, 450);
        glVertex2f(400, 450);
        glVertex2f(400, 380);
        glVertex2f(320, 380);
    glEnd();   
    glBegin(GL_POLYGON);
        glVertex2f(100, 350);
        glVertex2f(400, 350);
        glVertex2f(400, 200);
        glVertex2f(100, 200);
    glEnd();   
    glBegin(GL_POLYGON);
        glVertex2f(100, 170);
        glVertex2f(400, 170);
        glVertex2f(400, 110);
        glVertex2f(100, 110);
    glEnd();   
    glFlush();
    desenhaTexto();
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    menu();
}

void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500.0, 0, 500.0);
    sprintf(estado, "Clique em iniciar");
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Trabalho 2");
    init ();
    glutKeyboardFunc(handle_key);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;   /* ISO C requires main to return int. */
}

