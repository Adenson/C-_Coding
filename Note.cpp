#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<algorithm>//find的头文件
#include<vector>
#include<map>
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
/// 类中既有成员变量，又有成员函数
//class A1
//{ 
//public:
//	void f1()
//	{}
//private:
//	int _a;
//};
//
//// 类中仅有成员函数
//class A2
//{
//public:
//	void f2() {}
//};
//
//// 类中什么都没有---空类
//class A3
//{
//
//};
//
//int main()
//{
//	cout << sizeof(A1) << endl;//4
//	cout << sizeof(A2) << endl;//1
//	cout << sizeof(A3) << endl;//1
//	system("pause");
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	//相当于Date(Date* this, int year = 1900, int month = 1, int day = 1);但是我们不能写出来
//	{
//		_year = year;//this->_year = year;
//		_month = month;//this->_month = month;
//		_day = day;//this->_day = day;//在成员函数内部我们是可以写出this指针的。
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2019, 9, 10);
//	//相当于Date d1(&d1,2019,1,1);但是我们不能来传递，即不能写出来。
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
//	/*Time(const Time& t)
//	{
//		cout << "Time(const Time& t)" << endl;
//	}*/
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//};
//
//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//	}
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//	Time(const Time& t)
//	{
//		cout << "Time(const Time& t)" << endl;
//	}
//};
//class Date
//{
//public:
//	Date()
//	{
//		cout << "Date()" << this << endl;
//	}
//	~Date()
//	{
//		cout << "~Date()" << this << endl;
//	}
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(d1);
//	system("pause");
//	return 0;
//}
/class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//
//	 ~String()
//	 {
//		 cout << "~String()" << endl;
//		 free(_str);
//	 }
//private: 
//	char* _str;
//};
//
//int main()
//{
//	String s1("hello");
//	String s2(s1);
//	cout << &s2 << endl << &s1 << endl;
//}

//class Date
//{
//public:
//	void Display()
//	{
//		
//		cout << "Display ()" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl; 
//
//} 
//	void Display() const
//	{ 
//		cout << "Display () const" << endl; 
//		cout << "year:" << _year << endl; 
//		cout << "month:" << _month << endl; 
//		cout << "day:" << _day << endl << endl; 
//	}
//private:
//	int _year = 1990; // 年
//	int _month = 1; // 月  
//	int _day = 1; // 日 
//}; 
//int main()
//{
//	Date d1;
//	d1.Display();
//
//	const Date d2;
//	d2.Display();
//
//	system("pause");
//	return 0;
//}

//class Time
//{
//public:
//	Time(int hour = 0 ,int minute = 0, int second = 0)
//	:_hour(hour)
//	, _minute(minute)
//	, _second(second)
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
//	explicit Date(int year)
//		:_year(year)
//		//, _month(month)
//		//, _day(day)
//	{
//		cout << "Date()" << endl;
//	}
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2018);
//	d1.print();
//
//	Date d2 = 2019;
//	d2.print();
//
//	system("pause");
//	return 0;
//}

//template <typename T>

//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	    x = y;
//	    y = tmp;
//}

//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 100;
//	int b = 200;
//
//	double c = 12.99;
//	double d = 13.98763;
//	//Swap(a, b);
//
//	cout << Add<int>(a, d) << endl;
//
//	/*cout << a << "-" << b << endl;
//	Swap(c, d);
//	cout << c << "-" << d << endl;*/
//	system("pause");
//	return 0;
//}

//int main()
//{
//	string s("string.cpp");
//	/*cout << s.size() << endl;
//	cout << s.length() << endl;
//	cout << s.capacity() << endl;
//
//	s.clear();
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;*/
//
//	//s.resize(10, 'a');
//	//cout << s.size() << endl;
//	//cout << s.capacity() << endl;
//
//	//s.resize(10);
//	//cout << s.size() << endl;
//	//cout << s.capacity() << endl;
//
//	/*s.resize(1);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;*/
//
//	/*s.reserve(111);*/
//	//cout << s.size() << endl;
//	//cout << s.capacity() << endl;
//	//cout << s.c_str() << endl;
//
//	//size_t pos = s.find('.');
//	//string s2 = s.substr(pos, s.size() - pos);
//
//	//cout << suffix << endl;
//
//
//	//cout << *(s.begin()) << endl;
//
//	cout << s.c_str() << endl;
//	system("pause");
//	return 0;
//}

//int main()
//{
//    int a[4][5] = { 0 };
//	cout << sizeof(a) << endl;//80
//	cout << sizeof(&a) << endl;//4
//	cout << sizeof(a + 1) << endl;//4
//	cout << sizeof(&a + 1) << endl;//4
//	cout << sizeof(a[0]) << endl;//20
//	cout << sizeof(a[0] + 1) << endl;//4
//	cout << sizeof(&a[0]) << endl;//4
//	cout << sizeof(&a[0] + 1) << endl;//4
//	system("pause");
//	return 0;
//}
//class Date
//{
//public:
//	Date(int year = 2018)
//	{
//		this->_year = year;
//	}
//	void printf() const
//	{
//		cout << _year << endl;
//	}
//private:
//	int _year;
//};
//int main()
//{
//	const Date d(2018);
//	d.printf();
//	system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest&&src);
//	char* ret = dest;
//	while (*dest = *src)
//	{
//		dest++;
//		src++;
//	}
//	return ret;
//}
//int main()
//{
//	char arr[20] = "hello world";
//	char* str = "change world";
//	printf("%s\n", my_strcpy(arr, str));
//	system("pause");
//	return 0;
//}
