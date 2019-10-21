#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		static int MonthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		return MonthDays[month - 1];
	}

	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year >= 0 && month > 0 && month < 13
			&& day > 0 && day < GetMonthDay(year, day))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "Date error" << endl;
		}
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//-=֮������Ҳ����
	Date& operator-=(int days)
	{
		if (days < 0)
		{
			return *this += -days;
		}
		_day -= days;
		while (_day <= 0)
		{
			_month--;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	//+=֮������Ҳ����
	Date& operator+=(int days)
	{
		if (days < 0)
		{
			return *this -= -days;
		}
		_day = _day + days;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}

	//-���Ը���-=
	Date operator-(int days)
	{
		Date ret(*this);
		ret -= days;
		return ret;
	}

	//+���Ը���+=  
	//���������򣬾ֲ���������ʱ������ʧ�����Եô�ֵ���أ����ܴ����÷���
	Date operator+(int days)
	{
		Date ret(*this);
		ret += days;
		return ret;
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)//����Ƿ��Լ����Լ���ֵ
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	bool operator<(const Date& d)
	{
		return (_year < d._year)
			|| (_year == d._year && _month < d._month)
			|| (_year == d._year && _month == d._month && _day < d._day);
	}


    bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	bool operator>(const Date& d)
	{
		return (_year > d._year)
			|| (_year == d._year && _month > d._month)
			|| (_year == d._year && _month == d._month && _day > d._day);

		////���ߣ�return !(*this < d );
	}

	bool operator>=(const Date& d)
	{
		return *this > d || *this == d;

		////���ߣ�return!(*this < d );
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d );
	}

	//ǰ��++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	//����++
	Date operator++(int day)
	{
		Date tmp(*this);
		*this += 1;
		return tmp;
	}

	//ǰ��--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	//����--
	Date operator--(int day)
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}

	//���ڼ�ȥ����������֮�����������������Ǹ�int
	int operator-(const Date& d)
	{
		Date MaxDate(*this);
		Date MinDate(d);
		if (*this < d)
		{
			MaxDate = d;
			MinDate = *this;
		}
		int days = 0;
		while (1)
		{
			if (MinDate + days == MaxDate)
			{
				break;
			}
			days++;
		}
		return days;
	}

	//��ӡ����
	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2019, 9, 7);
	Date d2(2018, 9, 7);

	//d1 -= 500;
	//d1.print(); //2018 - 4 - 25

	//d1 += 500;
	//d1.print();//2021-1-19

	//(d1 - 500).print();//2018 - 4 - 25
	//(d1 + 500).print();//2021-1-19

	//Date d2 = d1 + 500;//2021-1-19

	//cout << (d2 == d1) << endl;//0
	//cout << (d2 > d1) << endl;//0
	//cout << (d2 < d1) << endl;//1
	//cout << (d2 >= d1) << endl;//0
	//cout << (d2 <= d1) << endl;//1
	//cout << (d2 != d1) << endl;//1

	//(d1++).print();
	//(++d1).print();

	//(d1--).print();
	//(--d1).print();

	cout << (d2 - d1) << endl;//��d2-d1)�ķ���ֵ�� int
	system("pause");
	return 0;
}