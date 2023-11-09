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
int n, k;
void mysolve()
{
	cin >> n >> k;
	int a = k / 2, b = (k + 1) / 2, c = (n + 1) / 2, d = n / k, e = n % k;

	if ((a * d + max(0ll, a - (k - e)) <= c && a * d + min(a, e) >= c) ||
	    (b * d + max(0ll, b - (k - e)) <= c && b * d + min(b, e) >= c))cout << "Yes" << endl;
	else cout << "No" << endl;
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
