#include<windows.h>
#include<gl/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);
void mouseMotion(int, int);
void ukuran(int, int);

int is_depth;

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

float xmov = 0.0f;
float ymov = 0.0f;
float zmov = 0.0f;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 700);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("GAP UKSW");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void tampil(void)
{
    if (is_depth) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glLineWidth(3.0);
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glTranslatef(xmov, ymov, zmov);
    glPushMatrix();

//depan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-120.0, -30.0, 0.0);
    glVertex3f(-120.0, 60.0, 0.0);
    glVertex3f(120.0, 60.0, 0.0);
    glVertex3f(120.0, -30.0, 0.0);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-120.0, -30.0, -190.0);
    glVertex3f(-120.0, 60.0, -190.0);
    glVertex3f(120.0, 60.0, -190.0);
    glVertex3f(120.0, -30.0, -190.0);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(120.0, -30.0, -190.0);
    glVertex3f(120.0, 60.0, -190.0);
    glVertex3f(120.0, 60.0, 0.0);
    glVertex3f(120.0, -30.0, 0.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-120.0, -30.0, -190.0);
    glVertex3f(-120.0, 60.0, -190.0);
    glVertex3f(-120.0, 60.0, 0.0);
    glVertex3f(-120.0, -30.0, 0.0);
    glEnd();

    //alas tanah
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-140.0, -30.0, -200.0);
    glVertex3f(-140.0, -30.0, 80.0);
    glVertex3f(140.0, -30.0, 80.0);
    glVertex3f(140.0, -30.0, -200.0);
    glEnd();

    //tiang kiri
    glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(45.0, -30.0, 75.0); //kanan
    glVertex3f(45.0, 85.0, 75.0);//kiri
    glVertex3f(45.0, 85.0, 110.0);//kiri
    glVertex3f(45.0, -30.0, 110.0);//kanan
    glEnd();
    //tiang Kanan
    glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-45.0, -30.0, 75.0); //kanan
    glVertex3f(-45.0, 90.0, 75.0);//kiri
    glVertex3f(-45.0, 90.0, 110.0);//kiri
    glVertex3f(-45.0, -30.0, 110.0);//kanan
    glEnd();
     //atap teras
              glBegin(GL_QUADS);
    glColor3ub(133,0,0);
    glVertex3f(120.2, 75.0, 5.0); //kanan
    glVertex3f(120.2, 60.0, 5.0);//kiri
    glVertex3f(45.0, 60.0, 5.0);//kiri
    glVertex3f(45.0, 75.0, 5.0);//kanan
    glEnd();
         glBegin(GL_QUADS);
    glColor3ub(133,0,0);
    glVertex3f(-120.2, 75.0, 5.0); //kanan
    glVertex3f(-120.2, 60.0, 5.0);//kiri
    glVertex3f(-45.0, 60.0, 5.0);//kiri
    glVertex3f(-45.0, 75.0, 5.0);//kanan
    glEnd();
          glBegin(GL_QUADS);
    glColor3ub(133,0,0);
    glVertex3f(120.2, 75.0, 5.0); //kanan
    glVertex3f(120.2, 60.0, 5.0);//kiri
    glVertex3f(120.2, 60.0, 0.0);//kiri
    glVertex3f(120.2, 75.0, 0.0);//kanan
    glEnd();
              glBegin(GL_QUADS);
    glColor3ub(133,0,0);
    glVertex3f(-120.2, 75.0, 5.0); //kanan
    glVertex3f(-120.2, 60.0, 5.0);//kiri
    glVertex3f(-120.2, 60.0, 0.0);//kiri
    glVertex3f(-120.2, 75.0, 0.0);//kanan
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(45.0, 60.0, 5.0); //kanan
    glVertex3f(-45.0, 60.0, 5.0);//kiri
    glVertex3f(-45.0, 60.0, 80.0);//kiri
    glVertex3f(45.0, 60.0, 80.0);//kanan
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(133,0,0);
    glVertex3f(45.0, 75.0, 5.0); //kanan
    glVertex3f(-45.0, 75.0, 5.0);//kiri
    glVertex3f(-45.0, 75.0, 80.0);//kiri
    glVertex3f(45.0, 75.0, 80.0);//kanan
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(133,0,0);
    glVertex3f(45.0, 75.0, 80.0); //kanan
    glVertex3f(45.0, 60.0, 80.0);//kiri
    glVertex3f(-45.0, 60.0, 80.0);//kiri
    glVertex3f(-45.0, 75.0, 80.0);//kanan
    glEnd();
      glBegin(GL_QUADS);
    glColor3ub(133,0,0);
    glVertex3f(-45.0, 75.0, 5.0); //kanan
    glVertex3f(-45.0, 60.0, 5.0);//kiri
    glVertex3f(-45.0, 60.0, 80.0);//kiri
    glVertex3f(-45.0, 75.0, 80.0);//kanan
    glEnd();
      glBegin(GL_QUADS);
    glColor3ub(133,0,0);
    glVertex3f(45.0, 75.0, 5.0); //kanan
    glVertex3f(45.0, 60.0, 5.0);//kiri
    glVertex3f(45.0, 60.0, 80.0);//kiri
    glVertex3f(45.0, 75.0, 80.0);//kanan
    glEnd();

     glPopMatrix();
    glutSwapBuffers();
}

void idle() {
    if (!mouseDown) {
        xrot += 0.3f;
        yrot += 0.4f;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        zmov += 3.0;
        break;
    case 'd':
    case 'D':
        xmov += 3.0;
        break;
    case 's':
    case 'S':
        zmov -= 3.0;
        break;
    case 'a':
    case 'A':
        xmov -= 3.0;
        break;
    case '7':
        ymov += 3.0;
        break;
    case '9':
        ymov -= 3.0;
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, lebar / tinggi, 5.0, 750.0);
    glTranslatef(0.0, -10.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
