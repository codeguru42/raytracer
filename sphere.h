#ifndef SPHERE_H
#define SPHERE_H

class Sphere {
public:
    Sphere(GLdouble radius) : radius(radius) {}
    void paint() { glutSolidSphere(radius, SLICES, STACKS); }

private:
    GLdouble radius;

    static const GLint SLICES = 10;
    static const GLint STACKS = 10;
};

#endif
