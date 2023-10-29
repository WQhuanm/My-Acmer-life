#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const long long mod = 1e9 + 7, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 2e5 + 10;

int n, q, tot;
int qlen;
int a[N], c[N];
ll ans[N];

#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

struct tree
{
	int l, r;
	ll sum[2];
	int  num; //sum奇偶贡献，num元素量，add标记
	bool add;
} t[N << 2];

inline void pushup(int p)
{
	t[p].sum[0] = (t[ls].sum[0] + t[rs].sum[0]);
	t[p].sum[1] = (t[ls].sum[1] + t[rs].sum[1]);
	t[p].num = t[ls].num + t[rs].num;
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	t[p].sum[1] = t[p].sum[0] = t[p].num = 0, t[p].add = 0; //初始化
	if (l == r)
		{
			return;
		}
	build(l, mid, ls), build(mid + 1, r, rs);
	pushup(p);
}

void change(int p, bool w)
{
	swap(t[p].sum[0], t[p].sum[1]);
	t[p].add ^= w;
}

void lazy(int p)
{
	if (t[p].l == t[p].r)return;
	if (t[p].add)
		{
			change(ls, t[p].add), change(rs, t[p].add);
			t[p].add = 0;
		}
}

void update(int x, int p, bool fl, ll w)
{
//	assert(t[p].l != 0 && t[p].r != 0);
	if (t[p].l == t[p].r)
		{
			t[p].sum[fl] += x * w, t[p].num += w;
			return;
		}
	lazy(p);
	if (x <= c[mid])update(x, ls, fl, w);
	else update(x, rs, fl, w);
	pushup(p);
}

void update_sum(int x, int p)
{
//	assert(t[p].l != 0 && t[p].r != 0);
	if (x <= c[t[p].l])
		{
			change(p, 1);
			return;
		}
	lazy(p);
	if (x <= c[mid])update_sum(x, ls);
	update_sum(x, rs);
	pushup(p);
}

int ask_num(int x, int p)
{
//	assert(t[p].l != 0 && t[p].r != 0);
	if (c[t[p].l] >= x)return 0;
	if (c[t[p].r] < x)return t[p].num;
	if (t[p].l == t[p].r)return 0;
	lazy(p);
	int ans = ask_num(x, ls);
	if (x > c[mid])ans += ask_num(x, rs);
	return ans;
}

struct node
{
	int l, r, id;
	bool operator<(const node&k)const
	{
		if (l / qlen != k.l / qlen)return l / qlen < k.l / qlen;
		else return ((l / qlen) & 1 ? r > k.r : r < k.r);
	}
} b[N];

void add(int x)
{
	int k = ask_num(x, 1);
	update_sum(x, 1);
	update(x, 1, k & 1, 1);
}
void del(int x)
{
	int k = ask_num(x, 1);
	update(x, 1, k & 1, -1);
	update_sum(x, 1);
}

void solve()
{
	qlen = n / sqrt(q);
	qlen = max(1ll, qlen);
	sort(b + 1, b + 1 + q);
	for (int i = 1, l = 1, r = 0; i <= q; ++i)//暴力对排序后的询问转移
		{
			while (l > b[i].l)add(a[--l]);
			while (r < b[i].r)add(a[++r]);
			while (l < b[i].l)del(a[l++]);
			while (r > b[i].r) del(a[r--]);
			ans[b[i].id] = t[1].sum[0] % mod;
		}
}

void mysolve()
{
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)cin >> a[i], c[++tot] = a[i];
	sort(c + 1, c + 1 + tot);
	tot = unique(c + 1, c + 1 + tot) - c - 1;
	build(1, tot, 1);
	for (int i = 1; i <= q; ++i)cin >> b[i].l >> b[i].r, b[i].id = i, b[i].l++, b[i].r++;
	solve();
	for (int i = 1; i <= q; ++i)cout << ans[i] << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
