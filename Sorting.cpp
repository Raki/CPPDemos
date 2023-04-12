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


void quicksort(std::vector<int> &data,int fst,int lst)
{
	if (fst < lst)
	{
		int lIndex, rIndex;

		lIndex = fst;
		rIndex = lst;
		auto pivotData = data.at(
			lIndex + (rIndex - lIndex) / 2
		);

		while (lIndex <= rIndex)
		{
			while (data.at(lIndex) < pivotData)
				lIndex++;
			while (data.at(rIndex) > pivotData)
				rIndex--;
			if (lIndex <= rIndex)
			{
				swap<int>(data.at(lIndex), data.at(rIndex));
				lIndex++;
				rIndex--;
			}
		}

		if(fst<rIndex)quicksort(data, fst, rIndex);
		if(lIndex<lst)quicksort(data, lIndex, lst);
	}
}



int main()
{
	auto beginTime = std::chrono::system_clock::now();
	decltype(beginTime) endTime;
	std::vector<int> arr = {8,7,9,4,5,6,2,3,1};
	arr.clear();
	for (auto i = 0; i < 2000000; i++)
	{
		arr.push_back(rand());
	}
	beginTime = std::chrono::system_clock::now();
	quicksort(arr,0,arr.size()-1);
	endTime = std::chrono::system_clock::now();
	fmt::print("qsort took {}ms\n",std::chrono::duration_cast<std::chrono::milliseconds>(endTime - beginTime).count());
	
	return EXIT_SUCCESS;
}


