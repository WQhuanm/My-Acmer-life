#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
#define int              long long
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 3e5 + 10;
bool aishi(ll n)
{
	if (n < 5)
		{
			if (n == 2 || n == 3)return 1;
			return 0;
		}
	else
		{
			if (n % 6 != 1 && n % 6 != 5)return 0;
			for (int i = 5; 1ll * i * i <= n; i += 6)if (n % i == 0 || n % (i + 2) == 0)return 0;
		}
	return 1;
}
int n;
int a[N];
void mysolve()
{
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; ++i)cin >> a[i], sum += a[i];
	if (n == 1)cout << (aishi(a[1]) ? "Yes" : "No") << endl;
	else if (n == 2)
		{
			if (sum & 1)
				{
					if (aishi(sum - 2))
						{
							cout << "Yes" << endl;
							return;
						}
				}
			else if (sum >= 4)
				{
					cout << "Yes" << endl;
					return;
				}
			cout << "No" << endl;
		}
	else cout << (sum >= 2 * n ? "Yes" : "No") << endl;

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
