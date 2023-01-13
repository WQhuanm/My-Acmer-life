#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N =  10;

int n, m, rx, ry, xx, xy, ex, ey;
bool vis[N][N][N], vis1[N][N];
int a[N][N];
int w[5][3] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct node
{
	int x, y, rx, ry, t;
} head, tmp, hd, tp;

bool bfs1(int j)
{
	memset(vis1, 0, sizeof(vis1));
	queue<node>q1;
	hd.x = head.rx, hd.y = head.ry;
	q1.push(hd);
	int x = head.x - w[j][0], y = head.y - w[j][1];
	vis1[head.rx][head.ry] = 1;
	if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != 1)
		{
			while (!q1.empty())
				{
					hd = q1.front();
					q1.pop();
					if (hd.x == x && hd.y == y)
						{
							rx = head.x, ry = head.y;
							return 1;
						}

					for (int i = 0; i < 4; ++i)
						{
							tp = hd;
							tp.x += w[i][0], tp.y += w[i][1];
							if (!vis1[tp.x][tp.y] && tp.x >= 1 && tp.x <= n && tp.y >= 1 && tp.y <= m && a[tp.x][tp.y] != 1)
								{
									vis1[tp.x][tp.y] = 1;
									q1.push(tp);
								}
						}
				}
		}

	return 0;
}

void bfs()
{
	memset(vis, 0, sizeof(vis));
	queue<node>q;
	head.x = xx, head.y = xy, head.t = 0, head.rx = rx, head.ry = ry;
	q.push(head);
	while (!q.empty())
		{
			head = q.front();
			q.pop();
			//	cout << head.x << ' ' << head.y << endl;
			if (a[head.x][head.y] == 3)
				{
					cout << head.t << endl;
					return ;
				}
			for (int i = 0; i < 4; ++i)
				{
					tmp = head;
					tmp.x += w[i][0], tmp.y += w[i][1];
					tmp.t++;
					if (!vis[tmp.x][tmp.y][i] && tmp.x >= 1 && tmp.x <= n && tmp.y >= 1 && tmp.y <= m && a[tmp.x][tmp.y] != 1)
						{
							int h =	a[head.x][head.y];
							a[head.x][head.y] = 1;
							bool flag = bfs1(i);
							a[head.x][head.y] = h;
							if (flag)
								{
									vis[tmp.x][tmp.y][i] = 1;
									tmp.rx = head.x, tmp.ry = head.y;
									q.push(tmp);
								}

						}

				}
		}
	cout << -1 << endl;

}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		{
			cin >> n >> m;
			for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
					{
						cin >> a[i][j];
						if (a[i][j] == 4)rx = i, ry = j;
						else if (a[i][j] == 2)xx = i, xy = j;
					}
			bfs();

		}

	return 0;
}

