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
int dp[20][20],bit[20];

int dfs(int len,int p,bool limit,bool flag)
{
	if(!len)return 1;
	if(!limit&&dp[len][p]!=-1)return dp[len][p];
	int top=limit?bit[len]:9;
	int ans=0;
	for(int i=0; i<=top; ++i)
		{
			if(!i&&flag)ans+=dfs(len-1,i,limit&&i==top,flag);
			else if(i&&p%i==0)ans+=dfs(len-1,i,limit&&i==top,0);
		}

	if(!limit)return dp[len][p]=ans;
	return ans;
}

int cal(int x)
{
	if(x<0)return 0;
	int k=0;
	while(x)bit[++k]=x%10,x/=10;
	return dfs(k,0,1,1);
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
