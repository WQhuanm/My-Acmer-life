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
const int mod = 1e9 + 7, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 5e5 + 10;

int n;
int pre[N], b[N], bt[N], c[N], ct[N];
void mysolve()
{
	cin >> n;
	pre[0] = 1;
	for (int i = 1; i <= n; ++i)pre[i] = pre[i - 1] * 2 % mod;
	int l, r, l1, r1;
	for (int i = 1; i <= n; ++i)
		{
			cin >> l >> r >> l1 >> r1;
			if (l > l1 || (l == l1 && r > r1))swap(l, l1), swap(r, r1);
			if (r >= l1)
				{
					b[l]++, b[max(r, r1) + 1]--;
					bt[l1]++, bt[min(r, r1) + 1]--;
				}
			else b[l]++, b[r + 1]--, b[l1]++, b[r1 + 1]--;
			l1++, l++;
			if (r >= l1)
				{
					if (l > r)
						{
							if (l1 <= r1)c[l1]++, c[r1 + 1]--;
						}
					else
						{
							if (l1 > r1)c[l]++, c[r + 1]--;
							else
								{
									c[l]++, c[max(r, r1) + 1]--;
									ct[l1]++, ct[min(r, r1) + 1]--;
								}

						}
				}
			else
				{
					if (l <= r)c[l]++, c[r + 1]--;
					if (l1 <= r1)c[l1]++, c[r1 + 1]--;
				}
		}
	ll ans = 0;
	for (int i = 1; i <= 5e5; ++i)
		{
			b[i] += b[i - 1], bt[i] += bt[i - 1], c[i] += c[i - 1], ct[i] += ct[i - 1];
			if (b[i] >= n)
				{
					ans = (ans + pre[bt[i]]) % mod;
					if (c[i] >= n)ans = (ans - pre[ct[i]] + mod) % mod;
				}
		}
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
