#include <fmt/format.h>
#include <vector>
#include <chrono>
#include <future>


void fillArr(std::vector<float> &arr,const size_t offSet,const size_t sze)
{
	for (size_t i = offSet; i < sze; i++)
	{
		arr.at(i) = rand();
	}
}

int main()
{

	std::vector<float> arr1(1000000);
	std::vector<float> arr2(1000000);

	auto beginTime = std::chrono::system_clock::now();

	const size_t sze = arr1.size();
	/*for (size_t i=0;i<sze;i++)
	{
		arr1.at(i) = rand();
		arr2.at(i) = rand();
	}*/
	//std::async();
	auto endTime = std::chrono::system_clock::now();
	fmt::print("Time taken for filling array {} milli sec\n", std::chrono::duration_cast<std::chrono::milliseconds>(endTime - beginTime).count());

}


