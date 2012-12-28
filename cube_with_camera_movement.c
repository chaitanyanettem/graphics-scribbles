#include<GL/glut.h>

GLfloat vertices[][3]={{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},{-1.0,1.0,-1.0},
{-1.0,-1.0,1.0},{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0}};

GLfloat colors[][3]={{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},{-1.0,1.0,-1.0},
{-1.0,-1.0,1.0},{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0}};
GLubyte cubeIndices[]={0,3,2,1,2,3,7,6,0,4,7,3,1,2,6,5,4,5,6,7,0,1,5,4};

static GLfloat theta[]={0.0,0.0,0.0};
static GLint axis=2;
static GLint viewer[]={0.0,0.0,5.0};

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(viewer[0],viewer[1],viewer[2],0.0,0.0,0.0,0.0,1.0,0.0);
	glRotatef(theta[0],1.0,0.0,0.0);
	glRotatef(theta[1],0.0,1.0,0.0);
	glRotatef(theta[2],0.0,0.0,1.0);
	glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,cubeIndices);
	glutSwapBuffers();
	glFlush();
}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)axis=0;
		if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)axis=1;
			if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)axis=2;
				theta[axis]=theta[axis]+2.0;
	if(theta[axis]>360.0)
		theta[axis]=theta[axis]-360.0;
	display();
}

void keys(unsigned char key,int x,int y)
{
	if(key=='x')
		viewer[0]=viewer[0]-1.0;
	if(key=='X')
		viewer[0]=viewer[0]+1.0;
	if(key=='y')
		viewer[1]=viewer[1]-1.0;
	if(key=='Y')
		viewer[1]=viewer[1]+1.0;
	if(key=='z')
		viewer[2]=viewer[2]-1.0;
	if(key=='Z')
		viewer[2]=viewer[2]+1.0;
	display();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glOrtho(-2.0,2.0,-2.0,2.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(600,600);
	glutCreateWindow("Colorcube viewer");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keys);
	glEnable(GL_DEPTH_TEST);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3,GL_FLOAT,0,vertices);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3,GL_FLOAT,0,colors);
	glutMainLoop();
}
