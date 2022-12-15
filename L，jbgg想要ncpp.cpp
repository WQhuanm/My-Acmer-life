#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 100;

int main()
{
	ll n, m, p;
	bitset<N>vis;
	cin >> n >> m >> p;
	ll k = 1;
	while (n / k)k *= 10;
	n %= p; //n或者k都可能比p大，直接加可能会错，先取余，不然n，k极大时乘起来直接爆
	k %= p;
	ll t = 0, ans = n;
	for (int i = 1; i <= m; ++i)
		{
			t = (t * k % p + n) % p;
			if (vis[t])break;
			vis[t] = 1;
			ans = max(ans, t);
		}
	cout << ans;
	return 0;
}
