#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
const int N = 3e5 + 10;

#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

struct tree
{
	int l, r;
	ll sum, add;
} t[N << 2];

inline void pushup(int p)
{
	t[p].sum = min(t[ls].sum, t[rs].sum);
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	t[p].sum = t[p].add = inf; //初始化
	if (l == r)
		{
			return;
		}
	build(l, mid, ls), build(mid + 1, r, rs);
	pushup(p);
}

inline void change(int p, ll w)
{
	t[p].sum = min(t[p].sum, w);
	t[p].add = min(t[p].add, w);
}

inline void lazy(int p)
{
	if (t[p].l == t[p].r)t[p].add = inf;
	if (t[p].add != inf)
		{
			change(ls, t[p].add), change(rs, t[p].add);
			t[p].add = inf;
		}
}

void update(int l, int r, int p, ll w)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			change(p, w);
			return;
		}
	lazy(p);
	if (l <= mid)update(l, r, ls, w);
	if (r > mid)update(l, r, rs, w);
	pushup(p);
}

ll ask(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p].sum;
	lazy(p);
	if (l <= mid)return ask(l, r, ls);
	else return ask(l, r, rs);
}

struct node
{
	int k, id;
	bool operator<(const node&k1)const
	{
		if (k != k1.k)return k < k1.k;
		else return id < k1.id;
	}
} a[N];

int vis[N];

void mysolve()
{
	int n, m, q;
	cin >> n >> m >> q;
	int x, y;
	string s;
	cin >> s;
	s = '$' + s;
	build(1, n, 1);
	for (int i = 1; i <= m; ++i)
		{
			cin >> x >> y;
			update(x, y, 1, i);
		}
	for (int i = 1; i <= n; ++i)a[i].id = i, a[i].k = ask(i, i, 1);
	sort(a + 1, a + 1 + n);
	a[n + 1].k = inf;
	for (int i = 1; i <= n; ++i)vis[a[i].id] = i;
	int cnt = count(s.begin(), s.end(), '1');
	int ans = 0, len = 0;
	for (int i = 1; i <= n; ++i)
		{
			if (a[i].k != inf)len++;
			else break;
		}
	for (int i = 1; i <= len && i <= cnt; ++i)if (s[a[i].id] == '1')ans++;
	ans = min(len - ans, cnt - ans);
	int p = min(cnt, len);
	int sum = max(0, cnt - len);
	while (q--)
		{
			cin >> y;
			x = vis[y];
			if (x <= p)
				{
					if (s[y] == '1')
						{
							if (p < len)
								{
									if (x != p && s[a[p].id] == '1')ans++;
									p--;
								}
							else
								{
									if (sum)sum--, ans++;
									else
										{
											if (x != p && s[a[p].id] == '1')ans++;
											p--;
										}
								}
							s[y] = '0';
						}
					else
						{
							if (p < len)
								{
									p++;
									if (s[a[p].id] == '1')ans--;
								}
							else
								{
									ans--, sum++;
								}
							s[y] = '1';
						}
				}
			else
				{
					if (s[y] == '1')
						{
							if (p < len)
								{
									if (s[a[p].id] == '0')ans--;
									p--;
								}
							else
								{
									if (sum > 0)sum--;
									else
										{
											if (s[a[p].id] == '0')ans--;
											p--;
										}

								}
							s[y] = '0';
						}
					else
						{
							if (p < len)
								{
									p++;
									if (p != x && s[a[p].id] != '1')ans++;
								}
							else sum++;
							s[y] = '1';
						}
				}
			cout <<  ans << endl;
		}

}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
