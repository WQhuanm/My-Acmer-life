#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 3e5 + 2, M = 32, K = 30;

typedef unsigned int uint;
mt19937 rnd(random_device{}());
uniform_int_distribution<uint> rd(0, UINT32_MAX);
#define rd (rd(rnd))

int n, q, cnt;
uint a[N];
ll t[M][N];
uint now[N << 1][M];
map<uint, int>mp;

void add(int k, int x, ll w)
{
	for (int i = x; i <= n; i += i & -i)t[k][i] += w;
}

ll ask(int k, int x)
{
	if (!x)return 0;
	ll ans = 0;
	for (int i = x; i; i -= i & -i)ans += t[k][i];
	return ans;
}

void change(int id, int w)
{
	if (!mp.count(w))
		{
			mp[w] = ++cnt;
			for (int i = 1; i <= K; ++i)now[cnt][i] = rd;
		}
	int u = mp[w], v = mp[a[id]];
	for (int i = 1; i <= K; ++i)add(i, id, (ll)now[u][i] - now[v][i]);
	a[id] = w;
}

bool check(int l, int r, int k)
{
	for (int i = 1; i <= K; ++i)if ((ask(i, r) - ask(i, l - 1)) % k)return 0;
	return 1;
}

void mysolve()
{
	mp[0] = 0;
	int op, x, y, k;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)cin >> x, change(i, x);
	while (q--)
		{
			cin >> op;
			if (op == 1)cin >> x >> y, change(x, y);
			else
				{
					cin >> x >> y >> k;
					if (check(x, y, k))cout << "YES" << endl;
					else cout << "NO" << endl;
				}
		}
}

signed main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	return 0;
}
