// GTestSuit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <gtest/gtest.h>

#include "../Matrix.h"

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

