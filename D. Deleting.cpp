#include <bits/stdc++.h>
using namespace std;
#define endl             "\n"
const int N = 2000;

bitset<N>f[N<<1];
int n;
int cost[4010][4010];

void mysolve()
{
	cin >> n;
	for (int i = 0; i < n - 1; ++i)for (int j = i + 1; j < n; j += 2)cin >> cost[i][j];
	int l = 1, r = (n >> 1) * (n >> 1);
	int ans = r;
	while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
		for(int i=0;i<n;++i)f[i].reset();
			for (int i = n - 2; ~i; --i)for (int j = i + 1; j < n; j += 2)
					{
						if (cost[i][j] <= mid && (i + 1 == j  || f[i + 1][(j - 1) >> 1]))f[i][j >> 1] = 1;
						if (j + 1 < n && f[i][j >> 1])f[i] |= f[j + 1];
					}
			if (f[0][(n - 1) >> 1])ans = mid, r = mid - 1;
			else l = mid + 1;
		}
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
