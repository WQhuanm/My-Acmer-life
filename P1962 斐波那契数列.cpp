#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
#define int              long long
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 1e9+7;
const int N = 10;

int n = 2;
struct mat
{
	ll t[N][N];
	mat()
	{
		for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)t[i][j] = 0;
	}
	void unit_mat()
	{
		for (int i = 1; i <= n; ++i)t[i][i] = 1;
	}
	mat operator*(const mat&b)const
	{
		mat ans;
		for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)
				{
					ans.t[i][j] = 0;
					for (int k = 1; k <= n; ++k)ans.t[i][j] = (ans.t[i][j] + t[i][k] * b.t[k][j] % mod) % mod;
				}
		return ans;
	}
} a;

mat fastmi(mat base, int power)
{
	mat ans;
	ans.unit_mat();
	while (power)
		{
			if (power & 1)ans = ans * base;
			power >>= 1, base = base * base;
		}
	return ans;
}
void mysolve()
{
	a.t[1][1] = a.t[1][2] = a.t[2][1] = 1, a.t[2][2] = 0;
	int n;
	cin >> n;
	if (n <= 2)cout << 1 << endl;
	else
		{
			a = fastmi(a, n - 2);
			ll ans = (a.t[1][1] + a.t[2][1]) % mod;
			cout << ans << endl;
		}
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
