#include <fmt/format.h>
#include <vector>
#include <chrono>
#include <future>


class Foo
{
private:
	int val;
public:
	void print() const; // const function
	void wish();
	static void test();
};

void Foo::print() const // can't modify any member of the class
{
	int temp = 4;
	fmt::print("val={}",val);
	//wish();			// can't call non-const member functions
}

void Foo::test()
{
	//wish();			// can't call a non-static member function, (since no this ptr??)
	fmt::print("int test");
}

void Foo::wish()
{
	fmt::print("Hey there");
	fmt::print("this {}", this);
}



int main()
{
	
	
	return EXIT_SUCCESS;
}


