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
const int mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;

int n, c;
int a[N];

void mysolve()
{
	cin >> n >> c;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	sort(a + 1, a + 1 + n);
	if (c < 0)
		{
			reverse(a + 1, a + 1 + n);
			for (int i = 1; i <= n; ++i)for (int j = n; j > i; --j)
					{
						int b = abs(a[j] - a[j - 1] - c), now = abs(a[i] - a[j] - c);
						if (i > 1)b += abs(a[i] - a[i - 1] - c), now += abs(a[j] - a[i - 1] - c);
						if (j < n)b += abs(a[j + 1] - a[j] - c), now += abs(a[j + 1] - a[j-1] - c);
						if (b == now)
							{
								int tmp = a[j];
								for (int p = j; p > i; --p)a[p] = a[p - 1];
								a[i] = tmp;break;
							}
					}
		}
	for(int i=1;i<=n;++i)cout<<a[i]<<" \n"[i==n];
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
