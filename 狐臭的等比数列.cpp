#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;
const int N = 110;

ll a[N], b[N], cnt[N];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	if (n == 2)
		{
			cout << 2 << endl;
			return 0;
		}

	sort(a + 1, a + 1 + n);
	if (a[1] == a[n])
		{
			cout << n << endl;
			return 0;
		}
	for (int i = 1; i < n; ++i)b[i] = a[i + 1] / __gcd(a[i + 1], a[i]);
	sort(b + 1, b + n);
	ll q = b[1];
	for (int i = 2; i * i <= q; ++i)
		{
			if (q % i == 0)
				{
					ll tmp = q;
					while (!(tmp % i))tmp /= i;
					if (tmp == 1)
						{
							q = i;
							break;
						}
				}
		}
	ll t = 0;
	for (int i = 1; i < n; ++i)
		{
			while (b[i] > 1)b[i] /= q, cnt[i]++;
			t = __gcd(t, cnt[i]);
		}
	ll ans = n;
	for (int i = 1; i < n; ++i)ans += cnt[i] / t - 1;
	cout << ans << endl;
	return 0;
}
