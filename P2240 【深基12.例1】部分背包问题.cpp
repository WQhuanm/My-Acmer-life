#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

struct moey
{
	int w, v;
	bool operator<(const moey &b)const
	{
		return v * 1.0 / w > b.v * 1.0 / b.w;
	}
} a[N];

int main()
{
	int n, t;
	cin >> n >> t;
	double ans = 0;
	for (int i = 1; i <= n; ++i)cin >> a[i].w >> a[i].v;
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i)
		{
			if (t >= a[i].w)
				{
					ans += a[i].v;
					t -= a[i].w;
				}
			else
				{
					double h = (a[i].v * 1.0) / a[i].w;
					ans += 1.0 * h * t ;
					break;
				}
		}
	printf("%.2lf\n", ans);
	return 0;
}

