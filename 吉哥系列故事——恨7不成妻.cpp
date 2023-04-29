#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 21;
const int mod=1e9+7;
struct node
{
	int cnt,dsum,ssum;
	node()
{
	cnt=-1,dsum=0,ssum=0;//记录B^2和与B和
}
	node(int a,int b,int c):cnt(a),dsum(b),ssum(c) {};
} dp[N][N][N];
int bit[N],pre[N];

node dfs(int len,int dsum,int ssum,bool limit)
{
	if(!len)return (dsum&&ssum?node(1,0,0):node(-1,0,0));
	if(!limit&&dp[len][dsum][ssum].cnt!=-1)return dp[len][dsum][ssum];
	node ans;
	int top=limit?bit[len]:9;
	for(int i=0; i<=top; ++i)if(i!=7)
	{
		node tmp=dfs(len-1,(dsum+i)%7,(ssum*10+i)%7,limit&&i==top);
		if(tmp.cnt!=-1)//子代有符合情况的
		{
			if(ans.cnt==-1)ans.cnt=0;
			int A=i*pre[len]%mod;
			ans.cnt=(ans.cnt+tmp.cnt)%mod;
			ans.ssum=(ans.ssum+tmp.ssum+2*tmp.dsum*A%mod+tmp.cnt*A%mod*A%mod)%mod;
			ans.dsum=(ans.dsum+tmp.dsum+tmp.cnt*A%mod)%mod;
		}
	}
	if(!limit)return dp[len][dsum][ssum]=ans;
	return ans;
}

int cal(int x)
{
	int k=0;
	while(x)bit[++k]=x%10,x/=10;
	return dfs(k,0,0,1).ssum;
}
void mysolve()
{
	int l,r;
	cin>>l>>r;
	cout<<(cal(r)-cal(l-1)+mod)%mod<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	pre[1]=1;
	for(int i=2; i<=20; ++i)pre[i]=pre[i-1]*10%mod;//预处理10^len
	while (t--)
	{
		mysolve();
	}
	system("pause");
	return 0;
}
