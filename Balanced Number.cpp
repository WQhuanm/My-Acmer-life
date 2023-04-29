#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 30;
int dp[N][N][2000],bit[N];

int dfs(int len,int sum,int pos,bool limit)
{
	if(!len)return sum==0;
	if(sum<0)return 0;
	if(!limit&&dp[len][pos][sum]!=-1)return dp[len][pos][sum];
	int ans=0;
	int top=limit?bit[len]:9;
	for(int i=0; i<=top; ++i)ans+=dfs(len-1,sum+i*(len-pos),pos,limit&&i==top);
	if(!limit)return dp[len][pos][sum]=ans;
	return ans;
}
int cal(int x)
{
	if(x<0)return 1;
	int k=0;
	while(x)bit[++k]=x%10,x/=10;
	int ans=0;
	for(int i=0; i<=k; ++i)ans+=dfs(k,0,i,1);//枚举pos
	return ans-k+1;//剔除多余前导0
}
void mysolve()
{
	int l,r;
	cin>>l>>r;
	cout<<cal(r)-cal(l-1)<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	memset(dp,-1,sizeof(dp));
	while (t--)
	{
		mysolve();
	}
	system("pause");
	return 0;
}
