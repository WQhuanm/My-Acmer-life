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
const int mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 1e6 + 10;

#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

struct tree
{
	int l, r;
	ll sum, st, add;
} t[N << 2];

inline void pushup(int p)
{
	t[p].sum = (t[ls].sum + t[rs].sum);
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	t[p].sum = t[p].st = t[p].add = 0; //初始化
	if (l == r)
		{
			return;
		}
	build(l, mid, ls), build(mid + 1, r, rs);
	pushup(p);
}

inline void change(int p, ll w)
{
	t[p].sum = (t[p].sum + w * (t[p].r - t[p].l + 1));
	t[p].add = (t[p].add + w);
}

inline void lazy(int p)
{
	if (t[p].l == t[p].r)return;
	if (t[p].st)
		{
			t[ls].add = t[rs].add = 0;
			t[ls].st = t[rs].st = 1;
			t[ls].sum = mid - t[p].l + 1;
			t[rs].sum = t[p].r - mid;
			t[p].st = 0;
		}
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

void st(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			t[p].sum = t[p].r - t[p].l + 1;
			t[p].st = 1, t[p].add = 0;
			return;
		}
	lazy(p);
	if (l <= mid)st(l, r, ls);
	if (r > mid)st(l, r, rs);
	pushup(p);
}

int n;
int a[N];
bool vis[N];
void mysolve()
{
	cin >> n;
	vis[0] = 0;
	for (int i = 1; i <= n; ++i)cin >> a[i], vis[i] = 0;
	int mex = 0;
	build(1, n, 1);
	for (int i = 1; i <= n; ++i)
		{
			vis[a[i]] = 1;
			while (vis[mex])
				{
					mex++;
					update(mex, mex, 1, n - i + 1);
				}
		}
	int ans = t[1].sum;
	for (int i = 1; i <= n; ++i)
		{
			st(a[i] + 1, n, 1);
			if (a[i])update(1, a[i], 1, 1);
			ans = max(ans, t[1].sum);
		}
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
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
