#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 155;

int dp[N][N];

int main()
{
	int n;
	int t;
	while (cin >> n && n != -1)
		{
			int k = 0;
			//	memset(mp, 0x3f, sizeof(mp));
			memset(dp, 0x3f, sizeof(dp));
			map<string, int>q;
			string a, b;
			cin >> a >> b;
			if (!q[a])q[a] = ++k;
			if (!q[b])q[b] = ++k;
			int t1 = q[a], t2 = q[b] ;
			for (int i = 1; i <= n; ++i)
				{
					cin >> a >> b >> t;
					if (!q[a])q[a] = ++k;
					if (!q[b])q[b] = ++k;
					dp[q[a]][q[b]] = dp[q[b]][q[a]] = min(dp[q[a]][q[b]], t);
				}
			for (int i = 1; i <= k; ++i)dp[i][i] = 0;
			for (int h = 1; h <= k; ++h)for (int i = 1; i <= k; ++i)for (int j = 1; j <= k; ++j)dp[i][j] = min(dp[i][j], dp[i][h] + dp[h][j]);
			if (dp[t1][t2] < INF)cout << dp[t1][t2] << endl;
			else cout << -1 << endl;
		}

	return 0;
}
