#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 5e5 + 10;

#define mid (t[p].l+((t[p].r-t[p].l)>>1))
#define ls p<<1
#define rs p<<1|1

struct tree
{
	int l, r;
	ll mx, mx2, sum, fmx;//区间最大值，次大值，区间和，区间历史最值
	int cnt;//区间最大值个数
	ll add, add2, madd, madd2;//非最值懒惰标记，非最值标记的历史最值标记  //最值的懒惰标记，最值标记的历史最值标记
	void clear()
	{
		add = add2 = madd = madd2 = 0;
	}
} t[N << 2];

int a[N];

inline void pushup(int p)
{
	t[p].sum = (t[ls].sum + t[rs].sum);
	t[p].fmx = max({t[p].fmx, t[ls].fmx, t[rs].fmx});
	t[p].mx = max(t[ls].mx, t[rs].mx);
	if (t[ls].mx == t[rs].mx)
		{
			t[p].cnt = (t[ls].cnt + t[rs].cnt);
			t[p].mx2 = max(t[ls].mx2, t[rs].mx2);
		}
	else if (t[ls].mx > t[rs].mx)
		{
			t[p].cnt = (t[ls].cnt);
			t[p].mx2 = max(t[ls].mx2, t[rs].mx);
		}
	else
		{
			t[p].cnt = (t[rs].cnt);
			t[p].mx2 = max(t[ls].mx, t[rs].mx2);
		}
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	t[p].fmx = t[p].mx2 = -INF;
	t[p].clear();
	if (l == r)
		{
			t[p].sum = t[p].fmx = t[p].mx = a[l];
			t[p].cnt = 1;
			return;
		}
	build(l, mid, ls), build(mid + 1, r, rs);
	pushup(p);
}

inline void change(int p, ll add, ll add2, ll madd, ll madd2)
{
	t[p].sum = (t[p].sum + add * (t[p].r - t[p].l + 1 - t[p].cnt) + madd * t[p].cnt);
	t[p].fmx = max(t[p].fmx, t[p].mx + madd2); //历史最大m=现在+最大标记
	t[p].mx = (t[p].mx + madd), t[p].mx2 = (t[p].mx2 + add);
	t[p].madd2 = max(t[p].madd2, t[p].madd + madd2), t[p].add2 = max(t[p].add2, t[p].add + add2);
	t[p].add = (t[p].add + add), t[p].madd = (t[p].madd + madd);
}

inline void lazy(int p)
{
	if (t[ls].mx == t[rs].mx)
		{
			change(ls, t[p].add, t[p].add2, t[p].madd, t[p].madd2), change(rs, t[p].add, t[p].add2, t[p].madd, t[p].madd2);
		}
	else if (t[ls].mx > t[rs].mx)//只有子区间最值等于父区间最值，才继承父区间的最值自身标记，否则都是继承非最值的标记
		{
			change(ls, t[p].add, t[p].add2, t[p].madd, t[p].madd2), change(rs, t[p].add, t[p].add2, t[p].add, t[p].add2);
		}
	else
		{
			change(ls, t[p].add, t[p].add2, t[p].add, t[p].add2), change(rs, t[p].add, t[p].add2, t[p].madd, t[p].madd2);
		}
	t[p].clear();
}

void add(int l, int r, int p, ll w)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			change(p, w, w, w, w);
			return;
		}
	lazy(p);
	if (l <= mid)add(l, r, ls, w);
	if (r > mid)add(l, r, rs, w);
	pushup(p);
}

void _mn(int l, int r, int p, ll w)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			if (w >= t[p].mx)return;
			if (w <= t[p].mx2)
				{
					lazy(p);
					_mn(l, r, ls, w), _mn(l, r, rs, w);
					pushup(p);
				}
			change(p, 0, 0, w - t[p].mx, w - t[p].mx);
			return;
		}
	lazy(p);
	if (l <= mid)_mn(l, r, ls, w);
	if (r > mid)_mn(l, r, rs, w);
	pushup(p);
}

ll ask_sum(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p].sum;
	ll ans = 0;
	lazy(p);
	if (l <= mid)ans = (ans + ask_sum(l, r, ls));
	if (r > mid)ans = (ans + ask_sum(l, r, rs));
	return ans;
}

ll ask_mx(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p].mx;
	ll ans = -INF;
	lazy(p);
	if (l <= mid)ans = max(ans, ask_mx(l, r, ls));
	if (r > mid)ans = max(ans, ask_mx(l, r, rs));
	return ans;
}

ll ask_fmx(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p].fmx;
	ll ans = -INF;
	lazy(p);
	if (l <= mid)ans = max(ans, ask_fmx(l, r, ls));
	if (r > mid)ans = max(ans, ask_fmx(l, r, rs));
	return ans;
}

