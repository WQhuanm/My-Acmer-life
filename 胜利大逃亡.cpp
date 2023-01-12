#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 55;
int a, b, c, t, s[N][N][N];
bool vis[N][N][N];
int wayx[8] = {1, -1, 0, 0, 0, 0};
int wayy[8] = {0, 0, 1, -1, 0, 0};
int wayz[8] = {0, 0, 0, 0, 1, -1};
struct node
{
	int x, y, z, t;
} head, tmp;
void bfs()
{
	memset(vis, 0, sizeof(vis));
	queue<node>q;
	q.push({1, 1, 1});
	vis[1][1][1] = 1;
	while (!q.empty())
		{
			head = q.front();
			q.pop();
			if (head.x == a && head.y == b && head.z == c)
				{
					if (head.t <= t)
						printf("%d\n", head.t);
					else 	printf("-1\n");
					return;
				}
			for (int i = 0; i < 6; ++i)
				{
					tmp = head;
					tmp.x += wayx[i];
					tmp.y += wayy[i];
					tmp.z += wayz[i];
					++tmp.t;
					if (!s[tmp.x][tmp.y][tmp.z] && tmp.x >= 1 && tmp.x <= a && tmp.y >= 1 && tmp.y <= b && tmp.z >= 1 && tmp.z <= c && !vis[tmp.x][tmp.y][tmp.z])
						{
							vis[tmp.x][tmp.y][tmp.z] = 1;
							q.push(tmp);
						}
				}

		}
	printf("-1\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		{
			scanf("%d %d %d %d", &a, &b, &c, &t);
			for (int i = 1; i <= a; ++i)for (int j = 1; j <= b; ++j)for (int k = 1; k <= c; ++k)scanf("%d", &s[i][j][k]);
			bfs();
		}

	return 0;
}
