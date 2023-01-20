#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 110;

ll f[N][N];
int x[N * N];

int main()
{
	int t1 = 1;
	int n, c, r;
	while (cin >> n >> c >> r && (n || c || r))
		{
			memset(f, 0x3f, sizeof(f));
			map<string, int>mp;
			int k = 0;
			string a, b, l;
			cin >> a;
			mp[a] = ++k;
			for (int i = 1; i <= c; ++i)
				{
					cin >> a;
					if (!mp[a])mp[a] = ++k;
					x[i] = mp[a];
				}
			for (int i = 1; i <= n; ++i)f[i][i] = 0;
			for (int i = 1; i <= r; ++i)
				{
					cin >> a >> l >> b;
					if (!mp[a])mp[a] = ++k;
					if (!mp[b])mp[b] = ++k;
					ll t = 0;
					int j = 2;
					while (l[j] >= '0' && l[j] <= '9')t = t * 10 + l[j] - '0', j++;
					if (l[0] == '<')f[mp[b]][mp[a]] = min(f[mp[b]][mp[a]], t);
					if (l[(int)l.size() - 1] == '>')f[mp[a]][mp[b]] = min(f[mp[a]][mp[b]], t);
				}

			for (int k1 = 1; k1 <= n; ++k1)for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)f[i][j] = min(f[i][j], f[i][k1] + f[k1][j]);

			ll ans = 0;
			for (int i = 1; i <= c; ++i)ans += f[1][x[i]] + f[x[i]][1];
//			cout << t1++ << ". " << ans << endl;
			printf("%d. %lld\n", t1++, ans);
		}

	return 0;
}
