#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;

int n;
int a[N];

bool check(int x)
{
	for (int i = 0; i < n - 1; ++i)
		{
			if ((a[n + i] > x && a[n + i + 1] > x) || (a[n - i] > x && a[n - i - 1] > x))return 0;
			if ((a[n + i] <= x && a[n + i + 1] <= x) || (a[n - i] <= x && a[n - i - 1] <= x))return 1;
		}
	return ((n & 1 && a[n] <= x) || (!(n & 1) && a[n] > x));
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= 2 * n - 1; ++i)cin >> a[i];
	int ans = -1, l = 1, r = 2 * n - 1;
	while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if (check(mid))ans = mid, r = mid - 1;
			else l = mid + 1;
		}
	cout << ans << endl;
}

int32_t main()
{
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
