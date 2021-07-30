#ifndef timer_h
#define timer_h

#include <iostream>
#include <chrono>

class Timer {

private:
	std::chrono::steady_clock::time_point begin;

public:
	Timer();
	void stop(std::string s);
};

Timer::Timer() {
	begin = std::chrono::steady_clock::now();
}

void Timer::stop(std::string s) {
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << s.c_str() << " Time elapsed = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1e6 << std::endl;
}

#endif