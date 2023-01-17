#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 70;
int a[N];
int n;
int flag;
bool vis[N];

void dfs(int k, int j, int x, int ans, int num)
{
	if (flag != 0)return;
	if (num == n)
		{
			flag = 1;
			return;
		}
	bool fl = 1;
	while (vis[k])++k;
	if (ans == x)
		{
			vis[j] = 1;
			while (vis[j])j--;
			dfs(k, j, x, a[j], num + 1);
		}

	else
		{
			for (int i = k; i < j && !flag; ++i)
				{
					if (ans + a[i] <= x)
						{
							if (!vis[i])
								{
									fl = 0;
									if (a[i] + ans == x)
										{
											vis[i] = 1;
											vis[j] = 1;
											int tj = j;
											while (vis[tj])tj--;
											dfs(k, tj, x, a[tj], num + 2);
											vis[i] = 0;
											vis[j] = 0;
										}
									else
										{
											vis[i] = 1;
											dfs(k, j, x, ans + a[i], num + 1);
											vis[i] = 0;
										}
									while (i < n && a[i] == a[i + 1])++i;
								}

						}
					else break;
				}
			if (fl && ans == a[j] && !flag)
				{
					flag = -1;
					return;
				}
		}

}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> n && n)
		{
			int	sum = 0;
			int maxn = -INF;
			for (int i = 1; i <= n; ++i)
				{
					cin >> a[i];
					sum += a[i];
					maxn = max(maxn, a[i]);
				}
			sort(a + 1, a + 1 + n);

			for (int i = maxn; i <= sum; ++i)
				{
					if (sum % i == 0)
						{
							flag = 0;
							memset(vis, 0, sizeof(vis));

							dfs(1, n, i, a[n], 0);
							if (flag == 1)
								{
									cout << i << endl;
									break;
								}
						}
				}
		}
	return 0;
}
