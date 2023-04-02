#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define endl             "\n"
typedef pair<int, int> pii;
const int N = 2e5 + 10;
int t[N],a[N],b[N];
unordered_map<int,pii>mp;
void add(int x,int w)
{
	for (int i=x; i; i-=i&-i)t[i]=max(t[i],w);
}
int ask(int x)
{
	int ans=0;
	for (int i=x; i<=N; i+=i&-i)ans=max(ans,t[i]);
	return ans;
}

int main()
{
	int n,m;
	cin>>n;
	for (int i=1; i<=n; ++i)cin>>a[i];
	cin>>m;
	for (int i=1; i<=m; ++i)
		{
			cin>>b[i];
			if (!mp[b[i]].first)mp[b[i]]= {i,i};//更新每个在b中出现的数的出现区间
			else mp[b[i]].second=i;
		}
	int ans=0,sum=0;
	for (int i=1; i<=n; ++i)
		{
			if (!mp[a[i]].first)sum++;//b中没出现直接加
			else
				{
					int tmp=ask(mp[a[i]].second)+1;//找符合条件的最长子串，寻找在b数组顺序在a[i]之后出现的数（这些数在a数组中是在a之前出现，先出现才能被加到t数组里面）
					ans=max(ans,tmp);
					add(mp[a[i]].first,tmp);//更新t数组中出现的数字的区间
				}
		}
	cout<<ans+sum<<endl;
	return 0;
}

