#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 3e5 + 10;
int dp[N];
int a[N],ans[N],maxn[N],f[N];
void mysolve()
{
	int n;
	cin>>n;
	for (int i=1; i<=n; ++i)cin>>a[i],dp[i]=-1,maxn[i]=f[i]=0;
	dp[n+1]=maxn[n+1]=f[n+1]=0;
	for (int i=n; i>=1; --i)
		{
			if (i==n)
				{
					if (a[i]==0)dp[i]=1;
				}
			else
				{
					if (dp[i+1]!=-1)//区间连续时
						{
							if (a[i]==dp[i+1])ans[i]=0;
							else ans[i]=1;
						}
					else
						{
							if (a[i]<=f[i+1])ans[i]=1;
							else ans[i]=2;
						}
					if (dp[min(n+1,i+a[i]+1)]!=-1&&i+a[i]<=n)dp[i]=dp[min(n+1,i+a[i]+1)]+1;//更新dp时，满足i+a[i]+1不超区间再加上他也是连续即可更新，否则是-1
				}
			maxn[i]=max(maxn[i+1],dp[i]);//更新maxn就是取(i,n)中的dp最大值
			f[i]=maxn[i+1]+1;//更新f就是你要么修改后最多加一步，要最多，这一步就到max。要么不修改
			if (a[i]+i+1<=n)f[i]=max(f[i],1+f[i+a[i]+1]);
		}
	for (int i=1; i<n; ++i)cout<<ans[i]<<" \n"[i==n-1];
}
int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
