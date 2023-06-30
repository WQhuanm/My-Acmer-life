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
const int N = 1e6 + 10;
const int mod = 998244353;

int t[N][26], fail[N], cnt[N];
int tot;

void add(string &s)
{
	int u = 0;
	for (auto v : s)
		{
			if (!t[u][v - 'a'])t[u][v - 'a'] = ++tot;
			u = t[u][v - 'a'];
		}
	cnt[u]++;
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

int ask(string&s)
{
	int ans = 0, u = 0;
	for (auto v : s)
		{
			u = t[u][v - 'a'];
			for (int j = u; j && ~cnt[j]; j = fail[j])
				{
					ans += cnt[j], cnt[j] = -1;
				}
		}
	return ans;
}

void mysolve()
{
	int n;
	string s;
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> s, add(s);
	build();
	cin >> s;
	cout << ask(s) << endl;
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
