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

	//-=之后自身也变了
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

	//+=之后自身也变了
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

	//-可以复用-=
	Date operator-(int days)
	{
		Date ret(*this);
		ret -= days;
		return ret;
	}

	//+可以复用+=  
	//出了作用域，局部变量与临时对象将消失，所以得传值返回，不能传引用返回
	Date operator+(int days)
	{
		Date ret(*this);
		ret += days;
		return ret;
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)//检测是否自己给自己赋值
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

		////或者：return !(*this < d );
	}

	bool operator>=(const Date& d)
	{
		return *this > d || *this == d;

		////或者：return!(*this < d );
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d );
	}

	//前置++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	//后置++
	Date operator++(int day)
	{
		Date tmp(*this);
		*this += 1;
		return tmp;
	}

	//前置--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	//后置--
	Date operator--(int day)
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}

	//日期减去日期是它们之间相差的天数，返回是个int
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

	//打印日期
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

	cout << (d2 - d1) << endl;//（d2-d1)的返回值是 int
	system("pause");
	return 0;
}