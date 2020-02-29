#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<algorithm>//find的头文件
#include<vector>
#include<string>
//
////1. 普通的命名空间
//  namespace N1// N1为命名空间的名称
// { 
//	// 命名空间中的内容，既可以定义变量，也可以定义函数
//	int a;
//	int Add(int left, int right)
//	{ 
//		return left + right; 
//	}
// }
//
////2.嵌套命名
//  namespace N2
//  {
//	  int a;
//	  int Add(int left, int right)
//	  {
//		  return left + right;
//	  }
//	  namespace N3
//	  {
//		  int b = 5;
//		  int sub(int left, int right)
//		  {
//			  return left - right;
//		  }
//	  }
//  }
//  //3. 同一个工程中允许存在多个相同名称的命名空间 
//  //   编译器后会合成同一个命名空间中。 
//  namespace N1
//  {
//	  int Mul(int left, int right)
//	  {
//		  return left * right; 
//	  }
//  }
//  using N2::N3::sub;
//  int main()
//  {
//	  printf("%d\n",sub(5, 3));
//	  printf("%d\n", N1::Mul(8 , 8));
//	  system("pause");
//	  return 0;
//  }
//
//int main()
//{
//	cout << "Hello world!!!" << endl; 
//	return 0;
//}
//int x = 100;
//int h = 200;
//void TestFunc(int a = h, int b = x, int c = 30)//3. 缺省值必须是常量或者全局变量
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//int main()
//{
//	TestFunc();
//	system("pause");
//	return 0;
//}

////a.h
//void TestFunc(int a = 10);
//
////a.c
//void TestFunc(int a = 20)
//{
//
//}
//// 注意：如果生命与定义位置同时出现，恰巧两个位置提供的值不同，那编译器就无法确定到底该用那个缺省值。 

//int Add(int left, int right)
//{
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	return left + right;
//}
//
//long Add(long left, long right)
//{
//	return left + right;
//}
//
//int main()
//{
//	Add(10, 20); Add(10.0, 20.0); Add(10L, 20L);
//	return;
//}

//extern "C"int Add(double left, double right);
//int main()
//{
//	cout << Add(5, 6) << endl;
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int& b = a;
//	cout << a << endl << b << endl;
//	cout << &a << endl << &b << endl;
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	//int &ra;//这句代码是错误的
//	int& pa = a;
//	int& ppa = a;
//	system("pause");
//	return 0;
//}


//void TestConstRef()
//{
//	const int a = 10;
//	//int& ra = a;   // 该语句编译时会出错，a为常量
//	const int& ra = a;//因为 a 是只读的，所以 ra 也只能变为只读
//
//	// int& b = 10; // 该语句编译时会出错，b为常量
//	const int& b = 10;
//
//	double d = 12.34;
//	//int& rd = d; // 该语句编译时会出错，类型不同
//	const int& rd = d;//

//void Swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
//int main()
//{
//	int a = 20;
//	int b = 10;
//	Swap(a, b);
//	cout << a << endl << b << endl;
//	//输出为 10 ，20，可以看出已经交换 a 和 b 的值
//	system("pause");
//	return 0;
//}

//int& TestRefReturn(int& pa)
//{
//	pa += 3;
//	return pa;
//}
//int main( )
//{
//	int a = 10;
//	int& ret = TestRefReturn(a);
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;//思考为什么输出为 7 ?
//	system("pause");
//	return 0;
//}

//#include <time.h>
//struct A
//{
//	int a[10000];
//};
//void TestFunc1(A a)
//{}
//void TestFunc2(A& a)
//{}
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//	{
//		TestFunc1(a);
//	}
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//	{
//		TestFunc2(a);
//	}
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
//}
//// 运行多次，检测值和引用在传参方面的效率区别
//int main()
//{
//	for (int i = 0; i < 10; ++i)
//	{
//		TestRefAndValue();
//	}
//	system("pause");
//	return 0;
//}
//

//#include <time.h>
//struct A
//{
//	int a[10000];
//};
//A a;
//A TestFunc1()
//{
//	return a;
//}
//A& TestFunc2()
//{
//	return a;
//}
//void TestReturnByRefOrValue()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//	{
//    	TestFunc1();
//	}
//	size_t end1 = clock();
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//	{
//      TestFunc2();
//	}
//	size_t end2 = clock();
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//// 测试运行10次，值和引用作为返回值效率方面的区别
//int main()
//{
//	for (int i = 0; i < 10; ++i)
//	TestReturnByRefOrValue();
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	int a = 10;
//
//	int& ra = a;
//	ra = 20;
//
//	int* pa = &a;
//	*pa = 20;
//
//	system("pause");
//	return 0;
//}
//int Add(int a, int b)
//{
//	return a + b;
//}
//int main()
//{
//	int ret = 0;
//	ret = Add(5, 8);
//	system("pause");
//	return 0;
//}
//int TestAuto()
//{ 
//	return 10; 
//}
//
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = &a;
//	auto d = 'a';
//	auto e = TestAuto();
//	cout << typeid(b).name() << endl;//输出为 int
//	cout << typeid(c).name() << endl;//输出为 int*
//	cout << typeid(d).name() << endl;//输出为 char
//	cout << typeid(e).name() << endl;//输出为 int
//
//	//auto f; 无法通过编译，使用auto定义变量时必须对其进行初始化
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	//a 和 b 都是 x 地址
//	//用auto声明指针类型时,用 auto 和 auto* 没有任何区别
//	auto& c = x;
//	//但用auto声明引用类型时则必须加 &
//	cout << typeid(a).name() << endl;//输出为 int*
//	cout << typeid(b).name() << endl;//输出为 int* 
//	cout << typeid(c).name() << endl;//输出为 int
//
//	*a = 20;
//	cout << x << endl;//输出为 20
//
//	*b = 30;
//	cout << x << endl;//输出为 30
//
//	 c = 40;
//	cout << x << endl;//输出为 40
//	system("pause");
//	return 0;
//}

//void TestAuto()
//{
//	auto a = 1, b = 2;
//	auto c = 3, d = 4.0;
//    //该行代码会编译失败，因为c和d的初始化表达式类型不同
//} 

// 此处代码编译失败，auto不能作为形参类型，因为编译器无法对a的实际类型进行推导 
//void TestAuto(auto a)
//{
//
//}

//void TestAuto()
//{
//	int a[] = { 1, 2, 3 };
//	auto b[] = { 4，5，6 }; //错误，auto 不能用来定义数组
//}

//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//
//	for (auto& e : array)
//	cout << e << " ";
//
//	for (int e : array)
//	cout << e << " ";
//}
//int main()
//{
//	TestFor();
//	system("pause");
//	return 0;
//}
//void f1(int*)
//{
//	cout << "f(int*)" << endl;
//}
//void f1(int x)
//{
//	cout << "f(int)" << endl;
//}
//int main()
//{
//	f1(NULL);
//
//	f1((int*)NULL);
//
//	f1(0);
//	system("pause");
//	return 0;
//}

//class className
//{ 
//	// 类体：由成员函数和成员变量组成
//}; // 一定要注意后面的分号


//class Person
//{
//public:
//	void Init(int height,int age)
//	{
//		_height = height;
//		_age = age;
//	}
//	void ShowInfo()
//	{
//		cout << _height << "-" << _age << endl;
//	}
//public:
//	int _height;
//	int _age;
//};
////void Person::ShowInfo()
////{
////	cout << _height << "-" << _age << endl;
////}
//int main()
//{
//	Person a;
//	a.Init(1, 2);
//	a.ShowInfo();
//	system("pause");
//	return 0;
//}
//class string
//{
//public:
//	string(const char* str = "jack") 
//	{ 
//		_str = (char*)malloc(strlen(str) + 1); 
//		strcpy(_str, str);
//	}
//
//	~string()
//	{
//		cout << "~string()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
//class Person
//{ 
//private:
//	string _name;
//	int    _age;
//};
//int main()
//{
//	Person p;
//	system("pause");
//	return 0;
//}


//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void print()
//	{
//		cout << _year << '-' << _month << '-' << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	Date d2;
//	d1.print();
//	d2.print();
//	system("pause");
//	return 0;
//}