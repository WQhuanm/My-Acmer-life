#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 5e4 + 10;

int tree[N * 10][15], pos[15], a[N][15];//pos记录每一个排列第i层的下标j
int n, m;
int num;
int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		{
			cin >> n >> m;
			num = 0;
			for (int i = 0; i <= n * m; ++i)memset(tree[i], 0, sizeof(tree[i]));//案例t可能太大，如果每次都是全部归0，会被tle
			for (int i = 1; i <= n; ++i)
				{
					for (int j = 1; j <= m; ++j)
						{
							cin >> a[i][j];
							pos[a[i][j]] = j;
						}
					int p = 0;
					for (int i = 1; i <= m; ++i)//建字典树
						{
							if (!tree[p][pos[i]])tree[p][pos[i]] = ++num;//在层数p建立下标为j=pos[i]的边
							p = tree[p][pos[i]];
						}
				}
			for (int i = 1; i <= n; ++i)
				{
					int ans = 0, p = 0;
					for (int j = 1; j <= m; ++j)
						{
							if (tree[p][a[i][j]])ans++, p = tree[p][a[i][j]];
							else break;
						}
					cout << ans;
					if (i == n)cout << endl;
					else cout << ' ';
				}
		}
	return 0;
}

