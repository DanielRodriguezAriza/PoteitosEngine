#include "Sky.h"
#include "GL/glut.h"
#include "Time.h"
#include <iostream>

Color Sky::skyColor = {0,0,0.2};

Sky::Sky()
{}

void Sky::setSkyColor(Color const& newSkyColor)
{
	Sky::skyColor = newSkyColor;
	glClearColor(newSkyColor.getR(), newSkyColor.getG(), newSkyColor.getB(), 1);
}

void Sky::lerpSkyColor(Color const& newSkyColor)
{
	Color ans = Math::lerp<Color>(Sky::skyColor,newSkyColor, Math::clamp<float>(Time::deltaTimeSeconds * 0.1,0,1));
	setSkyColor(ans);
}