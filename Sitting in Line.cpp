#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll               long long
const int INF = 0x3f3f3f3f3f3f3f3f;         //int型的INF
const int N = 20;

int dp[2][1<<18][N];
int a[N],p[N],b[N];
int tt=0;
void mysolve()
{
	int n;
	cin>>n;
	memset(dp,0x3f,sizeof(dp));
	vector<int>a1,vis(n+1);
	set<int>b1;
	for(int i=0; i<n; ++i)b1.insert(i);
	for(int i=0; i<n; ++i)
		{
			cin>>a[i]>>p[i];
			if(p[i]!=-1)
				{
					b[p[i]]=a[i];
					b1.erase(p[i]);
					vis[p[i]]=1;
				}
			else
				{
					a1.push_back(a[i]);
				}
		}
	while(!b1.empty())
		{
			int i=*b1.begin();
			b1.erase(i);
			b[i]=a1.back();
			a1.pop_back();
		}

	dp[0][0][0]=0;
	int ans=-INF;
	int t=0;
	for(int i=1; i<=n; ++i)
		{
			t^=1;
			if(!vis[i-1])
				{
					for(int j=0; j<(1<<n); ++j)
						{
							int cnt=0;
							for(int j1=0; j1<n; ++j1)if(j&(1<<j1))cnt++;
							if(cnt!=i-1)continue;
							for(int k=0; k<n; ++k)if(dp[t^1][j][k]!=INF)
									{
										for(int h=0; h<n; ++h)if(!vis[h]&&(j&(1<<h))==0)
												{
													if(dp[t][j|(1<<h)][h]==INF)dp[t][j|(1<<h)][h]=dp[t^1][j][k]+(i==1?0:b[h]*b[k]);
													else dp[t][j|(1<<h)][h]=max(dp[t][j|(1<<h)][h],dp[t^1][j][k]+b[h]*b[k]);
													if(i==n)ans=max(ans,dp[t][j|(1<<h)][h]);
												}
									}
						}
				}
			else
				{
					for(int j=0; j<(1<<n); ++j)
						{
							int cnt=0;
							for(int j1=0; j1<n; ++j1)if(j&(1<<j1))cnt++;
							if(cnt!=i-1)continue;
							for(int k=0; k<n; ++k)if(dp[t^1][j][k]!=INF)
									{
										int h=i-1;
										if(dp[t][j|(1<<h)][h]==INF)dp[t][j|(1<<h)][h]=dp[t^1][j][k]+(i==1?0:b[h]*b[k]);
										else dp[t][j|(1<<h)][h]=max(dp[t][j|(1<<h)][h],dp[t^1][j][k]+b[h]*b[k]);
										if(i==n)ans=max(ans,dp[t][j|(1<<h)][h]);
									}
						}

				}
		}
	cout<<"Case #"<<++tt<<":"<<endl;
	cout<<ans<<endl;
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
