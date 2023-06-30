#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 1e7 + 10;

struct tree
{
	int ls, rs;
	ll k;
	ll w;
} t[N];

int a[N], stk[N];
int n, cnt, root;

void build()
{
	int top = 0, p = 0;
	for (int i = 1; i <= n; ++i)
		{
			while (p && t[stk[p]].w > a[i])p--;
			t[++cnt].k = i, t[cnt].w = a[i];
			if (p)t[stk[p]].rs = cnt;
			if (p < top)t[cnt].ls = stk[p + 1];
			stk[++p] = cnt;
			if (p == 1)root = i;
			top = p;
		}
}
inline void read(int &x)
{
	x = 0;
	int  w = 1;
	char ch = 0;
	while (ch < '0' || ch > '9')
		{
			if (ch == '-') w = -1;
			ch = getchar();
		}
	while (ch >= '0' && ch <= '9')
		{
			x = x * 10 + (ch - '0');
			ch = getchar();
		}
	x = w * x;
}
void mysolve()
{
	read(n);
	for (int i = 1; i <= n; ++i)read(a[i]);
	build();
	ll l = 0, r = 0;
	for (int i = 1; i <= cnt; ++i)l ^= t[i].k * (t[t[i].ls].k + 1), r ^= t[i].k * (t[t[i].rs].k + 1);
	cout << l << " " << r << endl;
}

int32_t main()
{
//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了

	mysolve();

	system("pause");
	return 0;
}
