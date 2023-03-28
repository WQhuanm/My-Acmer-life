#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int N = 1e4 + 10;
const int mod=1e9+7;
int n,m;
set<string>s;
map<string,int>mp;
int cnt;
vector<int>in[N];
int dp[N][N];
void dfs(string p,int num)
{
	if (num==n)//求出每一列可能的状态
		{
			s.insert(p);
			mp[p]=++cnt;//mp把字符串转化为数字
			return;
		}
	for (int i=0; i<3; ++i)
		{
			char c=i+'0';
			if (num>0&&p[num-1]==c)continue;
			string tmp=p+c;
			dfs(tmp,num+1);
		}
}
bool myjud(string a,string b)//判断是否可以相邻
{
	for (int i=0; i<n; ++i)
		{
			if (a[i]==b[i])return 0;
		}
	return 1;
}

int main()
{
	cin>>n>>m;
	dfs("",0);
	for (auto &a:s)for (auto &b :s)
			{
				if (myjud(a,b))in[mp[a]].push_back(mp[b]);//求出每个状态可以与他相邻的状态
			}
	for (int i=1; i<=cnt; ++i)dp[1][i]=1;//显然，只有1列，每个状态只有一种情况
	for (int i=2; i<=m; ++i)for (int j=1; j<=cnt; ++j)for (auto &k:in[j])dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;//求和
	int ans=0;
	for (int i=1; i<=cnt; ++i)ans=(ans+dp[m][i])%mod;
	cout<<ans<<endl;
	return 0;
}
