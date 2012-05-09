//prog to implement rubber band technique
#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<string.h>

int xmin=0,xmax=500,ymin=0,ymax=500;
int xm,ym;//first point
int xmm,ymm;//second point
int f;//flag

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xmin,xmax,ymin,ymax);
	glMatrixMode(GL_MODELVIEW);
}

void reshapeFunc(int w,int h)
{
	glViewport(0,0,w,h);
	if(w>h)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(xmin*w/h,xmax*w/h,ymin,ymax);
		glMatrixMode(GL_MODELVIEW);
	}
	else
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(xmin,xmax,ymin*h/w,ymax*h/w);
		glMatrixMode(GL_MODELVIEW);
	}
	glutPostRedisplay();
}

void mousefunc(int button,int status,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON && status==GLUT_DOWN)
	{
		xm=x;
		ym=ymax-y;
		f=0;
	}
	if(button==GLUT_LEFT_BUTTON && status==GLUT_UP)
	{
		glLogicOp(GL_XOR);
		glRectf(xm,ym,xmm,ymm);

		glLogicOp(GL_COPY);
		glRectf(xm,ym,x,ymax-y);
		
		glFlush();
		f=0;
	}
}

void move(int x,int y)
{
	if(f==1)
	{
		glLogicOp(GL_XOR);
		glRectf(xm,ym,xmm,ymm);
	}
	xmm=x;
	ymm=ymax-y;
	glLogicOp(GL_XOR);
		glRectf(xm,ym,xmm,ymm);
		glFlush();
	f=1;
}

void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	glFlush();
}

int main(int argc, char* argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	glutInitWindowPosition(100,100);
	glutInitWindowSize(xmax,ymax);
	glutCreateWindow("RUBBER TECHNIQUE");
	myinit();
	glEnable(GL_COLOR_LOGIC_OP);
	glutDisplayFunc(display);
	glutMotionFunc(move);
	glutMouseFunc(mousefunc);
	glutReshapeFunc(reshapeFunc);
	glutMainLoop();
}