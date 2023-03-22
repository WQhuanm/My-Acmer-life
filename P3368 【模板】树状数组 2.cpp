#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;

int b[N];
int n;
void add(int x,int k)
{
	for (int i=x; i<=n; i+=i&-i)b[i]+=k;
}
ll ask(int x)
{
	ll ans=0;
	for (int i=x; i; i-=i&-i)ans+=b[i];
	return ans;
}

int main()
{
	int m,p,x,y,k;
	cin>>n>>m;
	for (int i=1; i<=n; ++i)cin>>x,add(i,x),add(i+1,-x);
	while (m--)
		{
			cin>>p;
			if (p==1)
				{
					cin>>x>>y>>k;
					add(x,k),add(y+1,-k);
				}
			else if (p==2)
				{
					cin>>x;
					cout<<ask(x)<<endl;
				}
		}
}
