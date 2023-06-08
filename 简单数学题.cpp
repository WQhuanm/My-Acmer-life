#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long

void mysolve()
{
	ll l,r,a,b;
	cin>>l>>r>>a>>b;
	ll cnt=r/a-l/a;
	ll g=__gcd(a,b);
	a/=g;
	ll p=1e18/a;
	if(b<=p)
		{
			ll lcm=a*b;
			cnt-=r/lcm-l/lcm;
		}
	cout<<max(0ll,cnt)<<endl;
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
