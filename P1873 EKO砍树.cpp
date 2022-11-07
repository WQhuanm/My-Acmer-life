#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 1e9 + 100;
const int N = 1e6 + 100;

ll a[N];
ll minn;
ll mid;
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	ll maxn = -INF;
	for (int i = 1; i <= n; ++i)
		{
			scanf("%lld", &a[i]);
			maxn = max(maxn, a[i]);
		}
	sort(a + 1, a + 1 + n);
	ll sum = 0;
	while (minn <= maxn)
		{
			mid = minn + ((maxn - minn) >> 1);
			for (int i = 1; i <= n; ++i)
				{
					if (a[i] - mid >= 0)sum += (a[i] - mid);
				}
			if (sum >= m)minn = mid + 1;
			else maxn = mid - 1;
			sum = 0;
		}
	cout << minn - 1 << endl;
	return 0;
}
