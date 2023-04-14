#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
typedef pair<int, int> pii;
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N =2e5+10;

struct node
{
	int v,c,d;
};
vector<node>edge1[N],edge2[N];
int b[N];
int n,m,q;

void dijksta(int st,vector<int>&dis,bool fl)//正反dijksta
{
	dis[st]=0;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({dis[st],st});
	if(!fl)
		while(!q.empty())
			{
				int u=q.top().second;
				q.pop();
				for(node k:edge1[u])
					{
						if(dis[k.v]>dis[u]+k.c)
							{
								dis[k.v]=dis[u]+k.c;
								q.push({dis[k.v],k.v});
							}
					}
			}
	else
		{
			while(!q.empty())
				{
					int u=q.top().second;
					q.pop();
					for(node k:edge2[u])
						{
							if(dis[k.v]>dis[u]+k.d)
								{
									dis[k.v]=dis[u]+k.d;
									q.push({dis[k.v],k.v});
								}
						}
				}
		}
}
void mysolve()
{
	cin>>n>>m>>q;
	int x,y,c,d;
	vector<int>dis1(n+1,llINF),dis2(n+1,llINF);
	for(int i=1; i<=m; ++i)cin>>x>>y>>c>>d,edge1[x].push_back({y,c,d}),edge2[y].push_back({x,c,d});
	dijksta(1,dis1,0),dijksta(n,dis2,1);
	multiset<ll>st;
	for(int i=1; i<=n; ++i)
		{
			cin>>b[i];
			if(dis1[i]!=llINF&&dis2[i]!=llINF)st.insert(dis1[i]+(dis2[i]+b[i]-1)/b[i]);//注意dis为llINF时，是不存在这种走法的，此时强行更新会污染数据，所以必须都可以走才更新
		}
	while(q--)
		{
			cin>>x>>y;
			if(dis1[x]!=llINF&&dis2[x]!=llINF)//注意边要可以走
				{
					st.erase(st.find(dis1[x]+(dis2[x]+b[x]-1)/b[x]));
					b[x]=y;
					st.insert(dis1[x]+(dis2[x]+b[x]-1)/b[x]);
				}
			cout<<*st.begin()<<endl;
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
