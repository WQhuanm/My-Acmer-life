#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 1e5 + 10;
int a[N];
double p[N];
void mysolve()
{
	int n,k;
	double m;
	cin>>n>>k>>m;
	vector<vector<double>>dp(100*k+1,vector<double>(k+1,-1));
	dp[0][0]=0;
	for (int i=1; i<=n; ++i)
		cin>>a[i]>>p[i];
	//j逆序，避免重复选a[i]，h当然也要逆序，不然你这h-1个就可能是同一个了（都是避免后效性）
	for (int i=1; i<=n; ++i)for (int j=k*100; j>=a[i]; --j)for (int h=min(i,k); h>=1; --h)
				{
					if (dp[j-a[i]][h-1]!=-1)//期望不为-1，说明有这个数
						{
							dp[j][h]=max(dp[j][h],dp[j-a[i]][h-1]+a[i]*p[i]);
						}
				}
	for (int j=100*k; j>=0; --j)
		{
			if (dp[j][k]>=m)//找到最大分数且期望大于要求m
				{
					printf("%lld %.2lf\n",j,dp[j][k]);
					return ;
				}
		}
	printf("0 0.00\n");
}
int32_t main()
{
	ll t;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
