#include <gtest/gtest.h>
#include "./myVector.h"

namespace {

TEST(TestMyVector, Constructor) {
	MyVector *v = new MyVector();
	delete v;
}

TEST(TestMyVector, PushBackOneInteger) {
	MyVector *v = new MyVector();
	v->pushBack(1);
	EXPECT_EQ(1, v->size());
	delete v;
}

TEST(TestMyVector, PushBackTwoInteger) {
	MyVector *v = new MyVector();
	v->pushBack(1);
	v->pushBack(2);
	EXPECT_EQ(2, v->size());
	
	delete v;
}

TEST(TestMyVector, IndexingOneElement) {
	MyVector *v = new MyVector();
	v->pushBack(77);
	EXPECT_EQ((*v)[0], 77);
	delete v;
}

TEST(TestMyVector, IndexingTwoElements) {
	MyVector *v = new MyVector();
	v->pushBack(77);
	v->pushBack(88);
	EXPECT_EQ((*v)[0], 77);
	EXPECT_EQ((*v)[1], 88);
	delete v;
}

}
