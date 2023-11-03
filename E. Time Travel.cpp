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

int n, t, k;
vector<int>tim[N];
vector<pii>edge[N];

struct node
{
	int x, t;
	bool operator<(const node&k)const
	{
		return t > k.t;
	}
};

void mysolve()
{
	cin >> n >> t;
	int sz, x, y;
	for (int i = 1; i <= t; ++i)
		{
			cin >> sz;
			for (int j = 1; j <= sz; ++j)cin >> x >> y, edge[x].push_back({y, i}), edge[y].push_back({x, i});
		}
	cin >> k;
	for (int i = 1; i <= k; ++i)cin >> x, tim[x].push_back(i);
	vector<int>vis(n + 1, inf);
	vector<bool>book(n + 1);
	vis[1] = 0;
	priority_queue<node>q;
	q.push({1, 0});
	while (!q.empty())
		{
			int u = q.top().x;
			q.pop();
			if (book[u])continue;
			book[u] = 1;
			for (auto [v, kind] : edge[u])if (!tim[kind].empty() && tim[kind].back() > vis[u])
					{
						int tmp = *upper_bound(tim[kind].begin(), tim[kind].end(), vis[u]);
						if (tmp < vis[v])vis[v] = tmp, q.push({v, vis[v]});
					}
		}
	if (vis[n] == inf)cout << -1 << endl;
	else cout << vis[n] << endl;
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
