#include <bits/stdc++.h>
using namespace std;
#define ll               long long
const int N = 1e5 + 10;
int tot, last, ans;
string s;

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

			if (t[tot].len % 2 == 0 && s.substr(x - t[tot].len + 1, t[tot].len / 2) == s.substr(x - t[tot].len + 1 + t[tot] . len / 2, t[tot].len / 2))t[tot].cnt++;

			t[tot].cnt += t[t[tot].fail].cnt;//cnt记录当前点为结尾的回文串个数
			t[tot].sz = 1;
		}
	last = t[p].ch[c - 'a']; //last记录上一个回文串的状态
	ans += t[last].cnt;
}

void mysolve()
{
	cin >> s;
	Pam_init();
	s = '$' + s;
	for (int i = 1; i < (int)s.size(); ++i)
		insert(s[i], i), cout << ans << " \n"[i == (int)s.size() - 1];
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
