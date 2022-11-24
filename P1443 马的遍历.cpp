#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 500;

int a[N][N];
struct node
{
	int x, y, ans;
};
int n, m, x, y;
bool vis[N][N];
int way[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-1, 2}, {-2, 1}};
node head;
void bfs()
{
	queue<node>q;
	q.push({x, y, 0});
	vis[x][y] = 1;
	while (!q.empty())
		{
			head = q.front();
			q.pop();
			for (int i = 0; i < 8; ++i)
				{
					int x = head.x + way[i][0], y = head.y + way[i][1];
					if (!vis[x][y] && x >= 1 && x <= n && y >= 1 && y <= m)
						{
							vis[x][y] = 1;
							a[x][y] = head.ans + 1;
							q.push({x, y, head.ans + 1});

						}
				}
		}
}

int main()
{

	cin >> n >> m >> x >> y;
	memset(a, -1, sizeof(a));
	a[x][y] = 0;
	bfs();
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			{
				cout << a[i][j];
				if (j == m)cout << endl;
				else cout << ' ';
			}

	return 0;
}
