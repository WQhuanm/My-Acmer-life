#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 2e5 + 10;
vector<int> getelement(int x)//暴力枚举因子
{
	vector<int>ans;
	for(int i=1; i*i<=x; ++i)if(x%i==0)
	{
		ans.push_back(i);
		if(i*i!=x)ans.push_back(x/i);
	}
	sort(ans.begin(),ans.end());
	return ans;
}
void mysolve()
{
	map<int,int>cnt;
	int n,x;
	cin>>n;
	for(int i=1; i<=n; ++i)cin>>x,cnt[x]++;
	int ans=0;
	for(auto [x,k]:cnt)
	{
		ans+=k*(k-1)*(k-2);//自身贡献
		if(x<=1e6)
		{
			vector<int>tmp=getelement(x);
			for(auto v:tmp)if(v!=1&&x%v==0&&cnt.count(x/v)&&cnt.count(x*v))ans+=cnt[x/v]*k*cnt[x*v];//取下限
		}
		else for(int i=2; i*x<=1e9; ++i)if(x%i==0&&cnt.count(x/i)&&cnt.count(x*i))ans+=cnt[x/i]*k*cnt[x*i];//取上限
	}
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
