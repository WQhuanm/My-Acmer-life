#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 1e5 + 10;

int a[N], b[N];
int n, m, q;
ll d[N];
int len;
ll sum1, sum2;
void ask_ans()
{
	ll sum = sum1 - sum2;
	ll ans = INF;
	if (sum > d[0])ans = min(ans, sum - *prev(lower_bound(d, d + 1 + len, sum)));
	if (sum <= d[len])ans = min(ans, *lower_bound(d, d + 1 + len, sum) - sum);
	cout << ans << endl;
}

void mysolve()
{
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			if (i & 1)sum1 += a[i];
			else sum2 += a[i];
		}
	for (int i = 1; i <= m; ++i)cin >> b[i];
	len = m - n;
	d[0] = 0;
	for (int i = 1; i <= n; ++i)d[0] += (i & 1 ? b[i] : -b[i]);
	for (int i = n + 1; i <= m; ++i)
		{
			d[i - n] = -d[i - n - 1] + b[i - n ] + (n & 1 ? b[i] : -b[i]);
		}
	sort(d, d + 1 + len);
	int l, r, x;
	ask_ans();
	while (q--)
		{
			cin >> l >> r >> x;
			int cnt = r - l + 1;
			if (l & 1)sum1 += (cnt + 1) / 2 * x, sum2 += cnt / 2 * x;
			else sum2 += (cnt + 1) / 2 * x, sum1 += cnt / 2 * x;
			ask_ans();
		}
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
