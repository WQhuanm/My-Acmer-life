#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define int ll
#define endl             "\n"
typedef pair<int, int> pii;
const int N = 2e5 + 10;
int n;
bool check(int h,int w,map<int,multiset<int>> mp1,map<int,multiset<int>>mp2,bool ft)//ft标记最开始是先减去谁，如h最长，应先减w
{
	int ct=n;
	while(h>0&&w>0)
		{
			bool cnt=0;
			if(ft)
				{
					for(auto v:mp1[h])
						{
							ct--;
							w-=v;
							mp2[v].erase(mp2[v].find(h));//删除w存的片，该片已经剪过，不可重复
							cnt=1;
						}
					if(w<0)return 0;
					ft^=1;//每次减完轮流
				}
			else
				{
					for(auto v:mp2[w])
						{
							h-=v;
							ct--;
							mp1[v].erase(mp1[v].find(w));
							cnt=1;
						}
					if(h<0)return 0;
					ft^=1;
				}
			if(!cnt)return 0;
		}
	if(ct)return 0;//成功减去n片
	return 1;
}
map<int,int>mp;
void mysolve()
{
	int x,y;
	int mx=0,my=0,sum=0;
	cin>>n;
	map<int,multiset<int>>mpx,mpy;//记录每个长度/宽度可以对于的宽度/长度
	for(int i=1; i<=n; ++i)cin>>x>>y,mx=max(mx,x),my=max(my,y),mpx[x].insert(y),mpy[y].insert(x),sum+=x*y;
	int cnt=0;
	pii ans[3];
	if(sum%mx==0&&check(mx,sum/mx,mpx,mpy,1))ans[++cnt]= {mx,sum/mx};
	if(sum%my==0&&sum/my!=mx&&check(sum/my,my,mpx,mpy,0))ans[++cnt]= {sum/my,my};
	cout<<cnt<<endl;
	for(int i=1; i<=cnt; ++i)cout<<ans[i].first<<" "<<ans[i].second<<endl;
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
