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
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;

int a[N];
int k = 0;
int n, m;
int dfn[N << 2], low[N << 2], sta[N << 2], scc[N << 2], sz[N << 2];//点为4n个
bool insta[N << 2];
int top, dfncnt, cnt, tot;//tot记录当前点数
vector<int>edge[N << 2], kind[N];

void init()
{
	for (int i = 0; i <= 2 * n; ++i)dfn[i] = 0; //2*n个元素
	for (int i = 0; i <= tot; ++i)edge[i].clear();
	top = cnt = dfncnt = 0;
	tot = 2 * n; //后面是辅助点
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++dfncnt;
	insta[u] = 1;
	sta[++top] = u;
	for (auto v : edge[u])
		{
			if (!dfn[v])
				{
					tarjan(v);
					low[u] = min(low[u], low[v]);
				}
			else if (insta[v])
				{
					low[u] = min(dfn[v], low[u]);
				}
		}
	if (low[u] == dfn[u])
		{
			sz[++cnt] = 0;
			while (1)
				{
					int v = sta[top--];
					insta[v] = 0;
					scc[v] = cnt;
					++sz[cnt];
					if (u == v)break;
				}
		}
}

bool _2sat()
{
	for (int i = 1; i <= 2 * n; ++i)
		{
			if (!dfn[i])tarjan(i); //2n个元素，辅组点没必要
		}
	for (int i = 1; i <= n; ++i)if (scc[i] == scc[i + n])return 0; //每个集合不能同时出现0与1
	return 1;
}

void pre_dis(int u)//对集合u优化建图
{
	if ((int)kind[u].size() < 2)return;
	for (int i = 0; i < (int)kind[u].size(); ++i)//处理前缀点
		{
			int now = kind[u][i], p_now = now <= n ? now + n : now - n;
			edge[++tot].push_back(p_now);//当前前缀点连接当前反点
			if (i)edge[now].push_back(tot - 1), edge[tot].push_back(tot - 1);//当前原点和前缀点连接上一个前缀点
		}
	for (int i = 0; i < (int)kind[u].size(); ++i) //处理后缀点
		{
			int now = kind[u][i], p_now = now <= n ? now + n : now - n;
			edge[now].push_back(++tot);//原点连接当前后缀点
			if (i)edge[tot - 1].push_back(tot), edge[tot - 1].push_back(p_now);//上一个后缀点连接反点和当前后缀点
		}
}

void pre_solve()
{
	init();//先输入n
	_2sat();
}

void mysolve()
{
	map<pii, int>mp;
	cin >> n;
	init();
	edge[n + 1].push_back(1);
	edge[n-1+n].push_back(n-1);
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			if (i > 1)
				{
					pii tmp = {a[i - 1], a[i]};
					if (!mp.count(tmp))mp[tmp] = ++k;
					kind[mp[tmp]].push_back(i - 1);
					edge[i + n].push_back(i - 1);
					if (i != 2 && i != n)edge[i - 1 + n].push_back(i);
				}
		}
	for (int i = 1; i <= k; ++i)pre_dis(i);
	if (!_2sat())
		{
			cout << "NO" << endl;
		}
	else
		{
			vector<int>ans;
			for (int i = 1; i < n; ++i)if (scc[i] < scc[i + n])ans.push_back(i);
			cout << (int)ans.size() << endl;
			for (auto v : ans)cout << v << " ";
			cout << endl;
		}
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
