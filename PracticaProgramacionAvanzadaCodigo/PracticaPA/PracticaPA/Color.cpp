#include "Color.h"
#include "Math.h"

//Constructores
Color::Color()
:r{1},g{0},b{0}
{}
Color::Color(float f)
:r{f}, g{f}, b{f}
{
	clampValues();
}
Color::Color(float f1, float f2, float f3)
:r{f1},g{f2},b{f3}
{
	clampValues();
}
Color::Color(Color const& other)
:r{other.r},g{other.g},b{other.b}
{}

//Operadores
Color& Color::operator=(Color const& other)
{
	this->setR(other.getR());
	this->setG(other.getG());
	this->setB(other.getB());
	this->clampValues();
	return *this;
}

Color Color::operator*(float f)
{
	Color ans = { this->getR() * f,this->getG() * f,this->getB() * f };
	ans.clampValues();
	return ans;
}

Color Color::operator*=(float f)
{
	this->setR(this->getR()*f);
	this->setG(this->getG()*f);
	this->setB(this->getB()*f);
	this->clampValues();
	return *this;
}

Color operator*(float f, Color const& c)
{
	Color ans = { c.getR() * f,c.getG() * f,c.getB() * f };
	ans.clampValues();
	return ans;
}

Color Color::operator+(Color const& other)
{
	Color ans = {this->getR()+other.getR(),this->getG()+other.getG(),this->getB()+other.getB()};
	ans.clampValues();
	return ans;
}

//Métodos:
void Color::clampValues()
{
	this->setR(Math::clamp(this->getR(), 0.f, 1.f));
	this->setG(Math::clamp(this->getG(), 0.f, 1.f));
	this->setB(Math::clamp(this->getB(), 0.f, 1.f));
}