#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 10;

int a[N][N];
int w[5][3] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool vis[N][N][5];//vis[a][b][i]表示以i方向去(b,a)位置是否进行过这个状态
bool vis1[N][N];//人找箱子普通标记就好
int n, m, sx, sy, rx, ry;

struct node
{
	int x, y, rx, ry, t; //对于每个状态的箱子，必须记录人上一次推完这个箱子后到达的位置
} head, tmp, hd, tp;

bool bfsr(int j)
{
	memset(vis1, 0, sizeof(vis1));
	queue<node>p;
	hd.x = head.rx, hd.y = head.ry;//人的初始位置就是bfs正在进行的head状态的人位置
	int x = head.x - w[j][0], y = head.y - w[j][1];//人需要去箱子箱子位置的后面
	p.push(hd);
	vis1[hd.x][hd.y] = 1;
	if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != 1) //人能去这个位置的话
		{
			while (!p.empty())
				{
					hd = p.front();
					p.pop();
					if (hd.x == x && hd.y == y)return 1;
					for (int i = 0; i < 4; ++i)
						{
							tp = hd;
							tp.x += w[i][0], tp.y += w[i][1];
							if (a[tp.x][tp.y] != 1 && tp.x >= 1 && tp.x <= n && tp.y >= 1 && tp.y <= m && !vis1[tp.x][tp.y])
								{
									vis1[tp.x][tp.y] = 1;
									p.push(tp);
								}
						}
				}
		}

	return 0;
}

void bfs()
{
	memset(vis, 0, sizeof(vis));
	head.x = sx, head.y = sy, head.rx = rx, head.ry = ry, head.t = 0;
	queue<node>q;
	q.push(head);
	while (!q.empty())
		{
			head = q.front();
			q.pop();
			if (a[head.x][head.y] == 3)
				{
					cout << head.t << endl;
					return;
				}
			for (int i = 0; i < 4; ++i)
				{
					tmp = head;
					tmp.x += w[i][0], tmp.y += w[i][1], tmp.t++;
					if (a[tmp.x][tmp.y] != 1 && tmp.x >= 1 && tmp.x <= n && tmp.y >= 1 && tmp.y <= m && !vis[tmp.x][tmp.y][i])
						{
							int h = a[head.x][head.y];
							a[head.x][head.y] = 1; //在bfs人是否可以去到箱子后面时，箱子是相当于墙的，人不能穿过箱子，所以先暂时改箱子为墙
							bool flag = bfsr(i); //i记录箱子移动方向，人便去反方向
							a[head.x][head.y] = h;
							if (flag)
								{
									vis[tmp.x][tmp.y][i] = 1;
									tmp.rx = head.x, tmp.ry = head.y; //人推完在原来箱子的位置
									q.push(tmp);
								}
						}
				}

		}
	cout << -1 << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		{
			cin >> n >> m;
			for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
					{
						cin >> a[i][j];
						if (a[i][j] == 2)sx = i, sy = j;
						else if (a[i][j] == 4)rx = i, ry = j;
					}
			bfs();
		}
}
