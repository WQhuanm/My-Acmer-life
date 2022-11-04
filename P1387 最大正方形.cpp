#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 110;
//题目描述
//在一n×m 的只包含 0 和 1 的矩阵里找出一个不包含 0 的最大正方形，输出边长。
//二维前缀和，符合的正方形无疑问其所有格子和为l*l(因为有l*l个1),那么我们只需要遍历<=min(n,m)的边长，找到符合数字和为l*l的正方形就好
int a[N][N];
int sum[N][N];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			{
				cin >> a[i][j];
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
			}
	int len = min(n, m);
	int l = 2;
	int ans = 1;
	while (l <= len)
		{
			for (int i = l; i <= n; ++i)for (int j = l; j <= m; ++j)
					{
						if (sum[i][j] - sum[i - l][j] - sum[i][j - l] + sum[i - l][j - l] == l * l)ans = max(ans, l);
					}
			l++;
		}
	cout << ans << endl;
}
