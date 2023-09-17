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
const int mod = 998244353;
const int N = 1e6 + 10;

int dp[N];
void mysolve()
{
	// 1 1 3 2 2 3 1
	//
	int n;
	cin >> n;
	if (n <= 3)
		{
			cout << 1 << endl;
			return;
		}
	//i+(i+1)*(2*i)
	int l = 2, r = inf, ans = 2;
	while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if (mid + 2 * mid*(mid / 2 + 1) >= n)ans = mid, r = mid - 1;
			else l = mid + 1;
		}
	cout << ans << endl;
}
//3 1 2 3 1
int32_t main()
{
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	dp[1] = 3;
	for (int i = 2; i <= 1e5; ++i)
		{

		}
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
