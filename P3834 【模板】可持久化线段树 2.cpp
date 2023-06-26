#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 2e5 + 10;

///

#define mid (t[p].l+((t[p].r-t[p].l)>>1))

struct tree
{
	int l, r, ls, rs;
	int sum;
} t[N << 5];

int a[N], b[N], number[N];//b为权值数离散区间，number为主席树版本
int top;

void build(int l, int r, int &p)
{
	p = ++top;
	t[p].l = l, t[p].r = r, t[p].sum = 0;
	if (l == r)
		{
			return;
		}
	build(l, mid, t[p].ls), build(mid + 1, r, t[p].rs);
}

void update(int x, int &p, int nod)//nod为上一版本信息
{
	if (!p || p == nod)p = ++top, t[p] = t[nod]; //新版本的树如果没有建立过或者进来时连的是老版本的树，新建
	t[p].sum = (t[p].sum + 1);
	if (t[p].l == t[p].r)return;
	if (x <= mid)update(x, t[p].ls, t[nod].ls);
	else update(x, t[p].rs, t[nod].rs);
}

int kth(int L, int R, int k)//询问[L,R],进来是[L-1,R]
{
	if (t[L].l == t[L].r)return b[t[L].l];
	int sum = t[t[R].ls].sum - t[t[L].ls].sum;
	if (k <= sum)return kth(t[L].ls, t[R].ls, k);
	else return kth(t[L].rs, t[R].rs, k - sum);
}

void mysolve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i], b[i] = a[i];
	sort(b + 1, b + 1 + n);
	int sz = unique(b + 1, b + 1 + n) - b - 1;
	build(1, sz, number[0]);
	for (int i = 1; i <= n; ++i)
		{
			int x = lower_bound(b + 1, b + 1 + sz, a[i]) - b;
			update(x, number[i], number[i - 1]);
		}
	int l, r, k;
	while (m--)
		{
			cin >> l >> r >> k;
			cout << kth(number[l - 1], number[r], k) << endl;
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
