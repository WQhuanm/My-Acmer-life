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

int a[N], xu[N];

int main()
{
	int t, n;
	cin >> t;
	while (t--)
		{
			int ans = 0;
			cin >> n;
			for (int i = 1; i <= n; ++i)cin >> a[i], xu[a[i]] = i;
			for (int i = (n + 1) / 2; i >= 1; --i)
				{
					int k = n - i + 1;
					if (i == (n + 1) / 2)
						{
							if (xu[i] > xu[k])
								{
									ans = i;
									break;
								}
						}
					else
						{
							if (xu[i] > xu[k] || xu[i] >= xu[i + 1] || xu[k] <= xu[k - 1])
								{
									ans = i;
									break;
								}
						}
				}
			cout << ans << endl;
		}
	return 0;
}
