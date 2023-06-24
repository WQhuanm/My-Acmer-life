#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 2e5 + 10;
const int mod = 998244353;

struct tree
{
	int l, r, ls, rs;
	int sum;
} t[N << 5];

int a[N], b[N], number[N];
int top;

int build(int l, int r)
{
	int p = top++;
	t[p].l = l, t[p].r = r, t[p].sum = 0;
	if (l == r)return p;
	int mid = l + ((r - l) >> 1);
	t[p].ls = build(l, mid), t[p].rs = build(mid + 1, r);
	return p;
}

int update(int x, int node)
{
	int p = top++;
	t[p] = t[node];
	t[p].sum++;
	if (t[p].l == t[p].r && t[p].l == x)return p;
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (x <= mid)t[p].ls = update(x, t[node].ls);
	else t[p].rs = update(x, t[node].rs);
	return p;
}

int ask(int node1, int node2, int k)
{
	if (t[node1].l == t[node1].r)return b[t[node1].l];
	int sum = t[t[node2].ls].sum - t[t[node1].ls].sum;
	if (k <= sum)return ask(t[node1].ls, t[node2].ls, k);
	else return ask(t[node1].rs, t[node2].rs, k - sum);
}

void mysolve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i], b[i] = a[i];
	sort(b + 1, b + 1 + n);
	int sz = unique(b + 1, b + 1 + n) - b - 1;
	number[0] = build(1, sz);
	for (int i = 1; i <= n; ++i)
		{
			int x = lower_bound(b + 1, b + 1 + sz, a[i]) - b;
			number[i] = update(x, number[i - 1]);
		}
	int l, r, k;
	while (m--)
		{
			cin >> l >> r >> k;
			cout << ask(number[l - 1], number[r], k) << endl;
		}
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
