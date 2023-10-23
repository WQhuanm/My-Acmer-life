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

int vis[40];

void mysolve()
{
	cin >> n;
	ll sum = 0;
	int cnt = 0;
	for (int i = 0; i <= 30; ++i)vis[i] = 0;
	for (int i = 1; i <= n; ++i)cin >> a[i], sum += a[i];
	if (sum % n)return cout << "NO" << endl, void();
	int ave = sum / n;
	sort(a + 1, a + 1 + n, greater<int>());
	for (int i = 1; i <= n; ++i)
		{
			if (a[i] > ave)
				{
					int tmp = a[i] - ave;
					bool fl = 0;
					for (int i = 0; i < 31; ++i)
						{
							if (__builtin_popcountll(tmp + (1ll << i)) == 1)
								{
									fl = 1;
									tmp += 1ll << i;
									tmp = __builtin_ctzll(tmp);
									vis[i]++, vis[tmp]--;
									break;
								}
						}
					if (!fl)return cout << "NO" << endl, void();
				}
			else if (a[i] == ave)
				{
					cnt++;
				}
			else
				{
					bool fl = 0;
					int now = ave - a[i];
					for (int i = 30; i; --i)
						{
							for (int j = i - 1; j >= 0; --j)if ((1ll << i) - (1ll << j) == now)
									{
										vis[i]++, vis[j]--;
										fl = 1;
										break;
									}
							if (fl)break;
						}
					if (!fl)return cout << "NO" << endl, void();
				}
		}
	for (int i = 0; i < 31; ++i)if (vis[i])return cout << "NO" << endl, void();
	cout << "YES" << endl;
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
