#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f
const int N = 3e5 + 10, M = 15;

int n, l, K;
int a[N], b[N];

#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

struct tree
{
	int l, r;
	ll sum[M], add[M];
} t[N << 2];

inline void pushup(int p)
{
	for (int k = 1; k <= K; ++k)t[p].sum[k] = min(t[ls].sum[k], t[rs].sum[k]);
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	for (int k = 1; k <= K; ++k)t[p].add[k] = 0;
	if (l == r)
		{
			for (int k = 1; k <= K; ++k)t[p].sum[k] = INF;
			return;
		}
	build(l, mid, ls), build(mid + 1, r, rs);
	pushup(p);
}

inline void change(int p, ll w, int k)
{
	t[p].sum[k] += w, t[p].add[k] += w;
}

inline void lazy(int p)
{
	if (t[p].l == t[p].r)return;
	for (int k = 1; k <= K; ++k)
		if (t[p].add[k])
			{
				change(ls, t[p].add[k], k), change(rs, t[p].add[k], k);
				t[p].add[k] = 0;
			}
}

void add_mn(int x, ll w, int k, int p)
{
	if (t[p].l == t[p].r)return t[p].sum[k] = min(t[p].sum[k], w), void();
	lazy(p);
	if (x <= mid)add_mn(x, w, k, ls);
	else add_mn(x, w, k, rs);
	pushup(p);
}

void update(int l, int r, int p, ll w)
{
	if (l > r)return;
	if (l <= t[p].l && t[p].r <= r)
		{
			for (int k = 1; k <= K; ++k)
				change(p, w, k);
			return;
		}
	lazy(p);
	if (l <= mid)update(l, r, ls, w);
	if (r > mid)update(l, r, rs, w);
	pushup(p);
}

ll ask(int l, int r, int k, int p)
{
	if (l > r)return INF;
	if (l <= t[p].l && t[p].r <= r)return t[p].sum[k];
	lazy(p);
	ll ans = INF;
	if (l <= mid)ans = min(ans, ask(l, r, k, ls));
	if (r > mid)ans = min(ans, ask(l, r, k, rs));
	return ans;
}

void mysolve()
{
	cin >> n >> l >> K;
	for (int i = 1; i <= n; ++i)cin >> a[i], b[i] = a[i];
	sort(b + 1, b + 1 + n);
	int len = unique(b + 1, b + 1 + n) - b - 1;
	int cnt = 0;
	for (int i = 1; i < l; ++i)cnt += a[i] >= a[l];
	build(1, len, 1);
	add_mn(lower_bound(b + 1, b + 1 + len, a[l]) - b, cnt, 1, 1);
	for (int i = l + 1; i <= n; ++i)
		{
			int x = lower_bound(b + 1, b + 1 + len, a[i]) - b;
			for (int k = K; k > 1; --k)
				{

					add_mn(x, ask(1, x - 1, k - 1, 1), k, 1);
				}
			update(1, x - 1, 1, 1);
		}
	int ans = ask(1, len, K, 1);
	cout << (ans < INF ? ans : -1) << endl;
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
