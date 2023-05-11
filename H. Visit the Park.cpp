#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
#define endll            endl<<endl
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 3e5 + 10;
const int mod=998244853;
map<pii,int>mp;
int cnt;
int sum[N],val[N];
int a[N];

ll fastmi(ll base,ll power)
{
	ll ans=1;
	while(power)
		{
			if(power&1)ans=ans*base%mod;
			base=base*base%mod;
			power>>=1;
		}
	return ans;
}
void mysolve()
{
	int n,m,k;
	cin>>n>>m>>k;
	int x,y,w;
	while(m--)
		{
			cin>>x>>y>>w;
			if(!mp[ {x,y}]&&!mp[ {y,x}])mp[ {x,y}]=mp[ {y,x}]=++cnt;
			int tmp=mp[ {x,y}];
			sum[tmp]++,val[tmp]+=w;
		}
	for(int i=1; i<=k; ++i)cin>>a[i];
	int ans=0;
	for(int i=1; i<k; ++i)
		{
			int tmp=mp[ {a[i],a[i+1]}];
			if(!sum[tmp])
				{
					cout<<"Stupid Msacywy!"<<endl;
					return;
				}
			ans=(ans*10%mod+val[tmp]*fastmi(sum[tmp],mod-2)%mod)%mod;
		}
	cout<<ans<<endl;
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
