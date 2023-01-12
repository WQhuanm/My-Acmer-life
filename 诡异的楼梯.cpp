#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 25;

char a[N][N];
int ways[5][3] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int sx, sy, ex, ey, n, m;
int vis[N][N];
struct node
{
	int x, y, t;
} head, tmp;

void bfs()
{
	memset(vis, 0x3f, sizeof(vis));
	queue<node>q;
	int ans = INF;
	head.x = sx, head.y = sy, head.t = 0;
	q.push(head);
	vis[sx][sy] = -1;
	while (!q.empty())
		{
			head = q.front();
			q.pop();

			if (head.x == ex && head.y == ey)
				{
					ans = min(ans, head.t);
				}
			for (int i = 0; i < 4; ++i)
				{
					tmp = head;
					tmp.x += ways[i][0], tmp.y += ways[i][1];
					if (a[tmp.x][tmp.y] != '*' && tmp.x >= 1 && tmp.x <= n && tmp.y >= 1 && tmp.y <= m && vis[tmp.x][tmp.y] > tmp.t + 1)
						{
							if (a[tmp.x][tmp.y] == '|')//行0，1
								{
									tmp.x += ways[i][0], tmp.y += ways[i][1];
									if ((a[tmp.x][tmp.y] == '.' || a[tmp.x][tmp.y] == 'T') && tmp.x >= 1 && tmp.x <= n && tmp.y >= 1 && tmp.y <= m && vis[tmp.x][tmp.y] > tmp.t + 1)
										{

											if (head.t % 2)
												{
													if (i == 0 || i == 1)tmp.t += 2;
													else tmp.t += 1;
												}
											else
												{
													if (i == 0 || i == 1)tmp.t += 1;
													else tmp.t += 2;
												}
											if (vis[tmp.x][tmp.y] >= tmp.t)
												{
													vis[tmp.x][tmp.y] = tmp.t;
													if (tmp.t < ans)
														q.push(tmp);
												}

										}
								}
							else if (a[tmp.x][tmp.y] == '-')
								{
									tmp.x += ways[i][0], tmp.y += ways[i][1];
									if ((a[tmp.x][tmp.y] == '.' || a[tmp.x][tmp.y] == 'T') && tmp.x >= 1 && tmp.x <= n && tmp.y >= 1 && tmp.y <= m && vis[tmp.x][tmp.y] > tmp.t + 1)
										{

											if (head.t % 2)
												{
													if (i == 0 || i == 1)tmp.t += 1;
													else tmp.t += 2;
												}
											else
												{
													if (i == 0 || i == 1)tmp.t += 2;
													else tmp.t += 1;
												}
											if (vis[tmp.x][tmp.y] > tmp.t)
												{
													vis[tmp.x][tmp.y] = tmp.t;
													if (tmp.t < ans)
														q.push(tmp);
												}
										}
								}
							else
								{

									++tmp.t;
									vis[tmp.x][tmp.y] = tmp.t;
									if (head.t < ans)
										q.push(tmp);
								}
						}
				}
		}
	cout << ans << endl;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> n >> m)
		{
			for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
					{
						cin >> a[i][j];
						if (a[i][j] == 'S')sx = i, sy = j;
						else if (a[i][j] == 'T')ex = i, ey = j;
					}

			bfs();
		}
	return 0;
}
