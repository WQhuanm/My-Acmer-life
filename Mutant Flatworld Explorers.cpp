#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
#define endll            endl<<endl
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 110;
bool vis[N][N];
int way[4][2]= {{0,1},{1,0},{0,-1},{-1,0}}; //顺时针
void mysolve()
{
	int n,m;
	cin>>n>>m;
	int x,y;
	char c;
	string s;
	while(cin>>x>>y>>c)
		{
			int p;
			if(c=='N')p=0;
			else if(c=='E')p=1;
			else if(c=='S')p=2;
			else p=3;
			cin>>s;
			bool flag=1;
			for(int i=0; i<(int)s.size(); ++i)
				{
					if(s[i]=='R')p=(p+1)%4;
					else if(s[i]=='L')p=(p-1+4)%4;
					else
						{
							int tx=x+way[p][0],ty=y+way[p][1];
							if(!(tx>=0&&tx<=n&&ty>=0&&ty<=m))
								{
									if(vis[x][y])continue;
									vis[x][y]=1;
									flag=0;
									break;
								}
							x=tx,y=ty;
						}
				}
			cout<<x<<' '<<y;
			if(p==0)cout<<" N";
			else if(p==1)cout<<" E";
			else if(p==2)cout<<" S";
			else if(p==3)cout<<" W";
			if(	!flag)cout<<" LOST";
			cout<<endl;
		}

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
