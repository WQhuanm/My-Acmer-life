#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;
const int N = 2e7 + 100;

struct node
{
	int next, to;
	ll w;
} edge[N];
int num;
int head[N];
//int dep[N];
ll dis[N];
int ch[N][2];
int num1;
void add(int u, int v, ll w)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].w = w;
	head[u] = num;
}

void dfs(int x, int fa)
{
	//dep[x] = dep[fa] + 1;
	for (int i = head[x]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (v != fa)
				{
					dis[v] = dis[x] ^ edge[i].w;
					dfs(v, x);
				}
		}

}

int main()
{
	int n;
	cin >> n;
	int u, v;
	ll w;
	for (int i = 1; i < n; ++i)
		{
			cin >> u >> v >> w;
			add(u, v, w);
			add(v, u, w);
		}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i)
		{

			//	cout << dis[i] << endl;
			int u1 = 0;
			for (int j = 32; j >= 0; --j)
				{
					int t = (dis[i] >> j) & 1;
					if (!ch[u1][t])ch[u1][t] = ++num1;
					u1 = ch[u1][t];
				}
		}
	ll ans = 0;

	for (int i = 1; i <= n; ++i)
		{
			int u1 = 0;
			ll tmp = 0;
			for (int j = 32; j >= 0; --j)
				{
					//cout << ch[u1][1] << endl;
					int t = (dis[i] >> j) & 1;
					if (ch[u1][!t])u1 = ch[u1][!t], tmp += (1 << j);
					else u1 = ch[u1][t];
				}
			ans = max(ans, tmp);
		}

	cout << ans << endl;
	return 0;
}
