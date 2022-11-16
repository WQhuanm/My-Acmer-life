#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 1100;

ll a[N];
ll dp[N][N];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)//项链是个环，所以2倍使变为线性
		{
			cin >> a[i];
			a[i + n] = a[i];
		}
	ll maxn = -INF;
	for (int len = 2; len <= n; ++len)
		{
			for (int i = 1; i <= 2 * n - 1; ++i)//虽然长度最长是n，但我们要保证1到2n全部有更新，不然到后面就全部没更新过了，所以i必须到2*n-1（因为这里最短长度为2）
				{
					int j = len + i - 1;//len=j-i+1
					for (int k = i; k < j; ++k)//k介于i与j中间，表示两段合一段求最优
						{
							//这里是dp[i][k]，dp[k + 1][j]，k+1，因为是两部分（在这道题），两个dp表示之前合成这两段产生能量，后面的a[i] * a[k + 1] * a[j + 1]表示这两段合并产生能量
							dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i] * a[k + 1] * a[j + 1]);
							maxn = max(maxn, dp[i][j]);
						}
				}
		}
//最终不是打印dp[1][n]，这样表示的是以1为头，n为尾，不一定是最优解，可能是dp[i][i+n]某一个才是
	cout << maxn << endl;
	return 0;
}
