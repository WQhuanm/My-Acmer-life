#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin>>t;
	while (t--)
		{
			int n,x;
			cin>>n;
			vector<int>zh,fu;//他们没人放0，用于确认是否正负数都存在
			for (int i=1; i<=n; ++i)
				{
					cin>>x;
					if (x>0)zh.push_back(x);
					else if (x<0)fu.push_back(x);
				}
			if (zh.empty()||fu.empty())//正负必须同时存在
				{
					cout<<"NO"<<endl;
					continue;
				}
			sort(zh.begin(),zh.end());
			sort(fu.begin(),fu.end());
			int i=0,j=0;
			int maxn=zh.back()-fu.front(),sum=0;
			vector<int>ans;
			while (i<(int)zh.size()&&j<(int)fu.size())
				{
					if (zh[i]+sum<maxn)//贪心加正数
						{
							ans.push_back(zh[i]);
							sum+=zh[i++];
						}
					else//不行补一个较大负数
						{
							ans.push_back(fu[j]);
							sum+=fu[j++];
						}
				}
			while (i<(int)zh.size())ans.push_back(zh[i++]);
			while (j<(int)fu.size())ans.push_back(fu[j++]);
			cout<<"YES"<<endl;
			while ((int)ans.size()<n)ans.push_back(0); //前面是没有存入0的，所以缺的话那就是0了
			for (auto &k:ans)cout<<k<<" ";
			cout<<endl;
		}
	return 0;
}
