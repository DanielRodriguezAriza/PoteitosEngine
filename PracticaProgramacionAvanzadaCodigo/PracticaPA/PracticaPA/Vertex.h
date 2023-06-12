#pragma once
#include "Vector3D.h"
#include "Color.h"

class Vertex
{
public:
	Vertex();
	Vertex(Vector3D const &location, Vector3D const &normal, Color const &color);
	
	inline Vector3D getVertexLocation() const { return this->vertexLocation; }
	inline Vector3D getVertexNormal() const { return this->vertexNormal; }
	inline Color getVertexColor() const { return this->vertexColor; }

	inline void setVertexLocation(Vector3D const& newLocation) { this->vertexLocation = newLocation; }
	inline void setVertexNormal(Vector3D const& newNormal) { this->vertexNormal = newNormal; }
	inline void setVertexColor(Color const& newColor) { this->vertexColor = newColor; }

	void Render();

private:
	Vector3D vertexLocation;
	Vector3D vertexNormal;
	Color vertexColor;
};