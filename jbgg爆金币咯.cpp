#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
int mod = 998244353;

ll cnt[30][5];
ll pows[N];
int main()
{
	int n;
	cin >> n;
	ll x;
	pows[0] = 1;
	for (int i = 1; i <= n; ++i)pows[i] = (pows[i - 1] * 2) % mod;
	for (int i = 1; i <= n; ++i)
		{
			cin >> x;
			for (int j = 26; j >= 0; --j)
				{
					if ((x >> j) & 1)cnt[j][1]++;
					else cnt[j][0]++;
				}
		}
	ll ans = 0;
	for (int i = 0; i <= 26; ++i)
		{
			ans = (ans + (pows[cnt[i][1] - 1] * pows[cnt[i][0]]) % mod * (1ll << i) % mod ) % mod;
		}
	cout << ans << endl;
	return 0;
}
