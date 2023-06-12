#pragma once
#include <cmath>

namespace Math
{
	template<typename T = float>
	T clamp(T const& elem, T const& min, T const& max)
	{
		T ans = elem;
		ans = ans < min ? min : ans;
		ans = ans > max ? max : ans;
		return ans;
	}

	template<typename T = float>
	T lerp(T const& a, T const& b, float const& t)
	{
		return (1 - t) * a + t * b;
	}


}