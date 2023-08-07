#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<ll, ll> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
const int N = 5e4 + 10;

#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))
struct tree
{
	int l, r;
	vector<pii> sum;
} t[N << 2];
pii a[N];

vector<pii> push(vector<pii>u, pii b)
{
	vector<pii>v;
	for (auto k : u)v.push_back({b.first + k.first, b.second + k.second});
	return v;
}

vector<pii> unit(vector<pii>u, vector<pii>v)
{
	int i = 0, j = 0;
	ll r = -10;
	vector<pii>ans;
	while (i < (int)u.size() && j < (int)v.size())
		{
			if (u[i].first <= r + 1)
				{
					ans.back().second = max(r, u[i++].second);
					continue;
				}
			if (v[j].first <= r + 1)
				{
					ans.back().second = max(r, v[j++].second);
					continue;
				}
			if (u[i].first <= v[j].first)ans.push_back(u[i++]), r = ans.back().second;
			else ans.push_back(v[j++]), r = ans.back().second;
		}
	while (i < (int)u.size())
		{
			if (u[i].first <= r + 1)ans.back().second = max(r, u[i++].second);
			else ans.push_back(u[i++]), r = ans.back().second;
		}
	while (j < (int)v.size())
		{
			if (v[j].first <= r + 1)ans.back().second = max(r, v[j++].second);
			else ans.push_back(v[j++]), r = ans.back().second;
		}
	return ans;
}

vector<pii> pre(vector<pii>u, vector<pii>v)
{
	if (!u.size())return v;
	if (!v.size())return u;
	vector<pii> ans = unit(u, v);
	for (auto k : v)ans = unit(ans, push(u, k));
	return ans;
}

inline void pushup(int p)
{
	t[p].sum = pre(t[ls].sum, t[rs].sum);
}
void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	if (l == r)
		{
			t[p].sum.clear();
			t[p].sum.push_back(a[l]);
			return;
		}
	build(l, mid, ls), build(mid + 1, r, rs);
	pushup(p);
}

void update(int x, int p)
{
	if (t[p].l == x && x == t[p].r)
		{
			t[p].sum.clear();
			t[p].sum.push_back(a[x]);
			return;
		}
	if (x <= mid)update(x, ls);
	if (x > mid)update(x, rs);
	pushup(p);
}

vector<pii> ask(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p].sum;
	vector<pii>ans;
	if (l <= mid)ans = pre(ans, ask(l, r, ls));
	if (r > mid) ans = pre(ans, ask(l, r, rs));
	return ans;
}

int n, q;
void mysolve()
{
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)cin >> a[i].first >> a[i].second;
	build(1, n, 1);
	int op, k, x, y;
	while (q--)
		{
			cin >> op;
			if (op == 1)cin >> k >> x >> y, a[k] = {x, y}, update(k, 1);
			else
				{
					cin >> x >> y;
					vector<pii>ans = ask(x, y, 1);
					ll res = 1;
					for (auto [l, r] : ans)res += r - l + 1;
					cout << res  << endl;
				}
		}
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
