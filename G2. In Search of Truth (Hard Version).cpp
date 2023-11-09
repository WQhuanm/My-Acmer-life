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
const int N = 1e6 + 10;

typedef unsigned long long ull;
mt19937 rnd(random_device{}());
uniform_int_distribution<ull> rd(0, ULLONG_MAX);
ull h = rd(rnd);

const int d = 330, lim = 1e9;
int vis[N];
void mysolve()
{
	int mn = 0, x;
	cin >> x;
	for (int i = 1; i <= d; ++i)
		{
			cout << "+ " << rd(rnd) % lim + 1 << endl;
			cin >> x;
			mn = max(mn, x);
		}
	vis[x] = 1;
	for (int i = 2; i <= d; ++i)
		{
			cout << "+ " <<  1 << endl;
			cin >> x;
			if (vis[x])return cout << "! " << i - vis[x] << endl, void();
			vis[x] = i;
		}
	int now = d + mn;
	cout << "+ " << mn << endl;
	cin >> x;
	if (vis[x])return cout << "! " << now - vis[x] << endl, void();
	while (1)
		{
			cout << "+ " <<  d << endl;
			now += d;
			cin >> x;
			if (vis[x])return cout << "! " << now - vis[x] << endl, void();
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
