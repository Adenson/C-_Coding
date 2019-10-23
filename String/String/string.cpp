#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

namespace S
{
	// string ģ��ʵ��  ��ɾ���
	class string
	{
	public:
		typedef const char* const_iterator;
		typedef char* iterator;

		const_iterator begin() const
		{
			return _str;
		}

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}


		//string(const char* str = "\0")    ����
		//string(const char* str = nullptr) ����
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			// �Ѿ�����'\0'
			strcpy(_str, str);// while (*dst++ = *src++);�����һ�θ�ֵ������'\0'
			_size = strlen(str);
			_capacity = _size;
		}


		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		//string copy1(s1)
		string(const string& s)
			:_str(new char[s._size + 1])
			, _size(s._size)
			, _capacity(s._size)
		{
			strcpy(_str, s._str);
		}

		// s1 = s2;
		// s1 = s1;
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete []_str;
				_str = new char[s._size + 1];
				strcpy(_str, s._str);
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}

		const char* c_str()
		{
			return _str;
		}

		char& operator[](size_t pos) const
		{
			return _str[pos];
		}

		size_t size()const
		{
			return _size;
		}
		
		size_t capacity()
		{
			return _capacity;
		}

		void reserve(size_t n)//Ϊ�ַ���Ԥ���ռ�
		{
			if (n > _capacity)// n С�� _capacity ʱ�����κ�����
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)//β��
		{
			//����
			if (_size == _capacity)
			{
				if (_capacity == 0)
				{
					reserve(8);
				}
				else
				{
					reserve(_capacity * 2);
				}
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';

			//���ߣ�insert(_size,ch)
		}

		// s1.append("11111");
		void append(const char* str)//���ַ�����׷��һ���ַ���
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		const string& operator+=(char ch)//����push_back
		{
			push_back(ch);
			return *this;
		}

		const string& operator+=(const char* str)//����append
		{
			append(str);
			return *this;
		}

		const string& operator+=(const string& s)//����append
		{
			append(s._str);
			return *this;
		}

		void insert(size_t pos, char ch)//��POSǰ�����һ���ַ�
		{
			assert(pos <=  _size);//�õ��ں��������ܶ���,���ڿ����ڡ�\0��ǰ�����
			if (_size == _capacity)
			{
				if (_capacity == 0)//ע������Ҫ�ж�_capacity�Ƿ�Ϊ0��������ж� cin ��ʱ������
				{
					reserve(8);
				}
				else
				{
					reserve(_capacity * 2);
				}
			}
			size_t end = _size + 1;
			while (end >= pos + 1)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			_size++;
		}

		void insert(size_t pos, const char* str)//��POSǰ�����һ���ַ���
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len >= _capacity)
			{
				reserve(_size+len);
			}
			size_t end = _size + len;
			while (pos + len <= end)
			{
				_str[end] = _str[end - len];
				--end;
			}
			while (*str)
			{
				_str[pos] = *str;
				++pos;
				++str;
				//_str[pos++] = *str++;
			}
			_size += len;
		}

		 size_t find(char ch)
		{
			 for (size_t i = 0; i < _size; ++i)
			{
				if (_str[i] == ch)
					return i;
			}
			 return string::npos;
		}

		 size_t find(const char* str)
		 {
			 const char* pos = strstr(_str, str);
			 if (pos == nullptr)
			 {
				 return string::npos;
			 }
			 else
			 {
				 return pos - _str;
			 }
		 }

		bool operator>(const string& s)const
		{
			char* str1 = _str;
			char* str2 = s._str;
			while (*str1 && *str2)
			{
				if (*str1 > *str2)
				{
					return true;
				}
				else if (*str1 < *str2)
				{
					return false;
				}
				else
				{
					++str1;
			    	++str2;
				}
			}
			if (*str1)
			{
				return true;
			}
			else
				return false;
		}

		bool operator==(const string& s)const
		{
			const char* str1 = _str;
			const char* str2 = s._str;
			while (*str1 && *str2)
			{
				if (*str1 == *str2)
				{
					++str1;
					++str2;
				}
				else
				{
					return false;
				}
			}
			if (*str1)
			{
				return false;
			}
			else if (*str2)
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		bool operator>=(const string& s)const
		{
			return operator>(s) || operator==(s);
		}
		
		friend ostream& operator<<(ostream& _cout, const string& s);
		friend istream& operator>>(istream& _cin, string& s);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static size_t npos;
	};
	size_t string::npos = -1;


	ostream& operator<<(ostream& _cout, const string& s)
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			_cout << s[i];
		}
		return _cout;
	}

	istream& operator>>(istream& _cin, string& s)
	{
		char ch = _cin.get();
		while (ch != ' '&& ch != '\n')
		{
			s += ch;
			ch = _cin.get();
		}
		return _cin;
	}
}

void test1()
{
	//S::string s1("hello");
	//S::string s2("hello");
	//cout << s1.c_str() << endl;
	//S::string copy1(s1);
	//cout << copy1.c_str() << endl;

	//S::string::iterator it1 = s1.begin();
	//while (it1 != s1.end())
	//{
	//	cout << *it1 << " ";
	//	++it1;
	//}
	//cout << endl;

	//for (auto e : s1)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//s1.append(" world!");
	//s1.operator+=('h');
	//s1.operator+=("ello");
	//s1.reserve(189);


	//cout << s1.size() << endl;
	//cout << s1.capacity() << endl;
	//cout << (s1 > s2)  << endl;
	//cout << (s1 == s2) << endl;
	//cout << (s1 >= s2) << endl;

	//s1.insert(5, "S");
	//cout << s1.c_str() << endl;

	//cout << s1.find('l') << endl;
	//cout << s1.find("llo") << endl;
}

void test2()//���ֱ����ַ�����ʽ:�±�+operator[]������������Χfor
{
	S::string s1("hello");
	for (int i = 0; i < s1.size(); ++i)
	{
		cout << s1[i]<<" ";
	}
	cout << endl;

	S::string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test3()
{
	//S::string s1("hello world");
	//cout << s1.c_str() << endl;
	//cout << s1 << endl;

	S::string s2;
	cin >> s2;
	cout << s2 << endl;
}
int main()
{
	//test1();
	//test2();
	test3();
	system("pause");
	return 0;
}