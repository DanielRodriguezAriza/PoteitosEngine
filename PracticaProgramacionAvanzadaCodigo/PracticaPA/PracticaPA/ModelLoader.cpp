#include "ModelLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Utility.h"

ModelLoader::ModelLoader()
:scale{ 1 }, model{}, vertexLocations{}, vertexNormals{}, maxMeshBoundary{}, minMeshBoundary{}
{}

ModelLoader::ModelLoader(std::string const& filename)
:ModelLoader{}
{
	this->loadModel(filename);
}

void ModelLoader::calculateBoundaries()
{
	Vector3D minPoint;
	Vector3D maxPoint;

	for (int i = 0; i < this->vertexLocations.size(); ++i)
	{
		Vector3D currentLocation = this->vertexLocations[i];

		//encontrar el boundary mínimo
		minPoint.setX(currentLocation.getX() < minPoint.getX() ? currentLocation.getX() : minPoint.getX());
		minPoint.setY(currentLocation.getY() < minPoint.getY() ? currentLocation.getY() : minPoint.getY());
		minPoint.setZ(currentLocation.getZ() < minPoint.getZ() ? currentLocation.getZ() : minPoint.getZ());

		//encontrar el boundary máximo
		maxPoint.setX(currentLocation.getX() > maxPoint.getX() ? currentLocation.getX() : maxPoint.getX());
		maxPoint.setY(currentLocation.getY() > maxPoint.getY() ? currentLocation.getY() : maxPoint.getY());
		maxPoint.setZ(currentLocation.getZ() > maxPoint.getZ() ? currentLocation.getZ() : maxPoint.getZ());
	}

	this->maxMeshBoundary = maxPoint;
	this->minMeshBoundary = minPoint;
}

Triangle ModelLoader::centerTriangle(Triangle const& t)
{
	Triangle ans;
	
	Vector3D modelCenter = {
		(this->minMeshBoundary.getX() + this->getWidth()) / 2.f,
		(this->minMeshBoundary.getY() + this->getHeight()) / 2.f,
		(this->minMeshBoundary.getZ() + this->getLength()) / 2.f
	};

	ans[0].setVertexLocation({t[0].getVertexLocation()-modelCenter});
	ans[1].setVertexLocation({t[1].getVertexLocation()-modelCenter});
	ans[2].setVertexLocation({t[2].getVertexLocation()-modelCenter});

	ans[0].setVertexNormal({t[0].getVertexNormal()});
	ans[1].setVertexNormal({t[1].getVertexNormal()});
	ans[2].setVertexNormal({t[2].getVertexNormal()});

	return ans;
}

Vector3D ModelLoader::parseObjLineToVector3D(std::string s)
{
	std::string pointType;
	float x, y, z;
	std::istringstream ss(s);
	ss >> pointType >> x >> y >> z;

	Vector3D ans{ x,y,z };
	ans *= this->getScale();
	return ans;
}

Triangle ModelLoader::parseObjTriangle(std::string s)
{
	char c;
	int vert0idx, vert1idx, vert2idx, norm10idx, norm11idx, norm12idx;

	std::istringstream ss(s);

	ss >> c;
	ss >> vert0idx >> c >> c >> norm10idx;
	ss >> vert1idx >> c >> c >> norm11idx;
	ss >> vert2idx >> c >> c >> norm12idx;

	Vector3D vertex0 = this->vertexLocations[vert0idx - 1];
	Vector3D vertex1 = this->vertexLocations[vert1idx - 1];
	Vector3D vertex2 = this->vertexLocations[vert2idx - 1];
	Vector3D normal = this->vertexNormals[norm10idx - 1];

	Triangle ans {vertex0,vertex1,vertex2,normal};

	return ans;
}

void ModelLoader::loadModel(std::string filename)
{
	try
	{
		std::ifstream objFile;
		objFile.open(filename);
		if (objFile.is_open())
		{
			std::string line;
			int count = 0;

			int materialIndex = -1;

			while (std::getline(objFile, line))
			{
				if (line[0] == 'v' && line[1] == 'n')
				{
					Vector3D normal = this->parseObjLineToVector3D(line);
					this->vertexNormals.push_back(normal);
				}
				else
				if (line[0] == 'v')
				{
					Vector3D vertex = this->parseObjLineToVector3D(line);
					this->vertexLocations.push_back(vertex);
				}
				else
				if (line[0] == 'f')
				{
					Triangle triangle = this->parseObjTriangle(line);
					triangle.setMaterialIndex(materialIndex);
					this->model.addTriangle(triangle);
				}
				else
				if (line[0] == 'u')
				{
					++materialIndex;
				}
			}
		}
		objFile.close();
		this->model.setScale({1});
	}
	catch (std::exception &ex)
	{
		Utility::printError("Excepción al procesar el archivo \"",filename,"\": ",ex.what(),"\n");
	}
}

void ModelLoader::centerMesh()
{
	for (Triangle& t : this->model.getTriangles())
	{
		t = centerTriangle(t);
	}
}