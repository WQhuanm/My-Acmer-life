#include <bits/stdc++.h>
using namespace std;
const int N = 4e2 + 10;
#define eps 1e-8
int n;
struct point
{
	double x, y;
	point() {}
	point(double tx, double ty)
	{
		x = tx;
		y = ty;
	}
} a[N];

double dis(point p1, point p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

point Circlecenter1(point p1, point p2, double r)//有圆的前提要保证两点距离小于等于2*r
{
	point mid = point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
	double angle = atan2(p1.x - p2.x, p2.y - p1.y);
	double d = sqrt(r * r - pow(dis(p1, mid), 2));
	return point(mid.x + d * cos(angle), mid.y + d * sin(angle));
}

point Circlecenter2(point p1, point p2, double r)//有圆的前提要保证两点距离小于等于2*r
{
	point mid = point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
	double angle = atan2(p1.x - p2.x, p2.y - p1.y);
	double d = sqrt(r * r - pow(dis(p1, mid), 2));
	return point(mid.x - d * cos(angle), mid.y - d * sin(angle));
}

bool check(point p, double r)
{
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		{
			if (dis(a[i], p) - r < eps)cnt++;
			if (cnt >= (n + 1) / 2)return 1;
		}
	return 0;
}

void mysolve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)scanf("%lf %lf", &a[i].x, &a[i].y);
	if (n == 1)
		{
			printf("%.6lf %.6lf %.6lf\n", a[1].x, a[1].y, 0.0);
			return;
		}
	point ans;
	double ra;
	double l = 0, r = 1e10;
	while (l - r < -eps)
		{
			double mid = l + ((r - l) / 2);
			bool fl = 0;
			for (int i = 1; i < n; ++i)if (!fl)for (int j = i + 1; j <= n; ++j)
						{
							if (dis(a[i], a[j]) -  mid * 2 < eps)
								{
									point center = Circlecenter1(a[i], a[j], mid);
									if (check(center, mid))
										{
											ans = center, ra = mid;
											fl = 1;
											break;
										}
									center = Circlecenter2(a[i], a[j], mid);
									if (check(center, mid))
										{
											ans = center, ra = mid;
											fl = 1;
											break;
										}
								}
						}
			if (fl)r = mid;
			else l = mid;
		}
	printf("%.6lf %.6lf %.6lf\n", ans.x, ans.y, ra);
}

int32_t main()
{
	mysolve();
	system("pause");
	return 0;
}
