#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 20;

int k = 3; //可以打印的次数
int n;
int bookz[N];
int bookf[N + 100];
int bookc[N];

int a[N];
int sum;
void dfs(int h)
{
	for (int i = 1; i <= n; ++i)
		{

			if (!bookf[i + h] && !bookz[i - h + 100] && !bookc[i])
				{
					bookf[i + h] = 1;
					bookz[i - h + 100] = 1;
					bookc[i] = 1;
					a[h] = i;

					if (h == n)
						{
							sum++;
							if (k)
								{
									k--;
									for (int j = 1; j <= n; ++j)
										{
											cout << a[j];
											if (j == n)cout << endl;
											else cout << " ";
										}
								}
						}
					else dfs(h + 1);
					bookf[i + h] = 0;
					bookz[i - h + 100] = 0;
					bookc[i] = 0;
				}
		}

}

int main()
{
	cin >> n;
	dfs(1);
	cout << sum << endl;
	return 0;
}
