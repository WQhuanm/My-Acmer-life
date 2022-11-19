#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 5e5 + 100;

int n, m, s;

struct poi
{
	int s, p;
};

vector<poi>a[N];

bool vis[N];
int dis[N];

void spfa(int s)
{
	memset(dis, 0x3f, sizeof(dis));
	queue<int>q;
	q.push(s);
	dis[s] = 0;
	while (!q.empty())
		{
			int tmp = q.front();
			q.pop();
			vis[tmp] = 0;//进来就重新标记为没访问，保证后面更新了可以重新访问
			for (int i = 0; i < (int)a[tmp].size(); ++i)//对以tmp点出发的所有边遍历
				{
					int j = a[tmp][i].s;
					int p = a[tmp][i].p;
					if (dis[j] > dis[tmp] + p)
						{
							dis[j] = dis[tmp] + p;
							if (!vis[j])
								{
									vis[j] = 1;//避免重复存入队列里面
									q.push(j);
								}
						}
				}

		}

}

int main()
{
	cin >> n >> m >> s;
	int u, v, w;
	for (int i = 1; i <= m; ++i)
		{
			cin >> u >> v >> w;
			a[u].push_back({v, w});//存入单向边

		}
	spfa(s);
	for (int i = 1; i <= n; ++i)
		{
			if (dis[i] < INF)cout << dis[i];
			else cout << (((ll)1 << 31) - 1);
			if (i == n)cout << '\n';
			else cout << ' ';
		}
}

