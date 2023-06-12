#pragma once
#include <chrono>

class Timer
{
public:

	Timer();

	void Restart();
	double getElapsedTime();

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime;

};

class Time
{
public:
	static double deltaTimeSeconds;
};