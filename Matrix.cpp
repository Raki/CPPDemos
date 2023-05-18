#include "Matrix.h"

namespace Matrix
{
	Matf::Matf(const size_t rws, const size_t cls):rows(rws),cols(cls)
	{
		data = new float[rws*cls];
	}
	Matf::~Matf()
	{
		if (data != nullptr)
		{
			delete[] data;
		}
	}
	void Matf::copyRow(const size_t rowInd, const std::vector<float>& row)
	{
		if (rowInd > rows-1)
			return;
		auto offset = rowInd * cols;
		memcpy(data + offset, row.data(), sizeof(float)*cols);
	}
	float Matf::at(const size_t& rowInd, const size_t& colInd)
	{
		if(rowInd>rows-1||colInd>cols-1)
			return 0.0f;
		auto offset = (rowInd * cols)+colInd;
		return *(data + offset);
	}
	Matf multiply(Matf* m1, Matf* m2)
	{
		if(m1->cols!=m2->rows)
			return Matf(1, 1);

		const auto m1Len = m1->rows * m1->cols;


	}
	Matf identity(const size_t rws, const size_t cls)
	{
		if (rws * cls == 0)
		{
			Matf mat(1, 1);
			mat.copyRow(0, { 0 });
			return mat;
		}
		else
		{
			Matf mat(rws, cls);
			for (size_t i=0;i<rws;i++)
			{
				std::vector<float> row;
				for (size_t j = 0; j < cls; j++)
				{
					(i == j) ? row.push_back(1) : row.push_back(0);
				}
				mat.copyRow(i, row);
			}
			return mat;
		}
	}
}
