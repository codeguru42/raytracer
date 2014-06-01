/*
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details.
 */
#include <GL/freeglut.h>

#include "geom.h"

#define MIN -5.0
#define MAX  5.0

GLfloat pitch = -70.0;
GLfloat yaw   =   0.0;
GLfloat roll  =  30.0;

GLfloat* mat_diffuse[3]
  = { new GLfloat[4] { 1.0, 0.0, 0.0, 0.0}
    , new GLfloat[4] { 0.0, 1.0, 0.0, 0.0}
    , new GLfloat[4] { 0.0, 0.0, 1.0, 0.0}
    };

GLfloat mat_specular[4]
  = { 1.0, 1.0, 1.0, 1.0 };

GLfloat mat_shininess[1]
  = {50.0};

const int SPHERE_COUNT = 3;
Color colors[SPHERE_COUNT]
  = { Color(mat_diffuse[0], mat_specular, mat_shininess)
    , Color(mat_diffuse[1], mat_specular, mat_shininess)
    , Color(mat_diffuse[2], mat_specular, mat_shininess)
    };
Sphere spheres[SPHERE_COUNT]
  = { Sphere(Point( 1.0,  0.0, 0.0), 1.5, colors[0])
    , Sphere(Point(-2.0,  2.0, 0.0), 2.0, colors[1])
    , Sphere(Point(-2.0, -2.0, 0.0), 1.0, colors[2])
    };

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

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  for (int i = 0; i < SPHERE_COUNT; ++i) {
    spheres[i].paint();
  }

  glutSwapBuffers();
}

void init() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_SMOOTH);

  GLfloat light_position[] = { 1.0, 1.0, -1.0, 0.0 };
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);
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
  glutCreateWindow("Raytracer");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return 0;
}
