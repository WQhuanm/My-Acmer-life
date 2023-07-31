#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
#define int              long long
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 3e5 + 10;
const int M = 40;
const int p = 0x04C11DB7;

bool a[N << 3];
ll b[N << 3];
int n1, n2, n, m;

void print(vector<bitset<M>>a)//打印看目前情况
{
	cout << endl;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m + 1; ++j)cout << a[i][j] << " \n"[j == m + 1];
	cout << endl;
}

int gauss(vector<bitset<M>>&a)//如果原始矩阵需要多次使用，那么传入临时的
{
	int r = 1;
	for (int i = 1; r <= n && i <= m; ++i)
		{
			int mx = r;
			for (int j = r + 1; j <= n; ++j)if (a[j][i] > a[mx][i])mx = j;
			if (!a[mx][i])continue; //主元为0，跳过
			if (mx != r)swap(a[mx], a[r]);
			for (int j = 1; j <= n; ++j)if (j != r)
					{
						if (a[j][i] == a[r][i])a[j] ^= a[r]; //只有j行在第i个位置的ai是1，才需要异或消去为0，否则无需操作
					}
			r++;
//			print(a);
		}
	for (int i = r; i <= n; ++i) //无解
		if (a[i][m + 1])return -1;

	if (r <= m)return 0; //无穷解

	return 1;
}

void mysolve()
{
	n = m = 32;
	cin >> n1 >> n2;
	int x;
	int tot = 0;
	for (int i = 1; i <= n1; ++i)
		{
			cin >> x;
			for (int j = 7; ~j; --j)a[++tot] = (x >> j) & 1;
		}
	for (int i = 1; i <= 32; ++i)b[++tot] = 1ll << (i - 1);
	for (int i = 1; i <= n2; ++i)
		{
			cin >> x;
			for (int j = 7; ~j; --j)a[++tot] = (x >> j) & 1;
		}
	vector<int>c;
	for (int i = 0; i < 32; ++i)if ((p >> i) & 1)c.push_back(32 - i);

	for (int i = 1; i <= tot; ++i)
		{
			for (auto v : c)a[i + v] ^= a[i], b[i + v] ^= b[i];
		}
	vector<bitset<M>>v(40);
	for (int i = 1; i <= 32; ++i)
		{
			int cur = b[tot + i] ^ (1ll << (i - 1));
			for (int j = 1; j <= 32; ++j)if (cur >> (j - 1) & 1)v[i][j] = 1;
			v[i][m + 1] = a[tot + i];
		}
	int fl = gauss(v);
	if (fl == -1)cout << -1 << endl;
	else
		{
			ll ans = 0;
			for (int i = 1; i <= 32; ++i)
				if (v[i][m + 1] & 1)ans |= 1ll << (32 - i);
			cout << ans << endl;
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
