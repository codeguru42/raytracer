#ifndef SPHERE_H
#define SPHERE_H

#include <GL/freeglut.h>

class Sphere {
public:
    Sphere(GLdouble radius) : radius(radius)
                            , mat_diffuse{1.0, 0.0, 0.0, 0.0}
                            , mat_specular{ 1.0, 1.0, 1.0, 1.0 }
                            , mat_shininess{ 50.0 }
                            {}
    void paint();

private:
    GLdouble radius;
    GLfloat mat_specular[4];
    GLfloat mat_diffuse[4];
    GLfloat mat_shininess[1];

    static const GLint SLICES = 20;
    static const GLint STACKS = 20;
};

#endif
