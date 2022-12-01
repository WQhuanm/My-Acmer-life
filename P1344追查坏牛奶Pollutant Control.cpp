#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 100;
const int M = 5000;
int n, m;
int num;//使用memcpy注意
ll ans;
int head[N];
int now[N];
int gap[M << 1];
int dep[N];
int le[N][N];
struct node
{
	ll to, next, w;
} edge[M << 1];

void add(ll u, ll v, ll w)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].w = w;
	head[u] = num;

	edge[++num].next = head[v];
	edge[num].w = 0;
	edge[num].to = u;
	head[v] = num;

}

void bfs()
{
	memset(dep, -1, sizeof(dep));
	dep[n] = 0;
	gap[0]++;
	queue<int>q;
	q.push(n);
	while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = head[x]; i; i = edge[i].next)
				{
					int v = edge[i].to;
					if (dep[v] == -1)
						{
							q.push(v);
							dep[v] = dep[x] + 1;
							gap[dep[v]]++;
						}
				}

		}

}

ll dfs(int x, ll sum)
{
	if (x == n)
		{
			ans += sum;
			return sum;
		}
	ll k, res = 0;
	for (int i = now[x]; i && sum; i = edge[i].next)
		{
			now[x] = i;
			int v = edge[i].to;
			ll w = edge[i].w;
			if (dep[v] == dep[x] - 1 && w)///////////////
				{
					k = dfs(v, min(sum, w));
					if (!k)continue;
					edge[i].w -= k;
					edge[i ^ 1].w += k;
					res += k;
					sum -= k;
					if (!sum)return res;
				}

		}
	gap[dep[x]]--;
	if (!gap[dep[x]])dep[1] = n + 1;
	dep[x]++;
	gap[dep[x]]++;
	return res;
}

int main()
{
	cin >> n >> m;
	ll u, v, w;
	num = 1;
	for (int i = 1; i <= m; ++i)
		{
			cin >> u >> v >> w;
			{
				add(u, v, w);
			}
		}
	bfs();
	ans = 0;
	while (dep[1] < n)
		{
			memcpy(now, head, sizeof(head));
			dfs(1, INF);
		}
	ll ans1 = ans;
	ans = 0;
	memset(gap, 0, sizeof(gap));
	for (int i = 2; i <= num; ++i)
		{
			if (!edge[i].w)edge[i].w = 1, edge[i ^ 1].w = 0;
			else edge[i].w = INF, edge[i ^ 1].w = 0;
		}
	bfs();
	while (dep[1] < n)
		{
			memcpy(now, head, sizeof(head));
			dfs(1, INF);
		}
	cout << ans1 << ' ' << ans << endl;
	return 0;
}
