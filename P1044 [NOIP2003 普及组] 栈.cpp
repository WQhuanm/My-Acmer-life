#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;
const int N = 20;

int a[N][N], ans[N][N];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)//求i个数的情况
		{
			a[i][i] = a[i][i - 1] = ans[i - 1][i - 1];//第i个放最后一位，或者倒数第二位的情况等于前面i-1所有可能情况
			a[i][1] = 1;//第i个数放第一个，后面都是固定的，情况1种，这个放a[i][i] = a[i][i - 1] = ans[i - 1][i - 1];后面是因为前面得到的可能更改a[i][1]
			for (int j = 2; j <= i - 2; ++j)a[i][j] = ans[i - 1][j];//j从i放第二位到倒数第三位处理
			for (int j = 1; j <= i; ++j)ans[i][j] = ans[i][j - 1] + a[i][j];//处理求和
		}
	cout << ans[n][n];
	return 0;
}
