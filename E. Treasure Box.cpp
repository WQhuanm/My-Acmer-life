#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 1e6 + 10;

ll pre[2][N], ans[N], c, sumr[N], suml[N];
int a[N];
int n;
string s;
void mysolve()
{
	cin >> n >> c;
	cin >> s;
	s = '$' + s;
	for (int i = 1; i <= n; ++i)cin >> a[i], ans[i] = INF, pre[0][i] = pre[1][i] = INF;
	int l = n + 1, r = 0;
	for (int i = 1; i <= n / 2; ++i)if (s[i] != s[n - i + 1])l = min(l, i), r = max(r, i);
	int nl = n - r + 1, nr = n - l + 1;
	if (l <= r)
		{
			for (int i = 1; i <= n; ++i)
				{
					pre[0][i] = pre[0][i - 1];
					if (s[i] != s[n - i + 1])
						{
							if (i <= r)pre[0][i] += a[i];
							else pre[0][i] = min(pre[0][i], pre[0][i] + a[i] - a[n - i + 1]);
							if (i >= r) ans[l] = min(pre[0][i] + c * (i - l), ans[l]);
						}
				}
			pre[1][n + 1] = 0;
			for (int i = n; i; --i)
				{
					pre[1][i] = pre[1][i + 1];
					if (s[i] != s[n - i + 1])
						{
							if (i >= nl)pre[1][i] += a[i];
							else pre[1][i] = min(pre[1][i], pre[1][i] + a[i] - a[n - i + 1]);
							if (i <= nl)ans[nr] = min(ans[nr], pre[1][i] + c * (nr - i));
						}
				}
			for (int i = 1; i <= n; ++i)
				{
					if (i < r)pre[0][i] = INF;
					if (i > nl)pre[1][i] = INF;
				}
			sumr[nr] = pre[0][nr] + c * (2 * nr - l);
			for (int i = nr - 1; i >= 1; --i)sumr[i] = min(sumr[i + 1], pre[0][i] + c * (2 * i - l));
			suml[l] = pre[1][l] + c * (nr - 2 * l);
			for (int i = l + 1; i <= n; ++i)suml[i] = min(suml[i - 1], pre[1][i] + c * (nr - 2 * i));

			for (int i = l ; i <= nr; ++i)
				{
					ans[i] = min(ans[l] + c * (i - l), ans[nr] + c * (nr - i));
					ans[i] = min({ans[i], sumr[i] - c * i, pre[0][i] + c * (i - l)});
					ans[i] = min({ans[i], suml[i] + c * i, pre[1][i] + c * (nr - i)});
				}

			for (int i = 1; i < l; ++i)ans[i] = ans[l] + c * (l - i);
			for (int i = n; i > nr; --i)ans[i] = ans[nr] + c * (i - nr);
		}
	else for (int i = 1; i <= n; ++i)ans[i] = 0;
	for (int i = 1; i <= n; ++i)cout << ans[i] << " \n"[i == n];
}

int32_t main()
{
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
//	system("pause");
	return 0;
}
