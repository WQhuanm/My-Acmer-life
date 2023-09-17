#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e6 + 5;
bool vis[MAXN][26];
int n, m, q;
string s, ans;
struct SAM   //最多2n-1个点和3n-4条边
{
	int len[MAXN << 1], link[MAXN << 1], ch[MAXN << 1][26]; //我们记 longest(v) 为其中最长的一个字符串，记 len(v) 为它的长度。
	int cnt[MAXN << 1];
	int cur, lst, siz;
	SAM()
{
	clear();
}
	void clear()    //设置起始点S
{
	for (int i = 0; i <= siz + 10; ++i)memset(vis[i], 0, sizeof(vis[i]));
	memset(ch, 0, sizeof(int) * (siz + 10) * 26);
	len[0] = 0;
	link[0] = -1;
	siz = 0;    //siz设置成0实际上有一个点，方便标记
	lst = cur = 0;
}
	void extend(int c)
{
	lst = cur, cur = ++siz;
	len[cur] = len[lst] + 1;
	cnt[cur] = 1;
	for (; ~lst && !ch[lst][c]; lst = link[lst])ch[lst][c] = cur;
	
	if (lst == -1)
	{
		link[cur] = 0;
	}
	else
	{
		int q = ch[lst][c];
		if (len[lst] + 1 == len[q])
		{
			link[cur] = q;
		}
		else            //克隆的点是q(lst的c后继)
		{
			int clone = ++siz;
			link[clone] = link[q];
			len[clone] = len[lst] + 1;
			link[cur] = link[q] = clone;
			for (; ~lst && ch[lst][c] == q; lst = link[lst])ch[lst][c] = clone;
			memcpy(ch[clone], ch[q], sizeof(ch[q]));
		}
	}
}
} p;
struct SequenceAM
{
	int nxt[MAXN][26];
	void init(int n)
{
	for (int i = 0; i < 26; ++i)nxt[n + 1][i] = 0;
	for (int i = n; i >= 1; --i)
	{
		for (int j = 0; j < 26; ++j)
			nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i] - 'a'] = i;
	}
}
} a;
int tot;
bool flag;

void dfs(int cur, int sp)
{
	for (int i = 0; i < 26; ++i)
	{
		if (a.nxt[sp + 1][i])
		{
			if (!p.ch[cur][i])
			{
				ans += 'a' + i;
				flag = 1;
				return;
			}
			else
			{
				if (vis[cur][i])continue;
				vis[cur][i] = 1;
				ans += 'a' + i;
				dfs(p.ch[cur][i], a.nxt[sp + 1][i]);
				if (flag)return;
				ans.pop_back();
				tot--;
			}
		}
	}
	
}
signed main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int TxT;// = read();
	cin >> TxT;
	while (TxT--)
	{
		ans.clear();
		cin >> s;
		n = (int)s.size();
		s = '$' + s;
		a.init(n);
		p.clear();
		for (int i = 1; i <= n; ++i)p.extend(s[i] - 'a');
		tot = 0;
		flag = 0;
		dfs(0, 0);
		if (flag)cout << ans << '\n';
		else cout << "-1\n";
	}
	return 0;
}

