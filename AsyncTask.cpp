#include <fmt/format.h>
#include <vector>
#include <chrono>
#include <future>



void fillArr(std::vector<float> &arr,size_t offSet,size_t sze)
{
	for (size_t i = offSet; i < sze; i++)
	{
		arr.at(i) = rand();
	}
}
void foo(std::vector<int> &arr)
{

}
bool is_prime(int x) {
	fmt::print("Calculating. Please, wait...\n");
	for (int i = 2; i < x; ++i) if (x % i == 0) return false;
	return true;
}

int main()
{

	std::vector<float> arr1(1000000);
	std::vector<float> arr2(1000000);
	

	auto beginTime = std::chrono::system_clock::now();

	const size_t sze = arr1.size();
	for (size_t i=0;i<sze;i++)
	{
		arr1.at(i) = rand();
		arr2.at(i) = rand();
	}
	auto endTime = std::chrono::system_clock::now();
	fmt::print("Time taken for filling array sequentially {} milli sec\n", std::chrono::duration_cast<std::chrono::milliseconds>(endTime - beginTime).count());

	beginTime = std::chrono::system_clock::now();
	auto part1 = std::async(std::launch::deferred,fillArr, std::ref(arr1),static_cast<size_t>(0), static_cast<size_t>(1000000));
	auto part2 = std::async(std::launch::deferred,fillArr, std::ref(arr2),static_cast<size_t>(0), static_cast<size_t>(1000000));
	part1.get();
	part2.get();
	endTime = std::chrono::system_clock::now();
	fmt::print("Time taken for filling array parallelly {} milli sec\n", std::chrono::duration_cast<std::chrono::milliseconds>(endTime - beginTime).count());

}


