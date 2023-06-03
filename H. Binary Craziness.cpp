#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
inline int read(int &x);
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 1e6 + 10;
const int mod = 998244353;

int a[N];
void mysolve()
{
	int n,m;
	cin>>n>>m;
	int x,y;
	while(m--)
		{
			cin>>x>>y;
			a[x]++,a[y]++;
		}
	map<int,int>mp;
	for(int i=1; i<=n; ++i)mp[a[i]]++;
	vector<pii>b;
	for(auto [k,v]:mp)
		{
			b.push_back({k,v});
		}
	int ans=0;
	for(int i=0; i<(int)b.size(); ++i)
		{
			for(int j=i+1; j<(int)b.size(); ++j)
				{
					ans=(ans+b[i].second*b[j].second%mod*(b[i].first^b[j].first)%mod*(b[i].first&b[j].first)%mod*(b[i].first|b[j].first)%mod)%mod;
				}
		}
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	//cin >> t;
	//read(t);
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

inline int read(int &x)
{
	x = 0;
	char ch = 0;
	while (ch < '0' || ch > '9')ch = getchar();
	while (ch >= '0' && ch <= '9')
		{
			x = x * 10 + ch - '0';
			ch = getchar();
		}
	return x;
}
