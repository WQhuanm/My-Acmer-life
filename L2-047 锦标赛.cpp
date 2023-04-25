#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 2e5 + 10;
int a[20][N],id[20][N],ans[N];
void mysolve()
{
	int k;
	cin>>k;
	bool flag=1;
	for(int i=1; i<=k; ++i)for(int j=1; j<=(1<<(k-i)); ++j)
	{
		cin>>a[i][j];
		if(i==1)ans[2*j-1]=a[i][j],id[i][j]=2*j;
		else
		{
			if(a[i][j]<a[i-1][j*2-1]&&a[i][j]<a[i-1][j*2])flag=0;
			else
			{
				if(a[i][j]>=a[i-1][j*2-1])ans[id[i-1][2*j-1]]=a[i][j],id[i][j]=id[i-1][j*2];
				else ans[id[i-1][2*j]]=a[i][j],id[i][j]=id[i-1][j*2-1];
			}
			a[i][j]=max({a[i][j],a[i-1][2*j-1],a[i-1][2*j]});
		}
	}
	int maxn;
	cin>>maxn;
	if(maxn<a[k][1])flag=0;
	else ans[id[k][1]]=maxn;
	if(!flag)cout<<"No Solution"<<endl;
	else
	{
		for(int i=1; i<=(1<<k); ++i)
		{
			if(i>1)cout<<" ";
			cout<<ans[i];
		}
	}
	
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
	{
		mysolve();
	}
	system("pause");
	return 0;
}
