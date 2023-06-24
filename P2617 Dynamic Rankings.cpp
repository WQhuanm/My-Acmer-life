#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 1e5 + 10;

struct node
{
	int op, x, y, k;
} c[N];

struct tree
{
	int l, r, ls, rs;
	int sum;
} t[N *400];

int  a[N], b[N << 1], number[N << 1], temp[2][30];
int top = 1, len;
int n, m;

int change(int x, int &p, int l, int r, int w)
{
	if (!p)p = top++;
	t[p].sum += w;
	if (l < r)
		{
			int mid = l + ((r - l) >> 1);
			if (x <= mid)change(x, t[p].ls, l, mid, w);
			else change(x, t[p].rs, mid + 1, r, w);
		}
	return p;
}

void pre_change(int j, int w)
{
	int x = lower_bound(b + 1, b + 1 + len, a[j]) - b ;
	for (int i = j; i <= n; i += i & -i)change(x, number[i], 1, len,  w);
}
int ask(int l, int r, int k)
{
	if (l == r)return b[l];
	int mid = l + ((r - l) >> 1);
	int sum = 0;
	for (int i = 1; i <= temp[0][0]; ++i)
		sum -= t[t[temp[0][i]].ls].sum;
	for (int i = 1; i <= temp[1][0]; ++i)
		sum += t[t[temp[1][i]].ls].sum;
	if (sum >= k)
		{
			for (int i = 1; i <= temp[0][0]; ++i)
				temp[0][i] = t[temp[0][i]].ls;
			for (int i = 1; i <= temp[1][0]; ++i)
				temp[1][i] = t[temp[1][i]].ls;
			return ask(l, mid, k);
		}
	else
		{
			for (int i = 1; i <= temp[0][0]; ++i)
				temp[0][i] = t[temp[0][i]].rs;
			for (int i = 1; i <= temp[1][0]; ++i)
				temp[1][i] = t[temp[1][i]].rs;
			return ask(mid + 1, r, k - sum);
		}
}
int pre_ask(int l, int r, int k)
{
	temp[0][0] = temp[1][0] = 0;
	for (int i = l - 1; i; i -= i & -i)
		temp[0][++temp[0][0]] = number[i];
	for (int i = r; i; i -= i & -i)
		temp[1][++temp[1][0]] = number[i];
	return ask(1, len, k);
}

void mysolve()
{

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i], b[++len] = a[i];
	char op;
	for (int i = 1; i <= m; ++i)
		{
			cin >> op;
			c[i].op = (op == 'Q');
			if (c[i].op)cin >> c[i].x >> c[i].y >> c[i].k;
			else
				{
					cin >> c[i].x >> c[i].y;
					b[++len] = c[i].y;
				}
		}
	sort(b + 1, b + 1 + len);
	len = unique(b + 1, b + 1 + len) - b - 1;
	for (int i = 1; i <= n; ++i)
		{
			pre_change(i, 1);
		}
	for (int i = 1; i <= m; ++i)
		{
			if (c[i].op)cout << pre_ask(c[i].x, c[i].y, c[i].k) << endl;
			else
				{
					pre_change(c[i].x, -1);
					a[c[i].x] = c[i].y;
					pre_change(c[i].x, 1);

				}
//			for (int i = 1; i <= n; ++i)
//				cout << pre_ask(i, i, 1) << " \n"[i == n];
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
