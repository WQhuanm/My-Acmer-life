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
const int mod = 998244353;
const int N = 5e5 + 10;

int qlen, n, m;
int t[N], dis[N], sum[N], ans[N], cnt[N];

ll res;

void add(int x)
{
	for (int i = x; i <= n; i += i & -i)t[i]++;
}

int ask(int x)
{
	if (x == 0)return 0;
	int ans = 0;
	for (int i = x; i; i -= i & -i)
		ans += t[i];
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

int a[N];

void addl(int x)
{
	res += sum[a[x]] - cnt[a[x]] * dis[x];
	cnt[a[x]]++, sum[a[x]] += dis[x];
}
void addr(int x)
{
	res += dis[x] * cnt[a[x]] - sum[a[x]];
	cnt[a[x]]++, sum[a[x]] += dis[x];
}
void dell(int x)
{
	cnt[a[x]]--, sum[a[x]] -= dis[x];
	res -= sum[a[x]] - cnt[a[x]] * dis[x];
}
void delr(int x)
{
	cnt[a[x]]--, sum[a[x]] -= dis[x];
	res -= cnt[a[x]] * dis[x] - sum[a[x]];
}

void solve()
{
	qlen = n / sqrt(m);
	sort(b + 1, b + 1 + m);
	res = 0;
	for (int i = 1, l = 1, r = 0; i <= m; ++i)//暴力对排序后的询问转移
		{
			while (l > b[i].l)addl(--l);
			while (r < b[i].r)addr(++r);
			while (l < b[i].l)dell(l++);
			while (r > b[i].r) delr(r--);
			ans[b[i].id] = res;
		}
}
void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			dis[i] = ask(a[i] - 1), add(a[i]);
		}
	int x, y;
	for (int i = 1; i <= m; ++i)cin >> x >> y, b[i] = {x, y, i};
	solve();
	for (int i = 1; i <= m; ++i)cout << ans[i] << endl;
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
