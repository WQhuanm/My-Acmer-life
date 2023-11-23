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

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	int mn = inf;
	int ans = 0;
	for (int i = n; i; --i)
		{
			if (a[i] > mn)
				{
					if ((a[i] + 1) / 2 <= mn)ans++, mn = min(a[i] / 2, mn);
					else
						{
							int l = 1, r = mn, res = 1;
							while (l <= r)
								{
									int mid = (l + r) >> 1;
									if (a[i] % mid <= a[i] / mid * (mn - mid))res = mid, l = mid + 1;
									else r = mid - 1;
								}
							 ans += (a[i] + mn - 1) / mn-1,mn=res;
						}
				}
			else mn = min(a[i], mn);
		}//a[i]%x<=a[i]/x*(mn-x)
	cout << ans << endl;
}

signed main()
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
