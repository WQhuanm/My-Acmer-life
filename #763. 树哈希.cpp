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
const int N = 1e6 + 10;

vector<int>edge[N];

typedef unsigned long long ull;
const ull mask = std::chrono::steady_clock::now().time_since_epoch().count();

ull h[N];
set<ull>s;

ull shift(ull x)
{
	x ^= mask;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	x ^= mask;
	return x;
}

void dfs(int u, int f)
{
	h[u] = 1;
	for (auto v : edge[u])if (v != f)
			{
				dfs(v, u);
				h[u] += shift(h[v]);
			}
	s.insert(h[u]);
}

int n, x, y;
void mysolve()
{
	cin >> n;
	for (int i = 1; i < n; ++i)cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	dfs(1, 0);
	cout << (int)s.size() << endl;
}

signed main()
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
