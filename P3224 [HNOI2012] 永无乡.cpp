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
const int N = 3e5 + 10;

struct line_tree
{
	struct tree
	{
		int ls, rs;
		ll sum;
	} t[N * 40];
	int tot = 0;
	void init()
	{
		for (int i = 0; i <= tot; ++i)t[i].ls = t[i].rs = t[i].sum = 0;
		tot = 0;
	}

	void pushup(int p)
	{
		t[p].sum = t[t[p].ls].sum + t[t[p].rs].sum;
	}

	void update(int l, int r, int x, int w, int &p)
	{
		if (!p)p = ++tot;
		if (l == r)
			{
				t[p].sum += w;
				return;
			}
		int mid = l + ((r - l) >> 1);
		if (x <= mid)update(l, mid, x, w, t[p].ls);
		else update(mid + 1, r, x, w, t[p].rs);
		pushup(p);
	}

	void merge(int l, int r, int &p, int &p2)
	{
		if (!p || !p2)return p = p | p2, void();
		t[++tot] = t[p], p = tot;
		if (l == r)
			{
				t[p].sum += t[p2].sum;
				return;
			}
		int mid = l + ((r - l) >> 1);
		merge(l, mid, t[p].ls, t[p2].ls);
		merge(mid + 1, r, t[p].rs, t[p2].rs);
		pushup(p);
	}

	ll ask(int k, int l, int r, int p)
	{
		if (!p || t[p].sum < k)return -1;
		if (l == r)return l;
		int mid = l + ((r - l) >> 1);
		if (t[t[p].ls].sum >= k)return ask(k, l, mid, t[p].ls);
		return ask(k - t[t[p].ls].sum, mid + 1, r, t[p].rs);
	}
} T;
int number[N], fa[N];
int n, m;
int a[N], b[N];

int find(int x)
{
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i], b[a[i]] = i, T.update(1, n, a[i], 1, number[i]), fa[i] = i;
	int x, y, q;
	while (m--)
		{
			cin >> x >> y;
			int fx = find(x), fy = find(y);
			if (fx != fy)T.merge(1, n, number[fx], number[fy]), fa[fy] = fx;
		}
	cin >> q;
	char c;
	while (q--)
		{
			cin >> c >> x >> y;
			if (c == 'Q')
				{
					int ans = T.ask(y, 1, n, number[find(x)]);
					cout << (~ans ? b[ans] : ans) << endl;
				}
			else
				{
					int fx = find(x), fy = find(y);
					if (fx != fy)T.merge(1, n, number[fx], number[fy]), fa[fy] = fx;
				}
		}
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
