#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

int book[N];

int b[N];

int main()
{
	int n;
	cin >> n;
	int k = 0;
	int a;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a;
			if (!book[a])
				{
					book[a] = 1;
					b[++k] = a;

				}
		}
	sort(b + 1, b + 1 + k);
	cout << k << endl;
	for (int i = 1; i <= k; ++i)
		{
			cout << b[i];
			if (i == k)cout << endl;
			else cout << " ";
		}
	return 0;
}
