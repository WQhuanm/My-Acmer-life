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

void mysolve()
{
	int ans=0;
	int t,n,a,b,k;
	cin>>t>>n>>a>>b>>k;
	a=min(a,t),b=min(b,t);
	if(k>n)
		{
			cout<<0<<endl;
			return;

		}
	if(n==k)
		{
			cout<<min(a,b )<<endl;
			return;
		}
	int p1=(n+1)/2,p2=n/2;
	int l=0,r=t;
	while(l<=r)
		{
			int mid=l+((r-l)>>1);
			if(mid*k<=min(mid,a)*p1+min(mid,b)*p2)ans=mid,l=mid+1;
			else r=mid-1;
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
