/*
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details.
 */
#include <GL/freeglut.h>

#define MIN -1.0
#define MAX  1.0

GLfloat pitch = -70.0;
GLfloat yaw   =   0.0;
GLfloat roll  =  30.0;

GLfloat lerp(GLfloat x,
             GLfloat xMin, GLfloat xMax,
             GLfloat yMin, GLfloat yMax) {
  return x * (yMax - yMin) / (xMax - xMin);
}

void display() {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glRotated(pitch, 1.0, 0.0, 0.0);
  glRotated(yaw  , 0.0, 0.0, 1.0);
  glRotated(roll , 0.0, 0.0, 1.0);

  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0, 1.0, 1.0);

  glBegin(GL_TRIANGLES);
  glVertex2f(1.0, 0.0);
  glVertex2f(0.0, 1.0);
  glVertex2f(-1.0, 0.0);
  glEnd();

  glutSwapBuffers();
}

void init() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLAT);
}

void reshape(int w, int h) {
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();

  if (w <= h) {
    glOrtho(MIN, MAX,
            lerp(MIN, 0, w, 0, h), lerp(MAX, 0, w, 0, h),
            2*MIN, 2*MAX);
  } else {
    glOrtho(lerp(MIN, 0, h, 0, w), lerp(MAX, 0, h, 0, w),
            MIN, MAX,
            2*MIN, 2*MAX);
  }
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Surface3D");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return 0;
}
