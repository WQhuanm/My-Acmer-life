#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long

const int N = 510;
const int mod = 998244353;

int dp[N][N],b[N];
ll sum[N];
void mysolve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j)cin>>dp[i][j];
	for(int i=1; i<=n; ++i)cin>>b[i];
	vector<int>v;
	v.push_back(b[n]);
	for(int i=n-1; i; --i)
		{
			int k=b[i];
			for(auto f:v)
				{
					for(auto t:v)if(f!=t)
							{
								dp[f][k]=min(dp[f][k],dp[f][t]+dp[t][k]);
							}
//					for(auto t:v)if(f!=t)
//							{
//								dp[f][k]=min(dp[f][k],dp[f][t]+dp[t][k]);
//							}
				}
			for(auto f:v)
				{
					for(auto t:v)if(f!=t)
							{
								dp[k][f]=min(dp[k][f],dp[k][t]+dp[t][f]);
							}
//					for(auto t:v)if(f!=t)
//							{
//								dp[k][f]=min(dp[k][f],dp[k][t]+dp[t][f]);
//							}
				}
			for(auto f:v)
				{
					for(auto t:v)if(f!=t)
							{
								dp[f][t]=min(dp[f][t],dp[f][k]+dp[k][t]);
							}
//					for(auto t:v)if(f!=t)
//							{
//								dp[f][t]=min(dp[f][t],dp[f][k]+dp[k][t]);
//							}
				}
			v.push_back(k);
			for(auto f:v)for(auto t:v)if(f!=t)
						sum[i]+=dp[f][t];
		}
	for(int i=1; i<=n; ++i)cout<<sum[i]<<" \n"[i==n];

}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

