#include <fmt/format.h>
#include <vector>
#include <chrono>
#include <future>


template<typename T>
inline void swap(T& v1, T& v2)
{
	auto temp = v1;
	v1 = v2;
	v2 = temp;
}

size_t partitionMidPoint(std::vector<int> &data,int low,int high)
{
	auto pivotData = data.at((low+high)/2);

	while (low<=high)
	{
		while (data.at(low) < pivotData)
			low++;
		while (data.at(high) > pivotData)
			high--;
		if (low <= high)
		{
			swap<int>(data.at(low),data.at(high));
			low++;
			high--;
		}
	}

	return low;
}

void sort(std::vector<int> &data,const std::vector<int>::size_type fst,const std::vector<int>::size_type lst)
{
	if (fst < lst)
	{
		auto pivot = partitionMidPoint(data, fst, lst);
		sort(data, fst, pivot - 1);
		sort(data, pivot + 1,lst);
	}
}

int main()
{
	std::vector<int> arr = {1,7,9,8,5,6,2,3,4};

	sort(arr,0,arr.size()-1);
	
	return EXIT_SUCCESS;
}


