#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int N = 2e5 + 10;

bitset<N>dp;
int cnt[N];
int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, n, m, x;
	cin >> t;
	while (t--)
		{
			cin >> n >> m;
			for (int i = 0; i <= m; ++i)dp[i] = 0, cnt[i] = 0;
			dp[0] = 1;//0位初始为1，用于进位
			while (n--)
				{
					cin >> x;
					if (x <= m)
						cnt[x]++;//先存储值
				}
			for (int i = m; i >= 1 && !dp[m]; --i)//如果dp[m]=1,那么不用继续了，最大值m已经得到
				{
					if (cnt[i])
						{
							int tmp = 1;//二进制优化
							while (cnt[i])
								{
									if (cnt[i] >= tmp)
										{
											dp |= dp << i * tmp;//每次或运算（|）位移i*tmp位，表示当前dp所有数加上i*tmp
											cnt[i] -= tmp;
											tmp <<= 1;
										}
									else
										{
											dp |= dp << i * cnt[i];
											cnt[i] = 0;
										}
								}
						}
				}
			for (int i = m; i >= 0; --i)
				{
					if (dp[i])
						{
							cout << i << endl;
							break;
						}
				}
		}
	return 0;
}
