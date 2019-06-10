#include <gtest/gtest.h>
#include "./NSLVector.h"

class TestNSLVector: public testing::Test{
protected:
	void SetUp() override {
		v.clear();
	}

	void TearDown() override {
	}

	NSLVector<int> v;
};

TEST_F(TestNSLVector, Constructor) {
}

TEST_F(TestNSLVector, PushBackOneInteger) {
	v.pushBack(1);
	EXPECT_EQ(v.size(), 1);
	EXPECT_EQ(v.capacity(), 1);
}

TEST_F(TestNSLVector, PushBackTwoInteger) {
	v.pushBack(1);
	v.pushBack(2);
	EXPECT_EQ(v.size(), 2);
	EXPECT_EQ(v.capacity(), 2);
}

TEST_F(TestNSLVector, IndexingOneElement) {
	v.pushBack(77);
	EXPECT_EQ(v[0], 77);
}

TEST_F(TestNSLVector, IndexingTwoElements) {
	v.pushBack(77);
	v.pushBack(88);
	EXPECT_EQ(v[0], 77);
	EXPECT_EQ(v[1], 88);
}

TEST_F(TestNSLVector, PushAndGetOneElement) {
	v.pushBack(666);
	EXPECT_EQ(v[0], 666);
}

TEST_F(TestNSLVector, PushAndGetTenElements) {
	for(int i = 0; i < 10; ++i)
		v.pushBack(i+3);
	for(int i = 0; i < 10; ++i)
		EXPECT_EQ(v[i], i+3);
}

TEST_F(TestNSLVector, PushAndClear) {
	v.pushBack(4);
	v.pushBack(1);
	v.pushBack(3);
	EXPECT_EQ(v.capacity(), 4);

	v.clear();
	EXPECT_EQ(v.size(), 0);
	EXPECT_EQ(v.capacity(), 4);
}

TEST_F(TestNSLVector, OutOfRangeExceptionWithNoElement) {
	EXPECT_THROW(
		{v[0] = 1;},
		std::out_of_range);
}

TEST_F(TestNSLVector, OutOfRangeExceptionWith1KElements) {
	for(int i = 0; i < 1000; ++i)
		v.pushBack(i);
	EXPECT_THROW(
		{v[1000] = 1;},
		std::out_of_range);
}

TEST_F(TestNSLVector, NegativeIndex) {
	EXPECT_THROW(
		{v[-1] = 9;},
		std::out_of_range);
}

TEST_F(TestNSLVector, IsEmpty) {
	EXPECT_TRUE(v.empty());
	v.pushBack(1);
	EXPECT_FALSE(v.empty());
	v.clear();
	EXPECT_TRUE(v.empty());
}

TEST_F(TestNSLVector, TestPush10M) {
	for(int i = 0; i < 10000000; ++i)
		v.pushBack(i+3);
}
