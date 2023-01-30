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
const int N = 2e5 + 10;

int main()
{
	int t;
	cin >> t;
	while (t--)
		{
			ll L, R;
			cin >> L >> R;
			ll ans = max(0ll, R / 2 - L + 1);//首先加上L到R/2这段区间的d
			for (ll l = 1, r; l < L; l = r + 1)//遍历l从1到L-1
				{
					ll k = (L - 1) / l;
					r = (L - 1) / k;
					ans += max(0ll, (min(r, R / (k + 2))) - l + 1);//注意不一定直接加上（r-l+1),因为可能r会超区间R，所以需要比较k倍数下(k*r+r)+r（k*r+r是最接近L,k*r+r+r是右边），即r*(k+2)<=R的最大r
				}
			cout << ans << endl;
		}

	return 0;
}
