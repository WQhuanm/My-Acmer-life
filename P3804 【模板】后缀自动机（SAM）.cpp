#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 2e6 + 10;
const int mod = 998244353;

struct tree
{
	int ch[26];
	int len, fa;
} t[N << 1];
int tot, last;
vector<int> edge[N];
int sz[N], ans = 0;
void add(int c)
{
	int p = last, np = last = ++tot;
	sz[np] = 1;//np是字符串上实际有的点，可以赋予val
	t[np].len = t[p].len + 1;
	while (~p && !t[p].ch[c])t[p].ch[c] = np, p = t[p].fa;
	if (p == -1)t[np].fa = 0;
	else
		{
			int q = t[p].ch[c];
			if (t[q].len == t[p].len + 1)t[np].fa = q;
			else
				{
					int nq = ++tot;
					t[nq] = t[q], t[nq].len = t[p].len + 1;//nq不是字符串上实际有的点，不可以赋予val
					t[np].fa = t[q].fa = nq;
					while (~p && t[p].ch[c] == q)t[p].ch[c] = nq, p = t[p].fa;
				}
		}
}


void dfs(int u)
{
//	sz[u] = 1;
	for (auto v : edge[u])
		{
			dfs(v);
			sz[u] += sz[v];
		}
	if (sz[u] != 1)ans = max(ans, sz[u] * t[u].len);
}

void mysolve()
{
	tot = last = 0;
	t[0].fa = -1;
	string s;
	cin >> s;
	for (auto v : s)add(v - 'a');
	for (int i = 1; i <= tot; ++i)edge[t[i].fa].push_back(i);
	dfs(0);
	cout << ans << endl;
}

int32_t main()
{
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
