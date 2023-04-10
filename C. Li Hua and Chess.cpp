#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		{
			int n,m;
			cin>>n>>m;
			int x=1,y=1;
			cout<<'?'<<' '<<x<<' '<<y<<endl;
			int d1,d2,d3;
			cin>>d1;
			if(d1==0)
				{
					cout<<'!'<<' '<<x<<' '<<y<<endl;
					continue;
				}
			if(n>=2)
				{
					cout<<'?'<<' '<<1+x<<' '<<1<<endl;
					cin>>d2;
					if(d1==d2)
						{
							y+=d1;
							cout<<'?'<<' '<<x<<' '<<y<<endl;
							cin>>d3;
							x+=d3;
							cout<<'!'<<' '<<x<<' '<<y<<endl;
						}
					else
						{
							x=1+d1;
							cout<<'?'<<' '<<x<<' '<<y<<endl;
							cin>>d3;
							y+=d3;
							cout<<'!'<<' '<<x<<' '<<y<<endl;
						}
				}
			else 	cout<<'!'<<' '<<x<<' '<<y+d1<<endl;
		}
	return 0;
}
