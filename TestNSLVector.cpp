#include <gtest/gtest.h>
#include "./NSLVector.h"

TEST(TestNSLVector, Constructor) {
	NSLVector v;
}

TEST(TestNSLVector, PushBackOneInteger) {
	NSLVector v;
	v.pushBack(1);
	EXPECT_EQ(v.size(), 1);
	EXPECT_EQ(v.capacity(), 1);
}

TEST(TestNSLVector, PushBackTwoInteger) {
	NSLVector v;
	v.pushBack(1);
	v.pushBack(2);
	EXPECT_EQ(v.size(), 2);
	EXPECT_EQ(v.capacity(), 2);
}

TEST(TestNSLVector, IndexingOneElement) {
	NSLVector v;
	v.pushBack(77);
	EXPECT_EQ(v[0], 77);
}

TEST(TestNSLVector, IndexingTwoElements) {
	NSLVector v;
	v.pushBack(77);
	v.pushBack(88);
	EXPECT_EQ(v[0], 77);
	EXPECT_EQ(v[1], 88);
}

TEST(TestNSLVector, PushAndGetOneElement) {
	NSLVector v;
	v.pushBack(666);
	EXPECT_EQ(v[0], 666);
}

TEST(TestNSLVector, PushAndGetTenElements) {
	NSLVector v;
	for(int i = 0; i < 10; ++i)
		v.pushBack(i+3);
	for(int i = 0; i < 10; ++i)
		EXPECT_EQ(v[i], i+3);
}

TEST(TestNSLVector, PushAndClear) {
	NSLVector v;
	v.pushBack(4);
	v.pushBack(1);
	v.pushBack(3);
	EXPECT_EQ(v.capacity(), 4);

	v.clear();
	EXPECT_EQ(v.size(), 0);
	EXPECT_EQ(v.capacity(), 4);
}

TEST(TestNSLVector, OutOfRangeExceptionWithNoElement) {
	NSLVector v;
	EXPECT_THROW(
		{v[0] = 1;},
		std::out_of_range);
}

TEST(TestNSLVector, OutOfRangeExceptionWith1KElements) {
	NSLVector v;
	for(int i = 0; i < 1000; ++i)
		v.pushBack(i);
	EXPECT_THROW(
		{v[1000] = 1;},
		std::out_of_range);
}

TEST(TestNSLVector, NegativeIndex) {
	NSLVector v;
	EXPECT_THROW(
		{v[-1] = 9;},
		std::out_of_range);
}

TEST(TestNSLVector, IsEmpty) {
	NSLVector v;
	EXPECT_TRUE(v.empty());
	v.pushBack(1);
	EXPECT_FALSE(v.empty());
	v.clear();
	EXPECT_TRUE(v.empty());
}
