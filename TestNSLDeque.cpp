#include <gtest/gtest.h>
#include "./NSLDeque.h"

class TestNSLDeque: public testing::Test{
protected:
	void SetUp() override {
		v.clear();
	}

	void TearDown() override {
	}

	NSLDeque<int> v;
};

TEST_F(TestNSLDeque, Constructor) {
}

// test case
// 1: only insert one
// 2: insert 100 element



// test pushfront test req C1 C4
TEST_F(TestNSLDeque, pushfront1_tt) {
	v.push_front(77);
	int val = v.front();
	EXPECT_EQ(val, 77);
	val = v.back();
	EXPECT_EQ(val, 77);
}

TEST_F(TestNSLDeque, pushfront2_tt) {
	for (int i=0;i<100;i++)
		v.push_front(i);
	for (int i=0;i<100;i++)
		EXPECT_EQ(v[i], 99 - i);
}

// test pushback test req C1 C4
TEST_F(TestNSLDeque, pushback1_tt) {
	v.push_back(77);
	int val = v.front();
	EXPECT_EQ(val, 77);
	val = v.back();
	EXPECT_EQ(val, 77);
}

TEST_F(TestNSLDeque, pushback2_tt) {
	for (int i=0;i<100;i++)
		v.push_back(i);
	for (int i=0;i<100;i++)
		EXPECT_EQ(v[i], i);
}
//test pop front req C2 C3 C4
// 1 case 
// TTT
TEST_F(TestNSLDeque, popfront1_ttt) {
	v.push_back(77);
	int val = v.front();
	EXPECT_EQ(val, 77);
	val = v.back();
	EXPECT_EQ(val, 77);
	v.pop_front();
}
//TFT
TEST_F(TestNSLDeque, popfront1_tft) {
	EXPECT_THROW(
		{v.pop_front();},
		std::out_of_range);
}
// 2 case
// TTT
TEST_F(TestNSLDeque, popfront2_ttt) {
	for (int i=0;i<100;i++)
		v.push_front(i);
	for (int i=0;i<100;i++)
	{
		EXPECT_EQ(v.front(), 99 - i);
		v.pop_front();
	}
}
// TFT
TEST_F(TestNSLDeque, popfront2_tft) {
	for (int i=0;i<100;i++)
		v.push_front(i);
	for (int i=0;i<100;i++)
	{
		EXPECT_EQ(v.front(), 99 - i);
		v.pop_front();
	}
	EXPECT_THROW(
		{v.pop_front();},
		std::out_of_range);
}


//test pop back req C2 C3 C4
// 1 case 
// TTT
TEST_F(TestNSLDeque, popback1_ttt) {
	v.push_back(77);
	int val = v.front();
	EXPECT_EQ(val, 77);
	val = v.back();
	EXPECT_EQ(val, 77);
	v.pop_back();
}
//TFT
TEST_F(TestNSLDeque, popback1_tft) {
	EXPECT_THROW(
		{v.pop_back();},
		std::out_of_range);
}
// 2 case
// TTT
TEST_F(TestNSLDeque, popback2_ttt) {
	for (int i=0;i<100;i++)
		v.push_back(i);
	for (int i=0;i<100;i++)
	{
		EXPECT_EQ(v.back(), 99 - i);
		v.pop_back();
	}
}
// TFT
TEST_F(TestNSLDeque, popback2_tft) {
	for (int i=0;i<100;i++)
		v.push_back(i);
	for (int i=0;i<100;i++)
	{
		EXPECT_EQ(v.back(), 99 - i);
		v.pop_back();
	}
	EXPECT_THROW(
		{v.pop_back();},
		std::out_of_range);
}
// insert C1 C3 C4
// 1
TEST_F(TestNSLDeque, insert1_ttt) {
	v.insert(0, 77);
	int val = v.front();
	EXPECT_EQ(val, 77);
	val = v.back();
	EXPECT_EQ(val, 77);
}

TEST_F(TestNSLDeque, insert1_tft) {
	EXPECT_THROW(
		{v.insert(1, 77);},
		std::out_of_range);
}

// 2
TEST_F(TestNSLDeque, insert2_ttt) {
	for (int i=0;i<50;i++)
	{
		v.push_front(i);
		v.insert(0 , 66);
	}
	for (int i=0;i<100;i++)
	{
		EXPECT_EQ(v[i], (i%2)?49-i/2:66);
	}
}

TEST_F(TestNSLDeque, insert2_tft) {
	for (int i=0;i<50;i++)
	{
		v.push_front(i);
		v.insert(0 , 66);
	}
	for (int i=0;i<100;i++)
	{
		EXPECT_EQ(v[i], (i%2)?49-i/2:66);
	}
	EXPECT_THROW(
		{v.insert(101, 77);},
		std::out_of_range);
}

// erase C2 C3 C4
// 1
TEST_F(TestNSLDeque, erase1_ttt) {
	v.push_back(77);
	int val = v.front();
	EXPECT_EQ(val, 77);
	v.erase(0);
}

TEST_F(TestNSLDeque, erase1_tft) {
	EXPECT_THROW(
		{v.erase(0);},
		std::out_of_range);
}
// 2
TEST_F(TestNSLDeque, erase2_ttt) {
	for (int i=0;i<100;i++)
		v.push_back(i);
	v.erase(50);
	for (int i=0;i<99;i++)
	{
		int val = i;
		if(i==50)
		{
			continue;
		}
		else if (val>50)
			val++;
		EXPECT_EQ(v[i], val);
	}
}

TEST_F(TestNSLDeque, erase2_tft) {
	for (int i=0;i<100;i++)
		v.push_back(i);
	v.erase(50);
	for (int i=0;i<99;i++)
	{
		int val = i;
		if(i==50)
		{
			continue;
		}
		else if(i>50)
			val ++;
		EXPECT_EQ(v[i], val);
	}
	for (int i=0;i<99;i++)
		v.pop_back();
	EXPECT_THROW(
		{v.pop_back();},
		std::out_of_range);
}
// test empty
// 1
TEST_F(TestNSLDeque, empty_1_t) {
	EXPECT_TRUE(v.empty());
	v.push_front(5);
	EXPECT_FALSE(v.empty());
}
TEST_F(TestNSLDeque, empty_1_f) {

	v.push_front(5);
	EXPECT_FALSE(v.empty());
	v.pop_front();
	EXPECT_TRUE(v.empty());

}
// 2
TEST_F(TestNSLDeque, empty_2_t) {
	EXPECT_TRUE(v.empty());
	for (int i =0; i<100 ; i++)
	{
		v.push_front(77);
	}
	EXPECT_FALSE(v.empty());
}

TEST_F(TestNSLDeque, empty_2_f) {
	for (int i =0; i<100 ; i++)
		v.push_front(5);
	
	EXPECT_FALSE(v.empty());
	for (int i =0; i<100 ; i++)
		v.pop_front();
	EXPECT_TRUE(v.empty());

}
// clear C2
// 1
TEST_F(TestNSLDeque, clear1_t) {
	v.push_front(5);
	v.clear();
	EXPECT_TRUE(v.empty());
}
// 2
TEST_F(TestNSLDeque, clear2_t) {
	for (int i=0;i<100;i++)
		v.push_front(i);
	v.clear();
	EXPECT_TRUE(v.empty());
}
// front C3 C4
// 1
TEST_F(TestNSLDeque, front1_tt) {
	v.push_front(5);
	EXPECT_EQ(v.front(),5);
	EXPECT_EQ(v.back(),5);
}
TEST_F(TestNSLDeque, front1_ft) {
	EXPECT_THROW(
		{v.front();},
		std::out_of_range);
}
// 2
TEST_F(TestNSLDeque, front2_tt) {
	for (int i=0;i<100;i++)
		v.push_front(i);
	EXPECT_EQ(v.front(), 99);
}
TEST_F(TestNSLDeque, front2_ft) {
	for (int i=0;i<100;i++)
		v.push_front(i);
	for (int i=0;i<100;i++)
		v.pop_back();
	EXPECT_THROW(
		{v.front();},
		std::out_of_range);
}
// back C3 C4
// 1
TEST_F(TestNSLDeque, back1_tt) {
	v.push_back(5);
	EXPECT_EQ(v.front(),5);
	EXPECT_EQ(v.back(),5);
}
TEST_F(TestNSLDeque, back1_ft) {
	EXPECT_THROW(
		{v.back();},
		std::out_of_range);
}
// 2
TEST_F(TestNSLDeque, back2_tt) {
	for (int i=0;i<100;i++)
		v.push_back(i);
	EXPECT_EQ(v.back(), 99);
}
TEST_F(TestNSLDeque, back2_ft) {
	for (int i=0;i<100;i++)
		v.push_back(i);
	for (int i=0;i<100;i++)
		v.pop_back();
	EXPECT_THROW(
		{v.back();},
		std::out_of_range);
}
// size
// 1
TEST_F(TestNSLDeque, size1_t) {
	v.push_front(5);
	EXPECT_EQ(v.size(),1);
}
// 2
TEST_F(TestNSLDeque, size2_t) {
	for (int i=0;i<100;i++)
		v.push_front(i);
	EXPECT_EQ(v.size(),100);
}
// test [] C3C4
// 1
TEST_F(TestNSLDeque, index1_tt) {
	v.push_front(5);
	EXPECT_EQ(v[0], 5);
}
TEST_F(TestNSLDeque, index1_ft) {
	int val;
	EXPECT_THROW(
		{val = v[0];},
		std::out_of_range);
}
// 2
TEST_F(TestNSLDeque, index2_tt) {
	for (int i=0;i<100;i++)
		v.push_front(i);
	for (int i=0;i<100;i++)
		EXPECT_EQ(v[i], 99-i);
}
TEST_F(TestNSLDeque, index2_ft) {
	for (int i=0;i<100;i++)
		v.push_front(i);
	for (int i=0;i<100;i++)
		EXPECT_EQ(v[i], 99-i);
	EXPECT_THROW(
		{v[100];},
		std::out_of_range);
}
// negative test
TEST_F(TestNSLDeque, NegativeIndex) {
	int val;
	EXPECT_THROW(
		{val = v[-1];},
		std::out_of_range);
}
// test insert in different location
TEST_F(TestNSLDeque, TestInsertWithPushFront) {
	for(int i = 0; i < 10000; ++i)
		v.push_front(i);
	
	for(int i = 9999; i >= 0; --i)
		v.insert(i, 66);
	for(int i = 0; i < 20000; ++i)
		if( i%2 == 0)
			EXPECT_EQ(v[i], 66);
		else
			EXPECT_EQ(v[i], 9999-i/2);
}

// test earse in different location
TEST_F(TestNSLDeque, TestErase) {
	for(int i = 0; i < 10000; ++i)
		v.push_front(i);
	
	for(int i = 9999; i >= 0; i-=2)
		v.erase(i);
	for(int i = 0; i < 5000; ++i)
		EXPECT_EQ(v[i], (4999-i)*2+1);
}
// test large push back
TEST_F(TestNSLDeque, TestPush10K) {
	for(int i = 0; i < 10000; ++i)
		v.push_back(i+3);

	for(int i = 0; i < 10000; ++i)
		EXPECT_EQ(v[i], i+3);
}
// PA {front(),back(),push_front(),front(),back()} 
TEST_F(TestNSLDeque, TestPA1) {
	EXPECT_THROW(
		{v.front();},
		std::out_of_range);
	EXPECT_THROW(
		{v.back();},
		std::out_of_range);
	v.push_front(5);
	v.front();
	v.back();
}
// PA {pop_front(),pop_back(),push_front(5) ,push_front(10),pop_front(),pop_back()} 
TEST_F(TestNSLDeque, TestPA2) {
	EXPECT_THROW(
		{v.pop_front();},
		std::out_of_range);
	EXPECT_THROW(
		{v.pop_back();},
		std::out_of_range);
	v.push_front(5);
	v.push_front(10);
	v.pop_front();
	v.pop_back();
}
// PA {insert() (negative index),push_front(),insert()}
TEST_F(TestNSLDeque, TestPA3) {
	EXPECT_THROW(
		{v.insert(-1, 5);},
		std::out_of_range);
	v.push_front(5);
	v.insert(1,-4);
}
// PA {erase() (negative index),,push_front(), erase()}
TEST_F(TestNSLDeque, TestPA4) {
	
	EXPECT_THROW(
		{v.erase(-1);},
		std::out_of_range);
	v.push_front(5);
	v.erase(0);
}
// {push_front(), v[0], empty(),clear(),empty(),v[0], clear()}
TEST_F(TestNSLDeque, TestPA5) {
	v.push_front(5);
	v[0];
	EXPECT_EQ(v.empty(), false);
	v.clear();
	EXPECT_EQ(v.empty(), true);
	int val;
	EXPECT_THROW(
		{val = v[0];},
		std::out_of_range);
	v.clear();
}
// CA {front(),back(),push_front(),front(),back()} 
TEST_F(TestNSLDeque, TestCA1) {
	EXPECT_THROW(
		{v.front();},
		std::out_of_range);
	EXPECT_THROW(
		{v.back();},
		std::out_of_range);
	v.push_front(5);
	v.front();
	v.back();
}
// CA {pop_front(),pop_back(),push_front(5) ,push_front(10),pop_front(),pop_back()} 
TEST_F(TestNSLDeque, TestCA2) {
	EXPECT_THROW(
		{v.pop_front();},
		std::out_of_range);
	EXPECT_THROW(
		{v.pop_back();},
		std::out_of_range);
	v.push_front(5);
	v.push_front(10);
	v.pop_front();
	v.pop_back();
}
// CA {insert() (negative index),push_front(),insert(),insert()}
TEST_F(TestNSLDeque, TestCA3) {
	EXPECT_THROW(
		{v.insert(-1, 5);},
		std::out_of_range);
	v.push_front(5);
	v.insert(1,-4);
	EXPECT_THROW(
		{v.insert(55, 5);},
		std::out_of_range);
}
// CA {erase() (negative index),,push_front(), erase(), erase()}
TEST_F(TestNSLDeque, TestCA4) {
	
	EXPECT_THROW(
		{v.erase(-1);},
		std::out_of_range);
	v.push_front(5);
	v.erase(0);
	EXPECT_THROW(
		{v.erase(66);},
		std::out_of_range);
}
//CA {v[-1], push_front(), v[0], empty(),clear(),empty(),v[0], clear()}
TEST_F(TestNSLDeque, TestCA5) {
	int val;
	EXPECT_THROW(
		{val = v[-1];},
		std::out_of_range);
	v.push_front(5);
	v[0];
	EXPECT_EQ(v.empty(), false);
	v.clear();
	EXPECT_EQ(v.empty(), true);
	EXPECT_THROW(
		{val = v[0];},
		std::out_of_range);
	v.clear();
}
// CACC {front(),back(),push_front(),front(),back()} 
TEST_F(TestNSLDeque, TestCACC1) {
	EXPECT_THROW(
		{v.front();},
		std::out_of_range);
	EXPECT_THROW(
		{v.back();},
		std::out_of_range);
	v.push_front(5);
	v.front();
	v.back();
}
// CACC {pop_front(),pop_back(),push_front(5) ,push_front(10),pop_front(),pop_back()} 
TEST_F(TestNSLDeque, TestCACC2) {
	EXPECT_THROW(
		{v.pop_front();},
		std::out_of_range);
	EXPECT_THROW(
		{v.pop_back();},
		std::out_of_range);
	v.push_front(5);
	v.push_front(10);
	v.pop_front();
	v.pop_back();
}
// CACC {insert() (negative index),push_front(),insert(),insert()}
TEST_F(TestNSLDeque, TestCACC3) {
	EXPECT_THROW(
		{v.insert(-1, 5);},
		std::out_of_range);
	v.push_front(5);
	v.insert(1,-4);
	EXPECT_THROW(
		{v.insert(55, 5);},
		std::out_of_range);
}
// CACC {erase() (negative index),,push_front(), erase(), erase()}
TEST_F(TestNSLDeque, TestCACC4) {
	
	EXPECT_THROW(
		{v.erase(-1);},
		std::out_of_range);
	v.push_front(5);
	v.erase(0);
	EXPECT_THROW(
		{v.erase(66);},
		std::out_of_range);
}
//CACC {v[-1], push_front(), v[0], empty(),clear(),empty(),v[0], clear()}
TEST_F(TestNSLDeque, TestCACC5) {
	int val;
	EXPECT_THROW(
		{val = v[-1];},
		std::out_of_range);
	v.push_front(5);
	v[0];
	EXPECT_EQ(v.empty(), false);
	v.clear();
	EXPECT_EQ(v.empty(), true);
	EXPECT_THROW(
		{val = v[0];},
		std::out_of_range);
	v.clear();
}
