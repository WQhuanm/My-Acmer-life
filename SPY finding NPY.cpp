#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
long double e = exp(1);

long double ans(int n, int k)
{
	double tmp = 0;
	for (int i = k; i < n; ++i)tmp += 1.0 / i;
	tmp = tmp * k / n;
	return tmp;
}
void mysolve()
{
	int n;
	cin >> n;
	int k = n / e;
	if (ans(n, k) < ans(n, k + 1))cout << k+1 << endl;
	else cout << k  << endl;
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
