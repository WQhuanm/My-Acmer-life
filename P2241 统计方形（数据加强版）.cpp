#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

int main()
{
	ll n, m;
	cin >> n >> m;
	ll sum1 = 0, sum2 = 0;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			{
				if (i == j)sum1 += (n - i + 1) * (m - j + 1);
				else sum2 += (n - i + 1) * (m - j + 1);

			}
	cout << sum1 << " " << sum2 << endl;
	return 0;

}
