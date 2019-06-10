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

