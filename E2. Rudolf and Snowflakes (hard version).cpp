#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;
int n;
int check(int i, int j)
{
	ll tmp = i * i, sum = i + 1;
	while (j--)
		{
			sum += tmp;
			if (sum > n)return -1;
			if (j && (n - sum) / tmp < i)return -1;
			tmp *= i;
		}
	if (sum == n)return 1;
	else if (sum < n)return 0;
	else return -1;
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= 64; ++i)
		{
			int l = 2, r =(ll)pow(n,1.0/(i+1));
			while (l <= r)
				{
					int mid = l + ((r - l) >> 1);
					int p = check(mid, i);
					if (p == 1)
						{
							cout << "YES" << endl;
							return;
						}
					else if (!p)l = mid + 1;
					else r = mid - 1;
				}
		}
	cout << "NO" << endl;
}

int32_t main()
{
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
