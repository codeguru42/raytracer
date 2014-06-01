#ifndef GEOM_H
#define GEOM_H

#include <GL/freeglut.h>

class Point {
public:
    const GLdouble x, y, z;
    Point(GLdouble x, GLdouble y, GLdouble z) : x(x), y(y), z(z) {}
};

class Sphere {
public:
    Sphere(GLdouble radius) : Sphere(Point(0.0, 0.0, 0.0), radius) {}
    Sphere(Point center, GLdouble radius);
    void paint();

private:
    Point center;
    GLdouble radius;
    GLfloat mat_specular[4];
    GLfloat mat_diffuse[4];
    GLfloat mat_shininess[1];

    static const GLint SLICES = 20;
    static const GLint STACKS = 20;
};

#endif
