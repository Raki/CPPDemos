#pragma once
#include <vector>
namespace Matrix
{
	struct Matf
	{
		/// <summary>
		/// Creates new Matrix
		/// </summary>
		/// <param name="rws" type="size_t"> rows </param>
		/// <param name="cls"> columns </param>
		Matf(const size_t rws,const size_t cls);
		~Matf();
		/// <summary>
		/// copies data to given rowIndex
		/// </summary>
		/// <param name="rowInd"> Index of the row </param>
		/// <param name="rowData"> Data of the row</param>
		void copyRow(const size_t rowInd,const std::vector<float>& rowData);
		/// <summary>
		/// Returns value at (rowInd,colInd)
		/// </summary>
		/// <param name="rowInd"> Row Index </param>
		/// <param name="colInd"> Column Index </param>
		/// <returns>float element</returns>
		float at(const size_t &rowInd, const size_t &colInd);
		size_t rows;
		size_t cols;
		float* data=nullptr;
	};

	/// <summary>
	/// Multiplies given matrices
	/// </summary>
	/// <param name="m1" type="Matrix"> Matrix 1</param>
	/// <param name="m2"> Matrix 2</param>
	/// <returns> Matf </returns>
	Matf multiply(Matf *m1,Matf *m2);

	Matf identity(const size_t rws, const size_t cls);
}