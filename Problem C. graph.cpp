#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 110;

vector<bitset<N>>a(N);
int n, m; //n,m为左边矩阵，最后一列是m+1

void print(vector<bitset<N>>a)//打印看目前情况
{
	cout << endl;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m + 1; ++j)cout << a[i][j] << " \n"[j == m + 1];
	cout << endl;
}

int res[N];
int gauss(vector<bitset<N>>&a)//如果原始矩阵需要多次使用，那么传入临时的
{
	int r = 1;
	for (int i = 1; r <= n && i <= m; ++i)
		{
//			r = i;
			int mx = r;
			for (int j = r + 1; j <= n; ++j)if (a[j][i] > a[mx][i])mx = j;
			if (!a[mx][i])continue; //主元为0，跳过
			if (mx != r)swap(a[mx], a[r]);
			for (int j = 1; j <= n; ++j)if (j != r)
					{
						if (a[j][i] == a[r][i])a[j] ^= a[r]; //只有j行在第i个位置的ai是1，才需要异或消去为0，否则无需操作
					}
			r++;
//			cout << r - 1 << endl;
			print(a);
		}
//	print(a);
	for (int i = r; i <= n; ++i) //无解
		if (a[i][m + 1])return -1;
	if (r <= m)
		{
			int j = 1;
			for (int i = 1; i <= n; ++i)
				if (a[j][i])
					res[i] = a[j][m + 1], j++;
			return 0; //无穷解
		}

	return 1;//最后m+1列即为解
}
int q;
void mysolve()
{
	cin >> n >> q;
	m = n;
	int x, y;
	while (q--)
		{
			cin >> x >> y;
			a[x][y] = a[y][x] = a[y][x] ^ 1;
		}
	for (int i = 1; i <= n; ++i)
		{
			int cur = 0;
			for (int j = 1; j <= n; ++j)cur ^= a[i][j];
			a[i][i] = a[i][n + 1] = cur;
		}
//	print(a);
	int ans = gauss(a);
	if (ans == -1)cout << ans << endl;
	else
		{
			for (int i = 1; i <= n; ++i)
				cout << res[i] << " \n"[i == n];
		}
}

int32_t main()
{
	freopen("in.in", "r", stdin);
	freopen("out2.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
//	system("pause");
	return 0;
}
