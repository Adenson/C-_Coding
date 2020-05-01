#define _CRT_SECURE_NO_WARNINGS 1
#include"BitSet.h"
int main()
{
	//BitSet bit(64);//开的位是范围个位（比如：0,4,64)就需要开64个位
	//bit.set(1);
	//bit.set(33);
	//bit.set(64);
	//cout << bit.test(1) << endl;
	//cout << bit.test(33) << endl;
	//cout << bit.test(64) << endl;

	//bit.reset(1);
	//bit.reset(33);
	//bit.reset(64);
	//cout << bit.test(1) << endl;
	//cout << bit.test(33) << endl;
	//cout << bit.test(64) << endl;


	//如果要解决开40亿个位
	//方法①：BitSet bit(pow(2,32));
	//方法②：用for循环32次
	//方法③：BitSet bit(-1)
	BitSet bit(-1);
	system("pause");
	return 0;
}