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
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;

int n;
int cnt[N], a[N], num[N];
bool flag;
void dfs(int u)
{
	int v = a[u];
	if (num[v] == num[u])return flag = 0, void();
	else if (~num[v])return;
	num[v] = num[u] ^ 1;
	dfs(v);
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i], cnt[a[i]]++, num[i] = -1;
	queue<int>q;
	for (int i = 1; i <= n; ++i)if (!cnt[i])q.push(i);
	while (!q.empty())
		{
			int u = q.front(), v = a[u];
			q.pop();
			num[u] = 0;
			if (!num[v])return cout << -1 << endl, void();
			if (num[v] == -1)
				{
					int p = a[v];
					if (!--cnt[p])q.push(p);
				}
			num[v] = 1;
		}
	flag = 1;
	for (int i = 1; i <= n; ++i)if (num[i] == -1)num[i] = 1, dfs(i);
	if (!flag)return cout << -1 << endl, void();
	vector<int>ans;
	for (int i = 1; i <= n; ++i)if (num[i] == 0)ans.push_back(a[i]);
	cout << ans.size() << endl;
	for (auto v : ans)cout << v << " ";
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
