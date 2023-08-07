#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
#define int              long long
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 3e5 + 10;
#define mpow(a) ((a)*(a))
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
};

point operator-(const point &a, const point&b)
{
	return point(a.x - b.x, a.y - b.y);
}

point operator+(const point &a,        const point&b)
{
	return point(a.x + b.x, a.y + b.y);
}

point o;//用极角排序需要明确极点o

//优先使用叉积，精度损失小（可能跑得慢?）
double cross(point oa, point ob)//计算叉积，传入的是向量oa与向量ob（即point a-o与point b-o)
{
	return oa.x * ob.y - ob.x * oa.y;
}

bool cmp_cross(point a, point b)
{
	double c = cross(a - o, b - o);
	if (fabs(c) < eps)
		{
			if (fabs(a.x - b.x) > eps)return a.x - b.x < -eps;        //叉积相同，x坐标小排前面
			else return a.y - b.y < -eps;// 如果x还相同，则y小
		}
	return c > eps;
}

//精度损失大，速度快
bool cmp_atan2(point a, point b)//atan2传入坐标，返回弧度，从第三象限逆时针2pi到第二象限[-pi,pi]（从负数开始，而非从第一象限的0开始）
{
	a = a - o, b = b - o;//需要明确极点o
	if (fabs(atan2(a.y, a.x) - atan2(b.y, b.x)) > eps)
		{
			return atan2(a.y, a.x) - atan2(b.y, b.x) < -eps;
		}
	else if (fabs(a.x - b.x) > eps)return a.x - b.x < -eps; //弧度相同，x坐标小的排前面
	else return a.y - b.y < -eps;// 如果x还相同，则y小
}

double dis(point p1, point p2)
{
	return sqrt(mpow(p1.x - p2.x) + mpow(p1.y - p2.y));
}

int n;
point a[N];
int st[N];

int tot = 0;

void add(double x, double y)
{
	a[++tot] = {x, y};
	if (tot > 1)
		{
			if (a[tot].y - a[1].y < -eps)swap(a[1], a[tot]);
			else if (fabs(a[tot].y - a[1].y) < eps && a[tot].x - a[1].x < -eps)swap(a[1], a[tot]);//凸包起点要y最小的前提下，x最小，才可以作为极点
		}
}

double dxita[5];
void mysolve()
{
	cin >> n;
	double pa, pb, r, x, y, xita;
	cin >> pa >> pb >> r;
	pa -= 2 * r, pb -= 2 * r;
	double d = sqrt(mpow(pa) + mpow(pb)) / 2  ;
	dxita[1] = atan2(pa, pb), dxita[2] = atan2(pa, -pb), dxita[3] = atan2(-pa, -pb), dxita[4] = atan2(-pa, pb);
	for (int i = 1; i <= n; ++i)
		{
			cin >> x >> y >> xita;
			for (int i = 1; i <= 4; ++i)
				{
					double x1 = x + d * cos(xita + dxita[i]), y1 = y + d * sin(xita + dxita[i]);
					add(x1, y1);
				}

		}
	o = a[1];
	sort(a + 2, a + 1 + tot, cmp_cross);//a[1]为极点，从2~n开始排序
	int top = 1;
	st[top] = 1;
	for (int i = 2; i <= tot; ++i)
		{
			while (top >= 2 && cross(a[st[top]] - a[st[top - 1]], a[i] - a[st[top]]) < eps)top--;//如果向量(top-1)->top叉积向量top->a[i]小于等于0，舍去top
			st[++top] = i;
		}
	st[top + 1] = 1;//最后栈加入起点，形成	闭环
	double ans = 0;
	for (int i = 1; i <= top; ++i)ans += dis(a[st[i]], a[st[i + 1]]);//凸包周长
	ans += acos(-1.0) * 2 * r;
	printf("%.2lf", ans);
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
