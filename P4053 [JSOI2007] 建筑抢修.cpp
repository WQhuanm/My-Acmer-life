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

int n;
pii a[N];

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i].second >> a[i].first;
	sort(a + 1, a + 1 + n);
	int sum = 0, ans = 0;
	priority_queue<int>q;
	for (int i = 1; i <= n; ++i)
		{
			if (sum + a[i].second <= a[i].first)ans++, sum += a[i].second, q.push(a[i].second);
			else
				{
					if (!q.empty() && q.top() > a[i].second && sum - q.top() + a[i].second <= a[i].first)
						{
							sum -= q.top(), q.pop();
							q.push(a[i].second);
							sum += a[i].second;
						}
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
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
