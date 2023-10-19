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
const int N = 3e6 + 10;

int n, m;
int fa[N];
int find(int x)
{
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
int cnt[N], val[N];
void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)fa[i] = i, val[i] = 1;
	int x, y;
	while (m--)
		{
			cin >> x >> y;
			int fx = find(x), fy = find(y);
			if (fx == fy)cnt[fx]++;
			else
				{
				
					cnt[fx] += cnt[fy]+1;
					val[fx] += val[fy];
					fa[fy] = fx;
				}
		}
	int ans = 0;
	vector<int>res;
	for (int i = 1; i <= n; ++i)if (fa[i] == i)
			{
				ans += val[i] * (val[i] - 1) / 2 - cnt[i];
				res.push_back(val[i]);
			}
	if (!ans)
		{
			sort(res.begin(), res.end());
			ans += res[0] * res[1];
		}
	cout << ans << endl;
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
