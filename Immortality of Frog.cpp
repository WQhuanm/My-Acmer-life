#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N =2e3;
const int mod=105225319;

int dp[N][1<<11],pre[N],l[N],r[N],p1[N],p2[N];
vector<int>sz[N];

void update(int x)
{
	for(int i=0; i<(int)sz[x].size(); ++i)
		{
			p1[i]=-1;
			for(int j=0; j<(int)sz[x+1].size(); ++j)if(sz[x][i]==sz[x+1][j])
					{
						p1[i]=j;
						break;
					}
		}
	for(int i=0; i<(int)sz[x+1].size(); ++i)
		{
			p2[i]=-1;
			for(int j=0; j<(int)sz[x].size(); ++j)if(sz[x+1][i]==sz[x][j])
					{
						p2[i]=j;
						break;
					}
		}
}

int change(int x,int j)
{
	int ans=0;
	for(int i=0; i<(int)sz[x].size(); ++i)
		{
			if(~p1[i]&&j&(1<<i))ans|=(1<<p1[i]);
			else if(p1[i]==-1&&!(j&(1<<i)))return -1;
		}
	return ans;
}

int tt=0;
void mysolve()
{
	int n;
	memset(dp,0,sizeof(dp));
	cin>>n;
	int cnt=n;
	for(int i=1; i<=n; ++i)cin>>l[i],sz[i].clear();
	for(int i=1; i<=n; ++i)
		{
			cin>>r[i];
			if(l[i]>1||r[i]<n)
				{
					cnt--;
					for(int j=l[i]; j<=r[i]; ++j)sz[j].push_back(i);
				}
		}
	cout<<"Case #"<<++tt<<": ";
	bool flag=1;
	for(int i=1; i<=n; ++i)if((int)sz[i].size()>10)
			{
				flag=0;
				break;
			}
	if(!flag)
		{
			cout<<0<<endl;
			return;
		}
	dp[0][0]=1;
	for(int i=0; i<n; ++i)
		{
			update(i);
			for(int j=0; j<(1<<(int)sz[i].size()); ++j)
				{
					int now=change(i,j);
					if(~now)
						{
							dp[i+1][now]=(dp[i+1][now]+dp[i][j])%mod;
							for(int k=0; k<(int)sz[i+1].size(); ++k)
								{
									if(p2[k]==-1||!(now&(1<<k)))dp[i+1][now|(1<<k)]=(dp[i+1][now|(1<<k)]+dp[i][j])%mod;
								}
						}
				}
		}
	int ans=pre[cnt]*dp[n][(1<<(int)sz[n].size())-1]%mod;
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	pre[0]=1;
	for(int i=1; i<=1000; ++i)pre[i]=pre[i-1]*i%mod;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
