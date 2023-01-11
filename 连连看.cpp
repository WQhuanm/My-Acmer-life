#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 1e3 + 10;

int a[N][N];
int vis[N][N];
int ways[10][5] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
int n, m;
int sx, sy, ex, ey, q;
struct node
{
	int x, y, i, ans;
} head, temp;
void bfs()
{
	memset(vis, 0x3f, sizeof(vis));
	queue<node>q;
	head.x = sx, head.y = sy, head.ans = 0, head.i = -1;
	q.push(head);
	while (!q.empty())
		{
			head = q.front();
			q.pop();
			if (head.x == ex && head.y == ey)
				{
					cout << "YES" << endl;
					return;
				}
			for (int i = 0; i < 4; ++i)
				{
					if (head.i == i)
						{
							temp = head;
							temp.x = head.x + ways[i][0], temp.y = head.y + ways[i][1];
							if ( (!a[temp.x][temp.y] || (temp.x == ex && temp.y == ey)) && temp.ans <= vis[temp.x][temp.y] && temp.x >= 1 && temp.x <= n && temp.y >= 1 && temp.y <= m)
								{
									vis[temp.x][temp.y] = temp.ans;
									q.push(temp);
								}
						}
					else if (head.ans < 2)
						{
							temp = head;
							temp.x = head.x + ways[i][0], temp.y = head.y + ways[i][1];
							if ( (!a[temp.x][temp.y] || (temp.x == ex && temp.y == ey))  && temp.x >= 1 && temp.x <= n && temp.y >= 1 && temp.y <= m)
								{

									if (temp.i != -1)temp.ans = head.ans + 1;
									temp.i = i;
									if (temp.ans <= vis[temp.x][temp.y])
										{
											vis[temp.x][temp.y] = temp.ans;
											q.push(temp);
										}

								}
						}
				}

		}
	cout << "NO" << endl;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> n >> m && (n || m))
		{
			for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)cin >> a[i][j];
			cin >> q;
			while (q--)
				{
					cin >> sx >> sy >> ex >> ey;
					if (a[sx][sy] != a[ex][ey] || !a[sx][sy] || !a[ex][ey] || sx < 1 || sy < 1 || ex < 1 || ey < 1 || ex > n || ey > m || sx > n || sy > m)
						{
							cout << "NO" << endl;
							continue;
						}
					bfs();
				}

		}
	return 0;
}

