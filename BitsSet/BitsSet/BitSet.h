#pragma once
using namespace std;
#include<iostream>
#include<vector>
class BitSet
{
public:
	BitSet(const size_t& bitCount)
		:_bitCount(bitCount)
	{
		_bit.resize((bitCount >> 5) + 1, 0);//多开一个空间，防止不是倍数的时候丢掉一些值比如：33 100
	}

	void set(const size_t& num)
	{
		//index表示在哪个字节；pos表示在字节的第几位
		size_t index = num >> 5;
		size_t pos = num % 32;
		_bit[index] |= (1 << pos);
	}

	void reset(const size_t& num)
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		_bit[index] &= ~(1 << pos);
	}

	bool test(const size_t& num)
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		return _bit[index] & (1 << pos);
	}
private:
	vector<int> _bit;
	size_t _bitCount;
};