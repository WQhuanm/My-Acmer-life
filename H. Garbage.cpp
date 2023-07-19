#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 1e5 + 10;
//#define int ll

#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

struct tree
{
	int l, r;
	int cnt[2][20][2];//类型k，记录i位，1/0个数
	int lazy[20], p[20];
} t[N << 2];

const int g = 20;

int a[N];

inline void pushup(int p)
{
	for (int k = 0; k < 2; ++k)for (int i = 0; i < g; ++i)for (int j = 0; j < 2; ++j)t[p].cnt[k][i][j] = t[ls].cnt[k][i][j] + t[rs].cnt[k][i][j];
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	for (int i = 0; i < g; ++i)t[p].lazy[i] = -1, t[p].p[i] = -1;
	if (l == r)
		{
			for (int i = 0; i < g; ++i)
				{
					int d = (a[l] >> i) & 1;
					if ((l >> i) & 1)t[p].cnt[0][i][d]++;
					else t[p].cnt[1][i][d]++;
				}
			return;
		}
	build(l, mid, ls), build(mid + 1, r, rs);
	pushup(p);
}

inline void change(int p, int fl[], int add[])
{
	for (int i = 0; i < g; ++i)
		{
			if (~fl[i])
				{
					if (fl[i] & 1)//强制
						{
							t[p].p[i] = 1;
							if (add[i] & 1)
								{
									t[p].cnt[1][i][1] += t[p].cnt[1][i][0], t[p].cnt[1][i][0] = 0;
									t[p].cnt[0][i][1] += t[p].cnt[0][i][0], t[p].cnt[0][i][0] = 0;
									t[p].lazy[i] = 1;
								}
							else
								{
									t[p].cnt[1][i][0] += t[p].cnt[1][i][1], t[p].cnt[1][i][1] = 0;
									t[p].cnt[0][i][0] += t[p].cnt[0][i][1], t[p].cnt[0][i][1] = 0;
									t[p].lazy[i] =  0;
								}
						}
					else
						{
							if (add[i] & 1)//不强制且修改为1
								{
									if (t[p].p[i] != 1)t[p].p[i] = 0;
									swap(t[p].cnt[1][i][1], t[p].cnt[1][i][0]);
									swap(t[p].cnt[0][i][1], t[p].cnt[0][i][0]);
									if (~t[p].lazy[i])t[p].lazy[i] ^= 1;
									else t[p].lazy[i] = 1;
								}
							else
								{
									if (t[p].lazy[i] == -1)t[p].lazy[i] = 0;
								}

						}
				}
		}
}

inline void lazy(int p)
{
	if (t[p].l == t[p].r)return;
	change(ls, t[p].p, t[p].lazy);
	change(rs, t[p].p, t[p].lazy);
	for (int i = 0; i < g; ++i)t[p].p[i] = -1, t[p].lazy[i] = -1;
}

void update(int l, int r, int p, int fl[], int add[])
{
	if (l <= t[p].l && t[p].r <= r)
		{
			change(p, fl, add);
			return;
		}
	lazy(p);
	if (l <= mid)update(l, r, ls, fl, add);
	if (r > mid)update(l, r, rs, fl, add);
	pushup(p);
}

ll ask(int l, int r, int p)
{
	ll ans = 0;
	if (l <= t[p].l && t[p].r <= r)
		{
			for (int i = 0; i < g; ++i)
				{
					ans = (ans + 1ll*(1 << i) * (1ll*t[p].cnt[1][i][1] + t[p].cnt[0][i][0]));
				}
			return ans;
		}
	lazy(p);
	if (l <= mid)ans = (ans + ask(l, r, ls));
	if (r > mid)ans = (ans + ask(l, r, rs));
	return ans;
}

void mysolve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	build(1, n, 1);
	int op, l, r, x;
	char c;
	while (m--)
		{
			cin >> op >> l >> r;
			if (op == 1)cout << ask(l, r, 1) << endl;
			else if (op == 2)
				{
					cin >> x;
					int fl[g], add[g];
					for (int i = 0; i < g; ++i)
						{
							fl[i] = 1;
							if ((x >> i) & 1)add[i] = 1;
							else add[i] = 0;
						}
					update(l, r, 1, fl, add);
				}
			else
				{
					cin >> x >> c;
					int fl[g], add[g];
					if (c == '&')
						{
							for (int i = 0; i < g; ++i)
								{
									fl[i] = -1;
									if ((x >> i) & 1)continue;
									else fl[i] = 1, add[i] = 0;
								}
						}
					else if (c == '|')
						{
							for (int i = 0; i < g; ++i)
								{
									fl[i] = -1;
									if ((x >> i) & 1) fl[i] = 1, add[i] = 1;
								}
						}
					else
						{
							for (int i = 0; i < g; ++i)
								{
									fl[i] = 0;
									if ((x >> i) & 1)add[i] = 1;
									else add[i] = 0;
								}
						}
					update(l, r, 1, fl, add);
				}
			//			if (m <= 7)
			{
				//				for (int i = 1; i <= n; ++i)
				//					cout << ask(i, i, 1) << " \n"[i == n];
				//					cout << ask(7, 17, 1) << endl;
			}

		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

