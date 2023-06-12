#include "Triangle.h"
#include "GL/glut.h"

Triangle::Triangle()
	:Solid{}, vertices {}, materialIndex{ 0 }
{}

Triangle::Triangle(Vector3D vertex0, Vector3D vertex1, Vector3D vertex2, Vector3D normal, Color color)
:vertices{ {vertex0,normal,color} ,{vertex1,normal,color},{vertex2,normal,color} },materialIndex{0}
{}

void Triangle::Render()
{
	glBegin(GL_TRIANGLES);
	this->getVertices()[0].Render();
	this->getVertices()[1].Render();
	this->getVertices()[2].Render();
	glEnd();
}