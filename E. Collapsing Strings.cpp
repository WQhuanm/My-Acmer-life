#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 1e6 + 10;

int ch[2][N][27];
ll cnt[2][N], len[2][N]; //N取决与有多少个不同字符串，常数巨大（接近n^2)
int tot, tot2;
ll ans;

inline void insert(string s)
{
	int p = 0; //p与tot初始值相同
	int l = (int)s.size();
	for (int i = l - 1; ~i; --i)
		{
			int c = s[i] - 'a';
			if (!ch[0][p][c])ch[0][p][c] = ++tot;
			int now = ch[0][p][c];
			len[0][now] += i + 1, cnt[0][now]++;
			p = now;
		}
	if (!ch[0][p][26])ch[0][p][26] = ++tot;
	p = ch[0][p][26], cnt[0][p]++;
	p = 0;
	for (int i = 0; i < l; ++i)
		{
			int c = s[i] - 'a';
			if (!ch[1][p][c])ch[1][p][c] = ++tot2;
			int now = ch[1][p][c];
			len[1][now] += l - i, cnt[1][now]++;
			p = now;
		}
	if (!ch[1][p][26])ch[1][p][26] = ++tot2;
	p = ch[1][p][26], cnt[1][p]++;
}

inline void ask(string s)
{
	int p = 0, l = (int)s.size();
	for (int i = 0; i < (int)s.size(); ++i)
		{
			int c = s[i] - 'a';
			for (int j = 0; j < 27; ++j)if (j != c)ans += len[0][ch[0][p][j]] + cnt[0][ch[0][p][j]] * (l - i); //0是正串
			if (!ch[0][p][c])
				{
					p = 0;
					break;
				}
			p = ch[0][p][c];
		}
	if (p)for (int j = 0; j < 26; ++j)ans += len[0][ch[0][p][j]];
	p = 0;
	for (int i = (int)s.size() - 1; ~i; --i)
		{
			int c = s[i] - 'a';
			for (int j = 0; j < 27; ++j)if (j != c)
					ans += len[1][ch[1][p][j]] + cnt[1][ch[1][p][j]] * (i + 1);
			if (!ch[1][p][c])
				{
					p = 0;
					break;
				}
			p = ch[1][p][c];
		}
	if (p)for (int j = 0; j < 26; ++j)ans += len[1][ch[1][p][j]];
}

int n;
string s;
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		{
			cin >> s, ask(s), insert(s);
			int l = (int)s.size();
			for (int i = 0; i <= l / 2; ++i)if (s[i] != s[l - i - 1])
					{
						ans += (l - i) * 2;
						break;
					}
		}
	cout << ans << endl;
}

signed main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
