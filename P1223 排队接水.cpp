#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

struct peo
{
	ll q, t;
	bool operator<(const peo&b)const
	{
		return t < b.t;
	}
} a[N];
ll sum[N];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].t;
			a[i].q = i;
		}
	sort(a + 1, a + 1 + n);
	ll ans = 0;
	for (int i = 2; i <= n; ++i)
		{
			sum[i] = sum[i - 1] + a[i - 1].t;
			ans += sum[i];
		}
	for (int i = 1; i <= n; ++i)
		{
			cout << a[i].q;
			if (i == n)cout << endl;
			else cout << ' ';
		}
	double T = ans * 1.0 / n;
	printf("%.2lf", T);
	return 0;
}
