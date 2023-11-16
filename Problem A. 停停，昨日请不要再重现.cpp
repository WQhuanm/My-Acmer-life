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
const int N = 4e3 + 10, lim = 2e3;

struct point
{
	int x, y;
};
point o = {2000, 2000};

int n, m, k;
int u, d, l, r;
string s;
int t[N][N];

int ask_mat(int x1, int y1, int x2, int y2)
{
	return t[x1][y1] - t[x1][y2 - 1] - t[x2 - 1][y1] + t[x2 - 1][y2 - 1];
}

void mysolve()
{
	cin >> n >> m >> k >> s;
	point now = o;
	u = 1, d = n, l = 1, r = m;
	int nu = 1, nd = n, nl = 1, nr = m;
	for (int i = lim - n - 10; i <= lim + n + 10; ++i)for (int j = lim - m - 10; j <= lim + m + 10; ++j)t[i][j] = 0;
	t[lim][lim] = 1;
	for (auto v : s)
		{
			if (v == 'U')
				{
					nu++, nd++, u = max(u, nu);
					now.x++;
					if (now.x >= lim - n && now.x <= lim + n && now.y >= lim - m && now.y <= lim + m)t[now.x][now.y] = 1;
				}
			else if (v == 'D')
				{
					nu--, nd--, d = min(nd, d);
					now.x--;
					if (now.x >= lim - n && now.x <= lim + n && now.y >= lim - m && now.y <= lim + m)t[now.x][now.y] = 1;
				}
			else if (v == 'L')
				{
					nl++, nr++, l = max(l, nl);
					now.y++;
					if (now.x >= lim - n && now.x <= lim + n && now.y >= lim - m && now.y <= lim + m)t[now.x][now.y] = 1;
				}
			else
				{
					nl--, nr--, r = min(r, nr);
					now.y--;
					if (now.x >= lim - n && now.x <= lim + n && now.y >= lim - m && now.y <= lim + m)t[now.x][now.y] = 1;
				}
		}
	int cnt;
	if (u > d || l > r)cnt = n * m;
	else cnt = n * m - (d - u + 1) * (r - l + 1);
	if (cnt > n * m - k)return cout << 0 << endl, void();
	if (u > d || l > r)return cout << cnt << endl, void();
	for (int i = lim - n; i <= lim + n; ++i)for (int j = lim - m; j <= lim + m; ++j)
			t[i][j] += t[i - 1][j] + t[i][j - 1] - t[i - 1][j - 1];
	int ans = 0;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			if (ask_mat(lim + d - i, lim + r - j, lim + u - i, lim + l - j) + cnt == n * m - k)ans++;
	cout << ans << endl;
}

signed main()
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
