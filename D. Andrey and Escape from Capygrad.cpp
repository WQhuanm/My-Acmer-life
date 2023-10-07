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
const int N = 3e5 + 10;

pii a[N];
int c[N], fa[N], ans[N];

struct node
{
	int l, r, a, b;
	bool operator<(const node&k)const
	{
		return l != k.l ? l < k.l : b < k.b;
	}
} b[N];
int n, q;
int find(int x)
{
	if (fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> b[i].l >> b[i].r >> b[i].a >> b[i].b, fa[i] = i, c[i] = 0;
	cin >> q;
	for (int i = 1; i <= q; ++i)cin >> a[i].first, a[i].second = i;
	sort(a + 1, a + 1 + q), sort(b + 1, b + 1 + n);
	int last = 0;
	int p = 1;
	for (int i = 1; i <= n; ++i)
		{
			if (i > 1)
				{
					if (b[last].b >= b[i].l)
						{
							if (b[last].b >= b[i].b)fa[i] = last;
							else fa[last] = i, last = i;
						}
					else last = i;
				}
			else last = i;
			while (p <= q && a[p].first < b[i].l)
				c[p++] = 0;
			while (p <= q && (a[p].first >= b[i].l && (i == n || a[p].first < b[i + 1].l)))
				c[p++] = i;
		}
	for (int i = 1; i <= q; ++i)
		{
			int now = find(c[i]);
			ans[a[i].second] = max(a[i].first, c[i] ? b[now].b : 0ll);
		}
	for (int i = 1; i <= q; ++i)cout << ans[i] << " \n"[i == q];
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
