#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 2e5 + 10;

#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

struct tree
{
	int l, r;
	ll sum;
	int mx, add;
} t[N << 2];

int a[N], b[N];
bool vis[N];

inline void pushup(int p)
{
	t[p].sum = (t[ls].sum + t[rs].sum);
	t[p].mx = max(t[ls].mx, t[rs].mx);
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	t[p].sum = t[p].add = 0; //初始化
	if (l == r)
		{
			t[p].sum = t[p].mx = b[l];
			return;
		}
	build(l, mid, ls), build(mid + 1, r, rs);
	pushup(p);
}

inline void change(int p, ll w)
{
	t[p].sum = (t[p].r - t[p].l + 1) * w;
	t[p].add = t[p].mx = w;
}
inline void lazy(int p)
{
	if (t[p].l == t[p].r)return;
	if (t[p].add)//mex可能为0，这里不应该设0的，可能修改为0的
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

ll ask_mx(int l, int r, int p, int w)
{
	if (t[p].l == t[p].r)return t[p].l;
	lazy(p);
	if (t[ls].mx >= w)return ask_mx(l, r, ls, w);
	else return ask_mx(l, r, rs, w);
}

int n;
vector<int>nx[N];

void mysolve()
{
	while (cin >> n && n)
		{
			vis[0] = 0, nx[0].clear();
			for (int i = 1; i <= n; ++i)cin >> a[i], vis[i] = 0, nx[i].clear();
			int mex = 0;
			for (int i = 1; i <= n; ++i)
				{
					if (a[i] < n)vis[a[i]] = 1, nx[a[i]].push_back(i);
					while (vis[mex])mex++;
					b[i] = mex;
				}
			for (int i = 0; i < n; ++i)reverse(nx[i].begin(), nx[i].end());
			build(1, n, 1);
			ll ans = t[1].sum;
			for (int i = 1; i < n; ++i)
				{
					if (a[i] < n)nx[a[i]].pop_back();
					if (t[1].mx >= a[i] + 1)
						{
							int l = ask_mx(1, n, 1, a[i] + 1), r;
							if (!nx[a[i]].empty())r = nx[a[i]].back() - 1;
							else r = n;
							if (l <= r)update(l, r, 1, a[i]);
						}
					ans += t[1].sum;
				}
			cout << ans << endl;
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
