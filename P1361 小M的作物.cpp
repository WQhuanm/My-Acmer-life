#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;

const int N = 2e7 + 100;//最后情况，有2e3+1e3*1e3左右的边，所以不能开小
const int M = 2e4 + 10;//最坏，点有1e3+2+2e3个
int n, m;
int t = 1e4 + 100;
int head[N ];
int now[N ];
int gap[N ];
int num;
int arr[M];
ll ans, sum;
int dep[M];
struct node
{
	ll to, next, w;
} edge[N];

void add(ll u, ll v, ll w)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].w = w;
	head[u] = num;

	edge[++num].next = head[v];
	edge[num].to = u;
	edge[num].w = 0;
	head[v] = num;
}

void bfs()
{
	memset(dep, -1, sizeof(dep));
	dep[t] = 0;
	gap[0]++;
	queue<int>q;
	q.push(t);
	while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = head[x]; i; i = edge[i].next)
				{
					int v = edge[i].to;
					if (dep[v] == -1)
						{
							dep[v] = dep[x] + 1;
							gap[dep[v]]++;
							q.push(v);
						}
				}
		}
}

ll dfs(int x, ll sum)
{
	if (x == t)
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
	if (!gap[dep[x]])dep[0] = t + 10;
	dep[x]++;
	gap[dep[x]]++;
	return res;
}

int main()
{
	cin >> n;
	int a, b;
	num = 1;
	sum = 0, ans = 0;
	for (int i = 1; i <= n; ++i)//先建立各个点各自与s，t的关系，我们设s为0
		{
			cin >> a;
			sum += a;
			add(0, i, a);
		}
	for (int i = 1; i <= n; ++i)
		{
			cin >> b;
			sum += b;
			add(i, t, b);
		}
	int m;
	cin >> m;
	int k;
	for (int i = 1; i <= m; ++i)//建立集合与虚点的关系
		{
			cin >> k;
			cin >> a >> b;
			sum += a + b;
			add(0, ++n, a);
			add(++n, t, b);
			for (int i = 1; i <= k; ++i)
				{
					cin >> arr[i];
					add(n - 1, arr[i], INF);
					add(arr[i], n, INF);
				}
		}
	bfs();
	while (dep[0] < n)
		{
			memcpy(now, head, sizeof(head));
			dfs(0, INF);
		}
	cout << sum - ans << endl;
	return 0;
}
