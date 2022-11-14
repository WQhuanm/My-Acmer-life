#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;
char a[N];
int book[10];
ll ans;
void mymin()
{
	int n;
	cin >> n >> a;
	ll sum = n;
	for (int i = 0; i < n; ++i)
		{
			if (!book[a[i] - '0'])
				{
					ans++;
					book[a[i] - '0']++;
				}
		}
	//cout << ans << endl << endl;
	int thelen = n;
	if (n > ans * ans)thelen = ans * ans;
	for (int i = 0; i < n; ++i)
		{
			memset(book, 0, sizeof(book));
			ans = 1;
			book[a[i] - '0']++;
			for (int j = i + 1; j - i + 1 <= thelen && j < n; ++j)
				{
					if (!book[a[j] - '0'])ans++;
					book[a[j] - '0']++;
					int flag = 1;
					for (int k = 0; k <= 9; ++k)if (book[k] > ans)flag = 0;
					if (flag)sum++;
				}

		}

	cout << sum << endl;
}
int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		{
			mymin();
		}
	return 0;
}
