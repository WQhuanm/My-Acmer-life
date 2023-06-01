#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
typedef pair<int,int> pii;

int a[N],mn[N];
void mysolve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)cin>>a[i],mn[i]=0;
	stack<pii>s;
	s.push({a[1],1});
	for(int i=2; i<=n; ++i)
		{
			if(!s.empty())
				{
					while(!s.empty()&&s.top().first<a[i])
						{
							pii u=s.top();
							s.pop();
							mn[u.second]=i;
						}
				}
			s.push({a[i],i});
		}
	unordered_map<int,int>mp;
	for(int i=1; i<=n; ++i)
		{
			if(mn[i])
				{
					mp[mn[i]-i]++;
					i=mn[i]-1;
				}
			else
				{
					mp[n-i+1]++;
					break;
				}
		}
	vector<int>v;
	for(pii u:mp)//二进制背包
		{
			int cnt=u.second;
			int t=1;
			while(t<=cnt)
				{
					v.push_back(u.first*t);
					cnt-=t,t<<=1;
				}
			if(cnt)v.push_back(u.first*cnt);
		}
	bitset<N/2>dp;
	dp.reset();
	dp.set(0);
	for(auto k:v)
		{
			dp=dp|(dp<<k);
			if(dp[n/2])
				{
					cout<<"Yes"<<endl;
					return;
				}
		}
	cout<<"No"<<endl;
}

signed main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t;
	cin>>t;
	while(t--)
		{
			mysolve();
		}
}
