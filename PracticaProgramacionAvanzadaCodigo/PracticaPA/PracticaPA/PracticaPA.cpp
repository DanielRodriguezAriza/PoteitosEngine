#include "Game.h"
#include <iostream>
#include <string>
#include <GL/glut.h>
#include "Utility.h"
#include "Color.h"
#include "Solid.h"

Game game;

bool fullScreen = false;

float const renderDistance = 2000.0f;

int const WINDOW_WIDTH = 800;
int const WINDOW_HEIGHT = 600;
int const WINDOW_POSITION_X = 0;
int const WINDOW_POSITION_Y = 0;
char const TITLE[] = "Poteitos Engine Instance";

GLclampf const RED = 0.0f;
GLclampf const GREEN = 0.0f;
GLclampf const BLUE = 0.2f;
GLclampf const ALPHA = 1.0f;

void initGraphics()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    float ambientLight[] = { 0.2f ,0.2f ,0.2f ,1.f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(RED,GREEN,BLUE,ALPHA);
    game.Init();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    game.Render();

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)(width) / (GLfloat)(height);
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f,aspectRatio,1.0f,renderDistance);
    glMatrixMode(GL_MODELVIEW);
}

void idle()
{
    game.Update();
    glutPostRedisplay();
}

void keyPressed(unsigned char key, int x, int y)
{
    game.ProcessKeyPressed(key,x,y);
    glutPostRedisplay();
}

void KeyReleased(unsigned char key, int x, int y)
{
    game.ProcessKeyReleased(key,x,y);
    glutPostRedisplay();
}

void mouseMoved(int x, int y)
{
    game.ProcessMouseMovement(x,y);
    glutPostRedisplay();
}

void mouseClicked(int button, int state, int x, int y)
{
    game.ProcessMouseClick(button,state,x,y);
    glutPostRedisplay();
}

void specialKeyPressed(int key, int x, int y)
{
    game.ProcessSpecialKeyPressed(key, x, y);
    if (key == 11)
    {
        fullScreen = !fullScreen;
        if (fullScreen)
        {
            glutFullScreen();
        }
        else
        {
            glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
            glutPositionWindow(WINDOW_POSITION_X, WINDOW_POSITION_Y);
        }
    }
    glutPostRedisplay();
}

void specialKeyReleased(int key, int x, int y)
{
    game.ProcessSpecialKeyReleased(key, x, y);
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    Utility::print("Iniciando el programa...\n");
    //cambiar la página de caracteres a unicode UTF-8 para que la consola de windows pueda mostrar caracteres especiales, colores y tildes correctamente.
    system("chcp 65001>nul");

    Utility::print("Generando ventana...\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA |GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    glutInitWindowPosition(WINDOW_POSITION_X,WINDOW_POSITION_Y);
    glutCreateWindow(TITLE);

    Utility::print("Registrando funciones de tratamiento de eventos...\n");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(KeyReleased);
    glutMotionFunc(mouseMoved);
    glutMouseFunc(mouseClicked);
    glutIdleFunc(idle);
    glutSpecialFunc(specialKeyPressed);
    glutSpecialUpFunc(specialKeyReleased);

    Utility::print("Iniciando gráficos...\n");
    initGraphics();

    Utility::print("Iniciando bucle infinito\n");
    Utility::printSuccess("Bucle infinito iniciado!\n");
    glutMainLoop();
    return 0;
}

