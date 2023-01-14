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
int n, m, t, sx, sy;
bool vis[N][N][1100];
int w[5][3] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

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
	while (!q.empty())
		{
			head = q.front();
			q.pop();
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
											int k = a[tmp.x][tmp.y] - 'A';//num的二进制第k位为1，表示有这把钥匙，我才可以进这个门
											if ((tmp.num >> k) & 1)
												{
													vis[tmp.x][tmp.y][tmp.num] = 1;
													q.push(tmp);
												}
										}
									else if (a[tmp.x][tmp.y] >= 'a' && a[tmp.x][tmp.y] <= 'z')
										{
											int k = a[tmp.x][tmp.y] - 'a';
											tmp.num |= (1 << k);//只有过钥匙点，一定拿到钥匙，所以状态改变一般不用+，而是直接num这个第k位用|运算保证是1
											if (!vis[tmp.x][tmp.y][tmp.num])//num更新，查询如果没有访问过，访问
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
					}
			bfs();
		}
	return 0;
}
