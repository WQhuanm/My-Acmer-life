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
const int N = 3e6 + 10;

int num[N];
int n, m;
int top;
void dfs(int p, int sum, int now)
{
	if (!p)
		{
			num[++top] = sum;
			return;
		}
	for (int i = now ; i <= m; ++i)
		{
			dfs(p - 1, (sum + i) % m, i);
		}
}

void mysolve()
{
	cin >> n >> m;
	top = 0;
	dfs(n - 1, 0, 1);
	for (int i = 1; i <= n; ++i)
		{
			int p = i % m;
			for (int j = 1; j <= top; ++j)cout << (p + m - num[j]) % m + 1 << " \n"[j == top];
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
