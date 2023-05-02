#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 2e4 + 10;
int len,ans,n,m;;
vector<int>cnt[N];
int tocnt(int x,int val)//upper_bound返回所有小于等于val个数的子集
{
	return upper_bound(cnt[x].begin(),cnt[x].end(),val)-cnt[x].begin();
}

void dfs(int pos,int a,int b)
{
	if(pos==len)
	{
		int sum=b-a,l=b-n,r=m-a;
		if(!a)l=max(1ll,l),r=min(r,b-1);
		if(l>r)return;
		ans+=__gcd(a,b)*(tocnt(sum,r)-tocnt(sum,l-1));//划分上下限求贡献
		return;
	}
	dfs(pos+1,a,b);
	dfs(pos+1,a,b|(1<<pos));
	if((a|(1<<pos))<=m)dfs(pos+1,a|(1<<pos),b|(1<<pos));//dfs枚举a,b组合情况
}
void mysolve()
{
	cin>>n>>m;
	if(n<m)swap(n,m);
	len=ans=0;
	while((1<<len)<=n)len++;//取二进制最长长度
	for(int i=0; i<(1<<len); ++i)
	{
		cnt[i].clear();
		for(int j=i; ; j=(j-1)&i)//枚举二进制子集
		{
			cnt[i].push_back(j);
			if(!j)break;
		}
		sort(cnt[i].begin(),cnt[i].end());//排序使后面可以二分
	}
	dfs(0,0,0);
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
