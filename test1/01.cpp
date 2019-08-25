#include <windows.h>
#include <GL/glut.h>

int ww = 600, wh = 400;
int xi, yi, xf0, yf0, xf1, yf1;
bool first = 1;

void drawLine(GLint x1, GLint y1, GLint x2, GLint y2)
{	
	//glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);

	glBegin(GL_LINES);
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
	glEnd();
	glFlush();
}

void display()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && first==1 && state == GLUT_DOWN){
		xi = x;
		yi = (wh-y);
		xf0 = x;
		yf0 = (wh-y);
		xf1 = x;
		yf1 = (wh-y);
		first=0;
	}
	else if(btn==GLUT_LEFT_BUTTON && first==0 && state == GLUT_DOWN){
		xi = x;
		yi = (wh-y);
		drawLine(xf1,yf1,xi,yi);
		xf1 = xi;
		yf1 = yi;
	}

	else if (btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		drawLine(xf0,yf0,xi,yi);
	}
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'q' || key == 'Q')
        exit(0);
	else if (key == 'e' || key == 'E'){
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
	}
}

void myinit()
{            
     glViewport(0,0,ww,wh);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);
     glMatrixMode(GL_MODELVIEW);	 
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(ww,wh);
	glutCreateWindow("Polygon");
	myinit();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard); 
	glutMainLoop();
     
	return 0;
}