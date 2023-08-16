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
const int N = 3e5 + 10;

int nxt[N], cnt[N], p[N], ans[N];
int n, m;
struct node
{
	int l, r, w;
	bool operator<(const node&k)const
	{
		return r - l < k.r - k.l;
	}
} a[N];
void mysolve()
{
	int x, y, w;
	cin >> n >> m;
	bool fl = 1;
	for (int i = 1; i <= n; ++i)nxt[i] = p[i] = i;
	for (int i = 1; i <= m; ++i)
		{
			cin >> x >> y >> w;
			if (x == y && w)fl = 0;
			a[i] = {x, y, w};
		}
	if (!fl)
		{
			cout << -1 << endl;
			return;
		}
	sort(a + 1, a + 1 + m);
	for (int i = 1; i <= m; ++i)
		{
			int l = a[i].l, r = a[i].r, w = a[i].w;
			int j = 0;
			for (int x = l; x <= r; ++x)j ^= cnt[x];
			if (j != w)
				{
					swap(p[nxt[l]], p[nxt[l] + 1]);
					cnt[l] ^= 1;
				}
			nxt[l] = r;
		}
	for (int i = 1; i <= n; ++i)ans[p[i]] = i;
	for (int i = 1; i <= n; ++i)cout << ans[i] << " \n"[i == n];
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
