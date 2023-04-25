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
const int N = 2e5 + 10;
vector<int>edge[N];
int ans,cnt,sz[N],dep[N];

void init(int n)
{
	for(int i=1; i<=n; ++i)edge[i].clear(),sz[i]=dep[i]=0;
	ans=cnt=0;
}

void dfs(int u)
{
	sz[u]=1;
	ans+=dep[u];//初始代价就是每个点的深度（意思就是他一开始有多少个括号在他外面（即祖先们））
	for(auto v:edge[u])
		{
			dep[v]=dep[u]+1;
			dfs(v);
			sz[u]+=sz[v];
		}
}
void mysolve()
{
	int k;
	string s;
	cin>>k>>s;
	init((int)s.size());
	stack<int>a;
	for(auto c:s)
		{
			if(c=='(')
				{
					if(a.empty())
						{
							a.push(++cnt);//第一个入栈显然是根节点，没有爸爸
							continue;
						}
					int u=a.top();
					edge[u].push_back(++cnt);
					a.push(cnt);
				}
			else
				{
					int u=a.top();
					a.pop();
					if(a.empty())//取出是空，说明是根节点
						dfs(u);
				}
		}
	sort(sz+1,sz+1+cnt,greater<int>());
	for(int i=1; i<=k; ++i)
		{
			if(sz[i]>1)ans-=sz[i]-1;
			else break;
		}
	cout<<ans<<endl;
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
