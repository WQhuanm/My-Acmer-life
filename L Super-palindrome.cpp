#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 5e3 + 10;

const int base = 457, base2 = 131, mod =  998244353, mod2 = 1e9 + 7;
ll mi[5][N];

void hash_init()
{
	mi[0][0] = mi[1][0] = 1;
	for (int i = 1; i <= N - 5; ++i)
		{
			mi[0][i] = mi[0][i - 1] * base % mod;
		}
}

struct hash_1d//字符串1~n
{
	int base = 131, mod = 998244353, p, n; //p表示使用哪个base的mi[]数组,0为base，1为base2
	string s;
	ll h[N];
	void init(int _base, int _mod, int _p, string _s, int _n)
	{
		base = _base, mod = _mod, p = _p, s = _s, n = _n;
		h[0] = 0;
		for (int i = 1; i <= n; ++i)h[i] = (h[i - 1] * base % mod + s[i]) % mod;
	}
	int get_sub(int l, int r)
	{
		return (h[r] - h[l - 1] * mi[p][r - l + 1] % mod + mod) % mod;
	}
} h, h2;

void mysolve()
{
	string s;
	cin >> s;
	int n = (int)s.size();
	s = '$' + s;
	h.init(base, mod, 0, s, n);
	unordered_map<int, bool>mp;
	int ans = 0;
	for (int i = 1; i < n; ++i)
		{
			int l = i, r = i + 1, len = 0;
			while (l >= 1)
				{
					if (h.get_sub(l, l + len) == h.get_sub(r, r + len))
						{
							ans++;
							r = r + len + 1, len = 0;
						}
					else len++;
					l--;
				}
		}
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	hash_init();
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
