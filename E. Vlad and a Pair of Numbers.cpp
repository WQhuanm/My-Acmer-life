#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;

void msolve()
{
	int x;
	cin >> x;
	if (x & 1)//x奇数显然无法构造
		{
			cout << -1 << endl;
			return;
		}
	else
		{
			int k = x >> 1;
			if ((k & x))//合法的构造即x必须没有连续的1，这样的他与右移一位的自己&得出是0，否则就一定不是0
				{
					cout << -1 << endl;//不是0说明无法构造
					return ;
				}
			cout << x / 2 * 3 << ' ' << x / 2 << endl;
		}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		{
			msolve();
		}

	return 0;
}
