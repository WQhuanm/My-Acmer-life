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
	for (int i = 1; i <= n; ++i)cin >> a[i];
	if(k<=0){
		if(*max_element(a+1,a+1+n)>=0)cout<<0<<endl;
		else cout<<-1<<endl;return;
	}
	int ans = inf;
	for (int i = 1; i <= n; ++i)
		{
			priority_queue<int>q;
			ll sum = 0, x = 0;
			for (int j = i; j <= n; ++j)
				{
					if (a[j] >= 0)sum += a[j], x++;
					else q.push(a[j]);
					if (sum >= k)
						{
							while (!q.empty() && sum + q.top() >= k)sum += q.top(), q.pop(), x++;
							int len = j - i + 1;
							ans = min(ans, 2 * len - 1 - x);
						}
				}
		}
	ans = (ans < inf ? ans : -1);
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
