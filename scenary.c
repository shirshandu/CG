#include<GL/glut.h>
#include<stdlib.h>
GLfloat x1,x2,y1,y2,x3,x4,y3,y4,x5,y5;
void dp(GLint cx,GLint cy)
{ 
	glBegin(GL_POINTS);
 	glVertex2i(cx,cy);
	glEnd();
}
void pix(GLint h,GLint k,GLint x,GLint y)
{
	dp(x+h,y+k);
	dp(x+h,-y+k);
	dp(-x+h,-y+k);
	dp(-x+h,y+k);
	dp(y+h,x+k);
	dp(y+h,-x+k);
	dp(-y+h,-x+k);
	dp(-y+h,x+k);

}
void cd(GLint h,GLint k,GLint r)
{
	GLint d=1-r,x=0,y=r;
	while(y>x)
	{
		pix(h,k,x,y);
		if(d<0)
			d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	pix(h,k,x,y);
}
void init()
{
	glClearColor(0.0,0.5,0.8,1.0);
	glColor3f(0.0,0.0,0.5);
	glPointSize(4.0);
	gluOrtho2D(0.0,1000.0,0.0,1000.0);
	//Co ordinates
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(0,-250);
	glVertex2i(0,250);
	glVertex2i(-250,0);
	glVertex2i(250,0);
glEnd();

}
void display()
{

float i,j;
for(i=0;i<600;i+=0.5)
{
	glClear(GL_COLOR_BUFFER_BIT);
//sun
	glColor3f(1.0,0.0,0.0);
	cd(600,500,35);
	cd(600,500,30);
	cd(600,500,25);
	cd(600,500,20);
	cd(600,500,15);
	cd(600,500,10);
	cd(600,500,50);
	cd(600,500,45);
	cd(600,500,40);
	cd(600,500,5);
	cd(600,500,55);
	cd(600,500,60);

//Dividng the Screen
	glColor3f(0.0,0.8,0.3);
	glBegin(GL_POLYGON);
	glVertex2i(0,500);
	glVertex2i(1000,500);
	glVertex2i(1000,0);
	glVertex2i(0,0);
	glEnd();	
//river	
//DOWN RIVER
	glColor3f(0.45,0.82,0.77);	
	//glColor3f(0.09,0.82,0.90);
	glBegin(GL_POLYGON);
	glVertex2i(0,0);	
	glVertex2i(0,200);
	glVertex2i(0,250);
	glVertex2i(500,150);
	glVertex2i(1000,100);
	glVertex2i(1000,0);
	glEnd();


//1st Hills

	glColor3f(0.05,0.35,0.05);
	//glColor3f(0.37,0.23,0.15);	
	glBegin(GL_QUADS);
	glVertex2i(0,500);
	glVertex2i(0,550);
	glVertex2i(100,600);
	glVertex2i(200,500);
	glEnd();
//Hills
	//glColor3f(0.37,0.23,0.15);
	glColor3f(0.05,0.35,0.05);	
	glBegin(GL_TRIANGLES);
	glVertex2i(400,500);
	glVertex2i(500,600);
	glVertex2i(600,500);
	glEnd();
//Center Part
	
	glColor3f(0.37,0.23,0.15);	
	glBegin(GL_TRIANGLES);
	glVertex2i(100,500);
	glVertex2i(300,600);
	glVertex2i(500,500);
	glEnd();

//2nd hill 
	glColor3f(0.0,0.5,0.0);
	glBegin(GL_TRIANGLES);
	glVertex2i(600,500);
	glVertex2i(700,600);
	glVertex2i(800,500);
	glEnd();

	glColor3f(0.37,0.23,0.15);
	glBegin(GL_TRIANGLES);
	glVertex2i(800,500);
	glVertex2i(1000,600);
	glVertex2i(1000,500);
	glEnd();
//tree + house
	int k;
	for(k=0;k<1100;k+=160)
	{
		glColor3f(0.5,0.3,0.5);
		glBegin(GL_POLYGON);
		glVertex2i(50+k,310);
		glVertex2i(50+k,350);
		glVertex2i(60+k,350);
		glVertex2i(60+k,310);
		glEnd();
		glColor3f(0.0,1.0,0.0);
		glBegin(GL_TRIANGLES);
		glVertex2i(40+k,350);
		glVertex2i(55+k,410);
		glVertex2i(70+k,350);
		glEnd();
//house
		glColor3f(1.0,1.2,0.0);
	    	glBegin(GL_POLYGON);
		glVertex2i(85+k,310);
		glVertex2i(85+k,350);
		glVertex2i(130+k,350);
		glVertex2i(130+k,310);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(100+k,310);
		glVertex2i(100+k,330);
		glVertex2i(115+k,330);
		glVertex2i(115+k,310);
		glEnd();
		glColor3f(0.0,1.0,1.0);
		glBegin(GL_TRIANGLES);
		glVertex2i(80+k,350);
		glVertex2i(105+k,380);
		glVertex2i(135+k,350);
		glEnd();
	}
	glFlush();
	}
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(700,700);
	glutCreateWindow("Natural Scenary");
	glutInitWindowPosition(0,0);
	init();	
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
