#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 3e5 + 10;

int a[N];
void mysolve()
{
	int n;
	cin >> n;
	vector<int>sz(10, 0);
	for (int i = 1; i <= n; ++i)cin >> a[i], sz[a[i]]++;
	cout << "- 0" << endl;
	vector<int>tmp(10, 0);
	for (int i = 1; i <= n; ++i)cin >> a[i], tmp[a[i]]++;
	int vis = -1;
	for (int i = 1; i <= 9; ++i)if (tmp[i] > sz[i])
			{
				vis = i;
				break;
			}
	if (vis == -1)
		{
			tmp = vector<int>(10, 0);
			cout << "- 0" << endl;
			for (int i = 1; i <= n; ++i)cin >> a[i], tmp[a[i]]++;
			for (int i = 1; i <= 9; ++i)if (tmp[i] > sz[i])
					{
						vis = i;
						break;
					}
		}
	cout << "- " << n - tmp[vis];
	for (int i = 1; i <= n; ++i)if (a[i] != vis)cout << " " << i;
	cout << endl;
	n = tmp[vis];
	int ans = -1;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			if (a[i] != vis)ans = i;
		}
	if (ans == -1)
		{
			cout << "- 0" << endl;
			for (int i = 1; i <= n; ++i)
				{
					cin >> a[i];
					if (a[i] != vis)ans = i;
				}
		}
	cout << "! " << ans << endl;
}

int32_t main()
{
//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
