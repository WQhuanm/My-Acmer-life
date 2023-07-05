#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 5e5 + 10;
const int mod = 998244353;

struct tree
{
	int ch[26];
	int fa, len;
} t[N << 1];//最多2n个节点

vector<int >edge[N << 1];
int sum[N << 1], sz[N << 1];
bool vis[N << 1];
int last, tot;

void add(int c)
{
	int p = last, np = last = ++tot;
	t[np].len = t[p].len + 1;
	sum[np] = 1;
	while (~p && !t[p].ch[c])t[p].ch[c] = np, p = t[p].fa;
	if (p == -1)t[np].fa = 0;
	else
		{
			int q = t[p].ch[c];
			if (t[p].len + 1 == t[q].len)t[np].fa = q;
			else
				{
					int nq = ++tot;
					t[nq] = t[q];
					t[nq].len = t[p].len + 1;
					t[q].fa = t[np].fa = nq;
					while (~p && t[p].ch[c] == q)t[p].ch[c] = nq, p = t[p].fa;
				}
		}
}

void dfs1(int u)
{
	for (auto v : edge[u])dfs1(v), sum[u] += sum[v];
}

void dfs2(int u)
{
	if (vis[u])return;
	vis[u] = 1;
	for (int i = 0; i < 26; ++i)
		{
			if (t[u].ch[i])dfs2(t[u].ch[i]), sum[u] += sum[t[u].ch[i]];
		}
}
string ans;
void dfs(int u, int k)
{
	if (k <= sz[u])return;
	else k -= sz[u];
	for (int i = 0; i < 26; ++i)if (t[u].ch[i])
			{
				if (sum[t[u].ch[i]] < k)
					{
						k -= sum[t[u].ch[i]];
						continue;
					}
				else
					{
						ans.push_back(i + 'a');
						dfs(t[u].ch[i], k);
						return;
					}
			}
}

void mysolve()
{
	t[0].fa = -1;
	tot = last = 0;
	string s1;
	cin >> s1;
	for (auto v : s1)add(v - 'a');
	int T, k;
	cin >> T >> k;
//	for (int i = 1; i <= tot; ++i)sum[i] = 1;
	if (T)
		{
			for (int i = 1; i <= tot; ++i)edge[t[i].fa].push_back(i);
			dfs1(0);
			sum[0] = 0;
		}
	for (int i = 1; i <= tot; ++i)sz[i] = (T?sum[i]:sum[i]=1);
	dfs2(0);
	if (k > sum[0])cout << -1 << endl;
	else
		{
			dfs(0, k);
			cout << ans << endl;
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了

	mysolve();

	system("pause");
	return 0;
}
