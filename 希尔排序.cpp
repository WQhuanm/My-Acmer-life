#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
//希尔排序（就是插入排序的升级
//不具稳定性
//每次对距离为gap的数排序，一般gap从n/2到1，每次除2，这样可以减少逆序对，比普通插入排序快得多
int n;
int a[N];
void shellsort()
{
	int gap = 1;
	gap = n / 2; //获得最大的gap
	while (gap >= 1)
		{
			for (int i = gap + 1; i <= n; ++i)  //每次对i之前的（每个距离为gap的数排序）
				{
					for (int j = i; j - gap >= 1 && a[j] < a[j - gap]; j -= gap)swap(a[j], a[j - gap]);//j每次减gap，只要符合条件，就一直下去
				}
			gap /= 2;//出来gap就变小
		}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	shellsort();
	for (int i = 1; i <= n; ++i)cout << a[i] << " ";
	return 0;
}
