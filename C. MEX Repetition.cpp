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

int n, k;
int a[N], b[N];
bool vis[N];

void mysolve()
{
	cin >> n >> k;
	for (int i = 0; i <= n; ++i)vis[i] = 0;
	int mex = 0;
	for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			vis[a[i]] = 1;
			while (vis[mex])mex++;
		}
	k %= n + 1;
	for (int i = 0; i < n; ++i)
		{
			if (i + k < n)b[i + k] = a[i];
			else if (i + k > n)
				{
					b[(i + k - 1) % n] = a[i];
				}
		}
	if (k)b[k - 1] = mex;

	for (int i = 0; i < n; ++i)cout << b[i] << " \n"[i == n - 1];

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
