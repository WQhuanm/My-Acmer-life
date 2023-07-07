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
const int N = 3e5 + 10;
const int mod = 998244353;

struct node
{
	int x, y, k, kind, i;
};

node a[N << 1], tl[N << 1], tr[N << 1];
int t[N], ans[N];
int cnt, n, m;

void add(int x, int w)
{
	for (int i = x; i <= n; i += i & -i)t[i] += w;
}

int ask(int x)
{
	int ans = 0;
	for (int i = x; i; i -= i & -i)ans += t[i];
	return ans;
}

void binarys(int ql, int qr, int l, int r)
{
	if (ql > qr)return;
	if (l == r)
		{
			for (int i = ql; i <= qr; ++i)if (a[i].kind == 2)ans[a[i].i] = l;
			return;
		}
	int mid = l + ((r - l) >> 1);
	int p1 = 0, p2 = 0;
	for (int i = ql; i <= qr; ++i)
		{
			if (a[i].kind == 1)
				{
					if (a[i].x <= mid)add(a[i].i, 1), tl[++p1] = a[i];
					else tr[++p2] = a[i];
				}
			else
				{
					int sum = ask(a[i].y) - ask(a[i].x - 1);
					if (sum >= a[i].k)tl[++p1] = a[i];
					else a[i].k -= sum, tr[++p2] = a[i];
				}
		}
	for (int i = ql; i <= qr; ++i)if (a[i].kind == 1 && a[i].x <= mid)add(a[i].i, -1);
	for (int i = 1; i <= p1; ++i)a[ql + i - 1] = tl[i];
	for (int i = 1; i <= p2; ++i)a[ql + p1 + i - 1] = tr[i];
	binarys(ql, ql + p1 - 1, l, mid);
	binarys(ql + p1, qr, mid + 1, r);
}
void mysolve()
{
	cin >> n >> m;
	int x, y, k;
	for (int i = 1; i <= n; ++i)
		{
			cin >> x, a[++cnt] = {x, i, i, 1, i};
		}
	for (int i = 1; i <= m; ++i)
		{
			cin >> x >> y >> k;
			a[++cnt] = {x, y, k, 2, i};
		}
	binarys(1, cnt, -inf, inf);
	for (int i = 1; i <= m; ++i)cout << ans[i] << endl;
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
