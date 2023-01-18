#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N =  10;

int mp[N][N];
int cnt[N][N];
ll ans;
int n, m;

void dfs(int j)
{
//	cout << j << endl;
	if (j == n && cnt[j][1] == cnt[j][2] && cnt[j][1] == cnt[j][0] / 2)
		{
			++ans;
			return;
		}
	if (cnt[j][1] == cnt[j][2] && cnt[j][1] == cnt[j][0] / 2)
		{
			dfs(j + 1);
		}
	else
		{
			for (int i = 1; i <= n; ++i)if (mp[j][i] == 1)
					{
						if (cnt[j][1] < cnt[j][0] / 2)
							{
								mp[j][i] = mp[i][j] = 2;
								++cnt[j][1], ++cnt[i][1];
								dfs(j);
								mp[j][i] = mp[i][j] = 1;
								--cnt[j][1], --cnt[i][1];
							}
						if (cnt[j][2] < cnt[j][0] / 2)
							{
								mp[j][i] = mp[i][j] = 3;
								++cnt[j][2], ++cnt[i][2];
								dfs(j);
								mp[j][i] = mp[i][j] = 1;
								--cnt[j][2], --cnt[i][2];
							}
						break;
					}
		}

}

int main()
{
	int t;
	cin >> t;
	while (t--)
		{
			cin >> n >> m;
			int x, y;
			memset(mp, 0, sizeof(mp));
			memset(cnt, 0, sizeof(cnt));
			ans = 0;
			for (int i = 1; i <= m; ++i)
				{
					cin >> x >> y;
					mp[x][y] = mp[y][x] = 1;
					cnt[x][0]++, cnt[y][0]++;
				}
			bool flag = 1;

			for (int i = 1; i <= n; ++i)
				{
					if (cnt[i][0] & 1)
						{
							cout << 0 << endl;
							flag = 0;
							break;
						}
				}
			if (flag)
				{
					dfs(1);
					cout << ans << endl;
				}
		}

	return 0;
}
