#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 5e3 + 10;

int n, m, dis[N], cnt[N], head[N], num;
bool vis[N];
struct node
{
	int next, to, t;
} edge[N * N];

void add(int u, int v, int w)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].t = w;
	head[u] = num;
}

bool spfa()
{
	memset(dis, 0x3f, sizeof(dis));
	dis[0] = 0;
	queue<int>q;
	q.push(0);
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			vis[u] = 0;
			for (int i = head[u]; i; i = edge[i].next)
				{
					int v = edge[i].to, w = edge[i].t;
					if (dis[v] > dis[u] + w)
						{
							dis[v] = dis[u] + w;
							cnt[v] = cnt[u] + 1;
							if (cnt[v] == n + 1)return 0;
							if (!vis[v])vis[v] = 1, q.push(v);
						}
				}
		}
	return 1;
}

int main()
{
	cin >> n >> m;
	int u, v, w;
	for (int i = 1; i <= n; ++i)add(0, i, 0);
	for (int i = 1; i <= m; ++i)
		{
			cin >> u >> v >> w;
			add(v, u, w);
		}
	if (spfa())
		{
			for (int i = 1; i <= n; ++i)cout << dis[i] << ' ';
		}
	else cout << "NO" << endl;

}
