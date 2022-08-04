#include <stdio.h>
#include <stdlib.h>

void criaUrano(int slices, int stacks, GLuint texture){
    GLUquadric *qobj = gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture);
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*0.1; // Manipula a velocidade da tragetória
	glColor3d(0.2,0.2,0.2);
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, TRUE);
    gluQuadricNormals(qobj, GLU_SMOOTH);
        glTranslatef((13* cos(2.0 * 3.14 * a*3.1 / 100)),(13 * sin(2.0 * 3.14 * a*3.1 / 100)), 0);
		glRotated(-50*a, 0, 0, 1);
		gluSphere(qobj,0.19,slices,stacks);
    gluDeleteQuadric(qobj);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);

	glFlush();
}
