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

void mysolve()
{
	int n,k;
	cin>>n>>k;
	deque<pii>q1,q2;
	vector<int>a1,a2;
	int x;
	for(int i=1; i<=n; ++i)
		{
			cin>>x;
			if(i<k)
				{
					while(!q1.empty()&&q1.back().first<x)q1.pop_back();
					q1.push_back({x,i});

					while(!q2.empty()&&q2.back().first>x)q2.pop_back();
					q2.push_back({x,i});
				}
			else
				{
					while(!q1.empty()&&q1.front().second<=i-k)q1.pop_front();
					while(!q1.empty()&&q1.back().first<x)q1.pop_back();
					q1.push_back({x,i});
					a1.push_back(q1.front().first);

					while(!q2.empty()&&q2.front().second<=i-k)q2.pop_front();
					while(!q2.empty()&&q2.back().first>x)q2.pop_back();
					q2.push_back({x,i});
					a2.push_back(q2.front().first);
				}
		}
	for(int i=0; i<=n-k; ++i)
		{
			if(!i)cout<<a2[i];
			else cout<<" "<<a2[i];
		}
	cout<<endl;
	for(int i=0; i<=n-k; ++i)
		{
			if(!i)cout<<a1[i];
			else cout<<" "<<a1[i];
		}
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
