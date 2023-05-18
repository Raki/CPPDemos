#include "Matrix.h"

namespace Matrix
{
	Matf::Matf(const size_t rws, const size_t cls):rows(rws),cols(cls)
	{
		data = new float[rws*cls];
	}
	Matf::Matf(const Matf& mat)
	{
		rows = mat.rows;
		cols = mat.cols;
		data = new float[rows * cols];
		memcpy(data,mat.data,sizeof(float)*rows*cols);
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

		Matf res(m1->rows,m2->cols);

		const auto m1Len = m1->rows * m1->cols;
		const auto m2Len = m2->rows * m2->cols;

		//re-arrange memory of m2 matrix for faster multiplcation
		std::vector<std::vector<float>> m2Rearr(m2->rows);
		for (size_t r = 0; r < m2->rows; r++)
		{
			auto rOffset = r * m2->cols;
			for (size_t c = 0; c < m2->cols; c++)
			{
				m2Rearr.at(c).push_back(*(m2->data + rOffset + c));
			}
		}

		float* m2Data = nullptr;
		std::vector<float> combinedArr;
		
		for (const auto& arr : m2Rearr)
		{
			combinedArr.insert(combinedArr.end(), arr.begin(), arr.end());
		}
		m2Data = combinedArr.data();

		//matrix multiplication
		for (size_t m1r=0;m1r<m1Len;m1r +=m1->cols)
		{
			std::vector<float> row;
			for (size_t m2r = 0; m2r < m2Len; m2r += m2->cols)
			{
				float sum = 0;
				//ToDo : use vector intrinsics to optimize below loop
				//element wise mutiplication between m1 row and m2 colum
				for (size_t i = m1r,j=m2r; i < m1r + m1->cols; i++,j++)
				{
					auto v1 = *(m1->data + i);
					auto v2 = *(m2Data + j);
					sum += v1*v2;
				}
				row.push_back(sum);
			}
			res.copyRow(m1r / m1->cols, row);
		}

		return res;
	}
	std::shared_ptr<Matf> identity(const size_t rws, const size_t cls)
	{
		if (rws * cls == 0)
		{
			auto mat=std::make_shared<Matf>(1, 1);
			mat->copyRow(0, { 0 });
			return mat;
		}
		else
		{
			auto mat = std::make_shared<Matf>(rws, cls);
			for (size_t i=0;i<rws;i++)
			{
				std::vector<float> row;
				for (size_t j = 0; j < cls; j++)
				{
					(i == j) ? row.push_back(1) : row.push_back(0);
				}
				mat->copyRow(i, row);
			}
			return mat;
		}
	}
}
