#include "geom.h"

Sphere:: Sphere(Point center, GLdouble radius)
    : center (center)
    , radius(radius)
    , mat_diffuse{1.0, 0.0, 0.0, 0.0}
    , mat_specular{ 1.0, 1.0, 1.0, 1.0 }
    , mat_shininess{ 50.0 }
{}

void Sphere::paint() {
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glPushMatrix();
    glTranslatef(center.x, center.y, center.z);
    glutSolidSphere(radius, SLICES, STACKS);
    glPopMatrix();
}
