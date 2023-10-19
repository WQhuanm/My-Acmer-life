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
const int N = 2e5 + 10;

int n, m, k;

int vis[2][N];

void mysolve()
{
	cin >> n >> m >> k;
	int x, y;
	while (k--)
		{
			cin >> x >> y;
			vis[0][x] = max(vis[0][x], y); //x行最远
			vis[1][y] = max(vis[1][y], x); //y列最远
		}
	x = n, y = m;
	while (x >= 1 && y >= 1)
		{
			if (vis[0][x] > y && vis[1][y] > x)x--, y--;
			else if (vis[0][x] > y)x--;
			else if (vis[1][y] > x)y--;
			else
				{
					if (x == 1 && y == 1)return cout << "Bhinneka" << endl, void();
					x--, y--;
				}
		}
	cout << "Chaneka" << endl;
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
