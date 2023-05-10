#include <fmt/format.h>
#include <typeinfo>


template<typename T>
T fByVal(T val)
{
	return val;
}

template<typename T>
void fByRef(T& val)
{
	// Next two statements will fail if fRef is called with a const param
	//T temp = 1; 
	//temp += 1;
}


template <typename T>
void fPtr(T* val)
{

}

template<typename T, std::size_t N>
constexpr std::size_t arraySize( T (&)[N]) noexcept
{
	return N;
}

const int* get();
const int& getRef();

int main()
{
	int x = 26;
	const int cx = x;
	const int& rx = x;
	const int* pt = &x;

	//Case 1
	{
		auto res1 = fByVal(x);	// paramType int, T type int
		auto res2 = fByVal(cx);	// paramType int, T type int , template deduction ignores const
		auto res3 = fByVal(rx); // paramType int, T type int , template deduction ignores const, ref and volatile
		auto res4 = fByVal(pt);
	}

	//Case 2
	{
		fByRef(x);	//paramType int& , T type int
		fByRef(cx); //paramType const int&, T type const int
		fByRef(rx); //paramType const int&, T type const int
	}
	{
		int x = 26;
		int* xPtr = &x;
		const int* cxPtr = &x;

		fPtr(xPtr);	// paramType int* , T type int
		fPtr(cxPtr);// paramType const int*, T type const int
	}
	int arr[] = { 1,2,3,4,5 };
	
	fByVal(arr);	// paramType int[] or int *, T type int *
	fByRef(arr);	// paramType int (&)[5] , T type int (&)[5]

	const auto valPtr = get();
	const auto valRef = getRef();
	const auto* vPtrptr = get();

	return EXIT_SUCCESS;
}