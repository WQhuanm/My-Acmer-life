#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define int              long long
const int N = 510;

struct node
{
	int lx, ly, rx, ry, val, i;
} a[N * N * 2], tl[N * N * 2], tr[N * N * 2];

int t[N][N], ans[N * 1000];
int n, tot;

void add(int x, int y, int w)
{
	for (int i = x; i <= n; i += i & -i)for (int j = y; j <= n; j += j & -j)t[i][j] += w;
}

int ask(int x, int y)
{
	int ans = 0;
	for (int i = x; i; i -= i & -i)for (int j = y; j; j -= j & -j)ans += t[i][j];
	return ans;
}

void binarys(int ql, int qr, int l, int r)
{
	if (ql > qr)return;
	if (l == r)
		{
			for (int i = ql; i <= qr; ++i)if (a[i].i)ans[a[i].i] = l;
			return;
		}
	int mid = l + ((r - l) >> 1);
	int p1 = 0, p2 = 0;
	for (int i = ql; i <= qr; ++i)
		{
			if (!a[i].i)
				{
					if (a[i].val <= mid)add(a[i].lx, a[i].ly, 1), tl[++p1] = a[i];
					else tr[++p2] = a[i];
				}
			else
				{
					ll sum = ask(a[i].rx, a[i].ry) - ask(a[i].rx, a[i].ly - 1) - ask(a[i].lx - 1, a[i].ry) + ask(a[i].lx - 1, a[i].ly - 1);
					if (sum >= a[i].val)tl[++p1] = a[i];
					else a[i].val -= sum, tr[++p2] = a[i];
				}
		}
	for (int i = ql; i <= qr; ++i)if (!a[i].i)if (a[i].val <= mid)add(a[i].lx, a[i].ly, -1);
	for (int i = 1; i <= p1; ++i)a[ql + i - 1] = tl[i];
	for (int i = 1; i <= p2; ++i)a[ql + p1 + i - 1] = tr[i];
	binarys(ql, ql + p1 - 1, l, mid), binarys(ql + p1, qr, mid + 1, r);
}

void mysolve()
{
	int q;
	cin >> n >> q;
	tot = 0;
	int x;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)
			{
				cin >> x;
				a[++tot] = {i, j, 0, 0, x, 0};
			}
	int x1, y1, x2, y2, k;
	for (int i = 1; i <= q; ++i)
		{
			cin >> x1 >> y1 >> x2 >> y2 >> k;
			a[++tot] = {x1, y1, x2, y2, k, i};
		}
	binarys(1, tot, 0, inf);
	for (int i = 1; i <= q; ++i)cout << ans[i] << endl;
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
