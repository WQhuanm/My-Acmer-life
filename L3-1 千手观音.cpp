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
const int N = 1e5 + 10;

unordered_map<string,int>mp;
string back[N];
int in[N];
int head[N],num;
struct node
{
	int next,to;
} edge[N];
void add(int u,int v)
{
	edge[++num].next=head[u];
	edge[num].to=v;
	head[u]=num;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,cnt=0;
	cin>>n;
	string s,tmp;
	vector<string>b;
	while (n--)
	{
		vector<string>a;
		cin>>s;
		s+='.';
		int len=0;//记录片段长度
		for (int i=0; i<(int)s.size(); ++i)
		{
			if (s[i]=='.')
			{
				tmp=s.substr(i-len,len);
				if (!mp[tmp])mp[tmp]=++cnt,back[cnt]=tmp;
				a.push_back(tmp);
				len=0;
			}
			else len++;
		}
		
		if ((int)a.size()==(int)b.size()) //如果前后字符串相同
		{
			for (int j=0; j<(int)a.size(); ++j)
			{
				if (a[j]!=b[j])
				{
					add(mp[b[j]],mp[a[j]]);
					in[mp[a[j]]]++;
					break;
				}
			}
		}
		b=a;
	}
	
	vector<string>ans;
	priority_queue< pair<string,int>,vector< pair<string,int> >,greater<pair<string,int> > >q;
	for (int i=1; i<=cnt; ++i)if (!in[i])q.push({back[i],i});
	while (!q.empty())
	{
		auto u=q.top();
		q.pop();
		ans.push_back(u.first);
		for (int i=head[u.second]; i; i=edge[i].next)
		{
			int v=edge[i].to;
			if (--in[v]==0)q.push({back[v],v});
		}
	}
	for (int i=0; i<(int)ans.size(); ++i)
	{
		cout<<ans[i];
		if (i==(int)ans.size()-1)cout<<endl;
		else cout<<'.';
	}
	return 0;
}
