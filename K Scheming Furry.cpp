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
const int mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 210;

int a[N][N];
int n, m;
void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)cin >> a[i][j];
	bool fl = 1;
	for (int i = 1; i <= n; ++i)for (int j = 1; j < m; ++j)if (a[i][j + 1] != a[i][j] + 1)
				{
					fl = 0;
					break;
				}
	int cnt = 0;
	for (int i = 1; i <= n; ++i)if (a[i][1] != 1 + (i - 1)*m)cnt++;
	if (fl && cnt == 2)cout << "FOX" << endl;
	else if (n > 2 && m > 2)cout << "NSFW" << endl;
	else if (n == 2 && m == 2)
		{
			if ((a[1][1] == 3 && a[1][2] == 4 && a[2][1] == 1 && a[2][2] == 2) || (a[1][1] == 2 && a[1][2] == 1 && a[2][1] == 4 && a[2][2] == 3))cout << "FOX" << endl;
			else if (a[1][1] == 4 && a[1][2] == 3 && a[2][1] == 2 && a[2][1] == 2 && a[2][2] == 1)cout << "CAT" << endl;
			else cout << "NSFW" << endl;
		}
	else if (n == 2)
		{
			bool fl = 1, f2 = 1;
			for (int i = 1; i <= m; ++i)if (a[2][i] != a[1][i] + m)
					{
						fl = 0;
						break;
					}
			for (int i = 1; i <= m; ++i)if (a[2][i] + m != a[1][i])
					{
						f2 = 0;
						break;
					}
			bool ct = 0;
			for (int i = 2; i <= m; ++i)for (int j = 1; j < i; ++j)if (a[1][j] > a[1][i])ct ^= 1;
			if ((fl && !ct) || (f2 && ct))cout << "CAT" << endl;
			else cout << "NSFW" << endl;
		}
	else
		{
			bool fl = 1, f2 = 1;
			for (int i = 1; i <= n; ++i)if (a[i][2] != a[i][1] + 1)
					{
						fl = 0;
						break;
					}
			for (int i = 1; i <= n; ++i)if (a[i][2] + 1 != a[i][1])
					{
						f2 = 0;
						break;
					}
			bool ct = 0;
			for (int i = 2; i <= n; ++i)for (int j = 1; j < i; ++j)if (a[j][1] > a[i][1])ct ^= 1;
			if ((fl && ct) || (f2 && !ct))cout << "FOX" << endl;
			else cout << "NSFW" << endl;
		}
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
