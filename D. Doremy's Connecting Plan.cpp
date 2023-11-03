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

int  n, c;

struct node
{
	int i, sum, val;
	bool operator<(const node&k)const
	{
		return val > k.val;
	}
} a[N];

void mysolve()
{
	cin >> n >> c;
	priority_queue<node>q;
	set<int>s;
	for (int i = 1; i <= n; ++i)cin >> a[i].sum, a[i].i = i, a[i].val = a[i].sum - i * c;
	sort(a + 2, a + 1 + n);
	for (int i = 2; i <= n; ++i)
		{
			a[1].sum += a[i].sum;
			if (a[1].sum < a[i].i * c)return cout << "NO" << endl, void();
		}
	cout << "YES" << endl;
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
