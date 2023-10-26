#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 12;

char a[N][N];
int n, m;

struct node
{
	int x, y, k, d, now;
};

bool vis[N][N][110][N][110];

void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)cin >> a[i][j];
	string s;
	int k;
	cin >> k >> s;
	queue<node>q;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			{
				if (a[i][j] == s[0])
					{
						q.push({i, j, 0, 0, 0});
					}
			}
	int len = (int)s.size();
	while (!q.empty())
		{
			node u = q.front();
			q.pop();
			if (vis[u.x][u.y][u.k][u.d][u.now])continue;
			vis[u.x][u.y][u.k][u.d][u.now] = 1;
			if (u.now == len - 1)
				{
					if (u.k == k)return cout << "YES" << endl, void();
					continue;
				}
			int p = 0;
			for (int i = u.x - 1; i <= u.x + 1; ++i)for (int j =  u.y - 1; j <= u.y + 1; ++j)
					{	
						++p;
						if ((i != u.x || j != u.y) && i >= 1 && i <= n && j >= 1 && j <= m && a[i][j] == s[u.now + 1])
							{
								node tmp = {i, j, u.k, u.d, u.now + 1};
								if (tmp.d && tmp.d != p)tmp.k++;
								tmp.d = p;
								if (tmp.k <= k)q.push(tmp);
							}
					}
		}
	cout << "NO" << endl;
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
