/*creates a mesh*/
#include<GL/glut.h>

#define max_x 20
#define max_y 25
#define dx 15
#define dy 10

GLint x[max_x],y[max_y];
GLint x0=50,y0=50;
GLint i,j;

void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,500.0,0.0,400.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	for(i=0;i<maxx;i++)
		x[i]=x0+i*dx;
	for(j=0;j<maxy;j++)
		y[j]=y0+j*dy;
	for(i=0;i<maxx-1;i++)
		for(j=0;j<maxy-1;j++)
		{
			glColor3f(0.0,0.0,1.0);
			glBegin(GL_LINE_LOOP);
				glVertex2i(x[i],y[j]);
				glVertex2i(x[i],y[j+1]);
				glVertex2i(x[i+1],y[j+1]);
				glVertex2i(x[i+1],y[j]);
			glEnd();
			glFlush();
		}
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,400);
	glutCreateWindow("rectangular Mesh");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}		
