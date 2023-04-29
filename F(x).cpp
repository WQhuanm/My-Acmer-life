#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
#define endll            endl<<endl
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 50;
int tt=0;
int tsum;
int dp[N][20000],bit[N];
int dfs(int len,ll sum,bool limit)
{
	if(!len)return sum<=tsum;
	if(sum>tsum)return 0;
	if(!limit&&dp[len][tsum-sum]!=-1)return dp[len][tsum-sum];
	int top=limit?bit[len]:9;
	int ans=0;
	for(int i=0; i<=top; ++i)
		ans+=dfs(len-1,sum+i*(1<<(len-1)),limit&&i==top);
	if(!limit)return dp[len][tsum-sum]=ans;
	return ans;
}
void mysolve()
{

	int a,b;
	cin>>a>>b;
	int p=1;
	tsum=0;
	while(a)tsum+=p*(a%10),a/=10,p*=2;
	int tmp=b,k=0;
	while(tmp)bit[++k]=tmp%10,tmp/=10;
	cout<<"Case #"<<++tt<<": ";
	cout<<dfs(k,0,1)<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	memset(dp,-1,sizeof(dp));
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
