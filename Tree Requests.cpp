#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 5e5 + 10;

int n, tot;
int a[N];
int sz[N], mx[N], col[N], son[N], id[N], num[N];
int cnt[N][26], dep[N];
bool ans[N];
string s;
vector<int>edge[N];
vector<pii>que[N];

void pre_dfs(int u, int f)//预处理树儿子
{
	dep[u] = dep[f] + 1;
	id[u] = ++tot, num[tot] = u;
	sz[u] = 1, mx[u] = son[u] = 0;
	for (int v : edge[u])if (v != f)
			{
				pre_dfs(v, u);
				sz[u] += sz[v];
				if (sz[v] > mx[u])mx[u] = sz[v], son[u] = v;
			}
}

int now[N];
void add(int d, int c)
{
	cnt[d][c]++;
	if (cnt[d][c] & 1)now[d]++;
	else now[d]--;
}

void del(int d, int c)
{
	if (cnt[d][c] & 1)now[d]--;
	else now[d]++;
	cnt[d][c]--;
}

void dfs(int u, int f, bool fl)
{
	for (int v : edge[u])if (v != f && v != son[u])dfs(v, u, 0);//先处理好轻子树的答案
	if (son[u])dfs(son[u], u, 1);//递归到重子树处理，然后继承重子树信息
	for (int v : edge[u])if (v != f && v != son[u])//dfs序连续，暴力访问所有轻子树节点
			{
				//                                （也可以dfs访问）
				for (int i = id[v]; i < id[v] + sz[v]; ++i)add(dep[num[i]], s[num[i]] - 'a');
			}

	add(dep[u], s[u] - 'a');
	for (auto [k, id] : que[u])//回答与u有关的询问
		{
			if (now[ k] <= 1)ans[id] = 1;
			//                        ans[id] = ;
		}
	if (!fl)//如果是轻子树，需要清空其留下的信息
		{
			for (int i = id[u]; i < id[u] + sz[u]; ++i)del(dep[num[i]], s[num[i]] - 'a');
		}
}
int q;

void mysolve()
{
	cin >> n >> q;
	int x, y;
	for (int i = 2; i <= n; ++i)cin >> x, edge[x].push_back(i), edge[i].push_back(x);
	cin >> s;
	s = '$' + s;
	for (int i = 1; i <= q; ++i)
		{
			cin >> x >> y;
			que[x].push_back({y, i});
		}
	pre_dfs(1, 0);
	dfs(1, 0, 1);
	for (int i = 1; i <= q; ++i)cout << (ans[i] ? "Yes" : "No") << endl;
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
	system("pause");
	return 0;
}
