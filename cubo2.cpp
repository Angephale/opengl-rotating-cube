#include <GL/glut.h>

float angulo = 0.0f;

void Face1() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.25f, -0.25f, 0.25f);
    glVertex3f(0.25f, -0.25f, 0.25f);
    glVertex3f(0.25f, 0.25f, 0.25f);
    glVertex3f(-0.25f, 0.25f, 0.25f);
    glEnd();
}

void Face2() {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.25f, -0.25f, -0.25f);
    glVertex3f(-0.25f, 0.25f, -0.25f);
    glVertex3f(0.25f, 0.25f, -0.25f);
    glVertex3f(0.25f, -0.25f, -0.25f);
    glEnd();
}

void Face3() {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-0.25f, 0.25f, -0.25f);
    glVertex3f(-0.25f, 0.25f, 0.25f);
    glVertex3f(0.25f, 0.25f, 0.25f);
    glVertex3f(0.25f, 0.25f, -0.25f);
    glEnd();
}

void Face4() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-0.25f, -0.25f, -0.25f);
    glVertex3f(0.25f, -0.25f, -0.25f);
    glVertex3f(0.25f, -0.25f, 0.25f);
    glVertex3f(-0.25f, -0.25f, 0.25f);
    glEnd();
}

void Face5() {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(0.25f, -0.25f, -0.25f);
    glVertex3f(0.25f, 0.25f, -0.25f);
    glVertex3f(0.25f, 0.25f, 0.25f);
    glVertex3f(0.25f, -0.25f, 0.25f);
    glEnd();
}

void Face6() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-0.25f, -0.25f, -0.25f);
    glVertex3f(-0.25f, -0.25f, 0.25f);
    glVertex3f(-0.25f, 0.25f, 0.25f);
    glVertex3f(-0.25f, 0.25f, -0.25f);
    glEnd();
}

void Desenha() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -2.0f);
    glRotatef(angulo, 1.0f, 1.0f, 0.0f);
    Face1();
    Face2();
    Face3();
    Face4();
    Face5();
    Face6();
    glutSwapBuffers();
}

void Atualiza(int value) {
    angulo += 2.0f;
    if (angulo > 360) {
        angulo -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(16, Atualiza, 0);
}

void Inicializa() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cubo Rotacionando");
    Inicializa();
    glutDisplayFunc(Desenha);
    glutTimerFunc(16, Atualiza, 0);
    glutMainLoop();
    return 0;
}
