#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 1e6 + 10;

int n, w;
pii a[N];
ll sum[N];

void mysolve()
{
	cin >> n >> w;
	int len;
	while (n--)
		{
			cin >> len;
			for (int i = 1; i <= len; ++i)cin >> a[i].first, a[i].second = i;
			a[0] = {0, 0}, a[len + 1] = {0, len + 1};
			sort(a, a + 2 + len, greater<pii>());
			int d = w - len;
			set<int>s;
			for (int i = 0; i <= len + 1; ++i)
				{
					int l = a[i].second, r = l + d;
					if (!s.empty() && *prev(s.end()) > a[i].second)r = min(r, *s.upper_bound(a[i].second) - 1);
					if (!s.empty() && *s.begin() < a[i].second)l = max(l, d + 1 + *prev(s.lower_bound(a[i].second)));
					if (l <= r)sum[l] += a[i].first, sum[r + 1] -= a[i].first;
					s.insert(a[i].second);
				}
		}
	for (int i = 1; i <= w; ++i)sum[i] += sum[i - 1], cout << sum[i] << " \n"[i == w];
}

signed main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	return 0;
}
