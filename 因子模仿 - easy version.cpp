#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define endl             "\n"
const int N = 1e6 + 10;
int t[N];
int n,q,x,op,l,r;
void add(int x,int w)
{
	for (int i=x; i<=n; i+=i&-i)t[i]+=w;
}
int ask(int x)
{
	int ans=0;
	for (int i=x; i; i-=i&-i)ans+=t[i];
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>q>>x>>x>>x>>x;
	char c;
	for (int i=1; i<=n; ++i)
		{
			cin>>c;
			if (c=='1')add(i,1),add(i+1,-1);
		}
	while (q--)
		{
			cin>>op>>l>>r;
			if (op==1)
				{
					add(l,1),add(r+1,-1);//区间修改
				}
			else
				{
					if (ask(r)&1)//单点查询
						{
							cout<<"Magical Splash Flare"<<endl;
						}
					else
						{
							cout<<"HoloPsychon"<<endl;
						}
				}
		}
	return 0;
}
