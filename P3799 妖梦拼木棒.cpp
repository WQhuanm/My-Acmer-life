#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
const int mod = 1e9 + 7;

ll a[N];
bool vis[N];
int main()
{
	int n;
	cin >> n;
	ll count = 0;
	int x;
	int maxn = -INF;
	for (int i = 1; i <= n; ++i)cin >> x, a[x]++, maxn = max(maxn, x);
	for (int i = 2; i <= maxn; ++i)
		{
			if (a[i] >= 2)
				{
					for (int j = 1; j <= i / 2; ++j)
						{
							if (j == i / 2 && i % 2 == 0 )
								{
									if (a[j] >= 2)
										{
											count += (a[i]  * (a[i] - 1) / 2 * a[j]  * (a[j] - 1) / 2) % mod;
											count %= mod;
										}
								}
							else
								{
									if (a[j] && a[i - j])
										{
											count += (a[i]  * (a[i] - 1) / 2 * a[j] * a[i - j]) % mod;
											count %= mod;
										}
								}
						}
				}
		}
	cout << count << endl;
}
