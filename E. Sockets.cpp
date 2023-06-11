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
		
int a[N],b[N],c[N];
void mysolve()
{
	int n,m;
	cin>>n>>m;
	vector<pii>p(m);
	multiset<int>s;
	for(int i=1; i<=n; ++i)
		{
			cin>>a[i];
			s.insert(a[i]);
		}
	for(int i=0; i<m; ++i)cin>>p[i].first,p[i].second=i+1;
	sort(p.begin(),p.end());
	unordered_map<int,vector<int>>mp;
	int u=0;
	for(auto [v,k]:p)
		{
			int cnt=0;
			while(v)
				{
					if(s.count(v))
						{
							s.erase(s.find(v));
							mp[v].push_back(k);
							u+=cnt;
							b[k]=cnt;
							break;
						}
					if(v==1)break;
					cnt++,v=(v+1)/2;
				}
		}
	int ans=0;
	for(int i=1; i<=n; ++i)
		{
			if(!mp[a[i]].empty())
				{
					c[i]=mp[a[i]].back(),mp[a[i]].pop_back();
					ans++;
				}
		}
	cout<<ans<< " "<<u<<endl;
	for(int i=1; i<=m; ++i)cout<<b[i]<<" \n"[i==m];
	for(int i=1; i<=n; ++i)cout<<c[i]<<" \n"[i==n];
		
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
