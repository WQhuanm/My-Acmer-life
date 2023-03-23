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
const int N =1e3 + 10;

int a[N];
vector<int>ans[N];
stack<int>b;
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1; i<=n; ++i)cin>>a[i];
	int maxn=INF,p=1;
	for (int i=1; i<=n; ++i)
	{
		while ((int)b.size()>0)//先拿背包
		{
			if (maxn>=b.top())
			{
				ans[p].push_back(b.top());
				maxn=b.top();
				b.pop();
				if ((int)ans[p].size()==k)
				{
					p++,maxn=INF;
				}
			}
			else break;
		}
		if ((int)b.size()==m)
		{
			if (a[i]<=maxn)//能插就插入
			{
				ans[p].push_back(a[i]);
				maxn=a[i];
				if ((int)ans[p].size()==k)
				{
					p++,maxn=INF;
				}
			}
			else//不行，i保持下一次还是这里，换树枝
			{
				p++,maxn=INF,i--;
			}
		}
		else if ((int)b.size()<m)//背包有空间直接放
		{
			b.push(a[i]);
		}
	}
	while ((int)b.size()>0)
	{
		if (maxn>=b.top())
		{
			ans[p].push_back(b.top());
			maxn=b.top();
			b.pop();
			if ((int)ans[p].size()==k)
			{
				p++,maxn=INF;
			}
		}
		else
		{
			p++,maxn=INF;
		}
	}
	for (int i=1; i<=p; ++i)for (int j=0; j<(int)ans[i].size(); ++j)
	{
		cout<<ans[i][j];
		if (j==(int)ans[i].size()-1)cout<<endl;
		else cout<<' ';
	}
	return 0;
}
