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

int n, m;
int ans[10];

int print(int x, int y)
{
	int tmp;
	cout << "DIG " << x << " " << y << endl;
	cin >> tmp;
	return tmp;
}
void mysolve()
{
	cin >> n >> m;
	cout << "SCAN " << 1 << " " << 1 << endl;
	cin >> ans[1];
	cout << "SCAN " << n << " " << 1 << endl;
	cin >> ans[2];
	int x12 = (ans[1] - ans[2]) / 2 + 1 + n, y12 = (ans[1] + ans[2]) / 2 + 3 - n;
	cout << "SCAN " << x12 / 2 << " " << y12 / 2 << endl;
	cin >> ans[3];
	cout << "SCAN " << x12 / 2 << " " << 1 << endl;
	cin >> ans[4];
	int y1 = (ans[4] - ans[3]) / 2 + 1, y2 = y12 - y1, x2 = (ans[4] + x12 - y12 + 2) / 2, x1 = x12 - x2;
	if (x1 > x2)swap(x1, x2);
	if (y1 > y2)swap(y1, y2);
	if (!print(x1, y1))print(x2, y1), print(x1, y2);
	else print(x2, y2);
}

signed main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
		cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
