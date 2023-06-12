#include "Vertex.h"
#include "GL/glut.h"

Vertex::Vertex()
:vertexLocation{}, vertexNormal{}, vertexColor{}
{}

Vertex::Vertex(Vector3D const& location, Vector3D const& normal, Color const& color)
:vertexLocation{ location }, vertexNormal{ normal }, vertexColor{ color }
{}

void Vertex::Render()
{
	glColor3f(getVertexColor().getR(), getVertexColor().getG(), getVertexColor().getB());
	glNormal3f(getVertexNormal().getX(), getVertexNormal().getY(), getVertexNormal().getZ());
	glVertex3f(getVertexLocation().getX(), getVertexLocation().getY(), getVertexLocation().getZ());
}