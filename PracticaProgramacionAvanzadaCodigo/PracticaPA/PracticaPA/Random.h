#pragma once
#include <iostream>

namespace Random
{
	void setSeed(time_t seed);
	
	template<typename T>
	T getRand(T const &min, T const &max)
	{
		if constexpr (std::is_integral<T>::value)
		{
			return min + rand() % (max - min + 1);
		}
		else
		{
			return min + ((float)(rand()) / (float)(RAND_MAX)) * (max - min);
		}
	}


}