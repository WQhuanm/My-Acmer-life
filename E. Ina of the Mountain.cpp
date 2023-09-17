#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 3e5 + 10;

int n, k;
int a[N];
void mysolve()
{
	cin >> n >> k;
	int ans = 0;
	priority_queue<int, vector<int>, greater<int>>q;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			a[i] %= k;
			if (a[i] <= a[i - 1])q.push(a[i ] - a[i-1] + k);
			else
				{
					q.push(a[i] - a[i - 1]);
					ans += q.top(), q.pop();
				}
		}
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
