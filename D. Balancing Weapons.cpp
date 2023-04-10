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

int cal(vector<int>&a,int l,int r) //计算不要修改的区间包含的数
{
	return upper_bound(a.begin(),a.end(),r)-lower_bound(a.begin(),a.end(),l);
}

void mysolve()
{
	int n,x,k;
	cin>>n>>k;
	vector<int>f(n),a(n);
	for(int i=0; i<n; ++i)cin>>f[i];
	for(int i=0; i<n; ++i)cin>>x,a[i]=f[i]*x;
	sort(f.begin(),f.end(),greater<int>());//注意，使用unique前需要先排序
	while(f.size()&&f.back()<=k+1)f.pop_back();//对于一定可以成功修改的，直接提出讨论
	f.resize(unique(f.begin(),f.end())-f.begin());//删除重复的数
	
	sort(a.begin(),a.end());//我们从小到大枚举区间范围
	int ans=n,r=k+1;//r至少从k+1开始，小于他则没有必要讨论,我们是利用a的值跳跃遍历[R-k,R]的区间
	for(auto u:a)
	{
		for(r=max(r,u); r<=u+k; ++r)
		{
			bool flag=1;
			for(auto p:f)//f从大到小遍历
			{
				if(k<r%p)
				{
					flag=0;
					break;
				}
			}
			if(flag)ans=min(ans,n-cal(a,r-k,r));
		}
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
