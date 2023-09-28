#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;

int n, a, b;
int A[N], B[N];

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> A[i];
	for (int i = 1; i <= n; ++i)cin >> B[i];
	int one = 0, two = 0, thr = 0;
	for (int i = 1; i <= n; ++i)
		{
			a = A[i], b = B[i];
			int st = 0, t = 0;
			while (1)
				{
					if (!a)
						{
							t = b ? 3 : 1;
							break;
						}
					else if (!b)
						{
							st++, t = a ? 3 : 1;
							break;
						}
					else if (a == b)
						{
							st += 2, t = 3;
							break;
						}
					else
						{
							if (a > b)
								{
									int cnt = a / b;
									st += cnt / 2 * 3;
									a -= cnt / 2 * 2 * b;
									if (a > b)
										{
											int ta = a, tb = b;
											st += 2, a -= b, b = 2 * tb - ta;
										}
								}
							else
								{
									int ta = a, tb = b;
									st += 2;
									a = tb - ta, b = ta;
								}
						}
				}
			if (t == 1)one++, two++, thr++;
			else if (st % 3 == 0)one++;
			else if (st % 3 == 1)two++;
			else thr++;
		}
	cout << (one == n || two == n || thr == n ? "YES" : "NO") << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
