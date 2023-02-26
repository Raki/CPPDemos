#include <fmt/format.h>
#include <vector>
#include <chrono>
#include <future>


inline bool isPowerof2(uint32_t n)
{
	int res = n & (n-1);
	return (n!=0&&res==0);
}

inline bool haveOppositSigns(int a,int b)
{
	bool res = !((a ^ b) < 0);
	return res;
}

int main()
{
	/*for (uint32_t n = 1; n <= 2000; n++)
	{
		if (isPowerof2(n))
			fmt::print("{} is power of 2\n", n);
	}*/
	
	//fmt::print("0 is power of two {}\n",isPowerof2(0));
	
	fmt::print("{} and {} have same signs : {}",-1,-2,haveOppositSigns(-1,2));
}


