#include <fmt/format.h>
#include <vector>
#include <chrono>
#include <future>

/*
* Below code is inspired by tutorials of Json Turner.
* https://www.youtube.com/watch?v=287_oG4CNMc&t=2s&ab_channel=C%E1%90%A9%E1%90%A9WeeklyWithJasonTurner
*/

struct LifeTime
{
	LifeTime() noexcept 
	{
		fmt::print("Lifetime() [default constructor]\n");
	}

	LifeTime(const LifeTime&) noexcept
	{
		fmt::print("Lifetime(const LifeTime&) [copy constructor]\n");
	}

	LifeTime(LifeTime&&) noexcept
	{
		fmt::print("Lifetime(LifeTime&&) [move constructor]\n");
	}

	~LifeTime() noexcept
	{
		fmt::print("~Lifetime() [destructor]\n");
	}

	LifeTime& operator=(const LifeTime& ) noexcept
	{
		fmt::print("operator=(const LifeTime&) [copy assignment]\n");
		return *this;
	}

	LifeTime& operator=(LifeTime&&) noexcept
	{
		fmt::print("operator=(LifeTime&&) [move assignment]\n");
		return *this;
	}
};

LifeTime f1()
{
	return LifeTime{};
}

LifeTime f2()
{
	return f1();
}

LifeTime f3()
{
	return f2();
}


int main()
{
	LifeTime l = f3();

	return EXIT_SUCCESS;
}


