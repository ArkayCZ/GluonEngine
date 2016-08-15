#pragma once

#include <chrono>

class Timer
{
public:
	static unsigned long long int GetCurrentMillis()
	{
		return std::chrono::system_clock::now().time_since_epoch().count() / 10000; 
	}

	static unsigned long long int GetCurrentNano()
	{
		return std::chrono::high_resolution_clock::now().time_since_epoch().count();
	}
};
