#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 1e6 + 10;
const int mod = 998244353;

int qlen;

struct node
{
	int l, r, t, id;
	bool operator<(const node&k)const
	{
		if (l / qlen != k.l / qlen)return l / qlen < k.l / qlen;
		else if (r / qlen != k.r / qlen)return r / qlen < k.r / qlen;
		else return t < k.t;
	}
} a[N];

struct version
{
	int id, bef, now;
} c[N];
int ans[N], sz[N], b[N], d[N];
int cnt_t, cnt, sum;

void add(int x)
{
	sz[x]++;
	if (sz[x] == 1)sum++;
}

void del(int x)
{
	sz[x]--;
	if (!sz[x])sum--;
}

void upadd(int l, int r, int t)
{
	if (l <= c[t].id && c[t].id <= r)del(c[t].bef), add(c[t].now);
	b[c[t].id] = c[t].now;
}

void updel(int l, int r, int t)
{
	if (l <= c[t].id && c[t].id <= r)del(c[t].now), add(c[t].bef);
	b[c[t].id] = c[t].bef;
}

void mysolve()
{
	int n, m;
	cin >> n >> m;
	qlen = pow(n, 2.0 / 3.0);
	for (int i = 1; i <= n; ++i)cin >> b[i], d[i] = b[i];
	char op;
	int x, y;
	for (int i = 1; i <= m; ++i)
		{
			cin >> op >> x >> y;
			if (op == 'Q')
				{
					++cnt;
					a[cnt] = {x, y, cnt_t, cnt};
				}
			else
				{
					++cnt_t;
					c[cnt_t] = {x, d[x], y};
					d[x] = y;
				}
		}
	sort(a + 1, a + 1 + cnt);
	for (int i = 1, l = 1, r = 0, t = 0; i <= cnt; ++i)
		{
			while (r < a[i].r)add(b[++r]);
			while (l > a[i].l)add(b[--l]);
			while (r > a[i].r)del(b[r--]);
			while (l < a[i].l)del(b[l++]);
			while (t < a[i].t)upadd(l, r, ++t);
			while (t > a[i].t)updel(l, r, t--);
			ans[a[i].id] = sum;
		}
	for (int i = 1; i <= cnt; ++i)cout << ans[i] << endl;
}

int32_t main()
{
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
