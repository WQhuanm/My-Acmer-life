#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define endll            endl<<endl
const int N = 12000;
string s[N];
bool vis[N];
string b;
vector<int>ans;
bool flag;
int m,k;
void dfs(int num,int p)
{
	if(num==m)//如果能m段匹配完，说明是正确答案，不用再dfs了
		{
			flag=1;
			return;
		}
	if(flag)return;
	for(int j=1; j<=m; ++j)
		{
			if(!vis[j])
				{
					int len=(int)s[j].size();
					if(b.substr(p+1,len)==s[j])
						{
							vis[j]=1;
							int tmp=p;
							ans.push_back(j);

							for(int x=p+len; x>=0; --x)if(b[x]==' ')
									{
										tmp=x;
										break;
									}
							dfs(num+1,tmp);
							if(flag)return;
							ans.pop_back();
							vis[j]=0;
						}
				}
		}
}

void mysolve()
{
	int n;
	cin>>n;
	getchar();
	getline(cin,b);
	b=' '+b;
	int p=0;
	cin>>m;
	for(int i=1; i<=m; ++i)
		{
			cin>>k;
			getchar();
			getline(cin,s[i]);
		}
	dfs(0,p);
	for(int i=0; i<(int)ans.size(); ++i)
		{
			if(i!=0)cout<<" ";
			cout<<ans[i];
		}

}

int32_t main()
{
	//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
