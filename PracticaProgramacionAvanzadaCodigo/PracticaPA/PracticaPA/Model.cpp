#include "Model.h"
#include "GL/glut.h"
#include "ModelLoader.h"

Model::Model()
:Solid{},triangles {}
{}

Model::Model(Model const& other)
:Solid{other}, triangles{other.triangles}
{}

Model::Model(std::string const& filename)
:Model{}
{
	ModelLoader loader;
	loader.loadModel(filename);
	this->setModel(loader.getModel());
}

void Model::Render()
{
	glPushMatrix();
	glTranslatef(this->getLocation().getX(), getLocation().getY(), getLocation().getZ());
	glColor3f(this->getColor().getR(), this->getColor().getG(), this->getColor().getB());
	glRotatef(this->getRotation().getX(), 1, 0, 0);
	glRotatef(this->getRotation().getY(), 0, 1, 0);
	glRotatef(this->getRotation().getZ(), 0, 0, 1);

	glScalef(this->getScale().getX(), this->getScale().getY(), this->getScale().getZ());

	for (Triangle& t : triangles)
	{
		t.Render();
	}

	glPopMatrix();
}

void Model::paintColor(Color const& newColor)
{
	for (Triangle &t : triangles)
	{
		t[0].setVertexColor(newColor);
		t[1].setVertexColor(newColor);
		t[2].setVertexColor(newColor);
	}
}

void Model::paintColorIndex(Color const& newColor, int index)
{
	for (Triangle& t : triangles)
	{
		if (t.getMaterialIndex() == index)
		{
			t[0].setVertexColor(newColor);
			t[1].setVertexColor(newColor);
			t[2].setVertexColor(newColor);
		}
	}
}

void Model::setModel(Model const& other)
{
	this->triangles = other.triangles;
}