#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t,n,m,x,y,ex,ey;
	string s;
	cin>>t;
	while (t--)
		{
			int dx,dy;
			cin>>n>>m>>x>>y>>ex>>ey>>s;
			if (s[0]=='D')dx=1;
			else dx=-1;
			if (s[1]=='R')dy=1;
			else dy=-1;
			int ans=0;
			while (x!=ex||y!=ey)
				{
					int f=0;
					if (x+dx>n||x+dx<1)ans++,dx=-dx,f++;
					if (y+dy>m||y+dy<1)ans++,dy=-dy,f++;//f记录一回转向次数
					x+=dx,y+=dy;
					ans-=(f==2);//如果x，y同时转两次，那么ans多加了一次
					if (ans>m*n)break;
				}
			if (ans>m*n)cout<<-1<<endl;
			else cout<<ans<<endl;
		}

	return 0;
}
