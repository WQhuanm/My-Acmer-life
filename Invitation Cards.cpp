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
const int N = 1e6 + 10;

int head[N], dis1[N], hd[N], dis2[N];
bool vis1[N], vis2[N];
int num, num1;
int n, m;

struct node
{
	int next, to, w;
} edge[N], eg[N];

void add(int u, int v, int w)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].w = w;
	head[u] = num;
}

void add1(int u, int v, int w)
{
	eg[++num1].next = hd[u];
	eg[num1].to = v;
	eg[num1].w = w;
	hd[u] = num1;
}

void dijkstra()
{
	memset(dis1, 0x3f, sizeof(dis1));
	memset(dis2, 0x3f, sizeof(dis2));
	memset(vis1, 0, sizeof(vis1));
	memset(vis2, 0, sizeof(vis2));
	dis1[1] = dis2[1] = 0;
	priority_queue<pii, vector<pii>, greater<pii>>q1, q2;
	q1.push({0, 1});
	while (!q1.empty())
		{
			int u = q1.top().second;
			q1.pop();
			if (vis1[u])continue;
			vis1[u] = 1;
			for (int i = head[u]; i; i = edge[i].next)
				{
					int v = edge[i].to, w = edge[i].w;
					if (dis1[v] > dis1[u] + w)
						{
							dis1[v] = dis1[u] + w;
							if (!vis1[v])
								q1.push({dis1[v], v});
						}
				}
		}
	q2.push({0, 1});
	while (!q2.empty())
		{
			int u = q2.top().second;
			q2.pop();
			if (vis2[u])continue;
			vis2[u] = 1;
			for (int i = hd[u]; i; i = eg[i].next)
				{
					int v = eg[i].to, w = eg[i].w;
					if (dis2[v] > dis2[u] + w)
						{
							dis2[v] = dis2[u] + w;
							if (!vis2[v])
								{
									q2.push({dis2[v], v});
								}
						}
				}
		}
}

int main()
{
	//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		{
			memset(head, 0, sizeof(head));
			memset(hd, 0, sizeof(hd));
			num = num1 = 0;
			cin >> n >> m;
			int u, v, w;
			for (int i = 1; i <= m; ++i)
				{
					cin >> u >> v >> w;
					add(u, v, w);
					add1(v, u, w);
				}
			dijkstra();
			int ans = 0;
			for (int i = 1; i <= n; ++i)
				{
					//	cout << dis1[i] << ' ' << dis2[i] << endl;
					ans += dis1[i] + dis2[i];
				}
			cout << ans << endl;
		}
	return 0;
}
