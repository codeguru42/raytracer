#include "geom.h"

Color::Color() {}

Color::Color(GLfloat* mat_diffuse, GLfloat* mat_specular, GLfloat* mat_shininess)
    : mat_diffuse  (mat_diffuse)
    , mat_specular (mat_specular)
    , mat_shininess(mat_shininess)
{}

void Color::tellGL() {
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

Sphere:: Sphere(Point center, GLdouble radius)
    : center(center)
    , radius(radius)
{}

Sphere:: Sphere(Point center, GLdouble radius, Color color)
    : center(center)
    , radius(radius)
    , color (color)
{}

void Sphere::paint() {
    color.tellGL();
    glPushMatrix();
    glTranslatef(center.x, center.y, center.z);
    glutSolidSphere(radius, SLICES, STACKS);
    glPopMatrix();
}
