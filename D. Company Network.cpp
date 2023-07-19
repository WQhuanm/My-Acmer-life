#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-8
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;

struct node
{
	int to, next;
	ll w;
} edge[N << 1];

int dep[N], head[N], pre[N][32];
int num;

const int lg = 19; //5e5

inline void add(int u, int v, ll w)
{
	edge[++num].next = head[u];
	edge[num].w = w;
	edge[num].to = v;
	head[u] = num;
}

void dfs1(int u, int f, ll w)
{
	dep[u] = dep[f] + w;
	pre[u][0] = f;
	for (int i = 1; i < lg; ++i)
		{
			pre[u][i] = pre[pre[u][i - 1]][i - 1];
		}
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (v != f)dfs1(v, u, edge[i].w);
		}
}
int p[N], b[N];
int dp[N];
void dfs(int u)
{
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			dfs(v);
			dp[u] += dp[v];
		}
}

void mysolve()
{
	int n, t;
	cin >> n >> t;
	ll w;
	for (int i = 2; i <= n; ++i)cin >> p[i];
	for (int i = 2; i <= n; ++i)cin >> b[i];
	for (int i = 2; i <= n; ++i)add(p[i], i, b[i]);
	dfs1(1, 0, 0);
	for (int i = 1; i <= n; ++i)
		{
			cin >> w;
			w++;
			dp[i] += w;
			int u = i;
			for (int j = lg; ~j; --j)if (dep[i] - dep[pre[u][j]] <= t)u = pre[u][j];
			dp[pre[u][0]] -= w;
		}
	dfs(1);
	cout << max_element(dp + 1, dp + 1 + n) - dp << " " << *max_element(dp + 1, dp + 1 + n) << endl;

}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
