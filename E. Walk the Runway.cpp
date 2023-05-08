#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 5e3 + 10;

void mysolve()
{
	int n,m;
	cin>>n>>m;
	vector<int>p(m);
	vector<vector<int>>a(n,vector<int>(m));
	for(int i=0; i<m; ++i)cin>>p[i];
	for(int i=0; i<n; ++i)for(int j=0; j<m; ++j)cin>>a[i][j];
	vector<bitset<N>>bs(m);
	for(int i=0; i<m; ++i)bs[i].set();//初始都是比其他人大，都为1
	for(int i=0; i<n; ++i)//枚举每个城市
		{
			vector<int>id(m);
			for(int j=0; j<m; ++j)id[j]=j;
			sort(id.begin(),id.end(),[&](int x,int y)//按照当前城市的值给每个模特排序
			{
				return a[i][x]<a[i][y];
			});
			bitset<N>tmp;//记录那些比当前j值小的模特
			for(int j=0; j<m; ++j)
				{
					int k=j;
					while(k<m-1&&a[i][id[k]]==a[i][id[k+1]])k++;
					for(int t=j; t<=k; ++t)bs[id[t]]&=tmp;//显然，在该城市中，j只比tmp中为1的模特值大，所以&tmp（这个影响是永久的）
					for(int t=j; t<=k; ++t)tmp.set(id[t]);
					j=k;
				}
		}
	vector<int>dp(m);
	vector<int>id(m);
	for(int j=0; j<m; ++j)id[j]=j;
	sort(id.begin(),id.end(),[&](int x,int y)//可以取任意城市的值来排序获得没有比别人大的点，以他为起点进行dp
	{
		return a[0][x]<a[0][y];
	});
	for(auto v:id)
		{
			dp[v]=p[v];
			for(int i=0; i<m; ++i)if(bs[v][i])//枚举比他一直比他小的模特
					{
						dp[v]=max(dp[v],dp[i]+p[v]);
					}
		}
	cout<<*max_element(dp.begin(),dp.end())<<endl;
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
