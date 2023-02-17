#include <fmt/format.h>
#include <vector>
#include <chrono>
#include <future>



int main()
{
	const char* content =
	#include "sample.txt"
	;
	fmt::print("Hash include {}",content);

}


