#include <fmt/format.h>
#include <vector>
#include <chrono>
#include <future>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void convertToGrayScale(unsigned char* data, int width ,int height,int nrChannels,int rBegin,int rEnd)
{
	const size_t stride = static_cast<size_t>(width) * static_cast<size_t>(nrChannels);
	for (int h = rBegin; h < rEnd; h++)
	{
		for (int w = 0; w < width; w++)
		{
			size_t offSet = (h * stride) + (static_cast<size_t>(w) * static_cast<size_t>(nrChannels));
			auto pixel = data + offSet;
			auto avg = (pixel[0] + pixel[1] + pixel[2]) / 3;
			pixel[0] = pixel[1] = pixel[2] = avg;
		}
	}
}

int main()
{
	std::string fileName="img/pexels-francesco-ungaro.jpg";
	int width = 0, height, nrChannels;
	unsigned char* data = nullptr;
	auto beginTime = std::chrono::system_clock::now();
	data = stbi_load(fileName.c_str(), &width, &height, &nrChannels, 0);
	auto endTime = std::chrono::system_clock::now();

	fmt::print("Time taken for loading img {} milli sec\n", std::chrono::duration_cast<std::chrono::milliseconds>(endTime - beginTime).count());

	int part = height / 2;
	std::vector<std::future<void>> futures;
	beginTime = std::chrono::system_clock::now();
	for (int p=0;p<height;p+=part)
	{
		auto bgn = p;
		auto end = p + part;
		if (end > height) end = height;
		futures.push_back(std::async(std::launch::async, convertToGrayScale, data, width, height, nrChannels, bgn,end));
	}

	for (size_t i = 0; i < futures.size(); i++)
		futures.at(i).get();
	endTime = std::chrono::system_clock::now();
	fmt::print("Time taken for converting to gray scale {} milli sec\n", 
	std::chrono::duration_cast<std::chrono::milliseconds>(endTime - beginTime).count()); 


	beginTime = std::chrono::system_clock::now();
	stbi_write_jpg("test.jpg", width, height, nrChannels, data, 90);
	endTime = std::chrono::system_clock::now();

	fmt::print("Time taken for saving img {} milli sec\n", std::chrono::duration_cast<std::chrono::milliseconds>(endTime - beginTime).count());
}


