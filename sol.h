#include <stdio.h>
#include <stdlib.h>

void criaSol(int slices, int stacks, GLuint texture){
    GLUquadric *qobj = gluNewQuadric();
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t; // Manipula a velocidade da tragetória
    glEnable(GL_TEXTURE_2D);
        glPushMatrix();
            glColor3d(1,1,0);
            glRotated(-2*a, 0, 0, 1);
            gluQuadricDrawStyle(qobj, GLU_FILL);
            gluQuadricTexture(qobj, TRUE);
            gluQuadricNormals(qobj, GLU_SMOOTH);
            glBindTexture(GL_TEXTURE_2D,texture);
                gluSphere(qobj,2,slices,stacks);
            gluDeleteQuadric(qobj);
        glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glFlush();

}

