#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 810;
int s = 0, t;
char a[30][30];
char b[30][30];
int head[N];
int now[N];
int gap[N];
int dep[N];
int num;
int ans;

struct node
{
	int to, next;
	ll w;
} edge[N * N];

void add(int u, int v, ll w)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].w = w;
	head[u] = num;

	edge[++num].next = head[v];
	edge[num].to = u;
	edge[num].w = 0;
	head[v] = num;
}

void bfs()
{
	memset(dep, -1, sizeof(dep));
	dep[t] = 0;
	gap[0]++;
	queue<int>q;
	q.push(t);
	while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = head[x]; i; i = edge[i].next)
				{
					int v = edge[i].to;
					ll w = edge[i ^ 1].w;
					if (dep[v] == -1 && w)
						{
							dep[v] = dep[x] + 1;
							gap[dep[v]]++;
							q.push(v);
						}
				}
		}
}

ll dfs(int x, ll sum)
{
	if (x == t)
		{
			ans += sum;
			return sum;
		}
	ll k, res = 0;
	for (int i = now[x]; i && sum; i = edge[i].next)
		{
			now[x] = i;
			int v = edge[i].to;
			ll w = edge[i].w;
			if (dep[v] == dep[x] - 1 && w)
				{
					k = dfs(v, min(sum, w));
					if (!k)continue;
					edge[i].w -= k;
					edge[i ^ 1].w += k;
					res += k;
					sum -= k;
					if (!sum)return res;
				}
		}
	gap[dep[x]]--;
	if (!gap[dep[x]])
		dep[s] = t + 1;
	dep[x]++;
	gap[dep[x]]++;
	return res;
}
int main()
{
	int tt, kk = 0;
	cin >> tt;
	while (tt--)
		{
			memset(head, 0, sizeof(head));
			memset(gap, 0, sizeof(gap));
			int n, d;
			cin >> n >> d;
			for (int i = 0; i < n; ++i)cin >> a[i];
			for (int i = 0; i < n; ++i)cin >> b[i];
			int m = strlen(a[0]);
			num = 1, ans = 0;
			int sum = 0;
			t = 2 * n * m + 2;
			//	s = t + 10;
			for (int i = 0; i < n; ++i)for (int j = 0; j < m; ++j)
					{
						int tmp = i * m + j + 1;
						if (b[i][j] == 'L')
							{
								sum++;
								add(s, tmp, 1);
							}
						if (a[i][j] > '0')
							{
								add(tmp, n * m + tmp, a[i][j] - '0');
								//	if (i + d > n - 1 || i - d < 0 || j + d > m - 1 || j - d < 1)add(tmp + n * m, t, a[i][j] - '0');
								for (int x = -d; x <= d; x++)for (int y = -d; y <= d; y++)
										{

											if (abs(x) + abs(y) <= d && abs(x) + abs(y) >= 1)
												{
													int tx = i + x, ty = j + y;
													if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1)
														{

															add( n * m + tmp, t, a[i][j] - '0');
															break;
														}
													else if (a[tx][ty] > '0')
														{

															add( n * m + tmp, tx * m + ty + 1, min(a[i][j] - '0', a[tx][ty] - '0'));
														}
												}
										}
							}

					}

			bfs();
			while (dep[s] < t)
				{
					memcpy(now, head, sizeof(head));
					dfs(s, INF);
				}

			//	cout << sum << ' ' << ans << endl;
			if (sum == ans)printf("Case #%d: no lizard was left behind.\n", ++kk);
			else if (sum - ans == 1)printf("Case #%d: 1 lizard was left behind.\n", ++kk);
			else printf("Case #%d: %d lizards were left behind.\n", ++kk, sum - ans);

		}

	return 0;
}
