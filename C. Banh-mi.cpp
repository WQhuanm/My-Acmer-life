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
const int mod = 1e9+7;
ll a[N],t[N],pre[N],sum[N];
int n;

inline void add(int x,ll w)
{
	for(int i=x; i<=n; i+=i&-i)t[i]=(t[i]+w);
}

inline ll ask(int x)//区间[1,x]的和
{
	ll ans=0;
	for (int i=x; i; i-=i&-i)ans=(ans+t[i]);
	return ans;
}

void mysolve()
{
	int q;
	string s;
	cin>>n>>q>>s;
	s="$"+s;
	for(int i=1; i<=n; ++i)if(s[i]=='1')add(i,1);
	int l,r;
	while(q--)
		{
			cin>>l>>r;
			int cnt=ask(r)-ask(l-1);
			if(!cnt)
				{
					cout<<0<<endl;
					continue;
				}
			int len=r-l;
			ll ans=(sum[len]-(cnt==len+1?0:sum[len-cnt])+mod)%mod;
			cout<<ans<<endl;
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	//cin >> t;
	pre[0]=1;
	for(int i=1; i<=N-5; ++i)pre[i]=pre[i-1]*2%mod;
	sum[0]=1;
	for(int i=1; i<=N-6; ++i)sum[i]=(sum[i-1]+pre[i])%mod;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
