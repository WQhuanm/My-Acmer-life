#include <bits/stdc++.h>
using namespace std;
#define  ll long long
const int N = 1e6 + 10;
int tot, last, ans;
string s;

const int base = 457, base2 = 131, mod =  998244353, mod2 = 1e9 + 7;
ll mi[5][N];

void hash_init()
{
	mi[0][0] = mi[1][0] = 1;
	for (int i = 1; i <= N - 5; ++i)
		{
			mi[0][i] = mi[0][i - 1] * base % mod;
			mi[1][i] = mi[1][i - 1] * base2 % mod2;
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
} h;

struct Pam
{
	int ch[26], len, cnt, fail, sz;
	void clear()
	{
		memset(ch, 0, sizeof(ch));
		len = cnt = fail = sz = 0;
	}
} t[N];

void Pam_init()
{
	for (int i = 0; i <= tot; ++i)t[i].clear();
	last = ans = 0, tot = 1; //last先指向偶回文，匹配失败才去奇回文，否则偶回文不会出现
	t[0].fail = t[1].fail = 1, t[1].len = -1; //t[0]为偶回文，t[1]奇回文
}

int get_fail(int u, int p)
{
	while (p - t[u].len - 1 <= 0 || s[p - t[u].len - 1] != s[p])
		u = t[u].fail;
	return u;
}

void insert(char c, int x) //下标从1开始
{
	int p = get_fail(last, x);
	if (!t[p].ch[c - 'a'])
		{
			t[++tot].fail = t[get_fail(t[p].fail, x)].ch[c - 'a'];
			t[p].ch[c - 'a'] = tot;
			t[tot].len = t[p].len + 2;
			if (t[tot].len % 4 == 0 && h.get_sub(x - t[tot].len + 1, x - t[tot].len + t[tot].len / 2) == h.get_sub(x - t[tot].len + 1 + t[tot].len / 2, x))ans = max(ans, t[tot].len);
		}
	last = t[p].ch[c - 'a']; //last记录上一个回文串的状态
//	cout << t[last].fail << endl;
}

int n;
void mysolve()
{
	cin >> n;
	cin >> s;
	s = '$' + s;
	Pam_init();
	hash_init();
	h.init(base, mod, 0, s, n);

	for (int i = 1; i < (int)s.size(); ++i)insert(s[i], i);
	cout << ans << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
