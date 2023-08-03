#include <bits/stdc++.h>
using namespace std;
#define ll               long long
const int N = 2e3 + 10;

const int base = 457, base2 = 131, mod = 1e9 + 7;
ll x[N], y[N]; //竖x(base2)，横y(base)
int n, m;

void init()
{
	x[0] = y[0] = 1;
	for (int i = 1; i < N; ++i)
		{
			y[i] = y[i - 1] * base % mod;
			x[i] = x[i - 1] * base2 % mod;
		}
}

struct hash_2d
{
	char ch[N][N];
	ll h[N][N];
	void init()
	{
		for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)
				h[i][j] = (h[i - 1][j] * base2 % mod + h[i][j - 1] * base % mod + (mod - h[i - 1][j - 1]) * base % mod * base2 % mod + ch[i][j]) % mod;
	}
	int get_sub(int x1, int y1, int x2, int y2)
	{
		return (h[x2][y2] - h[x1 - 1][y2] * x[x2 - x1 + 1] % mod + mod - h[x2][y1 - 1] * y[y2 - y1 + 1] % mod + mod + h[x1 - 1][y1 - 1] * y[y2 - y1 + 1] % mod * x[x2 - x1 + 1] % mod) % mod;
	}
} h, h2; //h2是h的回文对称矩阵

bool check(int x1, int y1, int x2, int y2)//判断矩阵是否回文
{
	return h.get_sub(x1, y1, x2, y2) == h2.get_sub(n - x2 + 1, m - y2 + 1, n - x1 + 1, m - y1 + 1);
}

void mysolve()
{
	cin >> n >> m;
	x[0] = y[0] = 1;
	for (int i = 1; i < N ; ++i) ////////////////////////////////
		{
			y[i] = y[i - 1] * base % mod;
			x[i] = x[i - 1] * base2 % mod;
		}
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)cin >> h.ch[i][j], h2.ch[n - i + 1][m - j + 1] = h.ch[i][j];
	h.init();
	h2.init();
	ll res = m * n;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			{
				int l = 1, r = min({i - 1, j - 1, n - i + 1, m - j + 1}), ans = 0;
				while (l <= r)//中心点，mid为半径
					{
						int mid = l + ((r - l) >> 1);
						if (check(i - mid, j - mid, i + mid, j + mid))ans = mid, l = mid + 1;
						else r = mid - 1;
					}
				res += ans;
				l = 1, r = min({i, j, n - i + 1, m - j + 1}), ans = 0;
				while (l <= r)
					{
						int mid = l + ((r - l) >> 1);
						if (check(i - mid + 1, j - mid + 1, i + mid, j + mid))ans = mid, l = mid + 1;
						else r = mid - 1;
					}
				res += ans;
			}
	cout << res ;
}

signed main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	return 0;
}
