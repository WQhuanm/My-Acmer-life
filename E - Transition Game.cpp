#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define endl             "\n"
#define int ll
const int N = 2e5 + 10;
int in[N],a[N];
int32_t main()
{
	int n;
	cin>>n;
	vector<vector<int>>v(n+1);
	for (int i=1; i<=n; ++i)
		{
			cin>>a[i];
			v[i].push_back(a[i]),in[a[i]]++;
		}
	queue<int>q;
	int ans=n;
	for (int i=1; i<=n; ++i)if (!in[i])q.push(i),ans--;//拓扑
	while (!q.empty())
		{
			int u=q.front();
			q.pop();
			for (auto v:v[u])if (--in[v]==0)q.push(v),ans--;
		}
	cout<<ans<<endl;
	return 0;
}
