#pragma once
#include "Solid.h"
#include "Triangle.h"
#include <vector>

class Model : public Solid
{
public:
	Model();
	Model(Model const& other);
	Model(std::string const &filename);

	void Render() override;

	inline void addTriangle(Triangle const& newTriangle) { triangles.push_back(newTriangle); }
	inline void clearTriangles() { triangles.clear(); }
	
	void paintColor(Color const& newColor);
	void paintColorIndex(Color const& newColor, int index);

	std::vector<Triangle> const &getTriangles() const { return this->triangles; }
	std::vector<Triangle> &getTriangles() { return this->triangles; }

	void setModel(Model const& other);

private:
	std::vector<Triangle> triangles;
};