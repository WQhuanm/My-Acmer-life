#include <bits/stdc++.h>
using namespace std;
#define endl             "\n"
#define mpow(x) ((x)*(x))//定义取平方
const double pi = acos(-1.0);

struct point
{
	long long x, y;
};

double q2 = sqrt(2);

void mysolve()
{
	point a, b, r1, r2;
	cin >> a.x >> a.y >> b.x >> b.y;
	r1.x = (a.x + b.x), r1.y = (a.y + b.y);
	cin >> a.x >> a.y >> b.x >> b.y;
	r2.x = (a.x + b.x), r2.y = (a.y + b.y);
	double ans = (abs(r1.x - r2.x) + abs(r1.y - r2.y)) * 1.0 / 2;
	ans -= q2 * sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))/2;
	printf("%.10lf\n", ans);
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
	return 0;
}
