#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//---------------------------------------------------------------------------------------------------------------------//
const int N = 20;
const int mod = 1e9 + 7;

int n = 7;
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

mat fastmi(mat base, ll power)
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

int f[10] = {1, 1, 3, 10, 23, 62, 170, 441};

void mysolve()
{
	int k;
	cin >> k;
	a.t[1][1] = 1, a.t[1][2] = 1, a.t[1][3] = 0, a.t[1][4] = 0, a.t[1][5] = 0, a.t[1][6] = 0, a.t[1][7] = 0;
	a.t[2][1] = 2, a.t[2][2] = 0, a.t[2][3] = 1, a.t[2][4] = 0, a.t[2][5] = 0, a.t[2][6] = 0, a.t[2][7] = 0;
	a.t[3][1] = 5, a.t[3][2] = 0, a.t[3][3] = 0, a.t[3][4] = 1, a.t[3][5] = 1, a.t[3][6] = 0, a.t[3][7] = 0;
	a.t[4][1] = 0, a.t[4][2] = 0, a.t[4][3] = 0, a.t[4][4] = 0, a.t[4][5] = 0, a.t[4][6] = 0, a.t[4][7] = 0;
	a.t[5][1] = 2, a.t[5][2] = 0, a.t[5][3] = 0, a.t[5][4] = 0, a.t[5][5] = 0, a.t[5][6] = 1, a.t[5][7] = 0;
	a.t[6][1] = 2, a.t[6][2] = 0, a.t[6][3] = 0, a.t[6][4] = 0, a.t[6][5] = 0, a.t[6][6] = 0, a.t[6][7] = 1;
	a.t[7][1] = 4, a.t[7][2] = 0, a.t[7][3] = 0, a.t[7][4] = 0, a.t[7][5] = 1, a.t[7][6] = 0, a.t[7][7] = 0;
	if (k <= 6)return cout << f[k] << endl, void();
	a = fastmi(a, k - 6);

	ll ans = (a.t[1][1] * f[6] % mod + a.t[2][1] * f[5] % mod + a.t[3][1] * f[4] % mod + a.t[4][1] * f[3] % mod
	          +( f[3]+f[0]) * a.t[5][1] % mod + a.t[6][1] * f[2] % mod + a.t[7][1] * f[1] % mod) % mod;
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

