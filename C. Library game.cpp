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

int n, m;
int a[N];
bool vis[N];
void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	sort(a + 1, a + 1 + n, greater<int>());
	int len, x;
	for (int i = 1; i <= n; ++i)if (a[i] > m / i)
			{
				cout << "Bernardo" << endl;
				int now = (m + i - 1) / i;
				for (int j = 1; j <= n; ++j)
					{
						cin >> len >> x;
					bool fl=1;
						for (int k = x; k < len + x; ++k)if (k % now == 0)
								{
									cout << k << endl;
							fl=0;
									break;
								}
					if(fl)cout<<x<<endl;
					}
				return;
			}
	cout << "Alessia" << endl;

	for (int i = 1; i <= n; ++i)
		{
			for (int l = 1; l + a[i] - 1 <= m; ++l)
				{
					bool fl = 1;
					for (int j = l; j < l + a[i]; ++j)if (vis[j])fl = 0;
					if (fl)
						{
							cout << a[i] << " " << l << endl;
							break;
						}
				}
			cin >> x;
			vis[x] = 1;
		}
}

int32_t main()
{

	mysolve();
	system("pause");
	return 0;
}
