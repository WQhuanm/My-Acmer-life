#include <bits/stdc++.h>
using namespace std;
#define endl             "\n"
const int N = 3e5 + 5, M = 1e4 + 5, lg = 20;

struct tree
{
	int ls, rs;
	int sum;
} t[N * 30];
int top;
struct zx_tree
{
#define mid (l+((r-l)>>1))
	int a[N], b[N], number[N], pos[M]; //b为权值数离散区间，number为主席树版本
	int  len, cnt, now; //len为b离散化后长度

	void update(int l, int r, int x, int &p, int nod) //nod为上一版本信息
	{
		if (!p || p == nod)p = ++top, t[p] = t[nod]; //新版本的树如果没有建立过或者进来时连的是老版本的树，新建
		t[p].sum = (t[p].sum + 1);
		if (l == r)return;
		if (x <= mid)update(l, mid, x, t[p].ls, t[nod].ls);
		else update(mid + 1, r, x, t[p].rs, t[nod].rs);
	}

	int kth(int l, int r, int L, int R, int k) //询问[L,R],进来是[L-1,R]
	{
		if (l == r)return now = k - 1, b[l];
		int sum = t[t[R].rs].sum - t[t[L].rs].sum;
		if (k <= sum)return kth(mid + 1, r, t[L].rs, t[R].rs, k);
		else return kth(l, mid, t[L].ls, t[R].ls, k - sum);
	}
	//kth(number[l-1],number[r],k)//询问[l,r]，进入时就是版本number[l-1]与number[r]

	void init()
	{
		len = 0; //多组数据离散化要初始化
		for (int i = 0; i <= cnt; ++i)number[i] = 0; //区间版本信息初始化
		for (int i = 1; i <= cnt; ++i)b[++len] = a[i];
		sort(b + 1, b + 1 + len);
		len = unique(b + 1, b + 1 + cnt) - b - 1;//去重
		for (int i = 1; i <= cnt; ++i)//载入区间版本
			{
				int x = lower_bound(b + 1, b + 1 + len, a[i]) - b;
				update(1, len, x, number[i], number[i - 1]);
			}
	}
} o, e;

int n, q;
void mysolve()
{
	cin >> n >> q;
	t[0].sum = t[0].ls = t[0].rs = top = 0;
	o.cnt = e.cnt = 0;
	int l, r, x;
	for (int i = 1; i <= n; ++i)
		{
			cin >> x;
			while (x % 2 == 0)
				{
					e.a[++e.cnt] = x;
					x >>= 1;
				}
			while (x)
				{
					if (x & 1)o.a[++o.cnt] = x;
					else o.cnt++, o.a[o.cnt] = o.a[o.cnt - 1];
					x >>= 1;
				}
			e.pos[i] = e.cnt, o.pos[i] = o.cnt;
		}
	e.init();
	o.init();
	while (q--)
		{
			cin >> l >> r >> x;
			x++;
			int len = e.pos[r] - e.pos[l - 1];
			if (x <= len)
				{
					int ans = max(e.kth(1, e.len, e.number[e.pos[l - 1]], e.number[e.pos[r]], x), o.kth(1, o.len, o.number[o.pos[l - 1]], o.number[o.pos[r]], 1));
					cout << ans << endl;
				}
			else
				{
					x -= len;
					len = o.pos[r] - o.pos[l - 1];
					if (x > len)
						{
							cout << 0 << endl;
							continue;
						}
					int val = o.kth(1, o.len, o.number[o.pos[l - 1]], o.number[o.pos[r]], x);
					int cnt = 1, tmp = val / 2;
					while (tmp && tmp % 2 == 0)
						{
							cnt++, tmp /= 2;
						}
					o.now %= cnt;
					int ans = val >> o.now;
					ans = max(ans, o.kth(1, o.len, o.number[o.pos[l - 1]], o.number[o.pos[r]], x + cnt - o.now));
					cout << ans << endl;
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
