#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int n;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2,2,-2,2,-2,2);
	glMatrixMode(GL_MODELVIEW);
}
void triangle(float *a,float *b,float *c)
{
	glBegin(GL_POLYGON);
		glVertex3fv(a);
		glVertex3fv(b);
		glVertex3fv(c);
	glEnd();
}
void divide_triangle(float *a,float *b,float *c,int n)
{
	float ab[3],bc[3],ac[3];
	int j;
	if(n>0)
	{
		for(j=0;j<3;j++)
		{
			ab[j]=(a[j]+b[j])/2;
			bc[j]=(b[j]+c[j])/2;
			ac[j]=(a[j]+c[j])/2;
		}
		divide_triangle(a,ab,ac,n-1);
		divide_triangle(ab,b,bc,n-1);
		divide_triangle(ac,bc,c,n-1);
	}
	else
	triangle(a,b,c);
}
void display1()
{
	float v[4][3]={{0,1,0},{.5,-.5,0},{-.5,-.5,0},{0,0,1}};
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	divide_triangle(v[0],v[1],v[2],n);
	glColor3f(0,1,0);
	divide_triangle(v[3],v[2],v[0],n);
	glColor3f(0,0,1);
	divide_triangle(v[3],v[0],v[1],n);
	glColor3f(1,0,1);
	divide_triangle(v[3],v[1],v[2],n);
	glFlush();
}
void main(int argc,char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("3D SIERPINSKI PATTERN");
	printf("Enter the value of n");
	scanf_s("%d",&n);
	myinit();
	glutDisplayFunc(display1);
	glutMainLoop();

}