#include <fmt/format.h>
#include <mmintrin.h>


int main()
{

	//256 bit argument, ps stands for packed single presion aka float.
	__m256 evens = _mm256_set_ps(2,4,6,8,10,12,14,16);
	__m256 odds = _mm256_set_ps(1,3,5,7,9,11,13,15);

	//compute difference of two vectors with a single operation
	//Format : _mm<bitwidth>_opname_<dataType>

	__m256 result = _mm256_sub_ps(evens, odds);

	//cast the result to float pointer
	float* fRes = (float*)&result;

	for (int i=0;i<8;i++)
	{
		fmt::print("{} ",fRes[i]);
	}

	return EXIT_SUCCESS;
}