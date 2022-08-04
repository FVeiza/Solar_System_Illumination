#include <stdio.h>
#include <stdlib.h>

void criaEuropa(int slices, int stacks, GLuint texture){
    GLUquadric *qobj = gluNewQuadric();
    glColor3d(0.2,0.2,0.2);
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*0.3; // Manipula a velocidade da traget�ria
    glPushMatrix();
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture);
    gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, TRUE);
    gluQuadricNormals(qobj, GLU_SMOOTH);
        glTranslatef((9.5* cos(2.0 * 3.14 * a*3.1 / 100)),(9.5 * sin(2.0 * 3.14 * a*3.1 / 100)), 0);
		glTranslatef(0.6*cos(2.0 * 3.14 * a*30/ 100),0.6*sin(2.0 * 3.14 * a*30/ 100), 0);
		// Transla��es acumulativas
		glRotated(-50*a, 0, 0, 1);
		gluSphere(qobj,0.05,slices,stacks);
    gluDeleteQuadric(qobj);
    glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glFlush();
}
