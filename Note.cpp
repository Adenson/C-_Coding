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