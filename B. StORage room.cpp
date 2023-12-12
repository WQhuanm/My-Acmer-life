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
const int N = 1e3 + 10;


int n, a[N][N];
int ans[N];
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)cin >> a[i][j];
	for (int i = 1; i <= n; ++i)ans[i] = (1ull << 30) - 1;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)if (i != j)ans[i] &= a[i][j];
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)if (i != j && a[i][j] != (ans[i] | ans[j]))return cout << "NO" << endl, void();
	cout << "YES" << endl;
	for(int i=1;i<=n;++i)cout<<ans[i]<<" \n"[i==n];
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
