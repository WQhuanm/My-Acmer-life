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

ll t[N];
int a[N];
vector<int>edge[N];
multiset<int>s;
int in[N];
int n, m, k;

void dfs(int u)
{
	for (auto v : edge[u])if (t[v] < t[u])
			{
				s.erase(s.find(t[v]));
				t[v] += k;
				s.insert(t[v]);
				dfs(v);
			}
}

void mysolve()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 1; i <= n; ++i)in[i] = 0, edge[i].clear();
	s.clear();
	int x, y;
	while (m--)
		{
			cin >> x >> y;
			edge[x].push_back(y), in[y]++;
		}
	priority_queue<pii, vector<pii>, greater<pii>>q, p, tmp;
	for (int i = 1; i <= n; ++i)if (!in[i])q.push({a[i], i}), p.push({a[i], i});
	int now = 0;

	while (!q.empty())
		{
			int u = q.top().second, cur = q.top().first;
			q.pop();
			now = cur - now % k + now;
			t[u] = now, s.insert(now);
			for (auto v : edge[u])if (--in[v] == 0)
					{
						if (a[v] >= a[u])q.push({a[v], v});
						else tmp.push({a[v], v});
					}
			if (q.empty())
				{
					now = (now + k - 1) / k * k;
					while (!tmp.empty())q.push(tmp.top()), tmp.pop();
				}
		}
	ll ans = *prev(s.end()) - *s.begin();
	while (!p.empty())
		{
			int u = p.top().second;
			p.pop();
			s.erase(s.find(t[u]));
			t[u] += k;
			s.insert(t[u]);
			dfs(u);
			ans = min(ans, *prev(s.end()) - *s.begin());
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
