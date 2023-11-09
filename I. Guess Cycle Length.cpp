#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl             "\n"

typedef unsigned long long ull;
mt19937 rnd(random_device{}());
uniform_int_distribution<ull> rd(0, ULLONG_MAX);

const int d = 3330, lim = 1e9;
void mysolve()
{
	int mn = 0, x;
	map<int, int>vis;
	for (int i = 1; i <= d; ++i)
		{
			cout << "walk " << rd(rnd) % lim + 1 << endl;
			cin >> x;
			mn = max(mn, x);
		}
	vis[x] = 1;
	for (int i = 2; i <= d; ++i)
		{
			cout << "walk " <<  1 << endl;
			cin >> x;
			if (vis[x])return cout << "guess " << i - vis[x] << endl, void();
			vis[x] = i;
		}
	int now = d + mn;
	cout << "walk " << mn << endl;
	cin >> x;
	if (vis[x])return cout << "guess " << now - vis[x] << endl, void();
	while (1)
		{
			cout << "walk " <<  d << endl;
			now += d;
			cin >> x;
			if (vis[x])return cout << "guess " << now - vis[x] << endl, void();
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
