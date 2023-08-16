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

int in[N];
void mysolve()
{
	int n;
	cin >> n;
	int x;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)cin >> x, in[i] += x;
	sort(in + 1, in + 1 + n);
	for (int i = 1, j = 0, cnt = 0; i <= n; ++i)
		{
			cnt += in[i];
			if (cnt == i * (i - 1) / 2)
				{
					if (i - j < 3)
						{
							cout << n - 1 << endl;
							return;
						}
					j = i;
				}
		}
	cout << n << endl;
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
