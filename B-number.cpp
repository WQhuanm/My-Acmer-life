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
const int N = 2e5 + 10;
int dp[20][5][20];
int bit[20];

int dfs(int len,int pre,bool jud,bool limit,int mod)
{
	if(len==0)return (pre==2&&jud);
	if(!limit&&dp[len][pre][mod]>=0)return dp[len][pre][mod];
	int ans=0;
	int top=limit?bit[len]:9;
	for(int i=0; i<=top; ++i)
		{
			if(!pre||(pre==1&&i!=3))ans+=dfs(len-1,i==1,(mod*10+i&&(mod*10+i)%13==0),limit&&(i==top),(mod*10+i)%13);
			else ans+=dfs(len-1,2,((mod*10+i)%13==0),limit&&(i==top),(mod*10+i)%13);
		}
	if(!limit)return dp[len][pre][mod]=ans;
	return ans;
}
void mysolve()
{
	int n;
	while(cin>>n)
		{
			int tmp=n,k=0;
			while(tmp)bit[++k]=tmp%10,tmp/=10;
			memset(dp,-1,sizeof(dp));
			cout<<dfs(k,0,0,1,0)<<endl;
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
