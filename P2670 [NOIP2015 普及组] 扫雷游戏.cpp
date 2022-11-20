#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 110;

int way[8][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};

char a[N][N];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
				cin >> a[i][j];
		}
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)
			{
				if (a[i][j] == '?')
					{
						int count = 0;
						for (int k = 0; k <= 7; ++k)
							{
								int x = i + way[k][0], y = j + way[k][1];
								if (x >= 1 && x <= n && y >= 1 && y <= m)
									{
										if (a[x][y] == '*')count++;
									}

							}
						a[i][j] = '0' + count;
					}
			}
	for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
				{
					cout << a[i][j];
				}
			cout << endl;
		}

	return 0;
}
