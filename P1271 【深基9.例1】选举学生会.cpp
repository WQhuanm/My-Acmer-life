#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
int book[N];
int main()
{
	int n, m;
	cin >> n >> m;
	int a;
	for (int i = 1; i <= m; ++i)
		{
			cin >> a;
			book[a]++;
		}
	for (int i = 1; i <= 1000; ++i)
		{
			while (book[i])
				{
					cout << i << ' ';
					book[i]--;
				}
		}
	return 0;
}
