#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
const int M = 1000;
int n, m;
int head[N];
int now[N];
int gap[N];
int dep[M];
int num;
ll ans;
struct node
{
	int to, next, w;
} edge[N];
void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].w = 1;
	edge[num].to = v;
	head[u] = num;

	edge[++num].next = head[v];
	edge[num].w = 0;
	edge[num].to = u;
	head[v] = num;
}

void bfs()
{
	memset(dep, -1, sizeof(dep));
	dep[n + 1] = 0;
	gap[0]++;
	queue<int>q;
	q.push(n + 1);
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
	if (x == n + 1)
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
			if (dep[v] == dep[x] - 1 && w)
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
	if (!gap[dep[x]])dep[0] = n + 4;
	dep[x]++;
	gap[dep[x]]++;
	return res;
}

int main()
{

	cin >> n >> m;
	int x, y;
	num = 1;
	for (int i = 1; i <= n; ++i)
		{
			cin >> x;
			if (x == 1)add(i, 0), add(0, i);
			if (x == 0)add(i, n + 1), add(n + 1, i);
		}
	for (int i = 1; i <= m; ++i)
		{
			cin >> x >> y;
			add(x, y), add(y, x);
		}
	bfs();
	ans = 0;
	while (dep[0] < n + 2)
		{
			memcpy(now, head, sizeof(head));
			dfs(0, INF);
		}
	cout << ans << endl;
	return 0;
}
