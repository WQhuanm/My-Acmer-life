#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 100;

int a[N];
void mysolve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)a[i] = n + 1;
	int x, y;
	for (int i = 1; i <= m; ++i)
		{
			cin >> x >> y;
			if (x < y)
				{
					a[x] = min(a[x], y);
				}
			else a[y] = min(a[y], x);
		}
	for (int i = n - 1; i >= 1; --i)a[i] = min(a[i], a[i + 1]);
	int ans = 0;
	for (int i = 1; i <= n; ++i)ans += a[i] - i;
	cout << ans << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;

	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
