#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;

bool judge(pii a, pii b)
{
	if(a.first>b.first)swap(a,b);
	return a.second>b.first&&a.second<b.second;
}

void mysolve()
{
	int n,k;
	cin>>n>>k;
	vector<bool>vis(2*n+1);
	vector<pii>ans;
	int x,y;
	for(int i=1; i<=k; ++i)
		{
			cin>>x>>y;
			if(x>y)swap(x,y);
			ans.push_back({x,y});
			vis[x]=vis[y]=1;
		}
	vector<int>v;
	for(int i=1; i<=2*n; ++i)if(!vis[i])v.push_back(i);
	int sz=(int)v.size()/2;
	for(int i=0; i<sz; ++i)ans.push_back({v[i],v[i+sz]});
	int res=0;
	for(int i=0; i<(int)ans.size(); ++i)for(int j=i+1; j<(int)ans.size(); ++j)res+=judge(ans[i],ans[j]);
	cout<<res<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
