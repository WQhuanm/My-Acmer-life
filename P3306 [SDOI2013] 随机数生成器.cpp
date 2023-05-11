#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
int p,a,b,x,t;

ll fastmi(int base,int power)
{
	ll ans=1;
	while(power)
		{
			if(power&1)ans=ans*base%p;
			base=base*base%p;
			power>>=1;
		}
	return ans;
}

void mysolve()
{
	cin>>p>>a>>b>>x>>t;
	if(x==t)
		{
			cout<<1<<endl;
			return;
		}
	if(a==0)
		{
			if(b==t)cout<<2<<endl;
			else cout<<-1<<endl;
			return;
		}
	else if(a==1)
		{
			if(!b)cout<<-1<<endl;
			else cout<<(t-x+p)%p*fastmi(b,p-2)%p+1<<endl;
			return;
		}
	int m=ceil(sqrt(p));
	int now=1,tmp=b*fastmi(a-1,p-2)%p;
	b=(t+tmp)*fastmi(x+tmp,p-2)%p;
	unordered_map<int,int>mp;
	for(int i=0; i<=m; ++i)//j从0到m
		{
			if(i)now=now*a%p;
			mp[b*now%p]=i;
		}
	int ans=1;
	for(int i=1; i<=m; ++i)
		{
			ans=ans*now%p;
			if(mp.count(ans)&&i*m-mp[ans]<p)
				{
					cout<<(i*m-mp[ans]+p)%p+1<<endl;
					return;
				}
		}
	cout<<-1<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
