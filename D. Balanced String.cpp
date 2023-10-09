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
const int N = 210;

int dp[2][N][N * N];
string s;
void mysolve()
{
	cin >> s;
	s = '$' + s;
	int zero = count(s.begin(), s.end(), '0'), one = 0, zeropre = 0, sum = 0;
	int p = 0, base = 100, bs2 = 20000;
	memset(dp, 0x3f, sizeof(dp));
	dp[0][base][bs2] = 0;
	for (int i = 1; i < (int)s.size(); ++i)
		{
			p ^= 1;
			for (int j = base + one - i; j <= base + one; ++j)//1比0多几个的贡献
				{
					for (int k = bs2 - 2 * i * i; k <= bs2 + 2 * i * i; ++k) //贡献为k
						{
							dp[p][j][k] = min(dp[p][j][k], dp[p ^ 1][j][k]);
							if (s[i] == '1')dp[p][j + 1][k + 2 * i] = min(dp[p][j + 1][k + 2 * i], dp[p ^ 1][j][k] + 1);
							else dp[p][j - 1][k - 2 * i] = min(dp[p][j - 1][k - 2 * i], dp[p ^ 1][j][k] + 1);
//						cout<<p<<" "<<j<<" "<<k<<"  "<<dp[p][j][k]<<endl;
						}
				}
			if (s[i] == '1')sum -= zeropre - zero, one++;
			else zero--, zeropre++;

		}
	cout << dp[p][base][ bs2-sum]/2 << endl;
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
