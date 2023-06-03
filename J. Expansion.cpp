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
const int N = 3e5 + 10;
const int mod = 998244353;
int a[N],b[N];
ll sum[N];
void mysolve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)cin>>a[i],sum[i]=a[i]+sum[i-1];
	if(sum[n]<0||sum[1]<0)
		{
			cout<<-1<<endl;
			return;
		}
	int ans=n,res=sum[1];//首先，每个都是要经过一次，答案>=n
	ll mx=sum[1];//枚举当前使用的资源最大点
	for(int i=1; i<n; ++i)
		{
			mx=max(sum[i],mx);
			if(res+sum[i+1]<0)
				{
					if(mx<=0)
						{
							cout<<-1<<endl;
							return;
						}
					int cnt=(-(res+sum[i+1])+mx-1)/mx;
					ans+=cnt;
					res+=sum[i+1]+cnt*mx;
				}
			else res+=sum[i+1];
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

