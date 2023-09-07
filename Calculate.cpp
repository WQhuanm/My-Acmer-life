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
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int lg = 40;

int pre[N][50], k[N], b[N];
ll fk[N][50], fval[N][50];
bool vis[N];
vector<int>edge[N];

int n, q;
void mysolve()
{
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)cin >> k[i];
	for (int i = 1; i <= n; ++i)cin >> b[i];
	for (int i = 1; i <= n; ++i)cin >> pre[i][0], fk[i][0] = k[pre[i][0]], fval[i][0] = b[pre[i][0]];
	for (int j = 1; j < lg; ++j)
		for (int i = 1; i <= n; ++i)
			{
				pre[i][j] = pre[pre[i][j - 1]][j - 1], fk[i][j] = fk[i][j - 1] * fk[pre[i][j - 1]][j - 1] % mod;
				fval[i][j] = (fval[i][j - 1] * fk[pre[i][j - 1]][j - 1] % mod + fval[pre[i][j - 1]][j - 1]) % mod;
			}
	int x, l, y;
	while (q--)
		{
			cin >> x >> l >> y;
			ll ans = y;
			for (int i = lg; ~i; --i)if (l >= 1ll << i)
					{
						ans = (ans * fk[x][i] % mod + fval[x][i]) % mod;
						x = pre[x][i];
						l -= 1ll << i;
					}
			cout << ans << endl;
		}
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
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
