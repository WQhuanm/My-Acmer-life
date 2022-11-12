#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

ll a[N];

int main()
{
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 1; i <= n - 1; ++i)
		{
			if (a[i] > a[i + 1])sum += a[i] - a[i + 1];
		}
	sum += a[n];
	cout << sum << endl;
	return 0;
}
