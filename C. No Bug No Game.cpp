#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 3020;

int n, k;
int p[N], w[N][15];
ll pre[N][N], sur[N][N];

void mysolve()
{
	cin >> n >> k;
	int sum = 0;
	for (int i = 0; i <= n + 1; ++i)for (int j = 0; j <= k; ++j)pre[i][j] = sur[i][j] = -1;
	pre[0][0] = sur[n + 1][0] = 0;
	for (int i = 1; i <= n; ++i)
		{
			cin >> p[i];
			for (int now = min(sum, k); now >= 0; --now)pre[i][now] = pre[i - 1][now];
			for (int j = 1; j <= p[i]; ++j)cin >> w[i][j];
			for (int now = min(sum, k); now >= 0; --now)if (~pre[i - 1][now])
					pre[i][now + p[i]] = max(pre[i][now + p[i]], pre[i - 1][now] + w[i][p[i]]);
			sum += p[i];
		}
	sum = 0;
	for (int i = n; i; --i)
		{
			for (int now =  min(sum, k); now >= 0; --now)sur[i][now] = sur[i + 1][now];
			for (int now =  min(sum , k); now >= 0; --now)if (~sur[i + 1][now])
					sur[i][now + p[i]] = max(sur[i][now + p[i]], sur[i + 1][now] + w[i][p[i]]);
			sum += p[i];
		}
	ll ans = 0;
	for (int i = 1; i <= k; ++i)ans = max(ans, pre[n][i]);
	for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= p[i]; ++j)
				{
					int lim = k - j;
					if (lim < 0)break;
					for (int now = 0; now <= lim; ++now)if (~pre[i - 1][now] && ~sur[i + 1][lim - now])ans = max(ans, pre[i - 1][now] + sur[i + 1][lim - now] + w[i][j]);
				}
		}
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
