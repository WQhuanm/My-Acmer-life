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

void mysolve()
{
	int n;
	string a,b;
	cin>>n>>a>>b;
	int ans=1,res=0;
	bool flag=1;
	int ct=0;
	for(int i=0; i<n; ++i)
		{
			if(a[i]=='?')
				{
					if(b[i]=='?')
						{
							ct++;
							ans=ans*55%mod;
						}
					else
						{
							ans=ans*(b[i]-'0'+1)%mod;
						}
				}
			else
				{
					if(b[i]=='?')
						{
							ans=ans*('9'-a[i]+1)%mod;
						}
					else
						{
							if(a[i]>b[i])
								{
									ans=0;
									flag=0;
									break;
								}
						}
				}
		}
	res=ans,ans=1;
	for(int i=0; i<n; ++i)
		{
			if(a[i]=='?')
				{
					if(b[i]=='?')
						{
							ans=ans*55%mod;
						}
					else
						{
							ans=ans*('9'-b[i]+1)%mod;
						}
				}
			else
				{
					if(b[i]=='?')
						{
							ans=ans*(a[i]-'0'+1)%mod;
						}
					else
						{
							if(a[i]<b[i])
								{
									ans=0;
									flag=0;
									break;
								}
						}
				}
		}
	res=(res+ans)%mod;
	int cnt=0;
	cnt+=count(a.begin(),a.end(),'?')+count(b.begin(),b.end(),'?');
	res=(fastmi(10,cnt)-res+mod+(flag&&ct?fastmi(10,ct):0))%mod;
	cout<<res<<endl;

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
