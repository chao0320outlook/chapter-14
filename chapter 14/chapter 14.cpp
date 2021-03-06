// chapter 14.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <functional>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Date
{
private:

	int day;
	int month;
	int year;
	explicit operator bool()
	{
		vector<vector<int>> days_per_month = { {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };
		return 1 <= month && month <= 12 && 1 <= day && day <= days_per_month[isLeapYear() ? 1 : 0][month - 1];
	}

	bool isLeapYear()
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}


};


map<string, function<int(int, int)>> map_1 =
{
	{"+",plus<int>()},
	{"-",minus<int>()},
	{"*",multiplies<int>()},
	{"/",divides<int>()},
	{"%",modulus<int>()}
};

int main()

{
	int a, b;
	char str_1;
	string str_2;
	cin >> a >> str_1>>b;
	str_2.push_back(str_1);
	cout << map_1[str_2](a, b) << endl;

	vector<int> vec_1 = {1234,21314,23,41432,5325,1232,34,34,2,5645,};
	vector<string> vec_2 = { "afaf","dsad","afaf","hdfahdsa","sadfasdgr" };

	auto cont_vec_1=count_if(vec_1.begin(), vec_1.end(), bind2nd(greater<int>(), 1024));
	auto cont_vec_2= find_if(vec_2.begin(), vec_2.end(), bind2nd(not_equal_to<string>(), "afaf"));

	cout << cont_vec_1 << endl;
	cout << *cont_vec_2 << endl;

	transform(vec_1.begin(), vec_1.end(), vec_1.begin(), bind2nd(multiplies<int>(), 2));
	for (auto &i : vec_1)
	{
		cout << i<<" ";
	}

	if (count_if(vec_1.begin(), vec_1.end(), bind2nd(modulus<int>(), 2)) == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	int secs = 300;                                  //延时300s的程序
	clock_t delay = secs * CLOCKS_PER_SEC;           //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

	return 0;
}

