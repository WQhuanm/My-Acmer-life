#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 100;

int mod = 998244353;
ll pows[N];//pows开的空间是N，因为不是简单的代表2的几次方，而是1的个数
ll cnt[30];
int main()
{
	ll n, x;
	cin >> n;
	pows[0] = 1;
	for (int i = 1; i <= n; ++i)pows[i] = pows[i - 1] * 2 % mod;//后面值很大，一定要取模
	for (int i = 1; i <= n; ++i)
		{
			cin >> x;
			for (int j = 22; j >= 0; --j)if ((x >> j) & 1)cnt[j]++;//记录每一位二进制
		}
	ll ans = 0;
	for (int i = 0; i <= 22; ++i)ans = (ans + ((pows[cnt[i] - 1] * pows[n - cnt[i]]) % mod) * (1 << i) % mod) % mod;
	cout << ans << endl;
	return 0;
}
