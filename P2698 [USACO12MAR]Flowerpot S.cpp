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
pii a[N];
void mysolve()
{
	int n,d;
	cin>>n>>d;
	int ans=INF;
	for(int i=1; i<=n; ++i)cin>>a[i].first>>a[i].second;
	deque<pii>q1,q2;
	sort(a+1,a+1+n);
	int p=-1;
	for(int i=1; i<=n; ++i)
		{
			while(!q1.empty()&&q1.back().first<a[i].second)q1.pop_back();
			q1.push_back({a[i].second,a[i].first});

			while(!q2.empty()&&q2.back().first>a[i].second)q2.pop_back();
			q2.push_back({a[i].second,a[i].first});

			if(q1.front().first-q2.front().first>=d)
				{
					ans=min(ans,abs(q1.front().second-q2.front().second));//队列的队首就是整个队列下标最小的，所以最大值与最小值的L就是min那一个
					p=min(q1.front().second,q2.front().second);
					while(!q1.empty()&&q1.front().second<=p)q1.pop_front();//合法后L右移，即删除小标小于等于L的元素
					while(!q2.empty()&&q2.front().second<=p)q2.pop_front();
				}
		}
	cout<<(ans<INF?ans:-1)<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
