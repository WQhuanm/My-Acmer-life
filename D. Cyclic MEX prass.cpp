#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 2e6 + 10;

#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

struct tree
{
	int l, r;
	ll sum;
	int  mx, st;
} t[N << 2];
int a[N], b[N];

int n;
inline void pushup(int p)
{
	t[p].sum = (t[ls].sum + t[rs].sum);
	t[p].mx = max(t[ls].mx, t[rs].mx);
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	t[p].sum =  0, t[p].st = -1; //初始化
	if (l == r)
		{
			if (l <= n)t[p].sum = t[p].mx = b[l];
			else t[p].sum = t[p].mx = 0;
			return;
		}
	build(l, mid, ls), build(mid + 1, r, rs);
	pushup(p);
}

inline void change(int p, ll w)
{
	t[p].sum = (t[p].sum + w * (t[p].r - t[p].l + 1));
}

inline void _set(int p, ll w)
{
	t[p].sum = (t[p].r - t[p].l + 1) * w;
	t[p].mx = t[p].st = w;
}

inline void lazy(int p)
{
	if (t[p].l == t[p].r)return;
	if (~t[p].st)
		{
			_set(ls, t[p].st), _set(rs, t[p].st);
			t[p].st = -1;
		}
}

void st(int l, int r, int p, ll w)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			_set(p, w);
			return;
		}
	lazy(p);
	if (l <= mid)st(l, r, ls, w);
	if (r > mid)st(l, r, rs, w);
	pushup(p);
}
int ask_mx(int l, int r, int p, ll w)
{
	if (t[p].l == t[p].r)return t[p].l;
	lazy(p);
	if (t[ls].mx >= w)return ask_mx(l, r, ls, w);
	else return ask_mx(l, r, rs, w);
}

bool vis[N];
void mysolve()
{
	cin >> n;
	vis[0] = 0;
	for (int i = 1; i <= n; ++i)cin >> a[i], vis[i] = 0;
	int mex = 0;
	for (int i = 1; i <= n; ++i)
		{
			vis[a[i]] = 1;
			while (vis[mex])mex++;
			b[i] = mex;
		}
	build(1, n << 1, 1);
	ll ans = t[1].sum;
	for (int i = 1; i <= n; ++i)
		{
			int l = ask_mx(1, n << 1, 1, a[i] + 1);
			st(l, n + i - 1, 1, a[i]);
			st(n + i, n + i, 1, n);
			ans = max(ans, t[1].sum);
		}
	cout << ans << endl;
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
	system("pause");
	return 0;
}
