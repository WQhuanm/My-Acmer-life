#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
ll a[N];
vector<ll>v[N];
int main()
{

	ll n;
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	sort(a + 1, a + 1 + n);//排序，从小到大，如果现有队列可以容纳a[i]，就把a[i]放入可以存放的数组中存的数最少的那一组
	ll k = 0;
	for (int i = 1; i <= n; ++i)
		{
			int maxn = INF, book, flag = 0;//maxn标记当前a[i]可以进入的数组的最小内存，book标记该数组的位置j，flag表示有没有找到可以放的数组
			for (int j = 1; j <= k; ++j)
				{
					if (a[i] - v[j][v[j][0]] == 1 && v[j][0] < maxn)//v[j][0] < maxn，保证最后是放入内存最小的数组
						{
							maxn = v[j][0];
							book = j;
							flag = 1;
						}
				}
			if (flag)
				{
					v[book].push_back(a[i]);
					v[book][0]++;

				}
			else//找不到，建立新的
				{
					v[++k].push_back(1);
					v[k].push_back(a[i]);
				}
		}
	ll ans = INF;
	for (int i = 1; i <= k; ++i)ans = min(v[i][0], ans);
	cout << ans << endl;
	return 0;
}
