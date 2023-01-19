#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 35;
int k;

double mp[N][N];

int main()
{
	int n, m, t = 1;
	double x;
	string a, b;
	map<string, int>q;
	while (cin >> n && n)
		{
			k = 0;
			memset(mp, 0, sizeof(mp));
			for (int i = 1; i <= n; ++i)
				{
					cin >> a;
					q[a] = ++k;
				}
			cin >> m;
			for (int i = 1; i <= m; ++i)
				{
					cin >> a >> x >> b;
					mp[q[a]][q[b]] = x;
				}

			for (int h = 1; h <= k; ++h)for (int i = 1; i <= k; ++i)for (int j = 1; j <= k; ++j)mp[i][j] = max(mp[i][j], mp[i][h] * mp[h][j]);
			bool flag = 0;
			printf("Case %d: ", t++);
			for (int i = 1; i <= n; ++i)if (mp[i][i] > 1.0)
					{
						flag = 1;
						break;
					}

			if (flag)	cout << "Yes" << endl;
			else cout << "No" << endl;
		}

	return 0;
}
