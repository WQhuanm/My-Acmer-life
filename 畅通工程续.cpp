#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 210;

int f[N][N];

int main()
{
	int n, m, a, b;
	int x;
	while (cin >> n >> m)
		{
			memset(f, 0x3f, sizeof(f));
			for (int i = 1; i <= m; ++i)
				{
					cin >> a >> b >> x;
					f[a][b] = f[b][a] =  min(f[b][a], x);
				}
			for (int i = 0; i < n; ++i)f[i][i] = 0;
			for (int k = 0; k < n; ++k)for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j)f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

			cin >> a >> b;
			if (f[a][b] < INF)cout << f[a][b] << endl;
			else cout << -1 << endl;

		}

	return 0;
}
