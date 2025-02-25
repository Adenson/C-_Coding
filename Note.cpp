#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<algorithm>
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


#include<iostream>
#include<queue>
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#define MAX_NUM 10
class BlockQueue
{
private:
    std::queue<int> _queue;
    int _capacity;
    pthread_cond_t _cond_pro;
    pthread_cond_t _cond_con;
    pthread_mutex_t mutex;
public:
    BlockQueue(int que_Maxcapacity)
      :_capacity(que_Maxcapacity)
    {
      pthread_mutex_init(&mutex,NULL);
      pthread_cond_init(&_cond_pro,NULL);
      pthread_cond_init(&_cond_con,NULL);
    }

    ~BlockQueue()
    {
      pthread_mutex_destroy(&mutex);
      pthread_cond_destroy(&_cond_pro);
      pthread_cond_destroy(&_cond_con);
    }
    
    //提供给生产者的接口（数据入队）
    bool queuePush(int& data)
    {
      //queue是一个临界资源所以需要加锁保护
      pthread_mutex_lock(&mutex);
      //判断队列是否添加满了
      while(_queue.size() == _capacity)
      {
        pthread_cond_wait(&_cond_pro,&mutex);
      }
      _queue.push(data);
      pthread_mutex_unlock(&mutex);
      pthread_cond_signal(&_cond_con);
      return true;
    }
    //提供给消费者的接口（数据出队）
    bool queuePop(int& data)
    {
      pthread_mutex_lock(&mutex);
      //判断队列是否为空
      while(_queue.empty()){
        pthread_cond_wait(&_cond_con,&mutex);
      }
      data = _queue.front();
      _queue.pop();
      pthread_mutex_unlock(&mutex);
      pthread_cond_signal(&_cond_pro);
      return true;
    }
};

void* pro_thr(void* arg)
{
  int i = 0;
  BlockQueue* queue = (BlockQueue*)arg;
  while(1){
    queue->queuePush(i);
    printf("pro_thr push %d\n",i++);
  }
  return NULL;
}

void* con_thr(void* arg)
{
  BlockQueue* queue = (BlockQueue*)arg;
  while(1){
    int data;
    queue->queuePop(data);
    printf("con_thr get %d\n",data);
  }
  return NULL;
}

#define MAX_THR 5
int main()
{
  BlockQueue queue(MAX_NUM);
  pthread_t pro_tid[MAX_THR];
  pthread_t con_tid[MAX_THR];
  int i = 0;
  int ret = 0;

  for(i = 0 ; i < MAX_THR; i++)
  {
    pthread_create(&pro_tid[i],NULL,pro_thr,(void*)&queue);
    if(ret != 0)
    {
      std::cerr << "pthread_create pro_thr error\n";
      return -1;
    }
  }

  for(i = 0; i < MAX_THR; i++)
  {
    pthread_create(&con_tid[i],NULL,con_thr,(void*)&queue);
    if(ret != 0)
    {
      std::cerr << "pthread_create pro_thr error\n";
      return -1;
    }
  }

  for(i = 0; i < MAX_THR; i++)
  {
    pthread_join(pro_tid[i],NULL);
    pthread_join(con_tid[i],NULL);
  }
  return 0;
}


#include<iostream>
using namespace std;
#include<vector>
#include<pthread.h>
#include<stdio.h>
#include <semaphore.h>
#include<unistd.h>
#define MAX_THR 5
#define MAX_queue 10
class RingQueue
{
  private:
    vector<int> _queue;
    int _capacity;
    int _write_step;
    int _read_step;
    sem_t _sem_lock;
    sem_t _sem_pro;
    sem_t _sem_con;
  public:
    RingQueue(int max_queue)
       :_queue(max_queue)
       ,_capacity(max_queue)
       ,_write_step(0)
       ,_read_step(0)
  {
    sem_init(&_sem_lock,0,1);
    sem_init(&_sem_pro,0,max_queue);
    sem_init(&_sem_con,0,0);
  }

    ~RingQueue()
    {
      sem_destroy(&_sem_lock);
      sem_destroy(&_sem_pro);
      sem_destroy(&_sem_con);
    }

    bool Push(int data)
    {
      sem_wait(&_sem_pro);

      sem_wait(&_sem_lock);
      _queue[_write_step] = data;
      _write_step = (_write_step + 1) % _capacity;
      sem_post(&_sem_lock);

      sem_post(&_sem_con);
      return true;
    }

    bool Pop(int& data)
    {
      sem_wait(&_sem_con);

      sem_wait(&_sem_lock);
      data = _queue[_read_step];
      _read_step = (_read_step + 1) % _capacity;
      sem_post(&_sem_lock);

      sem_post(&_sem_pro);
      return true;
    }
};

int num = 0;
void* pro_thr(void* argc)
{
  RingQueue* queue = (RingQueue*)argc;
  while(1)
  {
    queue->Push(num);
    printf("pro push a data --- %d\n",num++);
    sleep(1);
  }
}

void* con_thr(void* argc)
{
  RingQueue* queue = (RingQueue*)argc;
  while(1)
  {
    int data = 0;
    queue->Pop(data);
    printf("con get a data --- %d\n",data);
  }
}
int main()
{
  pthread_t pro_tid[MAX_THR];
  pthread_t con_tid[MAX_THR];
  RingQueue queue(10);
  for(int i = 0; i < MAX_THR; i++)
  {
    int ret = pthread_create(&pro_tid[i],NULL,pro_thr,(void*)&queue);
    if(ret != 0)
    {
      cerr << "pro_thr create error\n";
      return 0;
    }
  }
  for(int i = 0; i < MAX_THR; i++)
  {
    int ret = pthread_create(&con_tid[i],NULL,con_thr,(void*)&queue);
    if(ret != 0)
    {
      cerr << "con_thr create error\n";
      return 0;
    }
  }
  for(int i = 0; i < MAX_THR; i++)
  {
    pthread_join(pro_tid[i],NULL);
    pthread_join(con_tid[i],NULL);
  }
  return 0;
}

class Solution {
public:
    int minCount(vector<int>& coins) 
    {
        int counts = 0;
        for(int i = 0; i < coins.size(); i++)
        {
            counts += coins[i] % 2 == 0 ? coins[i] / 2 :coins[i] / 2 + 1;
        }
        return counts;
    }
};

int main()
{
	string str[] = { "香蕉", "苹果", "橘子", "香蕉" };
	map<string, int> countMap;

	//for (auto& e : str)
	//{
	//	map<string, int>::iterator it = countMap.find(e);
	//	if (it != countMap.end())
	//	{
	//		it->second++;
	//	}
	//	else{
	//		countMap.insert(pair<string, int>(e, 1));
	//	}
	//}

	//for (auto e : str)
	//{
	//	pair<map<string, int>::iterator, bool> ret = countMap.insert(pair<string, int>(e, 1));

	//	//make_pair()是一个函数模板，被设置成为内敛函数，可以方便我们使用的时候不用说明类型
	//	/*template<class K,class V>
	//	inline make_pair<const K& k,const V& v)
	//	{
	//		return pair<K, V>(k, v);
	//	}*/
	//	auto ret = countMap.insert(make_pair(e, 1));
	//	if (ret.second == false)
	//	{
	//		ret.first->second++;
	//	}
	//}

	//V& operator[](cosnt K& k)
	//{
	//	pair<map<K, V>::iterator, bool> ret = insert(pair<K,V>(k,v()));
	//	return ret.first->second;
	//}

	for (auto e : str)
	{
		countMap[e]++;
	}
	system("pause");
	return 0;
}
class Solution {
public:
    struct compare
    {
        bool operator()(pair<string,int>& l,pair<string,int>& r)
        {
            if(l.second > r.second)
            {
                return true;
            }
            else if(l.second == r.second)
            {
                if(l.first < r.first)
                {
                    return true;
                }
                return false;
            }
            else{
                return false;
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        map<string,int> countMap;
        for(auto& e : words)
        {
            countMap[e]++;
        }
        vector<pair<string,int>> v;
        for(auto& e : countMap)
        {
            v.push_back(e);
        }
        sort(v.begin(),v.end(),compare());

        vector<string> result;
        for(int i = 0; i < k; i++)
        {
            result.push_back(v[i].first);
        }

        return result;
    }
};

class Solution {
public:
    struct compare
    {
        bool operator()(pair<string,int>& l,pair<string,int>& r)
        {
            if(l.second > r.second)
            {
                return true;
            }
            else if(l.second == r.second)
            {
                if(l.first < r.first)
                {
                    return true;
                }
                return false;
            }
            else{
                return false;
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        map<string,int> countMap;
        for(auto& e : words)
        {
            countMap[e]++;
        }
        	priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pq;
        int i = 0;
        for(auto& e : countMap)
        {
            if(i < k)
            {
                pq.push(e);
                i++;
            }
            else{
                if(e.second > pq.top().second)
                {
                    pq.pop();
                    pq.push(e);
                }
            }
        }
        vector<string> result;
        for(int i = 0; i < k; i++)
        {
            result.push_back(pq.top().first);
            pq.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        map<string,int> countMap;
        for(auto& e : words)
        {
            countMap[e]++;
        }

        multimap<int,string,greater<int>> mm;
        for(auto& e : countMap)
        {
            mm.insert(make_pair(e.second,e.first));
        }

        int i = 0;
        vector<string> result;
        for(auto& e : mm)
        {
            if(i < k)
            {
                result.push_back(e.second);
                ++i;
            }
        }
        return result;
    }
};

class BitSet
{
public:
	BitSet(const size_t& bitCount)
		:_bitCount(bitCount)
	{
		_bit.resize((bitCount >> 5) + 1, 0);
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
//class A
//{
//public:
//	int _a;
//};
//
//class B:virtual public A
//{
//public:
//	int _b;
//};
//
//class C :virtual public A
//{
//public:
//	int _c;
//};
//
//class D :public B, public C
//{
//public:
//	int _d;
//};

class B
{
public:
	virtual B* Buyticket()
	{
		cout << "B" << endl;
		return nullptr;
	}
};

class singleton
{
public:
	static singleton& GetInstance()
	{
		return obj;
	}
private:
	static singleton obj;

	singleton(){};
	singleton(const singleton& obj) = delete;
};
singleton singleton::obj;

#include<mutex>
class singleton1
{
public:
	static singleton1& GetInstance()
	{
		if (_obj == nullptr)
		{
			_mutex.lock();
			if (_obj == nullptr)
			{
				_obj = new singleton1;
			}
			_mutex.unlock();
		}
		return *_obj;
	}
private:
	singleton1(){};
	singleton1(const singleton1& obj) = delete;
	static singleton1* _obj;
	static mutex _mutex;
};
singleton1* singleton1::_obj = nullptr;
mutex singleton1::_mutex;

int StrToInt(string str)
{
	int flag = 1;
	int num = 0;
	int i = 0;
	if (str[i] == '+')
	{
		flag = 1;
		i++;
	}
	else if (str[i] == '-')
	{
		flag = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
			i++;
		}
		else{
			return 0;
		}
	}
	return flag*num;
}
void BubbleSort(int* arr, int n)
{
	while (--n)
	{
		int counts = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i]>arr[i + 1])
			{
				counts++;
				swap(arr[i], arr[i + 1]);
			}
		}
		if (counts == 0)
			return;
	}
}
int main()
{
	int arr[] = { 5, 4, 3, 2, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, size);
	for (auto e : arr)
	{
		cout << e << endl;
	}
	system("pause");
	return 0;
}

void InsertSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			int j = i;
			int tmp = arr[i + 1];
			for (j; j >= 0 && arr[j] > arr[j + 1]; j--)
			{
				swap(arr[j], arr[j + 1]);
			}
			arr[j + 1] = tmp;
		}
	}
}

void ShellSort(int* arr, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < size - gap; i++)
		{
			if (arr[i]>arr[i + gap])
			{
				int j = i;
				int tmp = arr[i + gap];
				for (j; j >= 0 && arr[j] > arr[j + gap]; j -= gap)
				{
					swap(arr[j], arr[j + gap]);
				}
				arr[j + gap] = tmp;
			}
		}
	}
}

void SelectSort(int* arr, int size)
{
	int begin = 0;
	int end = size - 1;
	int min_index = 0;
	while (begin <= end)
	{
		min_index = begin;
		for (int i = begin; i <= end; i++)
		{
			if (arr[i] < arr[min_index])
			{
				min_index = i;
			}
		}
		swap(arr[begin], arr[min_index]);
		begin++;
	}
}

void adjustUp(int* arr, int index)
{
	int child = index;
	int parent = (index - 1) / 2;
	while (child > 0)
	{
		if (arr[child] > arr[parent])
		{
			swap(arr[child], arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else{
			break;
		}
	}
}
void adjustDown(int* arr, int index,int size)
{
	int parent = index;
	int child = parent * 2 + 1;
	while (child <= size - 1)
	{
		if (arr[child] < arr[child + 1] && child + 1 <= size - 1)
		{
			child = child + 1;
		}
		if (arr[child]>arr[parent])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}
void HeapSort(int* arr, int size)
{
	//for (int index = (size - 1 - 1) / 2; index >= 0; index--)
	//{
	//	adjustDown(arr, index, size);
	//}

	for (int index = size - 1; index >= 0; index--)
	{
		adjustUp(arr, index);
	}
	for (int i = --size; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		adjustDown(arr, 0, i);
	}
}

void BubbleSort(int* arr, int size)
{
	while (--size)
	{
		int  counts = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i]>arr[i + 1])
			{
				counts++;
				swap(arr[i], arr[i + 1]);
			}
		}
		if (counts == 0)
		{
			return;
		}
	}
}

int _QuickSort(int* arr, int left, int right)
{
	int key = arr[right];
	int key_index = right;
	while (left < right)
	{
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		while (left < right && arr[right] >= key)
		{
			right--;
		}
		swap(arr[left], arr[right]);
	}
	swap(arr[left], arr[key_index]);
	return left;
}
void QuickSort(int* arr, int left,int right)
{
	if (left >= right){
		return;
	}
	int ret = _QuickSort(arr, left, right);
	QuickSort(arr, left, ret - 1);
	QuickSort(arr, ret + 1, right);
}

void CountSort(int* arr, int size)
{
	int maxNum = arr[0];
	int minNum = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > maxNum)
			maxNum = arr[i];
		if (arr[i] < minNum)
			minNum = arr[i];
	}

	int range = maxNum - minNum + 1;
	int* count = new int[range];
	memset(count, 0, sizeof(range)*range);
	for (int j = 0; j < size; j++)
	{
		count[arr[j] - minNum]++;
	}

	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			arr[j++] = i + minNum;
		}
	}
}

int BinarySearch(int* arr, int size, int num)
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (num > arr[mid])
		{
			left = mid + 1;
		}
		else if (num < arr[mid])
		{
			right = mid - 1;
		}
		else
		{
			return left;
		}
	}
	return -1;
}
