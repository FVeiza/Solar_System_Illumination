#include <stdio.h>
#include <stdlib.h>

void criaMerc(int slices, int stacks, GLuint texture){
    GLUquadric *qobj = gluNewQuadric();
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*20; // Manipula a velocidade da tragetória
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture);
        glPushMatrix();
            glColor3d(0.2,0.2,0.2);
            gluQuadricDrawStyle(qobj, GLU_FILL);
            gluQuadricTexture(qobj, TRUE);
            gluQuadricNormals(qobj, GLU_SMOOTH);
                glTranslatef((4 * cos(2.0 * 3.14 * a*0.48 / 100)),(4* sin(2.0 * 3.14 * a*0.48 / 100)), 0);
                glRotated(-50*a, 0, 0, 1);
                gluSphere(qobj,0.05,slices,stacks);
            gluDeleteQuadric(qobj);
        glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	glFlush();
}
