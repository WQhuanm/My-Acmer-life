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
const int M = 5e4 + 10;

#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

struct line
{
	double k, b;
} a[N];//记录填入线段
struct tree
{
	int l, r, id;//id为0，表示该区间没有线段
} t[N << 2];

int n, tot;//tot为已经插入的线段数量

double cal(int id, int x)//x为坐标
{
	return a[id].k * x + a[id].b;
}

void  build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r, t[p].id = 0;
	if (l == r)return;
	build(l, mid, ls), build(mid + 1, r, rs);
}

void change(int p, int x)//x为id
{
	if (cal(x, mid) - cal(t[p].id, mid) > eps)swap(x, t[p].id);//保证t[p].id对应的是该位置的最优线段，只有严格大才更新（保证编号最小）
	if (t[p].l == t[p].r)return;
	//操作后 x为次优，在他能够比t[p].id优越的子区间更新
	double cl = cal(x, t[p].l) - cal(t[p].id, t[p].l), cr = cal(x, t[p].r) - cal(t[p].id, t[p].r);
	if (cl > eps || (fabs(cl) < eps && x < t[p].id))change(ls, x);//两个区间只会进入一个，如果x严格优越或者相等但是x编号小，更新
	if (cr > eps || (fabs(cr) < eps && x < t[p].id))change(rs, x);
}

void update(int l, int r, int p, int x)//x为id
{
	if (l <= t[p].l && t[p].r <= r)
		{
			change(p, x);
			return;
		}
	if (l <= mid)update(l, r, ls, x);
	if (r > mid)update(l, r, rs, x);
}

void add(double k, double b)
{
	a[++tot] = {k, b};
	update(1, M, 1, tot);
}

pii cmp(pii a, pii b)//获得最高且编号最小的点
{
	if (a.first - b.first > eps)return a;
	if (b.first - a.first > eps)return b;
	return (a.second < b.second ? a : b);
}
pii ask(int x, int p)//x为坐标
{
	if (t[p].l == t[p].r)return {cal(t[p].id, x), t[p].id};
	//李超没有下传标记，所有覆盖x的区间的最值才是最优
	pii ans = {cal(t[p].id, x), t[p].id};
	if (x <= mid)ans = cmp(ans, ask(x, ls));
	if (x > mid)ans = cmp(ans, ask(x, rs));
	return ans;
}

void mysolve()
{
	cin >> n;
	build(1, M, 1);//M为x坐标值域
	a[0] = {0, 0};//0为无线段，赋值极小
	double x, y;
	string s;
	while (n--)
		{
			cin >> s;
			if (s[0] == 'Q')
				{
					cin >> x;
					int ans = ask((int)x, 1).first;
					ans /= 100;
					cout << ans << endl;
				}

			else
				{
					cin >> x >> y;
					add(y, x - y);
				}
		}
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
