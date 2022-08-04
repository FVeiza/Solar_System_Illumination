#include <stdio.h>
#include <stdlib.h>

void criaGanimedes(int slices, int stacks, GLuint texture){
    GLUquadric *qobj = gluNewQuadric();
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*0.3; // Manipula a velocidade da traget�ria
	glColor3d(0.2,0.2,0.2);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture);
    gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, TRUE);
    gluQuadricNormals(qobj, GLU_SMOOTH);
        glTranslatef((9.5* cos(2.0 * 3.14 * a*3.1 / 100)),(9.5 * sin(2.0 * 3.14 * a*3.1 / 100)), 0);
		glTranslatef(-0.9*cos(2.0 * 3.14 * a*30/ 100),-0.9*sin(2.0 * 3.14 * a*30/ 100), 0);
		// Transla��es acumulativas
		glRotated(-50*a, 0, 0, 1);
		gluSphere(qobj,0.01,slices,stacks);
    gluDeleteQuadric(qobj);
    glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glFlush();
}

