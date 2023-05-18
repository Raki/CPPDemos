// GTestSuit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <gtest/gtest.h>

#include "../Matrix.h"

class Interm : public testing::Test
{
protected:
	const size_t ROWS = 5;
	const size_t COLS = 5;

	std::shared_ptr<Matrix::Matf> matIdentity;
	Matrix::Matf* mat1;
	Matrix::Matf* mat2;
	Matrix::Matf* mat3;
	Matrix::Matf* mat10rc_1;
	Matrix::Matf* mat10rc_2;

	void SetUp() override
	{
		matIdentity = Matrix::identity(ROWS, COLS);

		mat1 = new Matrix::Matf(ROWS, COLS);

		mat1->copyRow(0, { 1,2,3,4,5 });
		mat1->copyRow(1, { 6,7,8,9,10 });
		mat1->copyRow(2, { 11,12,13,14,15 });
		mat1->copyRow(3, { 16,17,18,19,20 });
		mat1->copyRow(4, { 21,22,23,24,25 });

		mat2 = new Matrix::Matf(ROWS, COLS);

		mat2->copyRow(0, { 1,2,3,4,5 });
		mat2->copyRow(1, { 6,7,8,9,10 });
		mat2->copyRow(2, { 11,12,13,14,15 });
		mat2->copyRow(3, { 16,17,18,19,20 });
		mat2->copyRow(4, { 21,22,23,24,25 });

		mat3 = new Matrix::Matf(ROWS, COLS);

		mat3->copyRow(0, { 1,2,3,4,5 });
		mat3->copyRow(1, { 6,7,8,9,10 });
		mat3->copyRow(2, { 11,12,13,14,15 });
		mat3->copyRow(3, { 16,17,18,19,20 });
		mat3->copyRow(4, { 21,22,23,24,25 });

		mat10rc_1 = new Matrix::Matf(10, 10);

		for (size_t i=1;i<100;i+=10)
		{
			const auto r = i / 10;
			std::vector<float> row;
			for (size_t j = i; j < i + 10; j++)
				row.push_back(static_cast<float>(j));
			mat10rc_1->copyRow(r,row);
		}

		mat10rc_2 = new Matrix::Matf(10, 10);

		for (size_t i = 1; i < 100; i += 10)
		{
			const auto r = i / 10;
			std::vector<float> row;
			for (size_t j = i; j < i + 10; j++)
				row.push_back(static_cast<float>(j));
			mat10rc_2->copyRow(r, row);
		}
	}

	void TearDown() override
	{
		matIdentity.reset();
		delete mat1;
		delete mat2;
		delete mat3;
		delete mat10rc_1;
		delete mat10rc_2;
	}
};

class Basic : public testing::Test
{
protected:
	const size_t ROWS = 3;
	const size_t COLS = 3;

	std::shared_ptr<Matrix::Matf> matIdentity;
	Matrix::Matf* mat1;
	Matrix::Matf* mat2;
	Matrix::Matf* mat3;

	void SetUp() override
	{
		matIdentity = Matrix::identity(ROWS, COLS);

		mat1 = new Matrix::Matf(ROWS, COLS);

		mat1->copyRow(0, { 1,2,3 });
		mat1->copyRow(1, { 4,5,6 });
		mat1->copyRow(2, { 7,8,9 });

		mat2 = new Matrix::Matf(ROWS, COLS);

		mat2->copyRow(0, { 1,2,3 });
		mat2->copyRow(1, { 4,5,6 });
		mat2->copyRow(2, { 7,8,9 });

		mat3 = new Matrix::Matf(ROWS, COLS);

		mat3->copyRow(0, { 2,3,4 });
		mat3->copyRow(1, { 5,6,7 });
		mat3->copyRow(2, { 8,9,10 });
	}

	void TearDown() override
	{
		matIdentity.reset();
		delete mat1;
		delete mat2;
		delete mat3;
	}
};

TEST_F(Interm, 10RCMul)
{
	auto res = Matrix::multiply(mat10rc_1, mat10rc_2);
	/*
		3355	3410	3465	3520	3575	3630	3685	3740	3795	3850
		7955	8110	8265	8420	8575	8730	8885	9040	9195	9350
		12555	12810	13065	13320	13575	13830	14085	14340	14595	14850
		17155	17510	17865	18220	18575	18930	19285	19640	19995	20350
		21755	22210	22665	23120	23575	24030	24485	24940	25395	25850
		26355	26910	27465	28020	28575	29130	29685	30240	30795	31350
		30955	31610	32265	32920	33575	34230	34885	35540	36195	36850
		35555	36310	37065	37820	38575	39330	40085	40840	41595	42350
		40155	41010	41865	42720	43575	44430	45285	46140	46995	47850
		44755	45710	46665	47620	48575	49530	50485	51440	52395	53350
		*/

	ASSERT_EQ(3355,  res.at(0, 0));
	ASSERT_EQ(8110, res.at(1, 1));
	ASSERT_EQ(13065, res.at(2, 2));
	ASSERT_EQ(18220, res.at(3, 3));
	ASSERT_EQ(23575, res.at(4, 4));
	ASSERT_EQ(29130, res.at(5, 5));
	ASSERT_EQ(34885, res.at(6, 6));
	ASSERT_EQ(40840, res.at(7, 7));
	ASSERT_EQ(46995, res.at(8, 8));
	ASSERT_EQ(53350,res.at(9, 9));
}

TEST_F(Interm, 10RCCheck)
{
	ASSERT_EQ(1,  mat10rc_1->at(0, 0));
	ASSERT_EQ(12,  mat10rc_1->at(1, 1));
	ASSERT_EQ(23,  mat10rc_1->at(2, 2));
	ASSERT_EQ(34, mat10rc_1->at(3, 3));
	ASSERT_EQ(45, mat10rc_1->at(4, 4));
	ASSERT_EQ(56, mat10rc_1->at(5, 5));
	ASSERT_EQ(67, mat10rc_1->at(6, 6));
	ASSERT_EQ(78, mat10rc_1->at(7, 7));
	ASSERT_EQ(89, mat10rc_1->at(8, 8));
	ASSERT_EQ(100, mat10rc_1->at(9,9));
}

TEST_F(Interm, Mul_Normal)
{
	/*
	215	230	245	260	275
	490	530	570	610	650
	765	830	895	960	1025
	1040 1130 1220 1310	1400
	1315 1430 1545 1660 1775
	*/
	auto mat = Matrix::multiply(mat1, mat2);

	ASSERT_EQ(215, mat.at(0, 0));
	ASSERT_EQ(530, mat.at(1, 1));
	ASSERT_EQ(895, mat.at(2, 2));
	ASSERT_EQ(1310, mat.at(3, 3));
	ASSERT_EQ(1775, mat.at(4, 4));
}

TEST_F(Interm, Mul_Identity)
{
	auto mat = Matrix::multiply(mat1, matIdentity.get());

	ASSERT_EQ(1, mat.at(0, 0));
	ASSERT_EQ(7, mat.at(1, 1));
	ASSERT_EQ(13, mat.at(2, 2));
	ASSERT_EQ(19, mat.at(3, 3));
	ASSERT_EQ(25, mat.at(4, 4));
}

TEST_F(Interm, Identity)
{
	ASSERT_EQ(1, matIdentity->at(0, 0));
	ASSERT_EQ(1, matIdentity->at(1, 1));
	ASSERT_EQ(1, matIdentity->at(2, 2));
	ASSERT_EQ(1, matIdentity->at(3, 3));
	ASSERT_EQ(1, matIdentity->at(4, 4));
}

TEST_F(Basic, Mul_Normal2)
{
	/*
	36 42 48
	81 96 111
	126 150 174
	*/
	auto mat = Matrix::multiply(mat1, mat3);

	ASSERT_EQ(36, mat.at(0, 0));
	ASSERT_EQ(96, mat.at(1, 1));
	ASSERT_EQ(174, mat.at(2, 2));
}

TEST_F(Basic, Mul_Normal)
{
	/*
	30 36 42
	66 81 96
	102 126 150
	*/
	auto mat = Matrix::multiply(mat1, mat2);

	ASSERT_EQ(30, mat.at(0, 0));
	ASSERT_EQ(81, mat.at(1, 1));
	ASSERT_EQ(150, mat.at(2, 2));
}

TEST_F(Basic, Mul_Identity)
{
	auto mat = Matrix::multiply(mat1, matIdentity.get());

	ASSERT_EQ(1, mat.at(0, 0));
	ASSERT_EQ(5, mat.at(1, 1));
	ASSERT_EQ(9, mat.at(2, 2));
}

TEST_F(Basic, Identity)
{
	auto mat = Matrix::identity(3, 3);

	ASSERT_EQ(1, mat->at(0, 0));
	ASSERT_EQ(1, mat->at(1, 1));
	ASSERT_EQ(1, mat->at(2, 2));
}

TEST_F(Basic,CopyRow)
{
	Matrix::Matf mat(3,3);

	mat.copyRow(0, { 1,2,3 });

	ASSERT_EQ(1, mat.at(0, 0));
}

int main()
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}

