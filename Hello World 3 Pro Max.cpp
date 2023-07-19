#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 1e5 + 10;
const int mod = 1e9 + 7;

#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

struct tree
{
	vector<vector<int>> p;
	int l, r;
} t[N << 2];
vector<int>v[26];
int a[20];

inline void pushup(int p)
{
	for (int i = 1; i < 11; ++i)t[p].p[i][i] = (t[ls].p[i][i] + t[rs].p[i][i]) % mod;
	for (int i = 1; i < 10; ++i)for (int j = i + 1; j < 11; ++j)
			{
				t[p].p[i][j] = (t[ls].p[i][j] + t[rs].p[i][j]) % mod;
				for (int k = i; k < j; ++k)t[p].p[i][j] = (t[p].p[i][j] + t[ls].p[i][k] * t[rs].p[k + 1][j] % mod) % mod;
			}
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	t[p].p = vector(11, vector<int>(11, 0));
	if (l == r)
		{
			for (int i = 1; i < 11; ++i)t[p].p[i][i] = a[i];
			return;
		}
	build(l, mid, ls), build(mid + 1, r, rs);
	pushup(p);
}

void update(int x, int p, int w)
{
	if (t[p].l == x && t[p].r == x)
		{
			for (int i = 1; i < 11; ++i)t[p].p[i][i] = 0;
			for (auto k : v[w])t[p].p[k][k] = 1;
			return;
		}
	if (x <= mid)update(x, ls, w);
	else update(x, rs, w);
	pushup(p);
}

vector <vector<int>> unit(vector <vector<int>> l, vector <vector<int>> r)
{
	vector p = vector(11, vector<int>(11, 0));
	for (int i = 1; i < 11; ++i)p[i][i] = (l[i][i] + r[i][i]) % mod;
	for (int i = 1; i < 10; ++i)for (int j = i + 1; j < 11; ++j)
			{
				p[i][j] = (l[i][j] + r[i][j]) % mod;
				for (int k = i; k < j; ++k)p[i][j] = (p[i][j] + l[i][k] * r[k + 1][j] % mod) % mod;
			}
	return p;
}

vector<vector<int>> ask(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p].p;
	vector ans = vector(11, vector<int>(11, 0));
	if (l <= mid)ans = unit(ask(l, r, ls), ans);
	if (r > mid)ans = unit(ans, ask(l, r, rs));
	return ans;
}

int p[10];

ll fastmi(ll base, ll power)
{
	ll ans = 1;
	while (power)
		{
			if (power & 1)ans = ans * base % mod;
			base = base * base % mod;
			power >>= 1;
		}
	return ans;
}

void mysolve()
{
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i < 8; ++i)cin >> p[i], sum += p[i];
	ll inv = fastmi(sum, mod - 2);
	a[1] = inv * p[1] % mod, a[2] = p[2] * inv % mod, a[3] = a[4] = a[9] = inv * p[3] % mod;
	a[5] = a[7] = inv * p[4] % mod, a[6] = inv * p[5] % mod, a[8] = inv * p[6] % mod, a[10] = inv * p[7] % mod;
	build(1, n, 1);
	int q, x, y, op;
	char c;
	cin >> q;
	while (q--)
		{
			cin >> op >> x ;
			if (op == 1)
				{
					cin >> c;

					update(x, 1, c - 'a' + 1);
				}
			else
				{
					cin >> y;
					vector<vector<int>> ans = ask(x, y, 1);
					cout << ans[1][10] << endl;
				}
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	v['h' - 'a' + 1].push_back(1);
	v['e' - 'a' + 1].push_back(2);
	v['l' - 'a' + 1].push_back(3);
	v['l' - 'a' + 1].push_back(4);
	v['l' - 'a' + 1].push_back(9);
	v['o' - 'a' + 1].push_back(5);
	v['o' - 'a' + 1].push_back(7);
	v['w' - 'a' + 1].push_back(6);
	v['r' - 'a' + 1].push_back(8);
	v['d' - 'a' + 1].push_back(10);
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
