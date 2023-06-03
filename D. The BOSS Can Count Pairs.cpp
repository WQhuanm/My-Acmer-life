#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
typedef pair<int, int> pii;
const int N = 2e5 + 10;
void mysolve()
{
	int n;
	cin>>n;
	vector<pii>a(n);
	for(int i=0; i<n; ++i)cin>>a[i].first;
	for(int i=0; i<n; ++i)cin>>a[i].second;
	sort(a.begin(),a.end());
	ll ans=0;
	for(int x=1; x*x<=2*n; ++x)
		{
			vector<int>cnt(n+1);//枚举x，x只与大于大于他的a匹配，显然在遇到pip前，如果真的存在a=x，我们可以存入每个x=a对应的b
			for(auto [k,v]:a)
				{
					int b=k*x-v;
					if(b>0&&b<=n)///b符合范围
						{
							ans+=cnt[b];
						}
					if(k==x)cnt[v]++;//在遇到a匹配前，先计入a=x的各个b的数目
				}
		}
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	cin >> t;
	//read(t);
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

