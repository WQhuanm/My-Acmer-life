#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 110;

#define mpow(x) ((x)*(x))//定义取平方
const double pi = acos(-1.0);

struct point
{
	double x, y;
	point()
	{
		x = y = 0;
	}
	point(double tx, double ty)
	{
		x = tx;
		y = ty;
	}
	point operator-(const point &b) const
	{
		return point(x - b.x, y - b.y);
	}
	point operator+(const point &b) const
	{
		return point(x + b.x, y + b.y);
	}
	double operator^(const point &b) const
	{
		return x * b.y - y * b.x;    //叉积
	}
	double operator*(const point &b) const
	{
		return x * b.x + y * b.y;    //点积
	}
};

double cross(point oa, point ob)//计算叉积，传入的是向量oa与向量ob（即point a-o与point b-o)，两共顶点向量叉积等于其平行四边形面积
{
	return oa.x * ob.y - ob.x * oa.y;
}

double dot(point a, point b)//点积
{
	return a.x * b.x + a.y * b.y;
}

double dis_pow(point p1, point p2)
{
	return (mpow(p1.x - p2.x) + mpow(p1.y - p2.y));
}
double dis(point p1, point p2)
{
	return sqrt(mpow(p1.x - p2.x) + mpow(p1.y - p2.y));
}

double dis_line(point p, point a, point b)//点p到直线ab距离
{
	return fabs(cross(a - p, b - p) / dis(a, b));
}

double distance_segment(point p, point a, point b)//点p到线段ab的距离
{
	if (dis_pow(a, b) < -eps)return dis(p, a);//a,b重合
	point ab = b - a, pa = a - p, pb = b - p;
	if (ab * pa > eps)return dis(p, a);//p在线段外，靠近a
	if (ab * pb < - eps)return dis(p, b);//p在线段外，靠近b
	return fabs(cross(pa, pb) / dis(a, b));//p可以垂直到线段
}

double area_triangle(point a, point b, point c)
{
	return fabs((a - b) ^ (a - c)) / 2;
}

int n;
point a[N];
bool vis[N];

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].x >> a[i].y;
		}

	int x;
	if (n & 1)
		{
			cout << "Beatrice" << endl;
			int ct = n - 2;
			while (ct--)
				{
					cin >> x;
					vis[x] = 1;
					double mn = INF;
					int ans = 1;
					if (!ct)break;
					for (int p = 1; p <= n; ++p)if (!vis[p])
							{
								int l = p - 1, r = p + 1;
								while (1)
									{
										if (!l)l = n;
										if (!vis[l])break;
										l--;
									}
								while (1)
									{
										if (r == n + 1)r = 1;
										if (!vis[r])break;
										r++;
									}
								double tmp = fabs(cross(a[l] - a[p], a[r] - a[p])) / 2;
								if (tmp - mn < eps)mn = tmp, ans = p;
							}
					cout << ans << endl;
					vis[ans] = 1, ct--;
				}
		}
	else
		{
			cout << "Alberto" << endl;
			int ct = n - 2;
			while (ct--)
				{
					double mn = INF;
					int ans = 1;
					for (int p = 1; p <= n; ++p)if (!vis[p])
							{
								int l = p - 1, r = p + 1;
								while (1)
									{
										if (!l)l = n;
										if (!vis[l])break;
										l--;
									}
								while (1)
									{
										if (r == n + 1)r = 1;
										if (!vis[r])break;
										r++;
									}
								double tmp = fabs(cross(a[l] - a[p], a[r] - a[p])) / 2;
								if (tmp - mn < eps)mn = tmp, ans = p;
							}
					cout << ans << endl;
					vis[ans] = 1;
					if (ct)
						{
							cin >> x;
							vis[x] = 1;
							ct--;
						}
				}
		}
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
