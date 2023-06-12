#include "Camera.h"
#include <GL/glut.h>

Camera::Camera()
:Solid{}
{
	this->setHasCollision(false);
}

void Camera::Render()
{
	glRotatef(this->getRotation().getX(), 1, 0, 0);
	glRotatef(this->getRotation().getY(), 0, 1, 0);
	glRotatef(this->getRotation().getZ(), 0, 0, 1);
	glTranslatef(-1 * this->getLocation().getX(), -1 * this->getLocation().getY(), -1 * this->getLocation().getZ());
}