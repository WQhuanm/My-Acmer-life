#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
//插入排序
//具有稳定性
//每次从为排序的堆中取出一个，插入排好序的位置中
int n;
int a[N];
void insertsort()
{
	for (int i = 2; i <= n; ++i)//这里默认第一个排好序，所以从第二个开始视为为排序的堆
		{
			//
			int j = i - 1;//j表示从1开始前面有多少个是排好序的
			int tmp = a[i];//后面a[j + 1] = a[j]交换后，a[i]的值会变，全程必须用临时变量来保存他
			while (j >= 1 && a[j] > tmp)//只要比序列的值小，就把比较的这个值往前移动，空一个位置给tmp
				{
					a[j + 1] = a[j];
					--j;
				}
			a[j + 1] = tmp;//j一直是前面一位，所以赋值tmp位置要加一
		}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	insertsort();
	for (int i = 1; i <= n; ++i)cout << a[i] << " ";
	return 0;
}
