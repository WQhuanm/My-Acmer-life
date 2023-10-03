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
const int mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 10;

bool vis[N][N][N];

int a[N][N], b[N];
int n = 9;

bool check()
{
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)if (!a[i][j])
				{
					vector<int>tmp;
					for (int k = 1; k <= n; ++k)if (!vis[k][i][j])tmp.push_back(k);
					if ((int)tmp.size() == 1)
						{
							a[i][j] = tmp[0];
							for (int k = 1; k <= n; ++k)vis[k][i][j] = 1;
							for (int k = 1; k <= n; ++k)vis[a[i][j]][i][k] = vis[a[i][j]][k][j] = 1;
							for (int pi = b[i]; pi <= b[i] + 2; ++pi)for (int pj = b[j]; pj <= b[j] + 2; ++pj)vis[a[i][j]][pi][pj] = 1;
							return 1;
						}
					for (auto k : tmp)
						{
							bool fl = 1;
							for (int pi = 1; pi <= n; ++pi)if ((pi != j) && !vis[k][i][pi])fl = 0;
							if (fl)
								{
									a[i][j] = k;
									for (int k = 1; k <= n; ++k)vis[k][i][j] = 1;
									for (int k = 1; k <= n; ++k)vis[a[i][j]][i][k] = vis[a[i][j]][k][j] = 1;
									for (int pi = b[i]; pi <= b[i] + 2; ++pi)for (int pj = b[j]; pj <= b[j] + 2; ++pj)vis[a[i][j]][pi][pj] = 1;
									return 1;
								}
							fl = 1;
							for (int pi = 1; pi <= n; ++pi)if ((pi != i) && !vis[k][pi][j])fl = 0;
							if (fl)
								{
									a[i][j] = k;
									for (int k = 1; k <= n; ++k)vis[k][i][j] = 1;
									for (int k = 1; k <= n; ++k)vis[a[i][j]][i][k] = vis[a[i][j]][k][j] = 1;
									for (int pi = b[i]; pi <= b[i] + 2; ++pi)for (int pj = b[j]; pj <= b[j] + 2; ++pj)vis[a[i][j]][pi][pj] = 1;
									return 1;
								}
							fl = 1;
							for (int pi = b[i]; pi <= b[i] + 2; ++pi)for (int pj = b[j]; pj <= b[j] + 2; ++pj)if ((pi != i || pj != j) && !vis[k][pi][pj])fl = 0;
							if (fl)
								{
									a[i][j] = k;
									for (int k = 1; k <= n; ++k)vis[k][i][j] = 1;
									for (int k = 1; k <= n; ++k)vis[a[i][j]][i][k] = vis[a[i][j]][k][j] = 1;
									for (int pi = b[i]; pi <= b[i] + 2; ++pi)for (int pj = b[j]; pj <= b[j] + 2; ++pj)vis[a[i][j]][pi][pj] = 1;
									return 1;
								}
						}
				}
	return 0;
}

void mysolve()
{
	for (int i = 1; i <= 3; ++i)b[i] = 1;
	for (int i = 4; i <= 6; ++i)b[i] = 4;
	for (int i = 7; i <= 9; ++i)b[i] = 7;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)
			{
				cin >> a[i][j];
				if (a[i][j])
					{
						for (int k = 1; k <= n; ++k)vis[k][i][j] = 1;
						for (int k = 1; k <= n; ++k)vis[a[i][j]][i][k] = vis[a[i][j]][k][j] = 1;
						for (int pi = b[i]; pi <= b[i] + 2; ++pi)for (int pj = b[j]; pj <= b[j] + 2; ++pj)vis[a[i][j]][pi][pj] = 1;
					}
			}
	while (check());
	check();
	bool fl = 1;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)if (!a[i][j])fl = 0;
	cout << (fl ? "Easy" : "Not easy") << endl;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)
			{
				if (a[i][j])cout << a[i][j] << " \n"[j == n];
				else cout << "." << " \n"[j == n];
			}
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
