#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

int a[N];
int b[N];

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			if (i >= 2)
				{
					b[i - 1] = a[i] + a[i - 1];
				}
		}
	ll ans = 0;
	for (int i = 1; i <= n - 1; ++i)
		{
			if (b[i] > x)
				{
					int h = (b[i] - x);
					b[i] -= h;
					b[i + 1] -= h;
					ans += h;
				}
		}
	cout << ans << endl;
	return 0;
}
