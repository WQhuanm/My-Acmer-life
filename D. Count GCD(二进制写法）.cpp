#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
const int mod = 998244353;

ll l;
int n, m;
int a[N];
int d;
vector<int>v;
void prime(ll x)
{
	v.clear();
	for (int i = 2; i * i <= x; ++i)
		{
			if (!(x % i))v.push_back(i);
			while (!(x % i))x /= i;
		}
	if (x > 1)v.push_back(x);
}

ll rc(ll d)
{
	ll ans = 0;
	for (int i = 1; i < (1 << (int)v.size()); ++i)
		{
			ll sum = 1;
			ll len = 0;
			for (int j = 0; j < (int)v.size(); ++j)
				{
					if ((i >> j) & 1)
						{
							sum *= v[j];
							len++;
						}
				}
			if (len & 1)ans += (d / sum);
			else ans -= (d / sum);
		}

	return d - ans;
}

void msolve()
{
	cin >> n >> m;
	int flag = 1;
	ll tans = 1;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			if (i >= 2)if (a[i - 1] % a[i])flag = 0;
		}
	if (!flag)
		{
			cout << 0 << endl;
			return ;
		}
	else
		{
			ll t = 1;
			for (int i = 2; i <= n; ++i)
				{
//					if (a[i] == a[i - 1] && i != 2)tans = (tans * (t % mod)) % mod;
//					else
//						{
					d = m / a[i];
					prime(a[i - 1] / a[i]);
					t = rc(d);
					tans = (tans * (t % mod)) % mod;
//						}
				}

		}
	cout << tans << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		{
			msolve();
		}

}
