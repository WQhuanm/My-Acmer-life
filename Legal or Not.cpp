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

bool mp[N][N];

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, a, b;
	while (cin >> n, n)
		{
			memset(mp, 0, sizeof(mp));
			cin >> m;
			bool flag = 1;
			for (int i = 1; i <= m; ++i)
				{
					cin >> a >> b;
					if (flag)
						{
							if (mp[b][a])
								{
									flag = 0;
									continue;
								}
							else if (!mp[a][b])
								{
									mp[a][b] = 1;
									for (int j = 0; j < n; ++j)if (mp[j][a])mp[j][b] = 1;
									for (int j = 0; j < n; ++j)
										{
											if (mp[b][j])
												{
													mp[a][j] = 1;
													for (int k = 0; k < n; ++k)if (mp[k][b])mp[k][j] = 1;
												}
										}
								}
						}
				}
			if (flag)cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	return 0;
}
