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

typedef unsigned long long ull;
mt19937 rnd(random_device{}());
uniform_int_distribution<ull> rd(0, ULLONG_MAX);
ull h = rd(rnd);

int n;
int ask()
{
	int ans = 0, x;
	set<int>s;
	while ((int)s.size() < n / 2)
		{
			s.insert(rd(rnd) % n + 1);
		}
	cout << "? " << (int)s.size();
	for (auto v : s)cout << " " << v;
	cout << endl;
	cin >> x;
	ans += x;

	cout << "? " << n - (int)s.size();
	for (int i = 1; i <= n; ++i)if (!s.count(i))cout << " " << i;
	cout << endl;
	cin >> x;
	ans += x;
	return ans;
}

void mysolve()
{
	cin >> n;
	cout << "? " << n;
	for (int i = 1; i <= n; ++i)cout << " " << i;
	cout << endl;
	int cnt = 0;
	cin >> cnt;
	for (int i = 1; i < 30; ++i)
		{
			int x = ask();
			if ((cnt - x) & 1)return cout << "! NO" << endl, void();
		}
	cout << "! YES" << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
