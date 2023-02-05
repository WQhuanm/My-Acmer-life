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
const int N = 5e4 + 10;

int  head[N * 3], dis[N];
bool vis[N];
int num, l, r;
struct node
{
	int next, to, w;
} edge[N * 3]; //最多建立N*3的边

void add(int u, int v, int w)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].w = w;
	head[u] = num;
}

void spfa()
{
	queue<int>q;
	memset(dis, -0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[l - 1] = 0; //从左边遍历到右边s[r]-s[l-1]就是答案了，一般设s[l-1]=0
	q.push(l - 1);
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			vis[u] = 0;
			for (int i = head[u]; i; i = edge[i].next)
				{
					int v = edge[i].to, w = edge[i].w;
					if (dis[v] < dis[u] + w)
						{
							dis[v] = dis[u] + w;
							if (!vis[v])vis[v] = 1, q.push(v);
						}
				}
		}

}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, u, v, w;
	while (cin >> n)
		{
			memset(head, 0, sizeof(head));
			num = 0;
			l = INF, r = -INF;
			for (int i = 1; i <= n; ++i)
				{
					cin >> u >> v >> w;
					add(u - 1, v, w);
					l = min(l, u), r = max(r, v);
				}
			for (int i = l; i <= r; ++i)add(i, i - 1, -1), add(i - 1, i, 0);
			spfa();
			cout << dis[r] << endl;
		}
	return 0;
}
