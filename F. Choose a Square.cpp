#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
const int N = 5e5 + 10;


struct node
{
	int l, r, c;
	bool operator<(const node&k)const
	{
		if (l != k.l)return l < k.l;
		else return r < k.r;
	}
} a[N];
int b[N];

#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

struct tree
{
	int l, r;
	int id;
	ll sum, add;
} t[N << 2];

inline void pushup(int p)
{
	t[p].sum = max(t[ls].sum, t[rs].sum);
	if (t[p].sum == t[ls].sum)t[p].id = t[ls].id;
	else t[p].id = t[rs].id;
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	t[p].sum = 0, t[p].add = 0; //初始化
	if (l == r)
		{
			t[p].sum = - b[l], t[p].id = b[l];
			return;
		}
	build(l, mid, ls), build(mid + 1, r, rs);
	pushup(p);
}

inline void change(int p, ll w)
{
	t[p].sum = (t[p].sum + w );
	t[p].add = (t[p].add + w);
}

inline void lazy(int p)
{
	if (t[p].l == t[p].r)t[p].add = 0;
	if (t[p].add)
		{
			change(ls, t[p].add), change(rs, t[p].add);
			t[p].add = 0;
		}
}

void update(int l, int r, int p, ll w)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			change(p, w);
			return;
		}
	lazy(p);
	if (l <= mid)update(l, r, ls, w);
	if (r > mid)update(l, r, rs, w);
	pushup(p);
}

pii ask(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return {t[p].sum, t[p].id};
	lazy(p);
	pii ans = {-INF, 0};
	if (l <= mid)
		{
			pii tmp = ask(l, r, ls);
			if (tmp.first > ans.first)ans = tmp;
		}
	if (r > mid)
		{
			pii tmp = ask(l, r, rs);
			if (tmp.first > ans.first)ans = tmp;
		}
	return ans;
}
int n;

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].l >> a[i].r >> a[i].c;
			if (a[i].l > a[i].r)swap(a[i].l, a[i].r);
			b[i] = a[i].r;
		}
	sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
	int len = unique(b + 1, b + 1 + n) - b - 1;
	build(1, len, 1);
	for (int i = 1; i <= n; ++i)update(lower_bound(b + 1, b + 1 + len, a[i].r) - b, len, 1, a[i].c);
	node ans = {(int)2e9, (int)2e9, 0};
	for (int i = 1, last = 1; i <= n; ++i)
		{
			if (i < n && a[i].l == a[i + 1].l)continue;
			pii tmp = ask(lower_bound(b + 1, b + 1 + len, a[i].l) - b, len, 1);
			if (tmp.first + a[i].l > ans.c)ans = {a[i].l, tmp.second, tmp.first + a[i].l};

			for (int j = last; j <= i; ++j)update(lower_bound(b + 1, b + 1 + len, a[j].r) - b, len, 1, -a[j].c);
			last = i + 1;
		}
	cout << ans.c << endl;
	cout << ans.l << " " << ans.l << " " << ans.r << " " << ans.r << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
