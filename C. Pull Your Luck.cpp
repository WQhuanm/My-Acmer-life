#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 1e5 + 100;
void mysolve()
{
	int n, x, p;
	cin >> n >> x >> p;
	int sum = 0;
	for (int i = 1; i <= 2 * n && i <= p; ++i)
		{
			sum += i;
			if (sum % n == (n - x) % n)
				{
					cout << "YES" << endl;
					return;
				}
		}
	cout << "NO" << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
