#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

char t1[10];
char t2[10];

ll a[N];
ll b[N];
ll dp[N];

ll a1[N];
ll b1[N];

int main()
{
	ll n;
	cin >> t1 >> t2 >> n;
	int s1 = 0, s2 = 0;
	int t = 0;
	int i, j;
	for ( i = 0; t1[i] != ':' && i <= 1; ++i)s1 = s1 * 10 + t1[i] - '0';
	for ( j = 0; t2[j] != ':' && j <= 1; ++j)s2 = s2 * 10 + t2[j] - '0';
	int len1 = strlen(t1);
	int len2 = strlen(t2);
	int s3 = 0, s4 = 0;
	for ( i = i + 1 ; i < len1; ++i)s3 = s3 * 10 + t1[i] - '0';
	for (j = j + 1; j < len2; ++j)s4 = s4 * 10 + t2[j] - '0';
	t = (s2 - s1) * 60 + (s4 - s3);
	ll x, y, z;
	ll k = 0;
	ll k1 = 0;
	for (int h = 1; h <= n; ++h)
		{
			cin >> x >> y >> z; //时间，价值，次数
			if (!z)
				{
					a1[++k] = x;
					b1[k] = y;
				}
			else
				{
					ll c = 1;
					while (c <= z)
						{
							z -= c;
							a[++k1] = c * x;
							b[k1] = c * y;
							c <<= 1;
						}
					if (z)
						{
							a[++k1] = z * x;
							b[k1] = z * y;
						}

				}

		}
	for (int i = 1; i <= k1; ++i)for (int j = t; j >= a[i]; --j)dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
	for (int i = 1; i <= k; ++i)for (int j = 0; j <= t; ++j)if (j >= a1[i])dp[j] = max(dp[j], dp[j - a1[i]] + b1[i]);
	cout << dp[t] << endl;
	return 0;
}
