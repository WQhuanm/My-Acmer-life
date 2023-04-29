#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 150;
const int mod=1e8;
int dp[N][N][N];
string s;
int bit[N];
int ls;

bool check(char c,int x,int y)
{
	if(c=='/'&&x<y)return 1;
	else if(c=='-'&&x==y)return 1;
	else if(c=='\\'&&x>y)return 1;
	return 0;
}
int dfs(int len,int p,bool limit,int last)
{
	if(!len)return p==ls;
	if(!limit&&dp[len][p][last]!=-1)return dp[len][p][last]%mod;
	int top=limit?bit[len]:9;
	int ans=0;
	for(int i=0; i<=top; ++i)
		{
			if(last==10)ans+=dfs(len-1,p,limit&&i==top,i==0?10:i),ans%=mod;
			else
				{

					if(p<ls&&check(s[p+1],last,i))
						ans+=dfs(len-1,p+1,limit&&i==top,i),ans%=mod;
					else if(check(s[p],last,i))
						ans+=dfs(len-1,p,limit&&i==top,i),ans%=mod;
				}
		}
	if(!limit)return dp[len][p][last]=ans%mod;
	return ans%mod;
}

int cal(string a,bool flag)
{
	int k=0;
	int len=0;
	while(len<(int)a.size()-1&&a[len]=='0')len++;
	for(int i=(int)a.size()-1; i>=len; --i)bit[++k]=a[i]-'0';
	if(flag)
		{
			int p=1;
			while(bit[p]==0&&p<k)p++;
			if(bit[p]==0)return 0;
			for(int i=p; i>=1; --i)bit[i]=(bit[i]-1+10)%10;
		}
	return dfs(k,0,1,10);
}

void mysolve()
{
	while(cin>>s)
		{
			memset(dp,-1,sizeof(dp));
			ls=(int)s.size();
			s=' '+s;
			string a,b;
			cin>>a>>b;
			printf("%08lld\n",(cal(b,0)-cal(a,1)+mod)%mod);
		}
}

int32_t main()
{
	ll t=1;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
