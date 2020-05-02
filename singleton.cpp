class singleton
{
public:
	static singleton& GetInstance()
	{
		return obj;
	}
private:
	static singleton obj;

	singleton(){}

	singleton(const singleton& obj) = delete;
	singleton& operator=(const singleton& obj) = delete;
};
singleton singleton::obj;//main函数之前就需要创建初始化这个实例对象

class singleton
{
public:
	static singleton& GetInstance()
	{
		if (_InstancePtr == nullptr)//此处检验是为了避免频繁加锁带来的低效率问题
		{
			_mutex.lock();//加锁是为了保证线程安全
			if (_InstancePtr == nullptr)
			{
				_InstancePtr = new singleton;
			}
			_mutex.unlock();
		}
		return *_InstancePtr;
	}
private:

	static singleton* _InstancePtr;
	static mutex _mutex;

	singleton(){};
	singleton(const singleton& obj) = delete;
	singleton& operator=(const singleton& obj) = delete;
};

singleton* singleton::_InstancePtr = nullptr;
mutex singleton::_mutex;
#include<thread>
int main() 
{
	vector<thread> threadArray;
	const size_t threadNum = 2;
	for (size_t i = 0; i < threadNum; i++)
	{
		threadArray.push_back(thread([]()
		{
			for (size_t i = 0; i < 100; i++)
			{
				cout << &singleton::GetInstance() << endl;
			}
		}));
	}

	for (auto& e : threadArray)
	{
		e.join();
	}
	system("pause");
	return 0;
}