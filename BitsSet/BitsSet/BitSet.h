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
		_bit.resize((bitCount >> 5) + 1, 0);//�࿪һ���ռ䣬��ֹ���Ǳ�����ʱ�򶪵�һЩֵ���磺33 100
	}

	void set(const size_t& num)
	{
		//index��ʾ���ĸ��ֽڣ�pos��ʾ���ֽڵĵڼ�λ
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