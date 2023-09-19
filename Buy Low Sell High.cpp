#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double åmemsetæå¤§127ï¼æå°128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 3e5 + 10;

int n;
bool vis[N];
void mysolve()
{
	cin >> n;
	int x;
	ll ans = 0;
	//9-1,8-1,
	priority_queue<pii, vector<pii>, greater<pii>>q;
	while (n--)
	{
		cin >> x;
		if (!q.empty() && x > q.top().first)
		{
			pii tmp = q.top();
			q.pop();
			ans += x - tmp.first;
			if (tmp.second)q.push({tmp.first, 0});
			q.push({x, 1});
		}
		else q.push({x, 0});
	}
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//ä½¿ç¨readè¯·æè§£ç»æ³¨éäº
	int t = 1;
	//	cin >> t;
	while (t--)
	{
		mysolve();
	}
	system("pause");
	return 0;
}
