#include <GL/glut.h>

float angle = 0.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(3.0, 3.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(angle, 1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
    // ৩ডি ঘনকের রঙ ও জ্যামিতি
    glColor3f(1.0, 0.5, 0.0); // কমলা
    glVertex3f(-0.5,-0.5, 0.5); glVertex3f(0.5,-0.5, 0.5); glVertex3f(0.5,0.5, 0.5); glVertex3f(-0.5,0.5, 0.5);
    glColor3f(0.0, 1.0, 1.0); // সায়ান
    glVertex3f(-0.5,-0.5,-0.5); glVertex3f(-0.5,0.5,-0.5); glVertex3f(0.5,0.5,-0.5); glVertex3f(0.5,-0.5,-0.5);
    glEnd();

    glutSwapBuffers();
    angle += 0.8f;
}

void timer(int v) {
    glutPostRedisplay();
    glutTimerFunc(20, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Igglut 3D Engine v1.0");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}

