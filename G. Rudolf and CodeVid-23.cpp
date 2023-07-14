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

struct node
{
	int t, good, ill;
} a[N];

int toint(string &s)
{
	int ans = 0;
	for (int i = 0; i < (int)s.size(); ++i)if (s[i] == '1')ans |= (1 << i);
	return ans;
}

void mysolve()
{
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int st = toint(s);
	for (int i = 1; i <= m; ++i)
		{
			cin >> a[i].t;
			cin >> s;
			a[i].good = toint(s);
			cin >> s;
			a[i].ill = toint(s);
		}
	vector<int>dis(1 << 11, inf);
	dis[st] = 0;
	priority_queue<pii, vector<pii>, greater<pii>>q;
	q.push({dis[st], st});
	while (!q.empty())
		{
			int u = q.top().second;
			q.pop();
			for (int i = 1; i <= m; ++i)
				{
					int v = u;
					v |= a[i].ill;
					for (int j = 0; j < n; ++j)if ((a[i].good >> j) & 1 && (v >> j) & 1)v -= 1 << j ;
					if (dis[v] > dis[u] + a[i].t)
						{
							dis[v] = dis[u] + a[i].t;
							q.push({dis[v], v});
						}
				}
		}
	if (dis[0] < inf)cout << dis[0] << endl;
	else cout << -1 << endl;
}

int32_t main()
{
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
