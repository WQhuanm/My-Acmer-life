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
const int N = 4e5 + 10;

int a[N];
int cnt[N];
int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		{
			int n, m;
			cin >> n >> m;
			for (int i = 0; i <= n + m; ++i)cnt[i] = 0;
			for (int i = 1; i <= n; ++i)
				{
					cin >> a[i];
					cnt[a[i]] = m + 1; //如果一个数没被修改，他会一直出现，共m+1次
				}
			int p, v;
			for (int i = 1; i <= m; ++i)
				{
					cin >> p >> v;
					cnt[a[p]] -= m - i + 1; //被修改的数后面都不会再出现了（除非再给一次）
					cnt[v] += m - i + 1; //新的数后面都会出现（直到被修改没）
					a[p] = v;
				}
			ll ans = 0;
			for (int i = 1; i <= n + m; ++i)ans += (ll)cnt[i] * (cnt[i] - 1) / 2 + (ll)cnt[i] * (m + 1 - cnt[i]);
			cout << ans << endl;
		}

	return 0;
}
