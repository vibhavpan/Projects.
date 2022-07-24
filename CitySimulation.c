//openGL program of City Simulation done by Vibhav.Please ignore //commented code.Enjoy!!

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14

int flag = 0;


void car()
{
	//draw body of car

	//glLoadIdentity();

	glColor3f(0.0, 0.0, 1.0);
	
	float counter = 1.25;
	counter += 0.3;

	glTranslated(counter, 0.0, 0.0);
	
	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_POLYGON);
	
	glVertex3f(1.25, 1.5, 0.0);
	glVertex3f(2.25, 1.5, 0.0);
	glVertex3f(2.25, 1.75, 0.0);
	glVertex3f(1.25, 1.75, 0.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(1.5, 1.5, 0.0);
	glVertex3f(2.0, 1.5, 0.0);
	glVertex3f(2.0, 2.0, 0.0);
	glVertex3f(1.5, 2.0, 0.0);

	glEnd();
	
	//for car's windshield

	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	glVertex3f(1.75, 1.75, 0.0);
	glVertex3f(2.0, 1.75, 0.0);
	glVertex3f(2.0, 2.0, 0.0);
	glVertex3f(1.75, 2.0, 0.0);

	glEnd();

	//for tyre
	glBegin(GL_TRIANGLE_FAN);

	glColor3d(0, 0, 0);

	float triangleAmount = 40.0;
	float x = 1.40; float y = 1.35; float radius = 0.15;

	float twicePi = 2 * PI;

	//center of circle
	glVertex2f(x, y);

	for (int i = 0; i <= 360; i++)
	{
		glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3d(0, 0, 0);
	x = 2; y = 1.35; radius = 0.15;

	twicePi = 2.0 * PI;
	glVertex2f(x, y); // center of circle
	for (int i = 0; i <= 360; i++) {
		glVertex2f(
			x + (radius * cos(i * twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();
}

void wheel(int x, int y)
{
	float th;
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0; i < 360; i++)
	{
		th = i * (3.1416 / 180);
		glVertex2f(x + 20 * cos(th), y + 20 * sin(th));
	}

	glEnd();

}
void circle(float cx,float cy,float r,int num_segments)
{
	glBegin(GL_POLYGON);

	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * PI * float(i) / float(num_segments);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glVertex2f(x + cx, y + cy);
	}
	glEnd();
}

void hut()
{
	glColor3f(1.0, 1.0, 1.0);

	//for base part
	glBegin(GL_POLYGON);

	glVertex3f(7.0, 2.0, 0.0);
	glVertex3f(8.0,2.0,0.0);
	glVertex3f(8.0, 3.0, 0.0);
	glVertex3f(7.0, 3.0,0.0);

	glEnd();

	glColor3f(0.0, 0.5, 0.5);

	//for door
	glBegin(GL_POLYGON);

	glVertex3f(7.25, 2.0, 0.0);
	glVertex3f(7.75, 2.0, 0.0);
	glVertex3f(7.75, 2.5, 0.0);
	glVertex3f(7.25, 2.5, 0.0);

	glEnd();

	glColor3f(0.5, 0.5, 0.0);
	
	glBegin(GL_POLYGON);
	
	glVertex3f(7.0, 3.0, 0.0);
	glVertex3f(7.5, 4.0, 0.0);
	glVertex3f(8.0, 3.0, 0.0);

	glEnd();


}

float counter = 600.0;

/*
void car()
{


	//Bottom Part
	glLoadIdentity();
	counter = counter + 0.03;
	glTranslated(counter, 0, 0.0);
	//glScaled(0.1,0.1,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-100, 20);
	glVertex2f(-100, 50);
	glVertex2f(-450, 50);
	glVertex2f(-450, 20);

	//Top Part
	glBegin(GL_POLYGON);
	glVertex2f(-150, 50);
	glVertex2f(-200, 70);
	glVertex2f(-400, 70);
	glVertex2f(-450, 50);

	glEnd();

	wheel(-200, 20);
	wheel(-380, 20);

}

*/
void display()
{

	glClear(GL_COLOR_BUFFER_BIT);
	//Push and pop matrix for separating circle object from Background
	glColor3f(0.0, 1.0, 0.0);
	car();
	glutSwapBuffers();
	glFlush();


}

void cloud()
{
	glPushMatrix();

	glColor3f(0.8, 0.8, 0.8);

	circle(200, 690, 25, 1000);
	circle(230, 700, 25, 1000);
	circle(180, 700, 25, 1000);
	circle(210, 720, 25, 1000);

}
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glPushMatrix();

	//sea

	glColor3f(0.25, 0.5, 1.0);

	glBegin(GL_POLYGON);
	glVertex3f(0.0, 4.0, 0.0);
	glVertex3f(10.0, 4.0, 0.0);
	glVertex3f(10.0, 10.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);

	glEnd();

	//bottom part of boat
	glColor3f(1.0, 0.5, 0.5);

	glBegin(GL_POLYGON);

	glVertex3f(6.5, 4.5, 0.0);
	glVertex3f(7.5, 4.5, 0.0);
	glVertex3f(8.0, 5.0, 0.0);
	glVertex3f(6.0, 5.0, 0.0);

	glEnd();

	//top part of boat 

	glColor3f(1.0, 0.0, 1.0);

	glBegin(GL_POLYGON);

	glVertex3f(6.5, 5, 0.0);
	glVertex3f(7.5, 5, 0.0);
	glVertex3f(7.5, 5.5, 0.0);
	glVertex3f(6.5, 5.5, 0.0);

	glEnd();

	//window of boat
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

	glVertex3f(6.55, 5.20, 0);
	glVertex3f(7.0, 5.20, 0.0);
	glVertex3f(7.0, 5.45, 0.0);
	glVertex3f(6.55, 5.45, 0.0);

	glEnd();

	//greenery
	glColor3f(0.0, 1.0, 0.0);

	glBegin(GL_POLYGON);

	glVertex3f(0.0, 2.0, 0.0);
	glVertex3f(10.0, 2.0, 0.0);
	glVertex3f(10.0, 4.0, 0.0);
	glVertex3f(0.0, 4.0, 0.0);

	glEnd();

	//to draw sun
	float x, y;
	int i;
	GLfloat radius;
	int triangleAmount = 40;

	GLfloat twicePi = 2.0 * PI;

	glBegin(GL_TRIANGLE_FAN);

	glColor3f(1.0, 1.0, 0.0);

	x = 3; y = 9; radius = 1;

	twicePi = 2 * PI;

	//center of circle
	glVertex2f(x, y);

	for (i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}

	glEnd();

	hut();

	//building 1
	glColor3f(1.0, 0.5, 0.0);


	glBegin(GL_POLYGON);
	glVertex3f(1.0, 2.0, 0.0);
	glVertex3f(2.0, 2.0, 0.0);
	glVertex3f(2.0, 4.0, 0.0);
	glVertex3f(1.0, 4.0, 0.0);


	glEnd();


	glColor3f(1.0, 0.5, 1.0);

	//building 2
	glBegin(GL_POLYGON);
	glVertex3f(3.0, 2.0, 0.0);
	glVertex3f(4.0, 2.0, 0.0);
	glVertex3f(4.0, 4.0, 0.0);
	glVertex3f(3.0, 4.0, 0.0);

	glEnd();


	//window1 for second building
	glColor3f(0.5, 0.5, 0.5);

	glBegin(GL_POLYGON);

	glVertex3f(3.25, 2.5, 0.0);
	glVertex3f(3.5, 2.5, 0.0);
	glVertex3f(3.5, 3, 0.0);
	glVertex3f(3.25, 3.0, 0.0);

	glEnd();

	//window 2 of second building

	glBegin(GL_POLYGON);

	glVertex3f(3.65f, 2.5f, 0.0f);
	glVertex3f(3.9f, 2.5f, 0.0f);
	glVertex3f(3.9f, 3.0f, 0.0f);
	glVertex3f(3.65f, 3.0f, 0.0f);

	glEnd();

	//third building
	glColor3f(1.0f, 1.0f, 0.0f);

	glBegin(GL_POLYGON);
	glVertex3f(5.0f, 2.0f, 0.0f);
	glVertex3f(6.0f, 2.0f, 0.0f);
	glVertex3f(6.0f, 4.0f, 0.0f);
	glVertex3f(5.0f, 4.0f, 0.0f);

	glEnd();

	//third building window 1

	glColor3f(0.5f, 0.5f, 0.5f);

	glBegin(GL_POLYGON);
	glVertex3f(5.25f, 2.5f, 0.0f);
	glVertex3f(5.5f, 2.5f, 0.0f);
	glVertex3f(5.5f, 3.0f, 0.0f);
	glVertex3f(5.25f, 3.0f, 0.0f);

	glEnd();

	//third building window 2

	glColor3f(0.5, 0.5, 0.5);

	glBegin(GL_POLYGON);
	glVertex3f(5.65f, 2.5f, 0.0f);
	glVertex3f(5.9f, 2.5f, 0.0f);
	glVertex3f(5.9f, 3.0f, 0.0f);
	glVertex3f(5.65f, 3.0f, 0.0f);


	glEnd();



	//for window one of first building

	glColor3f(0.5f, 0.5f, 0.5f);

	glBegin(GL_POLYGON);

	glVertex3f(1.2f, 2.5f, 0.0f);
	glVertex3f(1.45f, 2.5f, 0.0f);
	glVertex3f(1.45f, 3.0f, 0.0f);
	glVertex3f(1.2f, 3.0f, 0.0f);

	glEnd();

	//for window 2
	glBegin(GL_POLYGON);

	glVertex3f(1.6f, 2.5f, 0.0f);
	glVertex3f(1.85f, 2.5f, 0.0f);
	glVertex3f(1.85f, 3.0f, 0.0f);
	glVertex3f(1.6f, 3.0f, 0.0f);

	glEnd();

	//for road
	glColor3f(0.5, 0.5, 0.5);

	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(10.0f, 0.0f, 0.0f);
	glVertex3f(10.0f, 2.0f, 0.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);

	glEnd();

	//for cloud


	glColor3f(1.0, 1.0, 1.0);

	circle(200, 690, 25, 1000);
	circle(230, 700, 25, 1000);
	circle(180, 700, 25, 1000);
	circle(210, 720, 25, 1000);

	//glPopMatrix();


	car();
	//glTranslatef(3.0, 0.0, 0.0);
	//car();

	/*
		for (float i = 0.0; i < 10.0; i++)
		{
			//drawing the car
			//glColor3f(0.5, 0.5, 0);
			glTranslatef(i, 0.0, 0.0);
			

		}
		*/
	
		
	
	/*
	for (int i = 0; i < 10; i++)
	{

		car();
		glTranslatef(2, 0,0);
	}
	*/
	glFlush();

}

void myInit(void)
{
	//glClearColor(0.0, 0.0, 1.0, 0.0);
	cloud();
	glColor3f(1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1200, 0,800);
	//glOrtho(0.0, 10.0, 0.0, 10.0,-1.0,1.0);
}
/*
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glFlush();
}
*/
int main(int argc,char **argv)
{
	int input;

	printf("\n\t\t\t\tWelcome to City simulation by Vibhav(1CR19CS181)\n");
	printf("\n\t\t\t\t\tPress 1 to start the simulation\n");

	scanf_s("%d",&input);
	
	if (input == 1)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

		glutInitWindowPosition(10, 10);
		glutInitWindowSize(1000, 1000);

		glutCreateWindow("PROJECT");

		glMatrixMode(GL_PROJECTION);              // setup viewing projection
		glLoadIdentity();                           // start with identity matrix
		glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
		//cloud();

		glutDisplayFunc(display);
		glutDisplayFunc(draw);

		//myInit();

		glutMainLoop();

		

	}

	
}
