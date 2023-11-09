#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define inf 0x3f3f3f3f
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 5e5 + 10;

int n;

#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

struct tree
{
	int l, r;
	int mx, mn;
} t[N << 2];
int a[N];

inline void pushup(int p)
{
	t[p].mx = max(t[ls].mx, t[rs].mx);
	t[p].mn = min(t[ls].mn, t[rs].mn);
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	if (l == r)
		{
			t[p].mx = t[p].mn = a[l];
			return;
		}
	build(l, mid, ls), build(mid + 1, r, rs);
	pushup(p);
}

void update(int x, int p)
{
	if (t[p].l == t[p].r)
		{
			t[p].mx = t[p].mn = a[t[p].l];
			return;
		}
	if (x <= mid)update(x, ls);
	else update(x, rs);
	pushup(p);
}

int ask_mn(int l, int r, int p, int w)
{
	if (t[p].l == t[p].r)return (t[p].mn <= w ? t[p].l : -1);
	if (l <= t[p].l && t[p].r <= r)
		{
			if (t[rs].mn <= w)return ask_mn(l, r, rs, w);
			else return ask_mn(l, r, ls, w);
		}
	int ans = -1;
	if (l <= mid)ans = max(ans, ask_mn(l, r, ls, w));
	if (r > mid)ans = max(ans, ask_mn(l, r, rs, w));
	return ans;
}

int ask_mx(int l, int r, int p, int w)
{
	if (t[p].l == t[p].r)return (t[p].mx >= w ? t[p].l : inf);
	if (l <= t[p].l && t[p].r <= r)
		{
			if (t[ls].mx >= w)return ask_mx(l, r, ls, w);
			else return ask_mx(l, r, rs, w);
		}
	int ans = inf;
	if (l <= mid)ans = min(ans, ask_mx(l, r, ls, w));
	if (r > mid)ans = min(ans, ask_mx(l, r, rs, w));
	return ans;
}

ll ans;

void solve(int l, int r)
{
	if (l >= r)return;
	int p = a[(l + r) / 2];
	int i = l - 1, j = r + 1;
	while (1)
		{
			i = ask_mx(i + 1, r, 1, p), j = ask_mn(l, j - 1, 1, p);
			if (i < j)
				{
					swap(a[i], a[j]);
					ans++;
					update(i, 1), update(j, 1);
				}
//			for (int i = 1; i <= n; ++i)cout << a[i] << " \n"[i == n];
			else break;
		}

	solve(l, j), solve(j + 1, r);
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	build(1, n, 1);
	ans = 0;
	solve(1, n);
	cout << ans << endl;
//	for (int i = 1; i <= n; ++i)cout << a[i] << " \n"[i == n];
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
	return 0;
}
