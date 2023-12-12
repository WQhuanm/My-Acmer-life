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
const int mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;

int n, k;
int a[N];
void mysolve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	if (k >= 3)return cout << 0 << endl, void();
	sort(a + 1, a + 1 + n);	int mn = a[1];
	if (k == 1)
		{
		
			for (int i = 1; i < n; ++i)
				mn = min(mn, a[i + 1] - a[i]);
			cout << mn << endl;
		}
	else
		{
			for (int i = n; i; --i)for (int j = i - 1; j > 0; --j)
					{
						int now = a[i] - a[j];
						mn = min(mn, now);
						int p = lower_bound(a + 1, a + 1 + n, now) - a;
						mn = min(a[p] - now, mn);
						if (p > 1)mn = min(mn, now - a[p - 1]);
					}
			cout << mn << endl;
		}
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
