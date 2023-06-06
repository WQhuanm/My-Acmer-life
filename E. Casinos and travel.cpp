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
const int N = 1e5 + 10;
const int mod = 1e9+7;

ll fastmi(ll base, ll power)
{
	ll ans = 1;
	while (power)
		{
			if (power & 1)ans=ans*base%mod;
			base=base*base%mod;
			power >>=1;
		}
	return ans;
}

int in[N];
void mysolve()
{
	int n;
	cin>>n;
	if(n==1)
		{
			cout<<1<<endl;
			return;
		}
	int x,y;
	int cnt=n;
	for(int i=1; i<n; ++i)
		{
			cin>>x>>y;
			in[x]++,in[y]++;
			if(in[x]==2)cnt--;
			if(in[y]==2)cnt--;
		}
	int ans=cnt*fastmi(2,n-cnt+1)%mod+(n-cnt)*fastmi(2,n-cnt)%mod;
	cout<<ans%mod;
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
