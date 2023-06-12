#pragma once
#include <string>
#include "Solid.h"
#include "Model.h"

class ModelLoader
{
public:
	ModelLoader();
	ModelLoader(std::string const &filename);

	inline float const getWidth() const { return this->maxMeshBoundary.getX() - this->minMeshBoundary.getX(); }
	inline float const getHeight() const { return this->maxMeshBoundary.getY() - this->minMeshBoundary.getY(); }
	inline float const getLength() const { return this->maxMeshBoundary.getZ() - this->minMeshBoundary.getZ(); }
	inline Vector3D const getMaxMeshBoundary() const { return this->maxMeshBoundary; }
	inline Vector3D const getMinMeshBoundary() const { return this->minMeshBoundary; }

	inline float const getScale() const { return this->scale; }
	inline void setScale(float newScale) { this->scale = newScale; }
	
	inline Model getModel() { return this->model; }
	
	void loadModel(std::string filename);
	inline void clearModel() { vertexLocations.clear(); vertexNormals.clear(); model.clearTriangles(); }
	void centerMesh();

private:

	void calculateBoundaries();
	Triangle centerTriangle(Triangle const &t);

	Vector3D parseObjLineToVector3D(std::string s);
	Triangle parseObjTriangle(std::string s);

private:

	float scale;
	Model model;

	std::vector<Vector3D> vertexLocations;
	std::vector<Vector3D> vertexNormals;

	Vector3D maxMeshBoundary;
	Vector3D minMeshBoundary;
};