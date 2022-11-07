#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 15;
const double eps = 1e-6;
int n;
double a[N];
double mpow(double x)
{
	double ans = 0;
	double h = 1.0;
	for (int i = 1; i <= n + 1; ++i)
		{
			if (i == 1)ans += a[i];
			else
				{
					h *= x;
					ans += (a[i] * h);
				}
		}

	return ans;
}

int main()
{

	double L, R;
	cin >> n >> L >> R;
	for (int i = n + 1; i >= 1; --i)cin >> a[i];

	while (fabs(R - L) >= eps)
		{
			double mid = ((L + R) / 2);
			double ml = mid - eps, mr = mid + eps;
			if (mpow(ml) < mpow(mr))L = mid;
			else R = mid;
		}

	cout << L << endl;
	return 0;
}
