#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
typedef pair<int, int> pii;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 3e5 + 10;
int a[N],b[N];
void mysolve()
{
	int n;
	cin>>n;
	int ans=0;
	for(int i=1; i<=n; ++i)cin>>a[i],b[i]=i,ans+=i*(i-1)/2;
	sort(b+1,b+1+n,[&](int x,int y)//从大到小排序
	{
		return a[x]>a[y];
	});
	vector<int>l(n+1),r(n+1,n+1);
	stack<pii>s;
	for(int i=1; i<=n; ++i)//单调栈处理左右最小
		{
			while(!s.empty()&&s.top().first>a[i])r[s.top().second]=i,s.pop();
			if(!s.empty())l[i]=s.top().second;
			s.push({a[i],i});
		}
	set<int>st;
	st.insert(0);
	for(int i=1; i<=n; ++i)
		{
			int p=b[i];
			int k=l[p],y=r[p];
			int x=k?*prev(st.lower_bound(k)):0;//找到集合下标小于x的元素（找不到有一开始插入的0垫着）
			ans-=(y-p)*(k-x);//注意，这里p才是实际的下标，i不是
			st.insert(p);//大到小处理，处理完的数的下标扔到集合
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
