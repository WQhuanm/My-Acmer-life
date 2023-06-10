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
const int N =210;
const int mod = 998244353;

int a[N];
void mysolve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)cin>>a[i];
	sort(a+1,a+1+n);
	vector dp(410,vector<int>(n+1,-1));
	int ans=inf;
	for(int i=1; i<=400; ++i)for(int j=1; j<=i&&j<=n; ++j)
			{
				if(j-1&&dp[i-1][j-1]==-1)break;
				dp[i][j]=(j-1?dp[i-1][j-1]:0)+abs(a[j]-i);
				if(~dp[i-1][j]&&j<i)dp[i][j]=min(dp[i-1][j],dp[i][j]);
				if(j==n)ans=min(ans,dp[i][j]);
			}
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	cin >> t;
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
