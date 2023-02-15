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
const int N = 1e6 + 10;
ll sum[N];
int main()
{
	int n, q, l, r, x;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)cin >> l >> r, sum[l]++, sum[r + 1]--;//存储差分数组
	for (int i = 1; i < N; ++i)sum[i] += sum[i - 1];//转化为前缀和数组
	for (int i = 1; i < N; ++i)for (int j = i; j < N; j += i)if (sum[j])//记录所有不优雅的点
				{
					sum[i] = 1;
					break;
				}
	while (q--)
		{
			cin >> x;
			if (sum[x])cout << "NO" << endl;
			else cout << "YES" << endl;
		}

	return 0;
}
