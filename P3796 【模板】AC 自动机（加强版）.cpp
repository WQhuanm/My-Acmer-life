#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;

int t[N][26], fail[N], b[N], ans[N];
int tot;

void init(int n)
{
	for (int i = 0; i <= tot; ++i)memset(t[i], 0, sizeof(t[i])), fail[i] = b[i] = 0;
	tot = 0;
	for (int i = 1; i <= n; ++i)ans[i] = 0;
}

void add(string &s, int p)
{
	int u = 0;
	for (auto v : s)
		{
			int c = v - 'a';
			if (!t[u][c])t[u][c] = ++tot;
			u = t[u][c];
		}
	b[u] = p;
}

void build()
{
	queue<int>q;
	for (int i = 0; i < 26; ++i)if (t[0][i])q.push(t[0][i]);
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int i = 0; i < 26; ++i)
				{
					if (t[u][i])fail[t[u][i]] = t[fail[u]][i], q.push(t[u][i]);
					else t[u][i] = t[fail[u]][i];
				}
		}
}

void ask(string &s)
{
	int u = 0;
	for (auto v : s)
		{
			int c = v - 'a';
			u = t[u][c];
			for (int j = u; j; j = fail[j])
				{
					ans[b[j]]++;
				}
		}
}

void mysolve()
{
	int n;
	while (cin >> n && n)
		{
			init(n);
			vector<string>v;
			v.push_back(" ");
			string s;
			for (int i = 1; i <= n; ++i)
				{
					cin >> s;
					v.push_back(s);
					add(s, i);
				}
			build();
			cin >> s;
			ask(s);
			int mx = *max_element(ans + 1, ans + 1 + n);
			cout << mx << endl;
			for (int i = 1; i <= n; ++i)if (ans[i] == mx)cout << v[i] << endl;
		}
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
