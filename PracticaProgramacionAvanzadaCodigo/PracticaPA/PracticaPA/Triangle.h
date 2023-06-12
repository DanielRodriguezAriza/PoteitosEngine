#pragma once
#include "Vertex.h"
#include "Solid.h"
#include "Math.h"
#include <iostream>

class Triangle : public Solid
{
public:
	Triangle();
	Triangle(Vector3D vertex0, Vector3D vertex1, Vector3D vertex2, Vector3D normal, Color color = Color{1,1,1});

	void Render() override;

	inline Vertex const& getVertex(size_t idx) const { return vertices[idx]; }

	inline Vertex const *getVertices() const { return vertices; }
	inline Vertex *getVertices() { return vertices; }

	inline Vertex const& operator[](size_t idx) const { return this->vertices[idx]; }
	Vertex& operator[](size_t idx) { return this->vertices[idx]; }

	inline int const getMaterialIndex() const { return this->materialIndex; }
	inline void setMaterialIndex(int index) { this->materialIndex = index; }

private:
	Vertex vertices[3];
	int materialIndex;
};