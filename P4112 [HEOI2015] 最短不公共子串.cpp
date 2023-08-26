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
const int N = 2e3 + 10;

struct SAM
{
	struct tree
	{
		int ch[26];
		int len, fa;
	} t[N << 1];//至多2n个点
	int tot = 0, last = 0, n; //tot为当前节点数，根为0，last为上一个串

	void add(int c)
	{
		int p = last, np = last = ++tot;
		t[np].len = t[p].len + 1;
		while (~p && !t[p].ch[c])t[p].ch[c] = np, p = t[p].fa;//向上寻找p串后缀有+c字符的串
		if (p == -1)t[np].fa = 0;//找不到，父亲为根
		else
			{
				int q = t[p].ch[c];
				if (t[q].len == t[p].len + 1)t[np].fa = q;//如果找到的q刚好长度=p+1，说明就是直接p串+c而不是后缀，np父亲为q
				else
					{
						int nq = ++tot;//否则复制q，增加一个长度为p+1的，q与np父亲设为nq
						t[nq] = t[q], t[nq].len = t[p].len + 1;//nq是复制q的点，如果赋予它val/sz值，则一个子串重复计算
						t[np].fa = t[q].fa = nq;
						while (~p && t[p].ch[c] == q)t[p].ch[c] = nq, p = t[p].fa;//把所有p串父亲指向c时连q的改为连nq
					}
			}
	}
	void init(string &s)
	{
		tot = last = 0;
		t[0].fa = -1;
		for (auto v : s)add(v - 'a');
	}

} sa, sb;

struct subq
{
	int next[N][26];
	void init(string &s)
	{
		int len = (int)s.size();

		memset(next[len], -1, sizeof(next[len]));
		for (int i = len - 1; ~i; --i)memcpy(next[i], next[i + 1], sizeof(next[i])), next[i][s[i] - 'a'] = i + 1;
	}
} qa, qb;

int ans1, ans2, ans3, ans4;

void dfs(int psa,  int psb, int pqb, int len)
{
	if (len >= ans1 && len >= ans2)return;
	if (len)
		{
			if (psb == -1)ans1 = min(ans1, len);
			if (pqb == -1)ans2 = min(ans2, len);
		}
	for (int i = 0; i < 26; ++i)if (sa.t[psa].ch[i])
			{
				dfs(sa.t[psa].ch[i], (~sb.t[psb].ch[i] && sb.t[psb].ch[i] ? sb.t[psb].ch[i] : -1), (~pqb ? qb.next[pqb][i] : -1), len + 1);
			}
}

bool vis[N][N * 3];

void bfs(int psa,  int psb, int pqb, int len)
{
	if (len >= ans1 && len >= ans2)return;
	if (len)
		{
			if (psb == -1)ans1 = min(ans1, len);
			if (pqb == -1)ans2 = min(ans2, len);
		}
	for (int i = 0; i < 26; ++i)if (sa.t[psa].ch[i])
			{
				dfs(sa.t[psa].ch[i], (~sb.t[psb].ch[i] && sb.t[psb].ch[i] ? sb.t[psb].ch[i] : -1), (~pqb ? qb.next[pqb][i] : -1), len + 1);
			}
}

struct node
{
	int a, b, len;
};

string s;
int cnt = 0;
void bfs()
{
	queue<node>q;
	q.push({0, 0, 0});
	while (!q.empty())
		{
			node u = q.front();
			q.pop();
			if (vis[u.a][u.b])continue;
			vis[u.a][u.b] = 1;
			for (int i = 0; i < 26; ++i)if (~qa.next[u.a][i])
					{
						if (!sb.t[u.b].ch[i])
							{
								ans3 = u.len + 1;
								return;
							}
						q.push({qa.next[u.a][i], sb.t[u.b].ch[i], u.len + 1});
					}
		}
}

void bfs2()
{
	queue<node>q;
	q.push({0, 0, 0});
	while (!q.empty())
		{
			node u = q.front();
			q.pop();
			if (vis[u.a][u.b])continue;
			vis[u.a][u.b] = 1;
			for (int i = 0; i < 26; ++i)if (~qa.next[u.a][i])
					{
						if (qb.next[u.b][i] == -1)
							{
								ans4 = u.len + 1;
								return;
							}
						q.push({qa.next[u.a][i], qb.next[u.b][i], u.len + 1});
					}
		}
}
string a, b;
void mysolve()
{
	cin >> a >> b;
	sa.init(a), qa.init(a);
	sb.init(b), qb.init(b);
	ans1 = ans2 = ans3 = ans4 = inf;
	dfs(0,  0, 0, 0);
	bfs();
	memset(vis, 0, sizeof(vis));
	bfs2();
	ans1 = (ans1 < inf ? ans1 : -1);
	ans2 = (ans2 < inf ? ans2 : -1);
	ans3 = (ans3 < inf ? ans3 : -1);
	ans4 = (ans4 < inf ? ans4 : -1);
	cout << ans1 << endl << ans2 << endl << ans3 << endl << ans4 << endl;
}

int32_t main()
{
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
