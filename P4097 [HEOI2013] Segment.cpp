#include <bits/stdc++.h>
using namespace std;
typedef pair<double, int> pii;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
const int mod = 39989;
const int mod2 = 1e9;
const int N = 3e5 + 10;
const int M = 4e4 + 10;

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

void add(int x, int y, int x2, int y2)
{
	if (x > x2)swap(x, x2), swap(y, y2);
	if (x == x2)a[++tot] = {0, (double)max(y, y2)};//垂直x轴线段k设为0
	else
		{
			double k = (y - y2) * 1.0 / (x - x2), b = y - k * x;
			a[++tot] = {k, b};
		}
	update(x, x2, 1, tot);
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
	tot = 0;
	int op, x, y, x2, y2, ans = 0;
	build(1, M, 1);
	a[0] = {0, -inf};
	while (n--)
		{
			cin >> op;
			if (op)
				{
					cin >> x >> y >> x2 >> y2;
					x = (x + ans - 1) % mod + 1, x2 = (x2 + ans - 1) % mod + 1;
					y = (y + ans - 1) % mod2 + 1, y2 = (y2 + ans - 1) % mod2 + 1;
					add(x, y, x2, y2);
				}
			else
				{
					cin >> x;
					x = (x + ans - 1) % mod + 1;
					ans = ask(x, 1).second;
					cout << ans << endl;
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
