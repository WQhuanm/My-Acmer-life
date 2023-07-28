#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-9
#define int              long long
const int mod = 998244353;
const int N = 1e6 + 10;

#define mid (t[p].l+((t[p].r-t[p].l)>>1))
#define ls p<<1
#define rs p<<1|1

struct tree
{
	int l, r;
	ll mn, madd, add, val;
} t[N << 2];
int n, m, k;

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	t[p].mn = t[p].madd = t[p].val = t[p].add = 0;
	if (l == r)return;
	build(l, mid, ls), build(mid + 1, r, rs);
}

inline void change(int p, ll add, ll madd)
{
	t[p].mn = min(t[p].mn, t[p].val + madd), t[p].val += add;
	t[p].madd = min(t[p].madd, t[p].add + madd), t[p].add += add;
}

inline void lazy(int p)
{
	if (t[p].l == t[p].r)return;
	if (t[p].add || t[p].madd)
		{
			change(ls, t[p].add, t[p].madd), change(rs, t[p].add, t[p].madd);
			t[p].add = t[p].madd = 0;
		}
}

void add(int l, int r, int p, ll w)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			change(p, w, w);
			return;
		}
	lazy(p);
	if (l <= mid)add(l, r, ls, w);
	if (r > mid)add(l, r, rs, w);
}

ll ask(int x, int p)
{
	if (t[p].l == t[p].r && t[p].l == x)return t[p].mn;
	lazy(p);
	if (x <= mid)return ask(x, ls);
	return ask(x, rs);
}

void mysolve()
{
	cin >> n >> m >> k;
	int op, l, r, x;
	ll ans = 0;
	build(1, n, 1);
	while (m--)
		{
			cin >> op >> l >> r;
			if (op == 1)cin >> x, add(l, r, 1, x);
			else add(l, r, 1, -k), ans += r - l + 1;
//			for (int i = 1; i <= n; ++i)cout << ask(i, 1) << " \n"[i == n];
		}
	for (int i = 1; i <= n; ++i)
		{
			ll tmp = ask(i, 1);
			if (tmp < 0)ans -= (-tmp + k - 1) / k;
		}
	cout << ans << endl;
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
