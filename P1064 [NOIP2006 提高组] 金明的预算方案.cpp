#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
ll dp[N];

vector<pair<ll, ll> >v[N];
ll link[N];

int main()
{
	ll n, m;
	cin >> n >> m;
	ll x, y, z;
	ll k = 0;
	for (ll i = 1; i <= m; ++i)
		{
			cin >> x >> y >> z;
			if (!z)
				{
					v[++k].push_back({x, y * x});
					link[i] = k;
				}
			else
				{
					ll tmp = (int)v[link[z]].size();
					for (int t = 0; t < tmp; ++t)
						v[link[z]].push_back({x + v[link[z]][t].first, y * x + v[link[z]][t].second});
				}

		}

	for (ll i = 1; i <= k; ++i)for (int j = n; j >= 0; --j)for (int h = 0; h < (int)v[i].size(); ++h)
				{
					if (j >= v[i][h].first)dp[j] = max(dp[j], dp[j - v[i][h].first] + v[i][h].second);
				}
	cout << dp[n] << endl;
	return 0;
}
