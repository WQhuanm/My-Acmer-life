#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
const int mod = 998244353;
const int N = 3e5 + 10;
int a[3][N];
int k, mid;
struct node
{
	int q[N];
	int l, r, k;
	int get_val(int u)
	{
		if (l <= r)
			{
				int v = q[l];
				if (a[k][u] - a[k][v] > mid)return q[l++];
			}
		if (l <= r)
			{
				int v = q[r];
				if (a[k][v] - a[k][u] > mid)return q[r--];
			}
		return 0;
	}
} t[5];

int  scc[N << 1], q[N];
bool vis[N];
int  tot, cnt;
int n;

bool cmp(int x, int y)
{
	return a[k][x] < a[k][y];
}

void dfs(int u)
{
	if (vis[u])return;
	vis[u] = 1;
	for (int i = 0; i < 3; ++i)while (1)
			{
				int v = t[i].get_val(u);
				if (!v)break;
				v = v > n ? v - n : v + n;
				dfs(v);
			}
	q[++tot] = u;
}

void dfs2(int u)
{
	if (!vis[u])return;
	vis[u] = 0, scc[u] = cnt;
	for (int i = 0; i < 3; ++i)while (1)
			{
				int v = t[i].get_val(u > n ? u - n : u + n);
				if (!v)break;
				dfs2(v);
			}
}

bool check()
{
	for (int i = 0; i < 3; ++i)t[i].l = 1, t[i].r = 2 * n;
	tot = cnt = 0;
	for (int i = 1; i <= 2 * n; ++i)if (!vis[i])dfs(i);
	for (int i = 0; i < 3; ++i)t[i].l = 1, t[i].r = 2 * n;
	for (int i = tot; i; --i)if (vis[q[i]])cnt++, dfs2(q[i]);
	for (int i = 1; i <= n; ++i)if (scc[i] == scc[i + n])return 0;//每个集合不能同时出现0与1
	return 1;
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j < 3; ++j)cin >> a[j][i];
			for (int j = 0; j < 3; ++j)cin >> a[j][i + n];
		}
	int mn = inf, mx = -inf;
	for (int i = 0; i < 3; ++i)
		{
			mn = min(mn, *min_element(a[i] + 1, a[i] + 1 + 2 * n));
			mx = max(mx, *max_element(a[i] + 1, a[i] + 1 + 2 * n));
			t[i].k = i;
			for (int j = 1; j <= 2 * n; ++j)t[i].q[j] = j;
			k = i;
			sort(t[i].q + 1, t[i].q + 1 + 2 * n,cmp);
		}
	int l = 0, r = mx - mn, ans = r;
	while (l <= r)
		{
			mid = l + ((r - l) >> 1);
			if (check())ans = mid, r = mid - 1;
			else l = mid + 1;
		}
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
