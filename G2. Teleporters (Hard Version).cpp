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

pair<int, int>a[N];
ll sum[N];

int main()
{
	int t, n, x, c;
	cin >> t;
	while (t--)
		{
			cin >> n >> c;
			int ans = 0;
			for (int i = 1; i <= n; ++i)
				{
					cin >> x;
					a[i].first = x + min(i, n - i + 1);
					a[i].second = x + i;
				}
			sort(a + 1, a + 1 + n);//对每个点的最小步排序
			for (int i = 1; i <= n; ++i)sum[i] = sum[i - 1] + a[i].first;//记录最小步前缀和
			for (int i = 1; i <= n; ++i)//遍历每个点作为第一步
				{
					int l = 0, r = n;
					while (l <= r)//二分点数
						{
							int mid = (l + r) >> 1;
							ll tmp = sum[mid] + a[i].second;
							int cnt = mid + 1;//cnt记录总共可以走的点数（包括第一步）
							if (i <= mid)tmp -= a[i].first, cnt--;//如果第一步的点在二分的前缀区间，减去a[i].first这个最小步，点数-1
							if (tmp <= c)
								{
									ans = max(ans, cnt);
									l = mid + 1;
								}
							else r = mid - 1;
						}
				}
			cout << ans << endl;
		}

	return 0;
}
