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
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;

int n, p;
struct node
{
	int a, b;
	bool operator<(const node&k)const
	{
		return b < k.b;
	}
} a[N];
void mysolve()
{
	cin >> n >> p;
	for (int i = 1; i <= n; ++i)cin >> a[i].a;
	for (int i = 1; i <= n; ++i)cin >> a[i].b;
	sort(a + 1, a + 1 + n);
	int now = n - 1, sum = p;
	for (int i = 1; i <= n; ++i)
		{
			if (a[i].b >= p)break;
			if (a[i].a >= now)
				{
					sum += now * a[i].b, now = 0;
					break;
				}
			else
				{
					sum += a[i].a * a[i].b, now -= a[i].a;
				}
		}
	sum += now * p;
	cout << sum << endl;
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
