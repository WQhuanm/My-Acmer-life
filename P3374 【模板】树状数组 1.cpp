#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int N = 5e5 + 10;
int a[N],t[N];
int n;
void add(int x,int k)
{
	for (int i=x; i<=n; i+=i&-i)t[i]+=k;
}

ll ask(int x)
{
	ll ans=0;
	for (int i=x; i; i-=i&-i)ans+=t[i];
	return ans;
}

int main()
{
	int m,p,x,y;
	cin>>n>>m;
	for (int i=1; i<=n; ++i)cin>>a[i],add(i,a[i]);
	while (m--)
		{
			cin>>p>>x>>y;
			if (p==1)
				{
					add(x,y);
				}
			else if (p==2)
				{
					cout<<ask(y)-ask(x-1)<<endl;
				}
		}
	return 0;
}
