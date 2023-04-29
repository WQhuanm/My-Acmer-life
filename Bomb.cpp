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
int dp[30][2];
int bits[30];
int dfs(int len,bool pre,bool limit)
{
	if(!len)return 1;
	if(!limit&&dp[len][pre]>=0)return dp[len][pre];
	ll ans=0;
	int top=limit?bits[len]:9;
	for(int i=0; i<=top; ++i)
		{
			if(pre&&i==9)continue;
			ans+=dfs(len-1,i==4,limit&&(i==top));
		}
	if(!limit)return dp[len][pre]=ans;
	return ans;
}
void mysolve()
{
	int n;
	cin>>n;
	int k=0;
	int tmp=n;
	while(tmp)bits[++k]=tmp%10,tmp/=10;
	memset(dp,-1,sizeof(dp));
	cout<<n-dfs(k,0,1)+1<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
