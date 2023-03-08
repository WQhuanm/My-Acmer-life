#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int mod = 998244353;

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		{
			int l, r;
			cin >> l >> r;
			int k = 0;
			while ((1 << k)*l <= r)++k; //k为可以乘的2的个数
			--k;
			ll ans = (r >> k) - l + 1; //当前ans为可以只乘2获得k+1个数的数
			if (k > 0)
				{
					int cnt = (r >> (k - 1)) / 3 - l + 1;//少乘一个2，多乘一个3
					cnt = max(0, cnt); //cnt可能小于0
					ans = (ans + cnt * k % mod) % mod;
				}
			cout << k + 1 << ' ' << ans << endl;
		}
	return 0;
}
