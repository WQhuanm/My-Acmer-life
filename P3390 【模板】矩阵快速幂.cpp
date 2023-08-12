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
const int mod = 1e9 + 7;
const int N = 110;

int n, k;
struct mat
{
	ll t[N][N];
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
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)cin >> a.t[i][j];
	a = fastmi(a, k);
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)cout << a.t[i][j] << " \n"[j == n];
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
