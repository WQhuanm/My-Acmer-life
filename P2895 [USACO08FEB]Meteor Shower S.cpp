#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 500;

int a[N][N];
int way[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool vis[N][N];
struct node
{
	int x, y, t;
};
node head;
ll ans;
void bfs()
{
	queue<node>q;
	q.push({0, 0, 0});
	vis[0][0] = 1;
	while (!q.empty())
		{
			head = q.front();
			q.pop();
			if (a[head.x][head.y] == -1)
				{
					ans = head.t;
					return;
				}
			for (int i = 0; i < 4; ++i)
				{
					int tx = head.x + way[i][0], ty = head.y + way[i][1];
					if (tx >= 0 && ty >= 0 && (head.t < a[tx][ty] - 1 || a[tx][ty] == -1) && !vis[tx][ty])
						{
							vis[tx][ty] = 1;
							q.push({tx, ty, head.t + 1});
						}
				}

		}
}

int main()
{
	int n, x, y, t;
	cin >> n;
	memset(a, -1, sizeof(a));
	for (int j = 1; j <= n; ++j)
		{
			cin >> x >> y >> t;
			if (a[x][y] == -1 || a[x][y] > t)a[x][y] = t;
			for (int i = 0; i < 4; ++i)
				{
					int tx = x + way[i][0], ty = y + way[i][1];
					if (tx >= 0 && ty >= 0)if (a[tx][ty] == -1 || a[tx][ty] > t)a[tx][ty] = t;
				}
		}
	if (a[0][0] == -1)
		{
			cout << 0 << endl;
			return 0;
		}
	ans = -1;
	bfs();
	cout << ans << endl;
	return 0;
}
