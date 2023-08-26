#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 1e6 + 10;

#define mid (t[p].l+((t[p].r-t[p].l)>>1))

struct tree
{
	int l, r, ls, rs;
	int next;
} t[N << 5];

int a[N], number[N];//b为权值数离散区间，number为主席树版本
int top; //len为b离散化后长度

void build(int l, int r, int &p)
{
	p = ++top;
	t[p].l = l, t[p].r = r, t[p].next = 0;
	if (l == r)
		{
			t[p].next = -1;
			return;
		}
	build(l, mid, t[p].ls), build(mid + 1, r, t[p].rs);
}

void update(int x, int nx, int &p, int nod) //nod为上一版本信息
{
	if (!p || p == nod)p = ++top, t[p] = t[nod]; //新版本的树如果没有建立过或者进来时连的是老版本的树，新建
	if (t[p].l == t[p].r)
		{
			t[p].next = nx;
			return;
		}
	if (x <= mid)update(x, nx, t[p].ls, t[nod].ls);
	else update(x, nx, t[p].rs, t[nod].rs);
}

int ask(int x, int p)
{
	if (t[p].l == t[p].r)return t[p].next;
	if (x <= mid)return ask(x, t[p].ls);
	else return ask(x, t[p].rs);
}

int n, type, q, m;
int b[N];
void mysolve()
{
	top =  0; //多组数据离散化要初始化
	for (int i = 0; i <= n; ++i)number[i] = 0; //区间版本信息初始化
	cin >> type >> n >> q >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	build(1, m, number[n]);
	for (int i = n; i ; --i)
		update(a[i], i, number[i - 1], number[i]);//更新number[i-1]
	int len;
	while (q--)
		{
			cin >> len;
			int p = 0;
			for (int i = 1; i <= len; ++i)
				{
					cin >> b[i];
					if (~p)p = ask(b[i], number[p]);
				}
			cout << (~p ? "Yes" : "No") << endl;
		}
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
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
