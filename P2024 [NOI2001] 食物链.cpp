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

int n, k;
int fa[N];

int find(int x)
{
	if (fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
}
void mysolve()
{
	cin >> n >> k;
	int cnt = 0;
	for (int i = 1; i <= 3 * n; ++i)fa[i] = i;
	int x, y, op;
	for (int i = 1; i <= k; ++i)
		{
			cin >> op >> x >> y;
			if ((op == 2 && x == y) || x > n || y > n)
				{
					cnt++;
					continue;
				}
			if (op == 1)
				{
					if (find(x) == find(y + n) || find(x + n) == find(y))
						{
							cnt++;
							continue;
						}
					fa[find(x)] = find(y), fa[find(y + n)] = find(x + n), fa[find(x + 2 * n) ]= find(y + 2 * n);
				}
			else
				{
					if (find(x) == find(y) || find(y + n) == find(x + n) || find(y) == find(x + n))
						{
							cnt++;
							continue;
						}
					fa[find(x)] = find(y + n);
					fa[find(x + n)] = find(y + 2 * n), fa[find(y)] = find(x + 2 * n);
				}
		}
	cout << cnt << endl;
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
