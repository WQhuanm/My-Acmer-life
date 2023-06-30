#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;

int a[N], pre[10], mx[N], sum[10][N], sum2[10][N];
void mysolve()
{
	string s;
	cin >> s;
	int n = (int)s.size();
	vector<int>v[10];
	for (int i = 0; i < n; ++i)
		{
			int c = s[i] - 'A' + 1;
			a[i + 1] = c;
			v[c].push_back(i + 1);
		}
	mx[n + 1] = 0;
	for (int i = n; i; --i)mx[i] = max(mx[i + 1], a[i]);
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		{
			if (mx[i + 1] > a[i])ans -= pre[a[i]];
			else ans += pre[a[i]];
			for (int j = 1; j <= 5; ++j)
				{
					sum2[j][i] = sum2[j][i - 1] + (j == a[i] && mx[i + 1] <= a[i] ? 2 * pre[a[i]] : 0);
					sum[j][i] = sum[j][i - 1] + (j == a[i] && mx[i + 1] > a[i] ? 2 * pre[a[i]] : 0);
				}
		}
	ll res = ans;
	for (int i = 1; i <= n; ++i)
		{
			int t = (a[i] >= mx[i + 1] ? -pre[a[i]] : pre[a[i]]);
			for (int j = 1; j <= 5; ++j)
				{
//					if (mx[i + 1] > j)
//						{
//							int tmp = t - pre[j];
//							res = max(res, ans + tmp);
//						}
//					else if (mx[i + 1] == j)
//						{
//							int tmp = t + pre[j];
//							res = max(res, ans + tmp);
//						}
//					else
//						{
					int tmp = t + (j >= mx[i + 1] ? pre[j] : -pre[j]);
					if (j < mx[i])
						{
							int l = 0, r = i - 1;
//							int tmp = t + pre[j];
							for (int k = mx[i]; k <= 5; ++k)if (!v[k].empty() && (v[k].front()) < i)l = max(l, *prev(lower_bound(v[k].begin(), v[k].end(), i)));
							for (int k = mx[i] - 1; k >= j && k >= mx[i + 1]; --k)
								{
									tmp += sum[k][r] - sum[k][l];
									if (!v[k].empty() && (v[k].front()) < i)l = max(l, *prev(lower_bound(v[k].begin(), v[k].end(), i)));
								}
							res = max(res, ans + tmp);
						}
					else if (j > mx[i])
						{
//							int tmp = t + pre[j];
							for (int k = 1; k < j; ++k)
								tmp -= sum2[k][i - 1];
							res = max(res, ans + tmp);
						}
					else if (j == mx[i])	res = max(res, ans + tmp);

//				}
				}
		}
	cout << res << endl;
}
int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	pre[1] = 1;
	for (int i = 2; i < 7; ++i)pre[i] = pre[i - 1] * 10;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

