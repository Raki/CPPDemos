#include <fmt/format.h>
#include <vector>
#include <chrono>
#include <future>


int main()
{
	for (uint32_t n = 1; n <= 2000; n++)
	{
		int res = n & (n-1);

		if (res == 0)
			fmt::print("{} is power of 2\n", n);
	}
	
}


