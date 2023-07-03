#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int ll
void mysolve()
{
	int n, x;
	cin >> n;
	set<int>ans, s;
	ll r = n * (n + 1) / 2 + 1;
	for (int i = 1; i <= n; ++i)
		{
			cin >> x;
			set<int>pre;
			ans.insert(x), pre.insert(x);
			for (auto v : s)
				{
					ll tmp = lcm(v, x);
					if (tmp <= r)pre.insert(tmp), ans.insert(tmp);
				}
			s = pre;
		}
	ll res = 1;
	while (ans.count(res))res++;
	cout << res << endl;
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
