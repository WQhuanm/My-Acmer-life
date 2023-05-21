#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 3e5 + 10;
int dp[N][30],lg[N];
void mysolve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; ++i)cin>>dp[i][0];//dp[i][0]=[i,i-1+1]=[i,i]
	lg[1]=0;
	for(int i=2; i<=n; ++i)lg[i]=lg[i>>1]+1;//预处理lg
	for(int j=1; j<=lg[n]; ++j)for(int i=1; i+(1<<j)-1<=n; ++i)dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);//预处理st表
	int l,r;
	while(m--)
		{
			cin>>l>>r;
			int k=lg[r-l+1];
			cout<<max(dp[l][k],dp[r-(1<<k)+1][k])<<endl;//区间查询
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
