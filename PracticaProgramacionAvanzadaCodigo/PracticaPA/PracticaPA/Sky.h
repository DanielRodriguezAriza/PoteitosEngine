#pragma once
#include "Color.h"
#include "Math.h"

class Sky
{
public:
	Sky();

	static void setSkyColor(Color const& newSkyColor);
	static void lerpSkyColor(Color const& newSkyColor);

private:
	static Color skyColor;
};