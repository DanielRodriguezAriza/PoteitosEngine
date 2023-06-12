#pragma once
#include "Math.h"

class Color
{
public:
	Color();
	Color(float f);
	Color(float f1, float f2, float f3);
	Color(Color const& other);

	inline void setR(float f) { this->r = Math::clamp(f, 0.f, 1.f); }
	inline void setG(float f) { this->g = Math::clamp(f, 0.f, 1.f); }
	inline void setB(float f) { this->b = Math::clamp(f, 0.f, 1.f); }

	inline float const getR() const { return r; }
	inline float const getG() const { return g; }
	inline float const getB() const { return b; }

	Color &operator=(Color const &other);
	Color operator*(float f);
	Color operator*=(float f);
	Color operator+(Color const &other);

	void clampValues();

private:

	float r,g,b;
};

Color operator*(float f, Color const &c);