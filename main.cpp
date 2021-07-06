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
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("Evifania Chayu Saghoa - 672019089");
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
    glEnable(GL_LIGHTING);
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
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glTranslatef(xmov, ymov, zmov);
    glPushMatrix();

    //bagunan panjang tengah
     //lantaibawah
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(140.0, -20.0, 20.0); //kanan
    glVertex3f(-70.0, -20.0, 20.0);//kiri
    glVertex3f(-70.0, -20.0, -80.0);//kiri
    glVertex3f(140.0, -20.0, -80.0);//kanan
    glEnd();
        //Tembok kiri
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(140.0, -20.0, 20.0); //kanan
    glVertex3f(140.0, 100.0, 20.0);//kiri
    glVertex3f(140.0, 100.0, -80.0);//kiri
    glVertex3f(140.0, -20.0, -80.0);//kanan
    glEnd();
     //dinding Kanan
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(-70.0, -20.0, 20.0); //kanan
    glVertex3f(-70.0, 100.0, 20.0);//kiri
    glVertex3f(-70.0, 100.0, -80.0);//kiri
    glVertex3f(-70.0, -20.0, -80.0);//kanan
    glEnd();
    //dinding depan
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(-70.0, -20.0, 20.0); //kanan
    glVertex3f(-70.0, 100.0, 20.0);//kiri
    glVertex3f(140.0, 100.0, 20.0);//kiri
    glVertex3f(140.0, -20.0, 20.0);//kanan
    glEnd();
    //dinding depan kecil 1
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-73.0, 12.0, 20.3); //kanan
    glVertex3f(-73.0, 23.0, 20.3);//kiri
    glVertex3f(143.0, 23.0, 20.3);//kiri
    glVertex3f(143.0, 12.0, 20.3);//kanan
    glEnd();
        //dinding depan kecil 2
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-73.0, 52.0, 20.3); //kanan
    glVertex3f(-73.0, 63.0, 20.3);//kiri
    glVertex3f(143.0, 63.0, 20.3);//kiri
    glVertex3f(143.0, 52.0, 20.3);//kanan
    glEnd();
        //dinding depan kecil 2
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-73.0, 89.0, 20.3); //kanan
    glVertex3f(-73.0, 102.0, 20.3);//kiri
    glVertex3f(143.0, 102.0, 20.3);//kiri
    glVertex3f(143.0, 89.0, 20.3);//kanan
    glEnd();
    //dinding belakang
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(-70.0, -20.0, -80.0); //kanan
    glVertex3f(-70.0, 100.0, -80.0);//kiri
    glVertex3f(140.0, 100.0, -80.0);//kiri
    glVertex3f(140.0, -20.0, -80.0);//kanan
    glEnd();
        //dinding belakang kecil 1
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-73.0, 12.0, -80.3); //kanan
    glVertex3f(-73.0, 23.0, -80.3);//kiri
    glVertex3f(143.0, 23.0, -80.3);//kiri
    glVertex3f(143.0, 12.0, -80.3);//kanan
    glEnd();
        //dinding depan kecil 2
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-73.0, 52.0, -80.3); //kanan
    glVertex3f(-73.0, 63.0, -80.3);//kiri
    glVertex3f(143.0, 63.0, -80.3);//kiri
    glVertex3f(143.0, 52.0, -80.3);//kanan
    glEnd();
        //dinding depan kecil 2
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-73.0, 89.0, -80.3); //kanan
    glVertex3f(-73.0, 102.0, -80.3);//kiri
    glVertex3f(143.0, 102.0, -80.3);//kiri
    glVertex3f(143.0, 89.0, -80.3);//kanan
    glEnd();
    //genteng depan
    glBegin(GL_QUADS);
    glColor3ub(133,0,0);
    glVertex3f(-73.0, 120.0, -25.0); //kanan
    glVertex3f(143.0, 120.0, -25.0);//kiri
    glVertex3f(143.0, 100.0, 23.0);//kiri
    glVertex3f(-73.0, 100.0, 23.0);//kanan
    glEnd();
        //genteng belakang
    glBegin(GL_QUADS);
    glColor3ub(133,0,0);
    glVertex3f(-73.0, 120.0, -25.0); //kanan
    glVertex3f(143.0, 120.0, -25.0);//kiri
    glVertex3f(143.0, 100.0, -83.0);//kiri
    glVertex3f(-73.0, 100.0, -83.0);//kanan
    glEnd();

    //bagunan panjang kiri
       //lantaibawah
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-120.0, -20.0, -120.0); //kanan
    glVertex3f(-200.0, -20.0, -120.0);//kiri
    glVertex3f(-200.0, -20.0, -340.0);//kiri
    glVertex3f(-120.0, -20.0, -340.0);//kanan
    glEnd();
            //Tembok kiri
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(-120.0, -20.0, -120.0); //kanan
    glVertex3f(-120.0, 100.0, -120.0);//kiri
    glVertex3f(-120.0, 100.0, -340.0);//kiri
    glVertex3f(-120.0, -20.0, -340.0);//kanan
    glEnd();
        //dinding kiri kecil 1
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-119.7, 12.0, -117.0); //kanan
    glVertex3f(-119.7, 23.0, -117.0);//kiri
    glVertex3f(-119.7, 23.0, -343.0);//kiri
    glVertex3f(-119.7, 12.0, -343.0);//kanan
    glEnd();
        //dinding kiri kecil 2
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-119.7, 52.0, -117.0); //kanan
    glVertex3f(-119.7, 63.0, -117.0);//kiri
    glVertex3f(-119.7, 63.0, -343.0);//kiri
    glVertex3f(-119.7, 52.0, -343.0);//kanan
    glEnd();
        //dinding kiri kecil 2
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-119.7, 89.0, -117.0); //kanan
    glVertex3f(-119.7, 102.0, -117.0);//kiri
    glVertex3f(-119.7, 102.0, -343.0);//kiri
    glVertex3f(-119.7, 89.0, -343.0);//kanan
    glEnd();
     //dinding Kanan
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(-200.0, -20.0, -120.0); //kanan
    glVertex3f(-200.0, 100.0, -120.0);//kiri
    glVertex3f(-200.0, 100.0, -340.0);//kiri
    glVertex3f(-200.0, -20.0, -340.0);//kanan
    glEnd();
        //dinding kanan kecil 1
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-200.3, 12.0, -117.0); //kanan
    glVertex3f(-200.3, 23.0, -117.0);//kiri
    glVertex3f(-200.3, 23.0, -343.0);//kiri
    glVertex3f(-200.3, 12.0, -343.0);//kanan
    glEnd();
        //dinding kanan kecil 2
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-200.3, 52.0, -117.0); //kanan
    glVertex3f(-200.3, 63.0, -117.0);//kiri
    glVertex3f(-200.3, 63.0, -343.0);//kiri
    glVertex3f(-200.3, 52.0, -343.0);//kanan
    glEnd();
        //dinding kanan kecil 3
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-200.3, 89.0, -117.0); //kanan
    glVertex3f(-200.3, 102.0, -117.0);//kiri
    glVertex3f(-200.3, 102.0, -343.0);//kiri
    glVertex3f(-200.3, 89.0, -343.0);//kanan
    glEnd();
    //dinding depan
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(-120.0, -20.0, -120.0); //kanan
    glVertex3f(-120.0, 100.0, -120.0);//kiri
    glVertex3f(-200.0, 100.0, -120.0);//kiri
    glVertex3f(-200.0, -20.0, -120.0);//kanan
    glEnd();
    //dinding belakang
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(-120.0, -20.0, -340.0); //kanan
    glVertex3f(-120.0, 100.0, -340.0);//kiri
    glVertex3f(-200.0, 100.0, -340.0);//kiri
    glVertex3f(-200.0, -20.0, -340.0);//kanan
    glEnd();
    //genteng
    glBegin(GL_QUADS);
    glColor3ub(133, 0, 0);
    glVertex3f(-117.0, 100.0, -120.0); //kanan
    glVertex3f(-160.0, 120.0, -120.0);//kiri
    glVertex3f(-160.0, 120.0, -340.0);//kiri
    glVertex3f(-117.0, 100.0, -340.0);//kanan
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(133,0,0);
    glVertex3f(-203.0, 100.0, -120.0); //kanan
    glVertex3f(-160.0, 120.0, -120.0);//kiri
    glVertex3f(-160.0, 120.0, -340.0);//kiri
    glVertex3f(-203.0, 100.0, -340.0);//kanan
    glEnd();

    //Bangunan Panjang kanan
    //lantaibawah
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(200.0, -20.0, -120.0); //kanan
    glVertex3f(280.0, -20.0, -120.0);//kiri
    glVertex3f(280.0, -20.0, -340.0);//kiri
    glVertex3f(200.0, -20.0, -340.0);//kanan
    glEnd();
    //Tembok kanan
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(280.0, -20.0, -120.0); //kanan
    glVertex3f(280.0, 100.0, -120.0);//kiri
    glVertex3f(280.0, 100.0, -340.0);//kiri
    glVertex3f(280.0, -20.0, -340.0);//kanan
    glEnd();
            //dinding kanan kecil 1
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(280.3, 12.0, -117.0); //kanan
    glVertex3f(280.3, 23.0, -117.0);//kiri
    glVertex3f(280.3, 23.0, -343.0);//kiri
    glVertex3f(280.3, 12.0, -343.0);//kanan
    glEnd();
        //dinding kanan kecil 2
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(280.3, 52.0, -117.0); //kanan
    glVertex3f(280.3, 63.0, -117.0);//kiri
    glVertex3f(280.3, 63.0, -343.0);//kiri
    glVertex3f(280.3, 52.0, -343.0);//kanan
    glEnd();
        //dinding kanan kecil 3
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(280.3, 89.0, -117.0); //kanan
    glVertex3f(280.3, 102.0, -117.0);//kiri
    glVertex3f(280.3, 102.0, -343.0);//kiri
    glVertex3f(280.3, 89.0, -343.0);//kanan
    glEnd();
    //dinding kiri
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(200.0, -20.0, -120.0); //kanan
    glVertex3f(200.0, 100.0, -120.0);//kiri
    glVertex3f(200.0, 100.0, -340.0);//kiri
    glVertex3f(200.0, -20.0, -340.0);//kanan
    glEnd();

            //dinding kiri kecil 1
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(199.7, 12.0, -117.0); //kanan
    glVertex3f(199.7, 23.0, -117.0);//kiri
    glVertex3f(199.7, 23.0, -343.0);//kiri
    glVertex3f(199.7, 12.0, -343.0);//kanan
    glEnd();
        //dinding kiri kecil 2
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(199.7, 52.0, -117.0); //kanan
    glVertex3f(199.7, 63.0, -117.0);//kiri
    glVertex3f(199.7, 63.0, -343.0);//kiri
    glVertex3f(199.7, 52.0, -343.0);//kanan
    glEnd();
        //dinding kiri kecil 2
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(199.7, 89.0, -117.0); //kanan
    glVertex3f(199.7, 102.0, -117.0);//kiri
    glVertex3f(199.7, 102.0, -343.0);//kiri
    glVertex3f(199.7, 89.0, -343.0);//kanan
    glEnd();
    //dinding depan
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(200.0, -20.0, -120.0); //kanan
    glVertex3f(200.0, 100.0, -120.0);//kiri
    glVertex3f(280.0, 100.0, -120.0);//kiri
    glVertex3f(280.0, -20.0, -120.0);//kanan
    glEnd();
    //dinding belakang
    glBegin(GL_QUADS);
    glColor3ub(171,149,99);
    glVertex3f(200.0, -20.0, -340.0); //kanan
    glVertex3f(200.0, 100.0, -340.0);//kiri
    glVertex3f(280.0, 100.0, -340.0);//kiri
    glVertex3f(280.0, -20.0, -340.0);//kanan
    glEnd();
    //genteng
    glBegin(GL_QUADS);
    glColor3ub(133, 0, 0);
    glVertex3f(197.0, 100.0, -120.0); //kanan
    glVertex3f(240.0, 120.0, -120.0);//kiri
    glVertex3f(240.0, 120.0, -340.0);//kiri
    glVertex3f(197.0, 100.0, -340.0);//kanan
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(133, 0, 0);
    glVertex3f(283.0, 100.0, -120.0); //kanan
    glVertex3f(240.0, 120.0, -120.0);//kiri
    glVertex3f(240.0, 120.0, -340.0);//kiri
    glVertex3f(283.0, 100.0, -340.0);//kanan
    glEnd();

      //dinding serong kiri
    glBegin(GL_QUADS);
    glColor3ub(255,154,54);
    glVertex3f(-202.0, -20.0, -120.0); //kanan
    glVertex3f(-202.0, 100.0, -120.0);//kiri
    glVertex3f(-72.0, 100.0, 20.0);//kiri
    glVertex3f(-72.0, -20.0, 20.0);//kanan
    glEnd();
    //dinding serong kiri belakang
    glBegin(GL_QUADS);
    glColor3ub(255,154,54);
    glVertex3f(-117.0, -20.0, -120.0); //kanan
    glVertex3f(-117.0, 100.0, -120.0);//kiri
    glVertex3f(-72.0, 100.0, -80.0);//kiri
    glVertex3f(-72.0, -20.0, -80.0);//kanan
    glEnd();

    //dinding serong kanan
    glBegin(GL_QUADS);
    glColor3ub(255,154,54);
    glVertex3f(282.0, -20.0, -120.0); //kanan
    glVertex3f(282.0, 100.0, -120.0);//kiri
    glVertex3f(142.0, 100.0, 20.0);//kiri
    glVertex3f(142.0, -20.0, 20.0);//kanan
    glEnd();

        //dinding serong kanan belakang
    glBegin(GL_QUADS);
    glColor3ub(255,154,54);
    glVertex3f(198.0, -20.0, -120.0); //kanan
    glVertex3f(198.0, 100.0, -120.0);//kiri
    glVertex3f(142.0, 100.0, -81.0);//kiri
    glVertex3f(142.0, -20.0, -81.0);//kanan
    glEnd();

    //bangunan Kotak Kecil kiri
           //lantaibawah
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-110.0, 0.0, -5.0); //kanan
    glVertex3f(-180.0, 0.0, -5.0);//kiri
    glVertex3f(-180.0, 0.0, -80.0);//kiri
    glVertex3f(-110.0, 0.0, -80.0);//kanan
    glEnd();
         //Tembok kiri
    glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-180.0, 0.0, -5.0); //kanan
    glVertex3f(-180.0, 120.0, -5.0);//kiri
    glVertex3f(-180.0, 120.0, -80.0);//kiri
    glVertex3f(-180.0, 0.0, -80.0);//kanan
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(242, 192,102);
    glVertex3f(-180.3, 15.0, -7.0); //kanan
    glVertex3f(-180.3, 105.0, -7.0);//kiri
    glVertex3f(-180.3, 105.0, -78.0);//kiri
    glVertex3f(-180.3, 15.0, -78.0);//kanan
    glEnd();
            glBegin(GL_QUADS);
    glColor3ub(128, 236,255);//jendela
    glVertex3f(-180.5, 15.0, -30.0); //kanan
    glVertex3f(-180.5, 105.0, -30.0);//kiri
    glVertex3f(-180.5, 105.0, -55.0);//kiri
    glVertex3f(-180.5, 15.0, -55.0);//kanan
    glEnd();

      //dinding Kanan
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(-110.0, 0.0, -5.0); //kanan
    glVertex3f(-110.0, 120.0, -5.0);//kiri
    glVertex3f(-110.0, 120.0, -80.0);//kiri
    glVertex3f(-110.0, 0.0, -80.0);//kanan
    glEnd();
    //dinding depan
        glBegin(GL_QUADS);
    glColor3ub(255,234,171);
    glVertex3f(-110.0, 0.0, -05.0); //kanan
    glVertex3f(-110.0, 120.0, -05.0);//kiri
    glVertex3f(-180.0, 120.0, -05.0);//kiri
    glVertex3f(-180.0, 0.0, -05.0);//kanan
    glEnd();
            glBegin(GL_QUADS);
    glColor3ub(242, 192,102);//warna tengah
    glVertex3f(-113.0, 15.0, -04.7); //kanan
    glVertex3f(-113.0, 105.0, -04.7);//kiri
    glVertex3f(-177.0, 105.0, -04.7);//kiri
    glVertex3f(-177.0, 15.0, -04.7);//kanan
    glEnd();
     glBegin(GL_QUADS);
        glColor3ub(128, 236,255);//jendela
    glVertex3f(-135.0, 15.0, -04.5); //kanan
    glVertex3f(-135.0, 105.0, -04.5);//kiri
    glVertex3f(-155.0, 105.0, -04.5);//kiri
    glVertex3f(-155.0, 15.0, -04.5);//kanan
    glEnd();


            glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(-110.0, 0.0, -80.0); //kanan
    glVertex3f(-110.0, 120.0, -80.0);//kiri
    glVertex3f(-180.0, 120.0, -80.0);//kiri
    glVertex3f(-180.0, 0.0, -80.0);//kanan
    glEnd();

    //Bangunan Kotak Kecil kanan
          //lantaibawah
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(190.0, 0.0, -5.0); //kanan
    glVertex3f(260.0, 0.0, -5.0);//kiri
    glVertex3f(260.0, 0.0, -80.0);//kiri
    glVertex3f(190.0, 0.0, -80.0);//kanan
    glEnd();
             //Tembok kiri
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(190.0, 0.0, -5.0); //kanan
    glVertex3f(190.0, 120.0, -5.0);//kiri
    glVertex3f(190.0, 120.0, -80.0);//kiri
    glVertex3f(190.0, 0.0, -80.0);//kanan
    glEnd();
      //dinding Kanan
    glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(260.0, 0.0, -5.0); //kanan
    glVertex3f(260.0, 120.0, -5.0);//kiri
    glVertex3f(260.0, 120.0, -80.0);//kiri
    glVertex3f(260.0, 0.0, -80.0);//kanan
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(190.0, 0.0, -05.0); //kanan
    glVertex3f(190.0, 120.0, -05.0);//kiri
    glVertex3f(260.0, 120.0, -05.0);//kiri
    glVertex3f(260.0, 0.0, -05.0);//kanan
    glEnd();
            glBegin(GL_QUADS);
    glColor3ub(171, 149, 99);
    glVertex3f(190.0, 0.0, -80.0); //kanan
    glVertex3f(190.0, 120.0, -80.0);//kiri
    glVertex3f(260.0, 120.0, -80.0);//kiri
    glVertex3f(260.0, 0.0, -80.0);//kanan
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
    gluPerspective(80.0, lebar / tinggi, 5.0, 600.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
