#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;

int n, a[N];
int vis[40], cnt[2][40];

void mysolve()
{
	cin >> n;
	for (int i = 0; i <= 30; ++i)cnt[0][i] = cnt[1][i] = vis[i] = 0;
	ll avg = 0;
	for (int i = 1; i <= n; ++i)cin >> a[i], avg += a[i];
	if (avg % n)return cout << "NO" << endl, void();
	avg /= n;
	for (int i = 1; i <= n; ++i)
		{
			bool fl = 0;
			if (a[i] > avg)
				{
					int tmp = a[i] - avg;
					if (__builtin_popcount(tmp)==1)
						{
							fl = 1;
							cnt[0][__builtin_ctz(tmp)]++;
						}
					else
						{
							for (int i = 30; i && !fl; --i)for (int j = i - 1; ~j; --j)if ((1 << i) - (1 << j) == tmp)
										{
											fl = 1;
											vis[j]++, vis[i]--;
											break;
										}
						}
				}
			else if (a[i] < avg)
				{
					int tmp = avg - a[i];
					if (__builtin_popcount(tmp)==1)
						{
							fl = 1;
							cnt[1][__builtin_ctz(tmp)]++;
						}
					else
						{
							for (int i = 30; i && !fl; --i)for (int j = i - 1; ~j; --j)if ((1 << i) - (1 << j) == tmp)
										{
											fl = 1;
											vis[i]++, vis[j]--;
											break;
										}
						}
				}
		else fl=1;
			if (!fl)return cout << "NO" << endl, void();
		}
	for (int i = 30; ~i; --i)//vis吸入为+
		{
			vis[i] += cnt[1][i] - cnt[0][i];

			if (i)
				{
					if (vis[i] > 0)
						{
							int tmp = min(vis[i], cnt[0][i - 1]);
							vis[i] -= tmp, cnt[0][i - 1] -= tmp, vis[i - 1] += tmp;
						}
					else if (vis[i] < 0)
						{
							int tmp = min(-vis[i], cnt[1][i - 1]);
							vis[i] += tmp, cnt[1][i - 1] -= tmp, vis[i - 1] -= tmp;
						}
				}
			if (vis[i])return cout << "NO" << endl, void();
		}
	cout << "YES" << endl, void();
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
	system("pause");
	return 0;
}
