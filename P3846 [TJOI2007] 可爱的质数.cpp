#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
void mysolve()
{
	int a,b,mod;
	cin>>mod>>a>>b;
	if(__gcd(a,mod)!=1)//首先要满足a，p互质
		{
			cout<<"no solution"<<endl;
			return;
		}
	int m=ceil(sqrt(mod));//m向上取整
	unordered_map<int,int>mp;//哈希表
	int now=1;
	for(int i=0; i<=m; ++i)//哈希存入右边式子，0<=j<=m
		{
			if(i)now=now*a%mod;//now表示a的i次幂
			mp[b*now%mod]=i;//这里有乘法记得取模
		}
	int ans=1;
	for(int i=1; i<=m; ++i)
		{
			ans=ans*now%mod;//ans表示a^m的i次幂
			if(mp.count(ans)&&i*m-mp[ans]<mod)
				{
					cout<<(i*m-mp[ans]+mod)%mod<<endl;//因为从小到达枚举，所以第一个就是最小
					return;
				}
		}
	cout<<"no solution"<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
