#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"

int mod;

void mysolve()
{
	int a,b;
	cin>>a>>b>>mod;
	int base=1e9;
	base%=mod;
//	unordered_map<int,int>mp;
	if(base==0||b>=mod-1)
		{
			cout<<2<<endl;
			return;
		}

//	for(int i=0; i<=b&&i<mod; ++i)mp[(mod-i)%mod]=1;
	for(int i=0; i<=a&&i<mod; ++i)
		{
			int tmp=1ll*i*base%mod;
			if(tmp>0&&tmp<mod-b)
				{
					cout<<1<<endl;
					printf("%09d\n",i);
					return;
				}
		}
	cout<<2<<endl;
}

int32_t main()
{
//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
