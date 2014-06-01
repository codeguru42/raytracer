/*
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details.
 */
#ifndef GEOM_H
#define GEOM_H

#include <GL/freeglut.h>

class Point {
public:
    const GLdouble x, y, z;
    Point(GLdouble x, GLdouble y, GLdouble z) : x(x), y(y), z(z) {}
};

class Color {
public:
    Color();
    Color(GLfloat* mat_specular, GLfloat* mat_diffuse, GLfloat* mat_shininess);
    void tellGL();
private:
    GLfloat* mat_specular;
    GLfloat* mat_diffuse;
    GLfloat* mat_shininess;
};

class Sphere {
public:
    Sphere(GLdouble radius) : Sphere(Point(0.0, 0.0, 0.0), radius) {}
    Sphere(Point center, GLdouble radius);
    Sphere(Point center, GLdouble radius, Color color);
    void paint();

private:
    Point center;
    GLdouble radius;
    Color color;

    static const GLint SLICES = 20;
    static const GLint STACKS = 20;
};

#endif
