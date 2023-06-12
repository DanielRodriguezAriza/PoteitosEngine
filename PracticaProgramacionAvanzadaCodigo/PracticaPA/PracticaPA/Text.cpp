#include "Text.h"
#include "GL/glut.h"

Text::Text()
:Solid{},textData {"default text"}, isScreenSpace{false},isStroke{false}
{
	this->setHasCollision(false);
}

Text::Text(std::string const& newText)
:Solid{}, textData{ newText }, isScreenSpace {false},isStroke{false}
{
	this->setHasCollision(false);
}

void Text::Render()
{
	if (this->isScreenSpace) { glDisable(GL_LIGHTING); }

	glPushMatrix();
	glColor3f(this->getColor().getR(), this->getColor().getG(), this->getColor().getB());
	glTranslatef(this->getLocation().getX(), this->getLocation().getY(), this->getLocation().getZ());
	glRasterPos3d(0, 0, 0);
	
	if (this->isStroke)
	{
		float const strokeScale = 1.0f / 152.38f;
		glScalef(this->getScale().getX()*strokeScale, this->getScale().getY()*strokeScale, this->getScale().getZ()*strokeScale);
		for (char c : textData)
		{
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, c);
		}
	}
	else
	{
		for (char c : textData)
		{
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
		}
	}
	
	glPopMatrix();

	if (this->isScreenSpace) { glEnable(GL_LIGHTING); }
}