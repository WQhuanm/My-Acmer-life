#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 10;

char a[N][N];
bool vx[N][N], vy[N][N], flag;
int b[N * N];
int k;

void dfs(int n)
{
	if (flag)return;
	int x = b[n] / 4, y = b[n] % 4 ;
	for (int i = 1; i <= 4; ++i)
		{
			if (!vx[x][i] && !vy[y][i])
				{
					bool fl = 1;
					for (int j = (x / 2 ) * 2; j < (x / 2) * 2 + 2; ++j)for (int h = (y / 2) * 2; h < (y / 2) * 2 + 2; ++h)
							{
								if (a[j][h] - '0' == i )
									{
										fl = 0;
										break;
									}
							}
					if (fl)
						{
							a[x][y] = i + '0';
							//	cout << a[x][y] << endl;
							vx[x][i] = vy[y][i] = 1;
							if (n == k)
								{
									flag = 1;
									return;
								}
							else if (n < k)
								{
									dfs(n + 1);
									if (flag)return;
									a[x][y] = '*';
									vx[x][i] = vy[y][i] = 0;
								}

						}
				}
		}
}

int main()
{
	int t;
	cin >> t;
	for (int q = 1; q <= t; ++q)
		{
			k = 0;
			flag = 0;
			memset(vx, 0, sizeof(vx));
			memset(vy, 0, sizeof(vy));
			memset(b, 0, sizeof(b));
			for (int i = 0; i < 4; ++i)for (int j = 0; j < 4; ++j)
					{
						cin >> a[i][j];
						if (a[i][j] == '*')
							{
								b[++k] = i * 4 + j;
							}
						else
							{
								int h = a[i][j] - '0';
								vx[i][h] = vy[j][h] = 1;
							}
					}

			dfs(1);
			printf("Case #%d:\n", q);
			for (int i = 0; i < 4; ++i)for (int j = 0; j < 4; ++j)
					{
						cout << a[i][j];
						if (j == 3)cout << endl;
					}
		}

	return 0;
}
