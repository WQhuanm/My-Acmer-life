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
const ll mod = 1e9 + 7, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 210;

ll pre[N][N];

ll hibit(ll x)//ll最高位0是63，只有ull取得到
{
	if (!x)return 0;
	return (63 - __builtin_clzll(x));//返回二进制前导0个数，速度O(1)
}

void mysolve()
{
	ll l, r;
	cin >> l >> r;
	int nl = hibit(l), nr = hibit(r);
	ll ans = 0;
	for (int i = nl; i <= nr; ++i)
		{
			int L = max(1ull * l, 1ull << i), R = min(1ull * r, (1ull << (i + 1)) - 1);
			if (R >= L)
				for (int j = 1; j <= 100; ++j)if (pre[i][j] < INF && pre[i][j] <= R)
						{
							int tl = max(L, pre[i][j]), tr = min(R, pre[i][j + 1] - 1);
							if (tr >= tl)
								{
									ll tmp = (tr - tl + 1) % mod;
									ans = (ans + tmp * j % mod) % mod;
								}
						}
		}
	cout << ans << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	for (int i = 2; i <= 100; ++i)
		{
			pre[i][1] = i, pre[i][0] = 0;
			for (int j = 2; j <= 200; ++j)
				{
					if (pre[i][j - 1] < INF && (__int128)pre[i][j - 1] * (__int128)i < INF)pre[i][j] = pre[i][j - 1] * i;
					else pre[i][j] = INF;
				}
		}
	while (t--)
		{
			mysolve();
		}
	return 0;
}
