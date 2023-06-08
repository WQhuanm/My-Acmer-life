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

int dp[N],f[N];//存储sg值,f[i]存储的是i情况可以前往的状态
int n;

int sg(int x)
{
	if(x<=0)return dp[x]=0;//不合法状态：必败点
	if(~dp[x])return dp[x];
	set<int>mex;
	for(int i=0; i<x; ++i)//枚举x可以到达的状态
		{
			mex.insert(sg(i));
			//如果x到达的状态是同时由多个状态决定，那么获得他们的异或和,如s.insert( sg(j)^sg(x-i-j) )一次由两个状态决定
		}
	for(int i=1; i<x; ++i)mex.insert(sg(i)^sg(x-i));
	int ans=0;
	while(mex.count(ans))ans++;
	return dp[x]=ans;//记忆化
}

void mysolve()
{
//	memset(dp,-1,sizeof(dp));//初始化不能少
//	for(int i=1; i<=100; ++i)cout<<i<<" "<<sg(i)<<endl;
	int n,x;
	cin>>n;
	int ans=0;
	bool one =0;
	for(int i=1; i<=n; ++i)
		{
			cin>>x;
			if(x%4==0)x--;
			else if(x%4==3)x++;
			ans^=x;
			if(x>1)one=1;
		}
	if(one)
		{
			if(ans)cout<<"Alice"<<endl;
			else cout<<"Bob"<<endl;
		}
	else
		{
			if(ans)cout<<"Bob"<<endl;
			else cout<<"Alice"<<endl;
		}

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
