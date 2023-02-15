#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 5e3 + 10;
const int mod = 998244353;
ll dp[N];
int main()
{
	ll m;
	cin >> m;
	dp[0] = 1;
	for (int i = 1; i <= m; ++i)for (int j = i; j <= m; ++j)
			{
				dp[j] = (dp[j] + dp[j - i]) % mod;
			}
	cout << dp[m] << endl;
	return 0;
}

