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
const int N = 3e5 + 10;

int a[N];
void mysolve()
{
	int n;
	cin >> n;
	int fl = 0, ans = 0;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			if (!fl)ans++;
			if (!a[i])
				{
					if (fl == 2)fl = 0;
					else if (fl == 1)ans++;
					else fl = 1;
				}
			else if (a[i] == 1)
				{
					if (!fl)fl = 2;
				}
			else
				{
					fl = 2;
				}
		}
	cout << ans << endl;
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
