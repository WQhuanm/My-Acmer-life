#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 12;

char a[N][N];
bool vx[N][N], vy[N][N], vk[N][N];
int nx[N], ny[N], nk[N];
char c;
int _i = 1, _j = 1;
struct node
{
	int x, y;
};
vector<node>v;
bool f;
int ju(int _i, int _j);

void init()
{
	memset(vx, 0, sizeof(vx));
	memset(vy, 0, sizeof(vy));
	memset(vk, 0, sizeof(vk));
	memset(nx, 0, sizeof(nx));
	memset(ny, 0, sizeof(ny));
	memset(nk, 0, sizeof(nk));
	v.clear();
}

void dfs(int q, int t)
{
	//cout << q << ' ' << t << endl;
	if (f)return;
	int x = v[q].x, y = v[q].y;
	int h = ju(x, y);
	for (int i = 1; i <= 9; ++i)
		{
			if (!vx[x][i] && !vy[y][i] && !vk[h][i])
				{
					vx[x][i] = vy[y][i] = vk[h][i] = 1;
					a[x][y] = i + '0';
					if (q == t - 1)
						{
							f = 1;
							return;
						}
					else
						{
							dfs(q + 1, t);
						}
					if (f)return;
					vx[x][i] = vy[y][i] = vk[h][i] = 0;
					a[x][y] = '?';
				}
		}

}

int main()
{
	bool fl = 0;
	while (cin >> c)
		{

			if (fl)
				{
					fl = 0;
					cout << endl;
				}

			a[_i][_j] = c;
			if (c != '?')
				{
					int k = c - '0';
					int h = ju(_i, _j);
					++nk[h], ++nx[_i], ++ny[_j];
					vx[_i][k] = vy[_j][k] = vk[h][k] = 1;
				}
			if (_i == 9 && _j == 9)
				{
					fl = 1;
					_i = 0, _j = 9;
//					bool flag = 1;

					for (int i = 1; i <= 9; ++i)for (int j = 1; j <= 9; ++j)if (a[i][j] == '?')v.push_back({i, j});

					int t = v.size();
					if (t)
						{
							f = 0;
							dfs(0, t);
						}
					for (int i = 1; i <= 9; ++i)for (int j = 1; j <= 9; ++j)
							{
								cout << a[i][j];
								if (j == 9)cout << endl;
								else cout << " ";
							}

					init();

				}
			++_j;
			if (_j == 10)++ _i, _j = 1;
		}

	return 0;
}

//while (flag)
//{
//	flag = 0;
//	for (int i = 1; i <= 9; ++i)for (int j = 1; j <= 9; ++j)if (a[i][j] == '?')
//	{
//		int x = 0;
//		if (nx[i] == 8)
//		{
//			flag = 1;
//			++nx[i],++ny[j];
//			if (!x)
//			{
//				for (int k = 1; k <= 9; ++k)if (!vx[i][k])
//				{
//					x = k;
//					break;
//				}
//				a[i][j] = x + '0';
//			}
//			vx[i][x] = 1;
//
//		}
//		if (ny[j] == 8)
//		{
//			flag = 1;
//			++ny[j];
//			if (!x)
//			{
//				for (int k = 1; k <= 9; ++k)if (!vy[j][k])
//				{
//					x = k;
//					break;
//				}
//				a[i][j] = x + '0';
//			}
//			vy[j][x] = 1;
//		}
//		int h = ju(i, j);
//		if (nk[h] == 8)
//		{
//			flag = 1;
//			++nk[h];
//			if (!x)
//			{
//				for (int k = 1; k <= 9; ++k)if (!vk[h][k])
//				{
//					x = k;
//					break;
//				}
//				a[i][j] = x + '0';
//			}
//			vk[h][x] = 1;
//		}
//	}
//}

int ju(int _i, int _j)
{

	if (_i <= 3)
		{
			if (_j <= 3)
				{
					return 1;
				}
			else if (_j <= 6)
				{
					return 2;
				}
			else
				{
					return 3;
				}
		}
	else if (_i <= 6)
		{
			if (_j <= 3)
				{
					return 4;
				}
			else if (_j <= 6)
				{
					return 5;
				}
			else
				{
					return 6;
				}
		}
	else
		{
			if (_j <= 3)
				{
					return 7;
				}
			else if (_j <= 6)
				{
					return 8;
				}
			else
				{
					return 9;
				}
		}
}

