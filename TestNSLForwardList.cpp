#include <gtest/gtest.h>
#include "./NSLForwardList.h"

class TestNSLForwardList: public testing::Test{
protected:
	void SetUp() override {
		list.clear();
	}

	void TearDown() override {
	}

	NSLForwardList<int> list;
};

TEST_F(TestNSLForwardList, Constructor) {
}

TEST_F(TestNSLForwardList, PushFrontWorks) {
	list.pushFront(34);
	list.pushFront(67);
	EXPECT_EQ(list.front(), 67);
}

TEST_F(TestNSLForwardList, PopFront) {
	list.pushFront(34);
	list.pushFront(67);
	EXPECT_EQ(list.popFront(), 67);
	EXPECT_EQ(list.front(), 34);
}

TEST_F(TestNSLForwardList, IsEmpty) {
	EXPECT_TRUE(list.empty());
	list.pushFront(89);
	EXPECT_FALSE(list.empty());
	list.popFront();
	EXPECT_TRUE(list.empty());
}
