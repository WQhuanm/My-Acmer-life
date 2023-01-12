#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 210;

char a[N][N];
int sx, sy, n, m, ways[5][3] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int vis[N][N];
struct node
{
	int x, y, t;
} head, tmp;
void bfs()
{
	memset(vis, 0x3f, sizeof(vis));
	int ans = INF;
	queue<node>q;
	head.x = sx, head.y = sy, head.t = 0;
	q.push(head);
	vis[sx][sy] = -1;
	while (!q.empty())
		{
			head = q.front();
			q.pop();
			if (a[head.x][head.y] == 'r')
				{
					ans = min(ans, head.t);
				}
			for (int i = 0; i < 4; ++i)
				{
					tmp = head;
					tmp.x += ways[i][0], tmp.y += ways[i][1];
					if (a[tmp.x][tmp.y] != '#' && tmp.x >= 1 && tmp.x <= n && tmp.y >= 1 && tmp.y <= m && head.t + 1 < ans)
						{
							if (a[tmp.x][tmp.y] == 'x')
								{
									tmp.t += 2;
									if (tmp.t < vis[tmp.x][tmp.y])
										{
											vis[tmp.x][tmp.y] = tmp.t;
											q.push(tmp);
										}
								}
							else
								{
									tmp.t += 1;
									if (tmp.t < vis[tmp.x][tmp.y])
										{
											vis[tmp.x][tmp.y] = tmp.t;
											q.push(tmp);
										}
								}
						}
				}

		}
	if (ans < INF)
		{
			cout << ans << endl;
		}
	else cout << "Poor ANGEL has to stay in the prison all his life." << endl;

}

int main()
{

	while (cin >> n >> m)
		{
			for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
					{
						cin >> a[i][j];
						if (a[i][j] == 'a')sx = i, sy = j;
					}
			bfs();
		}

	return 0;
}
