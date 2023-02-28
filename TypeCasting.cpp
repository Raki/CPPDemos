#include <fmt/format.h>
#include <vector>
#include <chrono>
#include <future>


/*
* Types of casts
* 
* 1. static_cast
* 2. reinterpret_cast
* 3. dynamic_cast
* 4. const_cast
* 
*/

int main()
{
	//casting operations can be used when c++ is uncertain implicit casting.

	/*
	* static_cast when used processor needs to invoke some calculations handle the bit representations
	* Ex. int(26) to unsigned float(26.f)
	*/
	struct Base
	{
		int i;
	};

	struct Derived : public Base
	{
		float f;
	};

	int num1 = 26;
	float num2 = static_cast<float>(num1);
	Base b;
	b.i = 0;
	Derived d;
	d.i = 2;

	//case 1
	b = static_cast<Base>(d); //works

	//case 2
	Base b2;
	b2.i = 0;
	Derived d2;
	d2.i = 1;
	//d2 = static_cast<Derived>(b2); //Doesn't compile


	/*
	* reinterpret_cast when used processor does not invoke any calcuations, it simply treats a set of bits in the
	* memory like if it had another type.
	* 
	* reinterpret_cast is not portable due to byte order
	* 
	*/
	//case 3
	Base *b3 = new Base();
	b3->i = 2;
	Derived* d3 = new Derived();
	d3->i = 3;
	d3->f = 4.7f;

	//d3 = b3; //Doesn't compile

	d3 = reinterpret_cast<Derived*>(b3); //Only for the purpose of test, here f of d3 will have undefined value

	//case 4
	uint16_t v = 0x0001;
	uint8_t* ptr = reinterpret_cast<uint8_t*>(&v);
	auto data = *ptr;
	fmt::print("Is big endien {}", data==1);

}


