// GTestSuit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <gtest/gtest.h>

#include "../Matrix.h"


TEST(Basic, Identity)
{
	auto mat = Matrix::identity(3, 3);

	ASSERT_EQ(1, mat.at(0, 0));
	ASSERT_EQ(1, mat.at(1, 1));
	ASSERT_EQ(1, mat.at(2, 2));
}

TEST(Basic,CopyRow)
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

