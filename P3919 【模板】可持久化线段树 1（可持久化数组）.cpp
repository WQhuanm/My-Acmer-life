#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 2e6 + 10;

struct tree
{
	int l, r, ls, rs;
	int val;
} t[N << 5];

int a[N], b[N];
int top;

int  build(int l, int r)
{
	int p = top++;
	t[p].l = l, t[p].r = r;
	if (l == r)
		{
			t[p].val = a[l];
			return p;
		}
	int mid = l + ((r - l) >> 1);
	t[p].ls = build(l, mid), t[p].rs = build(mid + 1, r);
	return p;
}

int update(int x, int node, int w)
{
	int p = top++;
	t[p] = t[node];
	if (t[p].l == x && t[p].r == x)
		{
			t[p].val = w;
			return p;
		}
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (x <= mid)t[p].ls = update(x, t[node].ls, w);
	else t[p].rs = update(x, t[node].rs, w);
	return p;
}
int ask(int x, int p)
{
	if (t[p].l == x && t[p].r == x)return t[p].val;
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	int ans;
	if (x <= mid)ans = ask(x, t[p].ls);
	else ans = ask(x, t[p].rs);
	return ans;
}

void mysolve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	b[0] = build(1, n);
	int v, op, x, val;
	for (int i = 1; i <= m; ++i)
		{
			cin >> v >> op >> x;
			if (op == 1)
				{
					cin >> val;
					b[i] = update(x, b[v], val);
				}
			else
				{
					cout << ask(x, b[v])<<endl;
					b[i] = b[v];
				}
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了

	mysolve();

	system("pause");
	return 0;
}
