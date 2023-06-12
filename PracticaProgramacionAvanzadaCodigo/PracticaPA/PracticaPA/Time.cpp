#include "Time.h"

double Time::deltaTimeSeconds = 0;

Timer::Timer()
	:startTime{ std::chrono::high_resolution_clock::now() }
{}

void Timer::Restart()
{
	startTime = std::chrono::high_resolution_clock::now();
}

double Timer::getElapsedTime()
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsedTime = currentTime - startTime;
	return elapsedTime.count();
}