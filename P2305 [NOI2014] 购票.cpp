#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-8
typedef pair<int, ll> pii;
const int N = 2e5 + 10;

int n, type;
int len[N], p[N];
ll dp[N], dis[N], q[N], lim[N];
vector<int> t[N], pre_id[N], pre_len[N];
vector<ll>que;
vector<pii> edge[N];
double slope(int a, int b)
{
	return ((double)dp[a] - dp[b]) / ((double) dis[a] - dis[b]);
}

void push(int x, int id)
{
	pre_len[x].push_back(len[x]);
	if (len[x] > 1)
		{
			int l = 1, r = len[x] - 1;
			int ans = len[x];
			while (l <= r)
				{
					int mid = l + ((r - l) >> 1);
					if (slope(t[x][mid], id) - slope(t[x][mid], t[x][mid + 1]) < -eps)ans = mid, r = mid - 1;
					else l = mid + 1;
				}
			len[x] = ans;
		}
	++len[x];
	if (len[x] == (int)t[x].size())pre_id[x].push_back(0), t[x].push_back(id);////////////////////////
	else pre_id[x].push_back(t[x][len[x]]), t[x][len[x]] = id;
}

void pop(int x)
{
	t[x][len[x]] = pre_id[x].back(), pre_id[x].pop_back();
	len[x] = pre_len[x].back(), pre_len[x].pop_back();
}

void add(int x, int id)
{
	for (int i = x; i <= n; i += i & -i)
		~id ? push(i, id) : pop(i);
}

int find_id(int x, int id)
{
	int l = 1, r = len[x] - 1, ans = len[x];
	while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if (slope(t[x][mid], t[x][mid + 1]) - p[id] < -eps)l = ans = mid + 1;
			else ans = mid, r = mid - 1;
		}
	return t[x][ans];
}

ll  ask(int x, int id, int f)
{
	ll ans =  dp[f] - dis[f] * p[id] + q[id] + dis[id] * p[id];
	for (int i = x; i; i -= i & -i)
		if (len[i])
			{
				int j = find_id(i, id);
				ans = min(ans, dp[j] - dis[j] * p[id] + q[id] + dis[id] * p[id]);
			}
	return ans;
}

void dfs(int u, int f)
{
	if (u != 1)dp[u] = ask(n - (lower_bound(que.begin(), que.end(), dis[u] - lim[u]) - que.begin()), u, f);
	add(n - (int)que.size(), u), que.push_back(dis[u]);
	for (auto [v, w] : edge[u])
		dis[v] = dis[u] + w, dfs(v, u);
	que.pop_back(), add(n - (int)que.size(), -1);
}

void mysolve()
{
	cin >> n >> type;
	int f;
	ll x;
	t[1].push_back(0);
	for (int i = 2; i <= n; ++i)cin >> f >> x >> p[i] >> q[i] >> lim[i], edge[f].push_back({i, x}), t[i].push_back(0);
	dfs(1, 0);

	for (int i = 2; i <= n; ++i)cout << dp[i] << endl;
}

int32_t main()
{
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	//	system("pause");
	return 0;
}
