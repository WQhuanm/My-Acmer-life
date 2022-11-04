#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
///STL的sort排序与结构体内置自定义排序
struct stu
{
	int a, b;
	bool operator<(const stu &ash)const
	{
		if (a == ash.a)return b < ash.b;
		else return a < ash.a;
	}
};
