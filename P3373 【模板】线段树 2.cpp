#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 1e5 + 10;

int a[N];
int n, m, mod;
struct tree
{
	int l, r;
	ll sum, add, mul;
} t[4 * N + 2];

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r, t[p].mul = 1; //这里多更新了一个mul的初始值是1
	if (l == r)
		{
			t[p].sum = a[l] % mod;
			return;
		}
	int mid = l + ((r - l) >> 1);
	build(l, mid, 2 * p);
	build(mid + 1, r, 2 * p + 1);
	t[p].sum = (t[2 * p].sum + t[2 * p + 1].sum) % mod;
}

void lazy(int p)
{
	if (t[p].l == t[p].r)t[p].add = 0, t[p].mul = 1;
	if (t[p].add || t[p].mul != 1)//只要加法或者乘法有一个存在懒惰标记就更新
		{
			t[2 * p].sum = (t[2 * p].sum * t[p].mul + t[p].add * (t[2 * p].r - t[2 * p].l + 1)) % mod;
			t[2 * p + 1].sum = (t[2 * p + 1].sum * t[p].mul + t[p].add * (t[2 * p + 1].r - t[2 * p + 1].l + 1)) % mod;
			//更新sum与add都是先乘后加
			t[2 * p].add = (t[2 * p].add * t[p].mul + t[p].add) % mod;
			t[2 * p + 1].add = (t[2 * p + 1].add * t[p].mul + t[p].add) % mod;

			t[2 * p].mul = (t[2 * p].mul * t[p].mul) % mod;
			t[2 * p + 1].mul = (t[2 * p + 1].mul * t[p].mul) % mod;
			//重置标记
			t[p].add = 0, t[p].mul = 1;
		}
}

void addupdate(int l, int r, int p, ll z)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			t[p].sum = (t[p].sum + z * (t[p].r - t[p].l + 1)) % mod;
			t[p].add = (t[p].add + z) % mod;
			return;
		}
	lazy(p);
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (l <= mid)addupdate(l, r, 2 * p, z);//只有子代有在目标区间才进入
	if (r > mid)addupdate(l, r, 2 * p + 1, z);
	t[p].sum = (t[2 * p].sum + t[2 * p + 1].sum) % mod;
}

void mulupdate(int l, int r, int p, ll z)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			t[p].sum = (t[p].sum * z) % mod;//乘法需要对p的sum，add,mul都更新
			t[p].add = (t[p].add * z) % mod;
			t[p].mul = (t[p].mul * z) % mod;
			return;
		}
	lazy(p);
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (l <= mid)mulupdate(l, r, 2 * p, z);//只有子代有在目标区间才进入
	if (r > mid)mulupdate(l, r, 2 * p + 1, z);
	t[p].sum = (t[2 * p].sum + t[2 * p + 1].sum) % mod;
}

ll ask(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p].sum % mod;
	lazy(p);
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	ll ans = 0;
	if (l <= mid)ans += ask(l, r, 2 * p);
	if (r > mid)ans += ask(l, r, 2 * p + 1);
	return ans % mod;
}

int32_t main()
{
	cin >> n >> m >> mod;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	build(1, n, 1);
	int b, l, r, k;
	while (m--)
		{
			cin >> b >> l >> r;
			if (b == 1)
				{
					cin >> k;
					mulupdate(l, r, 1, k);
				}
			else if (b == 2)
				{
					cin >> k;
					addupdate(l, r, 1, k);
				}
			else if (b == 3)
				{
					cout << ask(l, r, 1) << endl;
				}
		}
	return 0;
}

