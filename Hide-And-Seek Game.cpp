#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define int ll
const int N = 3e3 + 10;
const int lg = 19;

vector<int>edge[N];
int dep[N], pre[N][26];

void dfs1(int u, int f)
{
	dep[u] = dep[f] + 1;
	pre[u][0] = f;
	for (int i = 1; i < lg; ++i)pre[u][i] = pre[pre[u][i - 1]][i - 1];
	for (auto v : edge[u])if (v != f)dfs1(v, u);
}

inline int LCA(int u, int v)
{
	if (dep[v] != dep[u])
		{
			if (dep[u] < dep[v])swap(u, v);
			for (int i = lg; ~i; --i)if (dep[pre[u][i]] >= dep[v])u = pre[u][i];
		}
	if (u == v)return u;
	for (int i = lg; ~i; --i)if (pre[u][i] != pre[v][i])u = pre[u][i], v = pre[v][i];
	return pre[u][0];
}

vector<int> toway(int x, int y)
{
	int lca = LCA(x, y);
	vector<int>s1;
	while (1)
		{
			s1.push_back(x);
			if (x == lca)break;
			x = pre[x][0];
		}
	vector<int>tmp;
	while (y != lca)tmp.push_back(y), y = pre[y][0];
	reverse(tmp.begin(), tmp.end());
	for (auto v : tmp)s1.push_back(v);
	return s1;
}

struct node
{
	int a, b, c;
	bool fl;
} a[N];

void exgcd(int a, int b, int &x, int &y)//&直接修改值
{
	if (!b)x = 1, y = 0;
	else
		{
			exgcd(b, a % b, y, x);//x继承了深层的y,y就继承深层的x，y再减去(a/b)*y2即-(a/b)*x即可
			y -= (a / b) * x;
		}
}

int getans(int a, int b, int c)
{
	a %= b, c %= b;
	c = (b + c) % b;
	int g = __gcd(a, b);
	if (c % g)return -1;
	int t = b / __gcd(a, b);
//	int b1 = b;
	a /= g, c /= g, b /= g;
	int x, y;
	exgcd(a, b, x, y);
	x %= b;
	x = (x + b) % b; //保证逆元为正数
	int ans = x * c;

//	for (int i = 1; i < g; ++i)
//		{
//			ans = min(ans, (x * c % b1 + i * b%b1) % b1);
//		}

	ans = (ans % t + t) % t;
	return ans;

}

void mysolve()
{
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)edge[i].clear();
	for (int i = 1; i < n; ++i)
		{
			cin >> x >> y;
			edge[x].push_back(y), edge[y].push_back(x);
		}
	dfs1(1, 0);
	while (m--)
		{
			for (int i = 1; i <= n; ++i)a[i].fl = 0;
			cin >> x >> y;
			vector<int> s1 = toway(x, y);
			for (int i = 0; i < (int)s1.size(); ++i)
				{
					a[s1[i]] = {i, 2 * (int)s1.size() - 2, 2 * (int)s1.size() - 2 * i - 2, 1};
				}
			cin >> x >> y;
			vector<int> s2 = toway(x, y);
			ll t = 1e18, vis = -1;
			for (int i = 0; i < (int)s2.size(); ++i)
				{
					if (a[s2[i]].fl == 1)
						{
							node p = a[s2[i]], q = {i, 2 * (int)s2.size() - 2, 2 * (int)s2.size() - 2 * i - 2, 1};
							int ans = -1;
							if ((ans = getans(p.b, q.b, q.a - p.a + q.c - p.c)) != -1)
								{
									int t1 = p.a + p.b * ans +  p.c ;
									if (t1 < t)t = t1, vis = s2[i];
								}
							if ((ans = getans(p.b, q.b, q.a - p.a + q.c)) != -1)
								{
									int t1 = p.a + p.b * ans ;
									if (t1 < t)t = t1, vis = s2[i];
								}
							if ((ans = getans(p.b, q.b, q.a - p.a  - p.c)) != -1)
								{
									int t1 = p.a + p.b * ans +  p.c;
									if (t1 < t)t = t1, vis = s2[i];
								}
							if ((ans = getans(p.b, q.b, q.a - p.a)) != -1)
								{
									int t1 = p.a + p.b * ans ;
									if (t1 < t)t = t1, vis = s2[i];
								}

						}
				}
			cout << vis << endl;
		}
}

int32_t main()
{
//	freopen("in.in", "r", stdin);
//	freopen("out2.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
//	system("pause");
	return 0;
}
