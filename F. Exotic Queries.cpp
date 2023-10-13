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
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 1e6 + 10;

#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

struct tree
{
	int l, r;
	ll sum, add;
} t[N << 2];
inline void pushup(int p)
{
	t[p].sum = max(t[ls].sum, t[rs].sum);
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	t[p].sum = t[p].add = 0; //初始化
	if (l == r)
		{
			return;
		}
	build(l, mid, ls), build(mid + 1, r, rs);
}

void update(int x, int p, ll w)
{
	if (t[p].l == t[p].r)
		{
			t[p].sum = w;
			return;
		}
	if (x <= mid)update(x, ls, w);
	else update(x, rs, w);
	pushup(p);
}

ll ask_max(int l, int r, int p)
{
	if (l > r)return 0;
	if (l <= t[p].l && t[p].r <= r)return t[p].sum;
	ll ans = 0;
	if (l <= mid)ans = max(ans, ask_max(l, r, ls));
	if (r > mid)ans = max(ans, ask_max(l, r, rs));
	return ans;
}

ll b[N];
int n, q;
void add(int x)
{
	if (!x)return;
	for (int i = x; i <= n; i += i & -i)b[i] += 1;
}
ll ask(int x)
{
	ll ans = 0;
	for (int i = x; i; i -= i & -i)ans += b[i];
	return ans;
}

vector<pii>qt[N];
vector<int>pos[N];
int cnt[N], ans[N];

void mysolve()
{
	cin >> n >> q;
	int x, y;
	for (int i = 1; i <= n; ++i)cin >> x, pos[x].push_back(i);
	for (int i = 1; i <= q; ++i)
		{
			cin >> x >> y;
			qt[y].push_back({x, i});
		}
	build(1, n, 1);
	for (int i = 1; i <= n; ++i)
		{
			cnt[i] = cnt[i - 1];
			if (!pos[i].empty())
				{
					cnt[i]++;
					update(pos[i][0], 1, i);
					for (int k = 1; k < (int)pos[i].size(); ++k)
						{
							update(pos[i][k], 1, i);
							add(ask_max(pos[i][k - 1] + 1, pos[i][k] - 1, 1));
						}

				}
			for (auto [l, id] : qt[i])
				{
					ans[id] = cnt[i] - cnt[l - 1] + ask(n) - ask(l - 1);
				}
		}
	for (int i = 1; i <= q; ++i)cout << ans[i] << endl;
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
