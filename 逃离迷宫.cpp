#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 210;

int vis[N][N];
int n, m, sx, sy, ex, ey, k;
int w[6][4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char a[N][N];
struct node
{
	int x, y, i, k;
} head, tmp;

void bfs()
{
	memset(vis, 0x3f, sizeof(vis));
	queue<node>q;
	head.x = sx, head.y = sy, head.k = 0, head.i = -1;
	q.push(head);
	vis[sx][sy] = -1;
	while (!q.empty())
		{
			head = q.front();
			q.pop();
			if (head.x == ex && head.y == ey)
				{
					cout << "yes" << endl;
					return;
				}
			for (int i = 0; i < 4; ++i)
				{
					tmp = head;
					tmp.x += w[i][0], tmp.y += w[i][1];
					if (tmp.i == i)
						{
							if (a[tmp.x][tmp.y] == '.' && tmp.x >= 1 && tmp.x <= m && tmp.y >= 1 && tmp.y <= n && tmp.k <= vis[tmp.x][tmp.y])
								{
									vis[tmp.x][tmp.y] = tmp.k;
									q.push(tmp);
								}

						}
					else
						{
							if (a[tmp.x][tmp.y] == '.' && tmp.x >= 1 && tmp.x <= m && tmp.y >= 1 && tmp.y <= n )
								{
									if (tmp.i != -1)tmp.k++;
									tmp.i = i;
									if (tmp.k <= k && tmp.k <= vis[tmp.x][tmp.y])
										{
											vis[tmp.x][tmp.y] = tmp.k;
											q.push(tmp);
										}

								}
						}
				}

		}
	cout << "no" << endl;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		{
			cin >> m >> n;
			for (int i = 1; i <= m; ++i)for (int j = 1; j <= n; ++j)cin >> a[i][j];
			cin >> k >> sy >> sx >> ey >> ex;
			if (a[sx][sy] == '.' && a[ex][ey] == '.' && sx >= 1 && sx <= m && sy >= 1 && sy <= n && ex >= 1 && ex <= m && ey >= 1 && ey <= n)
				bfs();
			else cout << "no" << endl;
		}
	return 0;
}
