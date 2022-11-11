#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e7 + 100;

ll a[N];
ll b[N];
ll dp[N];
int main()
{
	int n, w;
	cin >> n >> w;
	ll x, y, z; //价值，体积，数量
	ll k = 0;
	for (int i = 1; i <= n; ++i)
		{
			cin >> x >> y >> z;
			int c = 1;
			while (c <= z)
				{
					a[++k] = c * x;
					b[k] = c * y;
					z -= c;
					c <<= 1;

				}
			if (z)
				{
					a[++k] = z * x;
					b[k] = z * y;
				}
		}
	for (int i = 1; i <= k; ++i)for (int j = w; j >= b[i]; --j)dp[j] = max(dp[j], dp[j - b[i]] + a[i]);
	cout << dp[w] << endl;
	return 0;
}
