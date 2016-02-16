#include <stdio.h>
#include <GLUT/glut.h>


float red = 1.0, green = 1.0, blue = 1.0;


void Init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-1.0, 1.0, -1.0, -1.0, 1.0, 0.0);
}

void Display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(red, green, blue);
    glutWireTeapot(0.5);
    glFlush();
}

void Keyboard(unsigned char key, int x, int y){
    
    switch (key){
        case '1':
            red = 1.0;
            green = 0.0;
            blue = 0.0;
            break;
        case '2':
            red = 0.0;
            green = 1.0;
            blue = 0.0;
            break;
        case '3':
            red = 0.0;
            green = 0.0;
            blue = 1.0;
            break;
        case '4':
            red = 1.0;
            green = 1.0;
            blue = 0.0;
            break;
    }
    glutPostRedisplay();
}

void KeyboardSpecial(int key, int x, int y){
    if (key ==  GLUT_KEY_F1){
        red = 1.0;
        green = 1.0;
        blue = 1.0;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv){
    
    glutInit(&argc, argv);
    
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(300, 300);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutCreateWindow("GLUT Practice Part 1 - Laura del Pino Díaz");
    glutSetCursor(GLUT_CURSOR_WAIT);  //special cursor for window.
    Init();
    glutDisplayFunc(Display);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(KeyboardSpecial);
    
    glutMainLoop();
    
    return 0;
}