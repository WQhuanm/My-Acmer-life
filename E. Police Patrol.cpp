#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define int ll
typedef pair<int, int> pii;
inline void read(int &x);
const int N = 1e6+ 10;
const int mod = 998244353;

void mysolve()
{
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1; i<=n; ++i)cin>>a[i];
//	sort(a+1,a+1+n);
	sort(a.begin()+1,a.end());
	vector<pii>l(n+2),r(n+2);
	for(int i=1; i<=n; ++i)
		{
			if((i-1)%m==0)l[i].second=l[i-1].second+1,l[i].first=l[i-1].first+a[i];
			else l[i]=l[i-1];
		}
	for(int i=n; i; --i)
		{
			if((n-i)%m==0)r[i].second=r[i+1].second+1,r[i].first=r[i+1].first+a[i];
			else r[i]=r[i+1];
		}
	ll ans=INF;
	for(int i=1; i<=n; ++i)
		{
			ll tmp=(l[i].second*a[i]-l[i].first)*2+(r[i].first-r[i].second*a[i])*2;
			ans=min(ans,tmp);
		}
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}


