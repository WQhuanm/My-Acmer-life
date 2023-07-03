#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 2e6 + 10;

int t[N][26], fail[N], cnt[N], b[N], a[N];//b串尾，a每个串的串尾记录的num
int tot, num;

vector<int>edge[N];
void add(string &s, int i)
{
	int u = 0;
	for (auto v : s)
		{
			int c = v - 'a';
			if (!t[u][c])t[u][c] = ++tot;
			u = t[u][c];
		}
	if (!b[u])b[u] = ++num;
	a[i] = b[u];
}

void build()
{
	queue<int>q;
	for (int i = 0; i < 26; ++i)if (t[0][i])q.push(t[0][i]), edge[0].push_back(t[0][i]);
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int i = 0; i < 26; ++i)
				{
					if (t[u][i])fail[t[u][i]] = t[fail[u]][i], q.push(t[u][i]), edge[fail[t[u][i]]].push_back(t[u][i]);
					else t[u][i] = t[fail[u]][i];
				}
		}
}

int sum[N];

void ask(string &s)
{
	int u = 0;
	for (auto v : s)
		{
			int c = v - 'a';
			u = t[u][c];
			sum[u]++;
//			for (int j = u; j; j = fail[j])	cnt[b[j]]++;
		}
}

bool vis[N];

void dfs(int u)
{
	vis[u] = 1;
	for (auto v : edge[u])
		{
//			if (!vis[v])
			dfs(v);
			sum[u] += sum[v];
		}
	cnt[b[u]] += sum[u];
}

void mysolve()
{
	int n;
	cin >> n;
//	tot = -1;A
	string s;
	for (int i = 1; i <= n; ++i)cin >> s, add(s, i);
	build();
	cin >> s;
	ask(s);
//	for (int i = 1; i <= tot; ++i)edge[fail[i]].push_back(i);
//	for (int i = 1; i <= tot; ++i)if (!vis[i])dfs(i);
	dfs(0);
	for (int i = 1; i <= n; ++i)cout << cnt[a[i]] << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
