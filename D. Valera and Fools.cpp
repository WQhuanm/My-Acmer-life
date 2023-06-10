#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 3e3 + 10;
const int mod = 998244353;

int a[N],mx[N],f[N];//最速杀死前面i人需要几轮
bool vis[N];
void mysolve()
{
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; ++i)cin>>a[i],f[i]=-1;
	for(int i=n; i; --i)mx[i]=max(mx[i+1],a[i]);
	for(int i=2; i<=n; i++)if(a[i-1]==100&&(vis[i-2]||!a[i-2]))vis[i]=1;
	for(int i=1; i<=n; ++i)
		{
			if(f[i-1]==-1)break;
			if(vis[i])f[i]=f[i-1];
			else
				{
					if(mx[i+1])f[i]=f[i-1]+1;
					if(i>=2&&a[i-1]&&!vis[i-1]&&mx[i])f[i]=f[i-2]+1;
					if(f[i]==-1)f[i]=k+1;
					if(mx[i])for(int j=1; j<i; ++j)if(!vis[j]&&mx[j+1]<100&&a[j])f[i]=min(f[i],f[j-1]+i-j);
				}
			if(f[i]>k)
				{
					f[i]=-1;
					break;
				}
		}
	int ans=0;
	for(int i=1; i<=n; ++i)
		{
			if(~f[i-1])
				{
					if(!vis[i])
						{
							ans++;
							if(a[i]&&mx[i+1]<100)
								{
									int p=k-f[i-1];
									ans+=min(n-i,p);
								}
						}
				}
			else break;
		}
	if(f[n]!=-1)ans++;
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
