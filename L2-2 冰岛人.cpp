#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
#define endll            endl<<endl
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;

unordered_map<string,int>mp;
int cnt;
struct node
{
	int next,to;
} edge[N<<1];
int head[N],num;
void add(int u,int v)
{
	edge[++num].next=head[u];
	edge[num].to=v;
	head[u]=num;
}
bool sex[N];//记录性别，1为男，0为女
int fa[N],in[N],dep[N],pre[N];

void dfs(int u,int fa,int f)//遍历祖先树建立深度
{
	dep[u]=dep[fa]+1;
	pre[u]=f;//标记每个点的初代祖先
	for (int i=head[u]; i; i=edge[i].next)
		{
			int v=edge[i].to;
			dfs(v,u,f);
		}
}

void mysolve()
{
	int n;
	cin>>n;
	string a,b,tmp;
	while (n--)
		{
			cin>>a;
			if (!mp[a])mp[a]=++cnt;
			cin>>b;
			int len=(int)b.size();
			if (b[len-1]=='m')sex[mp[a]]=1;
			else if (b[len-1]=='n')
				{
					sex[mp[a]]=1;
					tmp=b.substr(0,len-4);//是冰岛人就建立关系边
					if (!mp[tmp])mp[tmp]=++cnt;
					fa[mp[a]]=mp[tmp];
					add(mp[tmp],mp[a]);
					in[mp[a]]++;
				}
			else if (b[len-1]=='r')
				{
					tmp=b.substr(0,len-7);
					if (!mp[tmp])mp[tmp]=++cnt;
					fa[mp[a]]=mp[tmp];
					add(mp[tmp],mp[a]);
					in[mp[a]]++;
				}
		}

	for (int i=1; i<=cnt; ++i)if (!in[i])dfs(i,i,i);//对所以初代祖先建立祖先树
	int q;
	cin>>q;
	while (q--)
		{
			cin>>a>>tmp>>b>>tmp;
			int x=mp[a],y=mp[b];
			if (!x||!y)//不存在这个人
				{
					cout<<"NA"<<endl;
					continue;
				}
			else if ((sex[x]^sex[y])==0)//性别相同
				{
					cout<<"Whatever"<<endl;
					continue;
				}
			else
				{
					if (pre[x]!=pre[y])//初代祖先不同
						{
							cout<<"Yes"<<endl;
							continue;
						}
					else
						{
							int lo=min(dep[x],dep[y]);//相同则找lca，判断是否符合即可
							while (dep[x]!=dep[y])
								{
									if (dep[x]<dep[y])swap(x,y);
									x=fa[x];
								}
							while (x!=y)x=fa[x],y=fa[y];
							int ans=lo-dep[x];
							if (ans>=4)cout<<"Yes"<<endl;
							else cout<<"No"<<endl;
						}
				}
		}

}

int32_t main()
{
//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mysolve();
	system("pause");
	return 0;
}
