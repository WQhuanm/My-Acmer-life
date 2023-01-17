#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 15;

int a[N];
bool vis[N], flag, v[10000];
void dfs(int n, int sum)
{
	for (int i = 1; i <= 4; ++i)
		{
			if ((a[i] == a[i - 1] || !a[i]) && n == 1)continue;
			if (!vis[i])
				{
					vis[i] = 1;
					if (n == 4)
						{
							vis[i] = 0;
							if (!v[sum * 10 + a[i]])
								{
									v[sum * 10 + a[i]] = 1;
									if (flag)
										{
											flag = 0;
											cout << sum * 10 + a[i];
										}
									else
										cout << ' ' << sum * 10 + a[i];
								}

						}
					else dfs(n + 1, sum * 10 + a[i]);
					vis[i] = 0;
				}
			if (n == 1 && a[i])cout << endl;
			if (n == 1)flag = 1;
		}

}

int main()
{
	bool fl = 1;
	while (cin >> a[1] >> a[2] >> a[3] >> a[4] && (a[1] || a[2] || a[3] || a[4]))
		{
			sort(a + 1, a + 5);
			flag = 1;
			if (fl)fl = 0;
			else cout << endl;
			a[0] = -1;
			memset(vis, 0, sizeof(vis));
			memset(v, 0, sizeof(v));
			dfs(1, 0);

		}

	return 0;
}
