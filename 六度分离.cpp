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

int mp[N][N];

int main()
{
	int n, m, a, b;
	while (cin >> n >> m)
		{
			memset(mp, 0x3f, sizeof(mp));
			for (int i = 1; i <= m; ++i)
				{
					cin >> a >> b;
					mp[a][b] = mp[b][a] = 0;
				}
			//	for (int i = 0; i < n; ++i)mp[i][i] = 0;
			bool flag = 1;
			for (int k = 0; k < n; ++k)for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j)
						{
							mp[i][j] = mp[j][i] = min(mp[i][j], min(mp[j][i], mp[i][k] + mp[k][j] + 1));
						}
			for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j)
					{
						if (flag)
							{
								if (mp[i][j] > 6)flag = 0;
							}
					}

			if (flag)cout << "Yes" << endl;
			else cout << "No" << endl;

		}

	return 0;
}
