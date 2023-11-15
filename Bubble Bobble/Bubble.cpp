#include"Bubble.h"
#include<GL/freeglut.h>

Bubble::Bubble(){}
Bubble::Bubble(float r, int sl, int st) {
	radius = r; slice = sl; stack = st;
}

void Bubble::setRadius(float r) {
	radius = r;
}
float Bubble::getRadius() const {
	return radius;
}
void Bubble::setSlice(int sl) {
	slice = sl;
}
void Bubble::setStack(int st) {
	stack = st;
}

void Bubble::setCenter(const Vector3f& c) {
	center = c;
}
Vector3f Bubble::getCenter() const {
	return center;
}
void Bubble::setVelocity(const Vector3f& v) {
	velocity = v;
}
Vector3f Bubble::getVelocity() const {
	return velocity;
}

void Bubble::setMTL(const Material& m) {
	mtl = m;
}

void Bubble::move() {
	center = center + velocity;
}
void Bubble::draw() const {

	float getambient[4] = { mtl.getAmbient()[0], mtl.getAmbient()[1], mtl.getAmbient()[2], mtl.getAmbient()[3] };
	float getdiffuse[4] = { mtl.getDiffuse()[0],mtl.getDiffuse()[1],mtl.getDiffuse()[2],mtl.getDiffuse()[3] };
	float getspecular[4] = { mtl.getSpecular()[0],mtl.getSpecular()[1],mtl.getSpecular()[2],mtl.getSpecular()[3] };
	float getemission[4] = { mtl.getEmission()[0] ,mtl.getEmission()[1] ,mtl.getEmission()[2] ,mtl.getEmission()[3] };
	float shininess[1] = { mtl.getShininess() };

	glPushMatrix();
	glTranslatef(center[0], center[1],center[2]);	

	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_EMISSION, getemission);
	glMaterialfv(GL_FRONT, GL_AMBIENT,getambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, getdiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, getspecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glutSolidSphere(radius, slice, stack);

	glPopMatrix();
}
