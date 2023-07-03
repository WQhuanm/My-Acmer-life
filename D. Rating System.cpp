#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int ll
typedef pair<ll, int>pii;
const int N = 3e5 + 10;
int a[N];
int sum[N];
void mysolve()
{
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; ++i)cin >> a[i], ans += a[i];
	sum[n + 1] = 0;
	int res = 0;
	for (int i = n; i; --i)
		{
			sum[i] = min(sum[i + 1] + a[i], 0ll);
			res = max(res, ans - sum[i]);
		}
	int tmp = 0;
	for (int i = 0; i <= n; ++i)
		{
			tmp += a[i];
			if (ans - sum[i + 1] == res)
				{
					cout << tmp << endl;
					return;
				}
		}
//	cout << res << endl;	
}

int32_t main()
{
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

