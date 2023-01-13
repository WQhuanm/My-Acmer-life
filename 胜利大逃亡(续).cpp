#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 25;

char a[N][N];
int n, m, t, sx, sy, ex, ey;
int w[5][3] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool vis[N][N][1050];
struct node
{
	int x, y, t, num;

} head, tmp;

void bfs()
{
	memset(vis, 0, sizeof(vis));
	queue<node>q;
	head.x = sx, head.y = sy, head.t = 0, head.num = 0;
	q.push(head);
	vis[sx][sy][0] = 1;
	while (!q.empty())
		{
			head = q.front();
			q.pop();
			//	cout << head.x << ' ' << head.y << ' ' << head.t << endl;
			if (a[head.x][head.y] == '^' && head.t < t)
				{
					cout << head.t << endl;
					return;
				}
			if (head.t + 1 < t)
				{
					for (int i = 0; i < 4; ++i)
						{
							tmp = head;
							tmp.x += w[i][0], tmp.y += w[i][1], tmp.t++;
							if (a[tmp.x][tmp.y] != '*' && tmp.x >= 1 && tmp.x <= n && tmp.y >= 1 && tmp.y <= m && !vis[tmp.x][tmp.y][tmp.num])
								{
									if (a[tmp.x][tmp.y] >= 'A' && a[tmp.x][tmp.y] <= 'Z')
										{
											int k = a[tmp.x][tmp.y] - 'A';
											if (((tmp.num) >> k) & 1)
												{
													vis[tmp.x][tmp.y][tmp.num] = 1;
													q.push(tmp);
												}
										}
									else if (a[tmp.x][tmp.y] >= 'a' && a[tmp.x][tmp.y] <= 'z')
										{
											int k = a[tmp.x][tmp.y] - 'a';
											tmp.num |= (1 << k);
											if (!	vis[tmp.x][tmp.y][tmp.num])
												{
													vis[tmp.x][tmp.y][tmp.num] = 1;
													q.push(tmp);
												}

										}
									else
										{
											vis[tmp.x][tmp.y][tmp.num] = 1;
											q.push(tmp);
										}
								}
						}
				}

		}

	cout << -1 << endl;
}

int main()
{
	while (cin >> n >> m >> t)
		{
			for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
					{
						cin >> a[i][j];
						if (a[i][j] == '@')sx = i, sy = j;
						else if (a[i][j] == '^')ex = i, ey = j;
					}
			bfs();
		}
	return 0;
}
