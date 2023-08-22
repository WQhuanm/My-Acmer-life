#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 1e6 + 10;

struct Pam
{
	int ch[26], len, cnt, fail, sz;
	void clear()
	{
		memset(ch, 0, sizeof(ch));
		len = cnt = fail = sz = 0;
	}
} t[N];

int tot, last;
string s;

void Pam_init()
{
	for (int i = 2; i <= tot; ++i)t[i].clear();
	last = 0, tot = 1; //last先指向偶回文，匹配失败才去奇回文，否则偶回文不会出现
	t[0].fail = t[1].fail = 1, t[1].len = -1; //t[0]为偶回文，t[1]奇回文
}

int get_fail(int u, int p)
{
	while (p - t[u].len - 1 <= 0 || s[p - t[u].len - 1] != s[p])u = t[u].fail;
	return u;
}

void insert(char c, int x) //下标从1开始
{
	int p = get_fail(last, x);
	if (!t[p].ch[c - 'a'])
		{
			t[++tot].fail = t[get_fail(t[p].fail, x)].ch[c - 'a'];
			t[p].ch[c - 'a'] = tot;
			t[tot].len = t[p].len + 2, t[tot].cnt = t[t[tot].fail].cnt + 1;//cnt记录当前点为结尾的回文串个数
			t[tot].sz = 1;
		}
	else t[t[p].ch[c - 'a']].sz++;//sz记录当前回文串出现次数
	last = t[p].ch[c - 'a'];
}

int ans;

void mysolve()
{
	Pam_init();
	cin >> s;
	s = '$' + s;
	for (int i = 1; i < (int)s.size(); ++i)
		{
			insert(s[i], i);
		}
	int ans = 0;
	for (int i = tot; ~i; --i)
		{
			t[t[i].fail].sz += t[i].sz;
			ans = max(ans, t[i].sz  * t[i].len);
		}
	cout << ans << endl;
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
