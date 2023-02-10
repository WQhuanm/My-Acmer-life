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
const int N = 250;

bool mp[N][N];

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, t = 1;
	while (cin >> n >> m && (n || m))
		{
			memset(mp, 0, sizeof(mp));
			int a, b, ans = 0;
			for (int i = 1; i <= m; ++i)
				{
					cin >> a >> b;
					if (a == b)ans++;
					else if (mp[b][a])ans++;
					else if (!mp[a][b])
						{
							mp[a][b] = 1;
							for (int i = 1; i <= n; ++i)
								{
									if (mp[i][a])mp[i][b] = 1;
								}
							for (int i = 1; i <= n; ++i)if (mp[b][i])
									{
										mp[a][i] = 1;
										for (int j = 1; j <= n; ++j)if (mp[j][b])mp[j][i] = 1;
									}
						}
				}
			cout << t++ << ". " << ans << endl;
		}

	return 0;
}
