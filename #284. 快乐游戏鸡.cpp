#include <bits/stdc++.h>
using namespace std;
#define ll               long long
const int N = 3e5 + 10;
typedef pair<int, int> pii;
const int lg = 19;
int n, tot;
int a[N], sz[N], mx[N], son[N], id[N], dep[N], head[N], tail[N], mx_[N][26], pre[N][26];
ll ans[N], sum[N];
vector<int>edge[N];
vector<pii>que[N];

struct node
{
	ll w;
	int dep;
} q[N], p[N];

void push(int u, node x)
{
	while (head[u] <= tail[u] && x.w >= q[head[u]].w)head[u]++;
	if (head[u] > tail[u])q[--head[u]] = x, sum[head[u]] = 0;
	else
		{
			if (x.dep < q[head[u]].dep)q[--head[u]] = x, sum[head[u]] = sum[head[u] + 1] + q[head[u] + 1].dep * (q[head[u] + 1].w - x.w);
		}
}

void dfs1(int u, int f)
{
	dep[u] = dep[f] + 1, pre[u][0] = f, mx_[u][0] = a[f];
	for (int i = 1; i < lg; ++i)pre[u][i] = pre[pre[u][i - 1]][i - 1], mx_[u][i] = max(mx_[u][i - 1], mx_[pre[u][i - 1]][i - 1]);
	mx[u] = son[u] = 0;
	sz[u] = 1;
	for (int v : edge[u])
		{
			dfs1(v, u);
			sz[u] += sz[v];
			if (sz[v] > mx[u])mx[u] = sz[v], son[u] = v;
//			if (sz[v] > sz[son[u]])son[u] = v;
		}
//	sz[u] = sz[son[u]] + 1;
}

void merge(int u, int v)
{
	int cnt = 0;
	while (head[u] <= tail[u] && q[head[u]].dep <= q[tail[v]].dep)p[++cnt] = q[head[u]++];////////////////////
	while (cnt && head[v] <= tail[v])
		{
			if (p[cnt].dep >= q[tail[v]].dep)push(u, p[cnt--]);
			else push(u, q[tail[v]--]);
		}
	while (cnt)push(u, p[cnt--]);
	while (head[v] <= tail[v])push(u, q[tail[v]--]);
}

ll ask(int u, int v)
{
	int mxn = 0;
	for (int i = lg; ~i; --i)if (dep[pre[v][i]] > dep[u])mxn = max(mxn, mx_[v][i]), v = pre[v][i];
	if (q[head[u]].w >= mxn)return (ll)mxn * (q[head[u]].dep - dep[u]);
	int l = head[u], r = tail[u], ans = head[u];
	while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if (q[mid].w >= mxn)ans = mid, r = mid - 1;
			else  l = mid + 1;
		}
	return sum[head[u]] - sum[ans] + q[head[u]].w * q[head[u]].dep - dep[u] * (ll)mxn - (ll)q[ans].dep * (q[ans].w - mxn);
}

void dfs(int u)
{
//	++tot;
	if (son[u])
		{
			dfs(son[u]);
			head[u] = head[son[u]], tail[u] = tail[son[u]];
		}
	else head[u] = id[u], tail[u] = id[u] - 1;
	for (int v : edge[u])if (v != son[u])dfs(v), merge(u, v);
	for (auto [v, i] : que[u])
		ans[i] = ask(u, v) + dep[v] - dep[u];
	push(u, {a[u], dep[u]});
}

void pre_id(int u)
{
	id[u] = ++tot;
	for (int v : edge[u])if (v != son[u])pre_id(v);
	if (son[u])pre_id(son[u]);
}

void mysolve()
{
	cin >> n;
	int x, y, q;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 2; i <= n; ++i)cin >> x, edge[x].push_back(i);
	cin >> q;
	for (int i = 1; i <= q; ++i)
		{
			cin >> x >> y;
			que[x].push_back({y, i});
		}
	dfs1(1, 0);
	pre_id(1);
	dfs(1);
	for (int i = 1; i <= q; ++i)cout << ans[i] << endl;
}

int32_t main()
{
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	return 0;
}
