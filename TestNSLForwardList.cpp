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

TEST_F(TestNSLForwardList, EraseElement) {
	list.pushFront(34);
	list.pushFront(67);
	list.erase(0);
	EXPECT_EQ(list.front(), 34);
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

TEST_F(TestNSLForwardList, Erase) {
	list.erase(0);
	list.pushFront(23);
	list.pushFront(34);
	list.erase(1);
	EXPECT_FALSE(list.empty());
	EXPECT_EQ(list.front(), 34);
	EXPECT_THROW({
		list.erase(-1);
	}, std::out_of_range);
}

TEST_F(TestNSLForwardList, Clear) {
	list.pushFront(45);
	list.pushFront(67);
	list.clear();
	EXPECT_TRUE(list.empty());
}
