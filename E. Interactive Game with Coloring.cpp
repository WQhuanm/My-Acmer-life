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
const int N = 3e5 + 10;

int n;
bool flag = 1;
int  col[N], in[N];
vector<pii>edge[N];

void pre_dfs(int u, int c)
{
	for (auto [v, id] : edge[u])
		{
			if (in[v] == 1)
				{
					col[id] = 1, pre_dfs(v, 1);
				}
			else
				{
					col[id] = (c !=2 ? 2 : 1), pre_dfs(v, col[id]);
				}
		}
}

void jud(int u, int c)
{
	if (u != 1)
		{
			for (auto [v, id] : edge[u])if (col[id] == c)
					{
						flag = 0;
						return;
					}
			if (edge[u].size() == 1 && c != 1)
				{
					flag = 0;
					return;
				}
		}
	for (auto [v, id] : edge[u])
		jud(v, col[id]);
}

void dfs(int u, int c)
{
	for (auto [v, id] : edge[u])
		{
			col[id] = (c + 1) % 3;
			dfs(v, col[id]);
		}
}
void mysolve()
{
	cin >> n;
	int x;
	for (int i = 2; i <= n; ++i)cin >> x, edge[x].push_back({i, i - 1}), in[x]++;
	pre_dfs(1, 0);
	jud(1, 0);
	int k = 2;
	if (!flag || in[1] == n - 1)
		{
			dfs(1, -1), k = (in[1] == n - 1 ? 1 : 3);
			for (int i = 1; i < n; ++i)col[i]++;
		}
	cout << k << endl;
	for (int i = 1; i < n; ++i)cout << col[i] << " \n"[i == n - 1];
	int op = 0;
	while (1)
		{
			cin >> op;
			if (op)return;
			vector<int>tmp;
			for (int i = 1; i <= k; ++i)
				{
					cin >> x;
					if (x == 1)tmp.push_back(i);
				}
			if (tmp.size() == 1)cout << tmp.front() << endl;
			else
				{
					if (tmp[0] + 1 == tmp[1] || k == 2)cout << tmp[0] << endl;
					else cout << tmp[1] << endl;
				}
		}

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
