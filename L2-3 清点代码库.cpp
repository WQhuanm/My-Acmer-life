#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 2e5 + 10;
map<vector<int>,int>mp;
vector<pair<int,vector<int>>>ans;
void mysolve()
{
	int n,m,x;
	cin>>n>>m;
	for(int i=1; i<=n; ++i)
		{
			vector<int>tmp;
			for(int j=1; j<=m; ++j)cin>>x,tmp.push_back(x);
			mp[tmp]++;
		}
	for(auto &k:mp)ans.push_back({-k.second,k.first});
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(auto k:ans)
		{
			cout<<-k.first;
			for(auto v:k.second)cout<<" "<<v;
			cout<<endl;
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
