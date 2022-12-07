#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 700;
const int M = 1e6 + 100;
int s = 0, t;
int num;
int head[N];
int now[N];
int gap[N];
int dep[N];
bool vis[M];//vis是对时间点的访问，开的区间是整个允许时间长度
ll ans;
int a[N];
struct node
{
	int next, to;
	ll w;
} edge[N * N];

struct work
{
	int s, e;
	ll n, t;
} arr[N];

void add(int u, int v, ll w)
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

void init()
{
	num = 1, ans = 0;
	memset(gap, 0, sizeof(gap));
	memset(head, 0, sizeof(head));
	memset(arr, 0, sizeof(arr));
	memset(vis, 0, sizeof(vis));
	memset(a, 0, sizeof(a));

}

void bfs()
{
	memset(dep, -1, sizeof(dep));
	queue<int>q;
	dep[t] = 0;
	gap[0]++;
	q.push(t);
	while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = head[x]; i; i = edge[i].next)
				{
					int v = edge[i].to;
					ll w = edge[i ^ 1].w;
					if (dep[v] == -1 && w)
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
	if (!gap[dep[x]])dep[s] = t + 1;
	dep[x]++;
	gap[dep[x]]++;
	return res;

}
int main()
{
	int n, m;
	while (cin >> n >> m)
		{
			int k = 0, sum = 0;
			t = 2 * n + 10;
			init();
			for (int i = 1; i <= n; ++i)
				{
					cin >> arr[i].s >> arr[i].n >> arr[i].e >> arr[i].t;
					if (!vis[arr[i].s])vis[arr[i].s] = 1, a[++k] = arr[i].s;
					if (!vis[arr[i].e])vis[arr[i].e] = 1, a[++k] = arr[i].e;
					add(s, i, arr[i].n * arr[i].t);
					sum += arr[i].n * arr[i].t;
				}
			sort(a + 1, a + 1 + k);//存入时间点并排序
			for (int i = 2; i <= k; ++i)add(n + i, t, (a[i] - a[i - 1])*m);//把时间段与汇点相连   //任务点为1到n，所以时间点存后，都是从n+i开始
			for (int i = 1; i <= n; ++i)for (int j = 2; j <= k; ++j)
					{
						if (arr[i].s <= a[j - 1] && arr[i].e >= a[j])add(i, n + j, INF);//满足a<区间起点（不是区间终点，必须整个个时间段在ab里面）,b>区间终点,就可以连接任务与该时间段
					}
			bfs();
			while (dep[s] < t)
				{
					memcpy(now, head, sizeof(head));
					dfs(0, INF);
				}
			//cout << sum << ' ' << ans << endl;
			if (sum == ans)cout << "Yes" << endl;
			else cout << "No" << endl;
		}

	return 0;
}
