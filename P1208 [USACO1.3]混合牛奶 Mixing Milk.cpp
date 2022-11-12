#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

struct milk
{
	ll p, v;
	bool operator<(const milk&b)const
	{
		return p < b.p;
	}
} a[N];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		{
			cin >> a[i].p >> a[i].v;
		}
	sort(a + 1, a + 1 + m);
	ll sum = 0;
	for (int i = 1; i <= m; ++i)
		{
			if (n >= a[i].v)
				{
					sum += a[i].p * a[i].v;
					n -= a[i].v;
				}
			else
				{
					sum += a[i].p * n;
					break;
				}
		}
	cout << sum << endl;
	return 0;
}

