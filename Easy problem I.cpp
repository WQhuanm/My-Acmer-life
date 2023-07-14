#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f

#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

const int N = 2e5 + 10;

struct tree
{
	int l, r;
	ll sum1, sum2;
	ll add1, add2;
	int p;
	int sz1, sz2;
	ll mn;
	int mnp;
} t[N << 2];

int a[N];

inline void pushup(int p)
{
	t[p].sum1 = (t[ls].sum1 + t[rs].sum1);
	t[p].sum2 = t[ls].sum2 + t[rs].sum2;
	t[p].sz1 = t[ls].sz1 + t[rs].sz1;
	t[p].sz2 = t[ls].sz2 + t[rs].sz2;
	t[p].mn = min(t[ls].mn, t[rs].mn);
	if (t[ls].mn == t[p].mn)t[p].mnp = t[ls].mnp;
	else t[p].mnp = t[rs].mnp;
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r, t[p].sz1 = t[p].sz2 = t[p].sum1 = t[p].sum2 = t[p].p = t[p].add1 = t[p].add2 = 0;
	t[p].add2 = -1;
	if (l == r)
		{
			t[p].sum1 = t[p].mn = a[l];
			t[p].mnp = l;
			t[p].sz1 = 1;
			return;
		}
	build(l, mid, ls), build(mid + 1, r, rs);
	pushup(p);
}

inline void change1(int p, ll w)
{
	if (t[p].sz1)
		{
			t[p].sum1 -= t[p].sz1 * w;
			if (t[p].mn < inf)t[p].mn -= w;
			t[p].add1 += w;
		}
}

inline void change2(int p, ll w, int p1)
{
	if (t[p].sz2)
		{
			t[p].sum2 = t[p].sz2 * w + (p1 ? - t[p].sum2 : t[p].sum2);
			t[p].add2 = (t[p].add2 == -1 ? w : w + (p1 ? -t[p].add2 : t[p].add2));
			t[p].p ^= p1;
		}
}

inline void lazy(int p),.,m
{
	if (t[p].l == t[p].r)return;
	if (t[p].add1)
		{
			change1(ls, t[p].add1), change1(rs, t[p].add1);
			t[p].add1 = 0;
		}
	if (~t[p].add2)
		{
			change2(ls, t[p].add2, t[p].p), change2(rs, t[p].add2, t[p].p);
			t[p].add2 = -1;
			t[p].p = 0;
		}
}

void update(int l, int r, int p, ll w)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			change1(p, w), change2(p, w, 1);
			return;
		}
	lazy(p);
	if (l <= mid)update(l, r, ls, w);
	if (r > mid)update(l, r, rs, w);
	pushup(p);
}

ll ask(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p].sum1 + t[p].sum2;
	lazy(p);
	ll ans = 0;
	if (l <= mid)ans += ask(l, r, ls);
	if (r > mid)ans += ask(l, r, rs);
	return ans;
}

int check(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return (t[p].mn < 0 ? t[p].mnp : -1);
	lazy(p);
	int ans = -1;
	if (l <= mid)ans = max(ans, check(l, r, ls));
	if (r > mid)ans = max(ans, check(l, r, rs));
	return ans;
}

void add(int x, int p)
{
	if (t[p].l == x && t[p].r == x)
		{
			t[p].sum2 -= t[p].sum1;
			t[p].sum1 = 0;
			t[p].sz2 = 1, t[p].sz1 = 0;
			t[p].mn = inf;
			return;
		}
	lazy(p);
	if (x <= mid)add(x, ls);
	else add(x, rs);
	pushup(p);
}

void mysolve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	build(1, n, 1);
	int op, l, r, x;
	while (m--)
		{
			cin >> op >> l >> r;
			if (op == 1)
				{
					cin >> x;
					update(l, r, 1, x);
					int p = -1;
					while ((p = check(l, r, 1)) != -1)add(p, 1);
				}
			else cout << ask(l, r, 1) << endl;
		}
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
