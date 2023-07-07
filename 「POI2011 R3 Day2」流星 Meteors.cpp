#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 3e5 + 10;
struct node
{
	int l1, r1, l2, r2, w;
} c[N];

vector<int>b[N];

int a[N << 1], ans[N], tl[N << 1], tr[N << 1], p[N];
ll t[N];
int n, m, k, x, y, w;

void add(int x, int w)
{
	for (int i = x; i <= m; i += i & -i)t[i] += w;
}

double ask(int x)
{
	double ans = 0;
	for (int i = x; i; i -= i & -i)ans += t[i];
	return ans;
}

void binarys(int ql, int qr, int l, int r)
{
	if (ql > qr)return;
	if (l == r)
		{
			for (int i = ql; i <= qr; ++i)ans[a[i]] = l;
			return;
		}
	int mid = l + ((r - l) >> 1), p1 = 0, p2 = 0;
	for (int i = l; i <= mid; ++i)
		{
			add(c[i].l1, c[i].w), add(c[i].r1 + 1, -c[i].w);
			if (c[i].l2)add(c[i].l2, c[i].w), add(c[i].r2 + 1, -c[i].w);
		}
	for (int i = ql; i <= qr; ++i)
		{
			double ans = 0;
			for (auto v : b[a[i]])
				{
					ans += ask(v);
					if (ans >= p[a[i]])break;
				}
			if (ans < p[a[i]])p[a[i]] -= ans, tr[++p2] = a[i];
			else tl[++p1] = a[i];
		}
	for (int i = l; i <= mid; ++i)
		{
			add(c[i].l1, -c[i].w), add(c[i].r1 + 1, c[i].w);
			if (c[i].l2)add(c[i].l2, -c[i].w), add(c[i].r2 + 1, c[i].w);
		}
	for (int i = 1; i <= p1; ++i)a[ql + i - 1] = tl[i];
	for (int i = 1; i <= p2; ++i)a[ql + p1 + i - 1] = tr[i];
	binarys(ql, ql + p1 - 1, l, mid);
	binarys(ql + p1, qr, mid + 1, r);
}

void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)cin >> x, b[x].push_back(i);
	for (int i = 1; i <= n; ++i)a[i] = i, cin >> p[i];
	cin >> k;
	for (int i = 1; i <= k; ++i)
		{
			cin >> x >> y >> w;
			if (x <= y)c[i] = {x, y, 0, 0, w};
			else c[i] = {1, y, x, m, w};
		}
	binarys(1, n, 1, k + 1);
	for (int i = 1; i <= n; ++i)
		{
			if (ans[i] < k + 1)cout << ans[i] << endl;
			else cout << "NIE" << endl;
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了

	mysolve();

	system("pause");
	return 0;
}
