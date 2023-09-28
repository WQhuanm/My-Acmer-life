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
const int N = 3e5 + 10;

int fa[N];
int n, m, k;

int find(int x)
{
	if (fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
}
void mysolve()
{
	cin >> n >> m >> k;
	vector<int>p(4);
	for (int i = 1; i <= 2 * (n + m); ++i)fa[i] = i;
	bool flag = 1;
	while (k--)
		{
			for (auto &v : p)cin >> v;
			int x = p[0], y = min(p[1], p[3]);
			if (p[1] < p[3]) //不等
				{
					if (find(x) == find(y + n) || find(x + n + m) == find(y + n + n + m))flag = 0;
					fa[find(x)] = find(y + n + n + m), fa[find(x + n + m)] = find(y + n);
				}
			else
				{
					if (find(x) == find(y + n + n + m) || find(x + n + m) == find(y + n))flag = 0;
					fa[find(x)] = find(y + n), fa[find(x + n + m)] = find(y + n + n + m);
//				if(fx!=fy
				}
		}
	cout << (flag ? "YES" : "NO") << endl;
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
