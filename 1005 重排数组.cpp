#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
typedef pair<int, int> pii;
const int N = 2000+20;

int mycnt(int x)
{
	int ans=0;
	while(x)ans++,x/=10;
	return ans;
}
const int mod=1e9+7;
pii a[N];
int pre[N],A[N];//pre表示10的几次幂，A是排列数
void mysolve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)cin>>a[i].first,a[i].second=mycnt(a[i].first);
	int ans=0;
	for(int i=1; i<=n; ++i)
		{
			vector<int>dp(n+1);//讨论当前元素a[i]在所有排列的总贡献，先给他处理下dp
			dp[0]=1;
			for(int j=1,p=0; j<=n; ++j)if(i!=j)//背包优化
					{
						p++;//p表示处理了p个数
						for(int k=p; k; --k)dp[k]=(dp[k]+dp[k-1]*pre[a[j].second]%mod)%mod;
					}
			for(int j=0; j<n; ++j)//枚举ai前面有几个元素的情况时的贡献
				ans=(ans+a[i].first*A[n-j-1]%mod*dp[j]%mod*A[j]%mod)%mod;
		}
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	pre[0]=1,A[0]=1;
	for(int i=1; i<=2000; ++i)pre[i]=pre[i-1]*10%mod,A[i]=A[i-1]*i%mod;
	mysolve();
	system("pause");
	return 0;
}
