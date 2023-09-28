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
const int N = 3e6 + 10;

int n;
int a[N];

int solve(int n)
{
	if (n == 1)return a[0] ? 1 : 0;
	bool fl = 1;
	for (int i = 0; i < n / 2; ++i)
		{
			if (a[i] != a[(i + n / 2) % n])
				{
					fl = 0;
					break;
				}
		}
	if (fl)return solve(n / 2);
	for (int i = 0; i < n / 2; ++i)a[i] ^= a[(i + n / 2) % n];
	return n / 2 + solve(n / 2);
}

void mysolve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> a[i];
	cout << solve(n) << endl;
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
