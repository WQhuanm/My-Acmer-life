#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

int a[N];
bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	int w, n;
	cin >> w >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	sort(a + 1, a + 1 + n, cmp);
	int right = n, left = 1;
	ll sum = 0;
	while (left <= right)
		{
			if (a[left] + a[right] <= w)
				{
					left++;
					right--;
				}
			else left++;
			sum++;
		}
	cout << sum << endl;
	return 0;
}
