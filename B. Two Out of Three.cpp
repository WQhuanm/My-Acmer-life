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

int n;
int a[N];
vector<int>b[110];
int ans[N];
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= 100; ++i)b[i].clear();
	for (int i = 1; i <= n; ++i)cin >> a[i], b[a[i]].push_back(i);
	int cnt = 0;
	for (int i = 1; i <= 100; ++i)if (!b[i].empty())
			{
				ans[b[i].front()] = 1;
				if ((int)b[i].size() > 1)
					{
						if (!cnt)
							{
								cnt = 1;
								for (int j = 1; j < (int)b[i].size(); ++j)ans[b[i][j]] = 2;
							}
						else
							{
								cnt = 2;
								for (int j = 1; j < (int)b[i].size(); ++j)ans[b[i][j]] = 3;
							}
					}
			}

	if (cnt < 2)cout << -1 << endl;
	else for (int i = 1; i <= n; ++i)cout << ans[i] << " \n"[i == n];
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
