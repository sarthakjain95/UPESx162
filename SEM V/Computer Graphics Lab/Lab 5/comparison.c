#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>

int pos_x, pos_y, r;

void init_gl(void){
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glColor3f(1.0, 1.0, 1.0);

    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1920, 1920, -1080, 1080);
}

void draw_relative_vertex(int x, int y){
    glVertex2i(pos_x + x, pos_y + y);
}

void draw_octant(int x, int y){
    draw_relative_vertex(x, y);
    draw_relative_vertex(y, x);
    //
    draw_relative_vertex(-x, y);
    draw_relative_vertex(y, -x);
    //
    draw_relative_vertex(x, -y);
    draw_relative_vertex(-y, x);
    //
    draw_relative_vertex(-x, -y);
    draw_relative_vertex(-y, -x);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);

    int xk = 0, yk = r, pk = 3 - 2 * r;

    while(xk <= yk){
        // Recompute points
        xk++;
        if(pk < 0){
            pk = pk + 4 * xk + 6;
        }else{
            yk--;
            pk = pk + 4 * (xk - yk) + 10;
        }
        // Draw points
        draw_octant(xk, yk);
    } 

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);

    xk = 0;
    yk = r;
    pk = 1 - r;

    while(xk <= yk){
        // Recompute points
        xk++;
        if(pk < 0){
            pk = pk + 2 * xk + 1;
        }else{
            yk--;
            pk = pk - 2 * yk + 2 * xk + 1;
        }
        // Draw points
        draw_octant(xk, yk);
    } 

    glEnd();
    glFlush();
}

int main (int argc, char** argv){
    printf("Enter position of origin:");
    scanf("%d %d", &pos_x, &pos_y);

    printf("Enter the radius of circle:");
    scanf("%d", &r);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);

    glutCreateWindow(*argv);
    init_gl();

    glutDisplayFunc(display);
    glutMainLoop();
}
