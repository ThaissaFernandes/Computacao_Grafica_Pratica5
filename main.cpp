#include <GL/glut.h>


GLfloat x = 100.0f;
GLfloat y = 150.0f;
GLsizei d = 50;


// Incremento do movimento
GLfloat passox = 3.0f;
GLfloat passoy = 3.0f;


// Largura e altura da janela
GLfloat largura = 400;
GLfloat altura = 400;


void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_TRIANGLES);


        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2i(x, y);


        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2i(x + d, y + d);


        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(x + d + d, y);


    glEnd();


    glutSwapBuffers();
}


void Timer(int value)
{
    x += passox;
    y += passoy;


    // Olha colisao com as bordas laterais
    if (x <= 0 || x + d + d >= largura) {
        passox = -passox;
    }


    // Olha colisao com as bordas inferior e superior
    if (y <= 0 || y + d >= altura) {
        passoy = -passoy;
    }


    glutPostRedisplay();
    glutTimerFunc(16, Timer, 1);
}


void AlteraJanela(GLsizei w, GLsizei h)
{
    if (h == 0)
        h = 1;


    largura = w;
    altura = h;


    glViewport(0, 0, w, h);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    gluOrtho2D(0, largura, 0, altura);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Pratica 5 - Triangulo Policores");


    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraJanela);


    glutTimerFunc(33, Timer, 1);


    glutMainLoop();


    return 0;
}

