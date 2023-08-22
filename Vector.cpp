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
const int N =  10;

struct node
{
	ll x, y, z;
	bool operator<(const node&k)const
	{
		return (x + y + z) > (k.x + k.y + k.z);
	}
} a[N];

int cross(int i, int j, int p)
{
	__int128 tmp = ((__int128)a[p].y - a[i].y) * ((__int128)a[j].x - a[i].x) - ((__int128)a[p].x - a[i].x) * ((__int128)a[j].y - a[i].y);
	return (tmp > 0 ? 1 : (tmp < 0 ? -1 : 0));
}

void mysolve()
{
	int n = 3;
	for (int i = 1; i < 5; ++i)cin >> a[i].x >> a[i].y >> a[i].z;
	if (a[4].x + a[4].y + a[4].z == 0)
		{
			cout << "YES" << endl;
			return;
		}
	sort(a + 1, a + 1 + n);
	while (a[n].x + a[n].y + a[n].z == 0)n--;
	if (!n)
		{
			cout << "NO" << endl;
			return;
		}
	else if (n == 1)
		{
			double x = 1.0 * a[4].x / a[1].x, y = 1.0 * a[4].y / a[1].y, z = 1.0 * a[4].z / a[1].z;
			if (fabs(x - y) < eps && fabs(y - z) < eps)cout << "YES" << endl;
			else cout << "NO" << endl;
			return;
		}
	ll lcm = 1;
	for (int i = 1; i < 5; ++i)
		{
			ll sum = a[i].x + a[i].y + a[i].z;
			if (!sum)continue;
			ll g = __gcd(sum, lcm);
			lcm = lcm / g * sum;
		}
	for (int i = 1; i < 5; ++i)
		{
			ll sum = a[i].x + a[i].y + a[i].z, tmp = lcm / sum;
			a[i].x *= tmp, a[i].y *= tmp, a[i].z *= tmp;
		}
	int f1 = cross(1, 2, 4), f2 = cross(2, 3, 4), f3 = cross(3, 1, 4);
	if (!f1 && !f2 && !f3)
		{
			int x1 = (a[1].x - a[4].x > 0 ? 1 : a[1].x - a[4].x < 0 ? -1 : 0);
			int x2 = (a[3].x - a[4].x > 0 ? 1 : a[3].x - a[4].x < 0 ? -1 : 0);
			if ((x1 <= 0 && x2 <= 0) || (x1 >= 0 && x2 >= 0))
				{
					cout << "NO" << endl;
					return;
				}
			x1 = (a[1].y - a[4].y > 0 ? 1 : a[1].y - a[4].y < 0 ? -1 : 0);
			x2 = (a[3].y - a[4].y > 0 ? 1 : a[3].y - a[4].y < 0 ? -1 : 0);
			if (x1 > x2)swap(x1, x2);
			if ((x1 <= 0 && x2 <= 0) || (x1 >= 0 && x2 >= 0))
				{
					cout << "NO" << endl;
					return;
				}
			cout << "YES" << endl;
			return;
		}

	if ((f1 <= 0 && f2 <= 0 && f3 <= 0) || (f1 >= 0 && f2 >= 0 && f3 >= 0))
		{
			cout << "YES" << endl;
			return;
		}
	cout << "NO" << endl;
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
