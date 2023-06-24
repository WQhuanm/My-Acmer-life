#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define eps 1e-9
#define int              double

int n, r;
int x, y, dx, dy;

void solve2()//起点为矢量
{
	double inv = sqrt(x * x + y * y);
	double ax = r * x * 1.0 / inv, ay = r * y * 1.0 / inv;
	printf("Observe at (%.4lf,%.4lf)\n", ax, ay);
}

void mysolve()
{
	cin >> n >> r;
	while (n--)
		{
			cin >> x >> y >> dx >> dy;
			int a = dx * dx + dy * dy, b = 2 * (x * dx + y * dy), c = x * x + y * y - r * r;
			int deta = b * b - 4 * a * c;
			double ax, ay, tx, ty;
			if (deta < 0)//判别式
				{
					a = dy, b = -dx, c = (-x * a - y * b);
					if (!a)
						{
							ax = 0, ay = r, ty = y, tx = 0;
							if (abs(a * ax + b * (-ay) + c) < abs(a * ax + b * ay + c))ay = -ay;
						}
					else
						{
							double xita = atan(b * 1.0 / a);
							tx = -c * 1.0 / (a + b * b * 1.0 / a);
							ty = tx * b * 1.0 / a;
							ax = r * cos(xita), ay = r * sin(xita);
							if (fabs(a * (-ax) + b * (-ay) + c) < fabs(a * ax + b * ay + c))ay = -ay, ax = -ax;
						}
//判断射线是否经过投影点(tx,ty)，方向向量相同
					if ((dy && fabs((ty - y) * 1.0 / fabs(ty - y) - dy * 1.0 / fabs(dy)) > eps) || (dx && fabs((tx - x) * 1.0 / fabs(tx - x) != dx * 1.0 / fabs(dx)) > eps))
						{
							solve2();
							continue;
						}
					printf("Observe at (%.4lf,%.4lf)\n", ax, ay);
				}
			else
				{
					double x2 = (-b - sqrt(deta) * 1.0) / (2 * a);
					if (x2 > 0)//射线方向穿过圆
						{
							double ans = x2;
							printf("Crash at (%.4lf,%.4lf)\n", x + ans * dx, y + ans * dy);
						}
					else solve2();//射线方向不能穿过圆
				}
		}
}

int32_t main()
{
	mysolve();
}

