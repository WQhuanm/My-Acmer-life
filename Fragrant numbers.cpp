#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
const int N = 30;
string s=" 11451419191145141919";
ll add(int x,int y)
{
	ll ans=0;
	for (int i=x; i<=y; ++i)
		{
			ans=ans*10+s[i]-'0';
		}
	return ans;
}
vector<int>dp[N][N];
bool vis[N][N][5010];
int le[5010];

int32_t main()
{
	int t,n;
//	memset(le,0x3f,sizeof(le));
	for (int i=1; i<=15; ++i)for (int j=i; j<=15; ++j)
			{
				int tmp=add(i,j);
				if (tmp<=5000)
					{
						dp[i][j].push_back(tmp);
						vis[i][j][tmp]=1;
						le[tmp]=min(le[tmp],j-i+1);
					}
			}

	for (int len=2; len<=15; ++len)for (int i=1; i+len-1<=15; ++i)
			{
				int j=i+len-1;
				for (int k=i; k<j; ++k)
					{
						for (auto &x:dp[i][k])for (auto &y:dp[k+1][j])
								{
									if (x+y<=5000&&!vis[i][j][x+y])
										{
											vis[i][j][x+y]=1;
											dp[i][j].push_back(x+y);
											//	le[x+y]=min(le[x+y],j-i+1);
										}
									if (x*y<=5000&&!vis[i][j][x*y])
										{
											vis[i][j][x*y]=1;
											dp[i][j].push_back(x*y);
											//	le[x*y]=min(le[x*y],j-i+1);
										}
								}
					}
			}

	cin>>t;

	while (t--)
		{
			cin>>n;
			for (int i=1; i<=15; ++i)for (auto &x:dp[1][i])if (x<=5000&&!le[x])le[x]=i;
			if (le[n])
				{
					cout<<le[n]<<endl;
				}
			else
				{
					cout<<-1<<endl;
				}
		}
	return 0;
}
