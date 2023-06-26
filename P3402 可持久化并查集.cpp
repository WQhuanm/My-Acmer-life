#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 3e5 + 10;

struct tree
{
	int l, r, ls, rs;
	int fa, sz;
} t[N << 5];

int  number[N];
int top, now;

void build(int l, int r, int &p)
{
	p = ++top;
	t[p].l = l, t[p].r = r;
	if (l == r)
		{
			t[p].fa = l, t[p].sz = 1;
			return;
		}
	int mid = l + ((r - l) >> 1);
	build(l, mid, t[p].ls), build(mid + 1, r, t[p].rs);
}

void updatesz(int x, int w, int &p, int nod)
{
	if (p == nod)p = ++top, t[p] = t[nod];
	if (t[p].l == x && t[p].r == x)
		{
			t[p].sz += w;
			return;
		}
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (x <= mid)updatesz(x, w, t[p].ls, t[nod].ls);
	else updatesz(x, w, t[p].rs, t[nod].rs);
}

void update(int x, int f, int &p, int nod)
{
	if (p == nod)p = ++top, t[p] = t[nod];
	if (t[p].l == x && t[p].r == x)
		{
			t[p].fa = f;
			return;
		}
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (x <= mid)update(x, f, t[p].ls, t[nod].ls);
	else update(x, f, t[p].rs, t[nod].rs);
}

int asksz(int x, int p)
{
	if (t[p].l == t[p].r)return t[p].sz;
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (x <= mid)return asksz(x, t[p].ls);
	else return asksz(x, t[p].rs);
}

int ask(int x, int p)
{
	if (t[p].l == t[p].r)return t[p].fa;
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (x <= mid)return ask(x, t[p].ls);
	else return ask(x, t[p].rs);
}

int find(int x)
{
	int fa = ask(x, number[now]);//fa[x]=find(fa[x]);
	if (fa != x)
		{
			fa = find(fa);
		//	update(x, fa, number[now], number[now - 1]);
		}
	return fa;
}

void mysolve()
{
	int n, m;
	cin >> n >> m;
	build(1, n, number[0]);
	int op, a, b, fa, fb, sza, szb;
	for (int i = 1; i <= m; ++i)
		{
			now = i;
			number[i] = number[i - 1];
			cin >> op;
			if (op == 1)
				{
					cin >> a >> b;
					fa = find(a), fb = find(b);
					sza = asksz(fa, number[i]), szb = asksz(fb, number[i]);
					if (fa != fb)
						{
							if (sza <= szb)
								{
									update(fa, fb, number[i], number[i - 1]);
									updatesz(fb, sza, number[i], number[i - 1]);
								}
							else
								{
									update(fb, fa, number[i], number[i - 1]);
									updatesz(fa, szb, number[i], number[i - 1]);
								}
						}
				}
			else if (op == 2)
				{
					cin >> a;
					number[i] = number[a];
				}
			else
				{
					cin >> a >> b;
					cout << (find(a) == find(b)) << endl;
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
