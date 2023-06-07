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

int a[N];
ll sum[N],b[N];

void mysolve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)cin>>a[i],sum[i]=sum[i-1]+a[i];
	string s;
	cin>>s;
	s="$"+s;
	for(int i=n; i; --i)b[i]=b[i+1]+a[i]*(s[i]=='1');
	ll ans=b[1];
	for(int i=n; i; --i)if(s[i]=='1')ans=max(ans,b[i+1]+sum[i-1]);
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
