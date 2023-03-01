#include <fmt/format.h>
#include <vector>
#include <chrono>
#include <future>


/*
* Compiler warning levels
*  /w  : Supresses all compiler warning
*  /W0 = /w
*  /W1 = Severe warnings
*  /W2 = significant warnings
*  /W3 = production quality warnings
*  /W4 = informational warnings
*  /Wall = displays all warnings
*  /WX = Treats all warnings as errors.
*/

/*
* For a new project, it may be best to use /WX in all compilations; 
resolving all warnings ensures the fewest possible hard-to-find code defects.
*/

/*
* Can be set at Project Properties -> C++ -> General -> Warning Level
*/

class Foo
{
public:
	Foo()
	{

	}

	int test() // This won't give compiler error untill this function was called
	{

	}

};

bool testFun() // Gives compilation error
{

}

int main()
{
	
	//case 1
	{
		Foo f;   // compiles without errors
	}

	//case 2
	{
		//Foo f;   
		//auto res = f.test(); // compilation error
	}

	return EXIT_SUCCESS;
}


