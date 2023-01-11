#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 20;

int a[N][N], vis[N][N], sx, sy, ex, ey;
int ways[N][N] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int t, n, m;
int ans;
struct node
{
	int x, y, t, ans;
} head, temp;

void bfs()
{
	queue<node>q;
	memset(vis, -1, sizeof(vis));
	head.x = sx, head.y = sy, head.t = 6, head.ans = 0;
	q.push(head);
	while (!q.empty())
		{
			head = q.front();
			q.pop();
			if (head.x == ex && head.y == ey && head.t)
				{
					cout << head.ans << endl;
					return;
				}

			if (head.t > 1)
				{
					for (int i = 0; i <= 3; ++i)
						{
							temp.ans = head.ans + 1;
							temp.t = head.t - 1;
							temp.x = ways[i][0] + head.x, temp.y = ways[i][1] + head.y;

							if (temp.x >= 1 && temp.x <= n && temp.y >= 1 && temp.y <= m && a[temp.x][temp.y] != 0 )
								{
									if (a[temp.x][temp.y] == 4)
										{
											if (vis[temp.x][temp.y] == -1)
												{
													vis[temp.x][temp.y] = 1;
													temp.t = 6;
													q.push(temp);
												}
										}
									else if (a[temp.x][temp.y] == 3)
										{
											cout << temp.ans << endl;
											return;
										}
									else if (temp.t > vis[temp.x][temp.y])
										{
											vis[temp.x][temp.y] = temp.t;
											q.push(temp);
										}

								}
						}
				}

		}
	cout << -1 << endl;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--)
		{
			cin >> n >> m;
			for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
					{
						cin >> a[i][j];
						if (a[i][j] == 2)sx = i, sy = j;
						else if (a[i][j] == 3)ex = i, ey = j;

					}
			bfs();

		}
	return 0;
}

