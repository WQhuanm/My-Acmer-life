#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
#define endl             "\n"

const int N = 5e5 + 10;

inline int C(int n, int m)
{
	if (n < m)return 0;
	if (m == 3)return n * (n - 1) * (n - 2) / 6;
	else return n * (n - 1) / 2;
}

int ch[N * 30][2], cnt[N * 30]; //N取决与有多少个不同字符串，常数巨大（接近n^2)
int tot;
ll ans;

void init()
{
	for (int i = 0; i <= tot; ++i)ch[i][0] = ch[i][1] = cnt[i] = 0;
	tot = ans = 0;
}

inline void insert(int x, int w)
{
	int p = 0;
	for (int i = 0; i < 62; ++i)
		{
			int t = (x >> i) & 1;
			if (!ch[p][t])ch[p][t] = ++tot;
			p = ch[p][t];
			cnt[p] += w;
		}
}

inline void ask(int x, int w)
{
	int p = 0;
	for (int i = 0; i < 62; ++i)
		{
			int t = (x >> i) & 1;
			if (i % 2 == 0)
				{
					ans -= C(w, 2) * cnt[ch[p][t ^ 1]];
				}
			p = ch[p][t];
		}
}

void mysolve()
{
	int n;
	cin >> n;
	init();
	ll x;
	map<ll, int>mp;
	for (int i = 1; i <= n; ++i)cin >> x, mp[x]++;
	ans = C(n, 3);
	for (auto [v, k] : mp)
		{
			if (k >= 3)ans -= C(k, 3);
			insert(v, k);
		}
	for (auto [v, k] : mp)if (k >= 2)
			ask(v, k);
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
