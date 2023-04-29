#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 20;
int dp[N][2000][N],bit[N];
int k;
int tocnt(int x)//计数lis
{
	int cnt=0;
	for(int i=0; i<10; ++i)if(x&(1<<i))cnt++;
	return cnt;
}

int update(int x,int p)
{
	for(int i=p; i<10; ++i)if(x&(1<<i))return (x^(1<<i))|(1<<p);//更新lis就是贪心从比p第一个大的数更新，表示lis为相同长度时，用p可以更小
	return x|(1<<p);//找不到比p大的，那么lis长度加1，即加了个p
}

int dfs(int len,int x,bool limit)
{
	if(!len)return tocnt(x)==k;
	if(!limit&&dp[len][x][k]!=-1)return dp[len][x][k];
	int ans=0;
	int top=limit?bit[len]:9;
	for(int i=0; i<=top; ++i)ans+=dfs(len-1,(!x&&!i?0:update(x,i)),limit&&i==top);//!x&&!i?0:update(x,i)处理第一次继承问题，即前面都是0，如果当前i为0或为其他的情况
	if(!limit)return dp[len][x][k]=ans;
	return ans;
}

int cal(int x)
{
	int len=0;
	while(x)bit[++len]=x%10,x/=10;
	return dfs(len,0,1);
}

int tt=0;
void mysolve()
{
	int l,r;
	cin>>l>>r>>k;
	cout<<"Case #"<<++tt<<": ";
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
