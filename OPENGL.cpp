#include<GL/GLUT.H>

void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//we make 3 d object thats why we need to clear color buffer and depth buffer
    glLoadIdentity();// is used to set current matrix  model or projectional
    glTranslatef(0, 0, -10);
    glRotatef(-60, 1, 1, 0);
    glBegin(GL_QUADS);// it need  compulsary end. we have to draw quard thats why we take.
    
    // cube's front draw 
    glColor3f(1, 0, 0);//red colour given to that
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);

    // cubes back
    glColor3f(0, 1, 0);//green colour given to that
    glVertex3f(-1, 1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, 1, -1);

    //cubes right
    glColor3f(0, 0, 1);//blue colour given to that
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);

    //cubes left
    glColor3f(0, 1, 1);// colour given to that
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);

    //cube top
    glColor3f(1, 1, 0);// colour given to that
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);

    //cube bottom
    glColor3f(1, 0, 1);// colour given to that
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, -1, -1);
    glEnd();
    glFlush();
}
void init()
{
    glClearColor(0, 0, 0, 1);//background color
    glEnable(GL_DEPTH_TEST);
}
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 4, 50);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D transformation");
    glutDisplayFunc(mydisplay);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();
    return 0;
}
