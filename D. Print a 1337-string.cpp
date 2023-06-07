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
	int n;
	cin>>n;
	for(int i=1; i<=1e5; ++i)
		{
			ll t=1ll*i*(i+1)/2;
			int cnt=n/t;
			if(n-cnt*t-(1+2*(i+1))*cnt>0)
				{
					int p=n-cnt*t-(1+2*(i+1))*cnt;
					if(1+i+1+cnt+(p?p+2:0)<=1e5)
						{
							string s="1";
							if(p)
								{
									s+="33";
									for(int j=1; j<=p; ++j)s.push_back('7');
								}
							for(int j=1; j<=i+1; ++j)s.push_back('3');
							for(int j=1; j<=cnt; ++j)s.push_back('7');
							cout<<s<<endl;
							return;
						}
				}
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

