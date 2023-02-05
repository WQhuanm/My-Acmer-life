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
const int N = 1e2 + 10;

int head[N * N], dis[N], a[N], cnt[N];
bool vis[N];
int num;

int n;
struct node
{
	int next, to, w;

} edge[N * N];

void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}

void spfa()
{
	queue<int>q;
	memset(vis, 0, sizeof(vis));
	memset(dis, -0x3f, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	dis[1] = 100;
	q.push(1);
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			if (dis[u] < INF)
				vis[u] = 0;
			for (int i = head[u]; i; i = edge[i].next)
				{
					int v = edge[i].to;
					if (dis[v] < dis[u] + a[v] && dis[u] + a[v] > 0)
						{
							dis[v] = dis[u] + a[v];
							if (!vis[v])
								{
									q.push(v);
									cnt[v]++;
									if (cnt[v] > n)dis[v] = INF;
								}
						}
				}
		}

}

int main()
{
	while (cin >> n && n != -1)
		{
			memset(head, 0, sizeof(head));
			num = 0;
			int v, m;
			for (int i = 1; i <= n; ++i)
				{
					cin >> a[i] >> m;
					for (int j = 1; j <= m; ++j)
						{
							cin >> v;
							add(i, v);
						}
				}
			spfa();
			//cout << dis[n] << endl;
			if (dis[n] > 0)cout << "winnable" << endl;
			else cout << "hopeless" << endl;
		}

	return 0;
}
