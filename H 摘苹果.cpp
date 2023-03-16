#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int N = 1e5 + 10;
int a[N];
struct tree
{
	int l, r;
	ll sum, cnt, maxn;
} t[N << 2];

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r, t[p].cnt = 0;
	if (l == r)
		{
			t[p].sum = t[p].maxn = a[l];
			if (t[p].sum < 100)t[p].cnt = 1;
			return;
		}
	int mid = l + ((r - l) >> 1);
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
	t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
	t[p].cnt = t[p << 1].cnt + t[p << 1 | 1].cnt;
	t[p].maxn = max(t[p << 1].maxn, t[p << 1 | 1].maxn);
}

void update(int l, int r, int p)
{
	if (t[p].maxn < 10)return;
	if (t[p].l == t[p].r)
		{

			t[p].sum = t[p].maxn = t[p].sum * 2 / 3;
			if (t[p].sum < 100)t[p].cnt = 1;
			return;
		}
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (l <= mid)update(l, r, p << 1);
	if (r > mid)update(l, r, p << 1 | 1);
	t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
	t[p].cnt = t[p << 1].cnt + t[p << 1 | 1].cnt;
	t[p].maxn = max(t[p << 1].maxn, t[p << 1 | 1].maxn);
}

ll asksum(int l, int r, int p)
{
	if (t[p].r <= r && l <= t[p].l)return t[p].sum;
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	ll ans = 0;
	if (l <= mid)ans += asksum(l, r, p << 1);
	if (r > mid)ans += asksum(l, r, p << 1 | 1);
	return ans;
}
ll askcnt(int l, int r, int p)
{
	if (t[p].r <= r && l <= t[p].l)return t[p].cnt;
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	ll ans = 0;
	if (l <= mid)ans += askcnt(l, r, p << 1);
	if (r > mid)ans += askcnt(l, r, p << 1 | 1);
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	int op, x, y;
	build(1, n, 1);
	while (m--)
		{
			cin >> op >> x >> y;
			if (op == 1)update(x, y, 1);
			else if (op == 2)cout << askcnt(x, y, 1) << endl;
			else if (op == 3)cout << asksum(x, y, 1) << endl;
		}

	return 0;
}
