#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

struct apple
{
	ll x, y;
	bool operator<(const apple&b)const
	{
		return y < b.y;
	}
} arr[N];

int main()
{
	int n, s, a, b;
	cin >> n >> s >> a >> b;
	for (int i = 1; i <= n; ++i)
		{
			cin >> arr[i].x >> arr[i].y;
			if (arr[i].x > a + b)arr[i].y = INF;
		}
	sort(arr + 1, arr + 1 + n);
	ll sum = 0;
	for (int i = 1; i <= n; ++i)
		{
			if (s >= arr[i].y)
				{
					sum++;
					s -= arr[i].y;
				}
		}
	cout << sum << endl;
	return 0;
}
