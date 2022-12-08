#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e6 + 100;
bool vis[N];
int a, b;
int fa[N];
int num[N][10];
int ans;
void dfs(int x)
{
	ans++;
	if (!fa[x])
		{
			cout << ans - 1 << endl;
			return;
		}
	dfs(fa[x]);
	cout << num[x][1] << num[x][2] << num[x][3] << num[x][4] << endl;

}

bool judge(int x)
{
//	cout << 1 << endl;
	if (x == b)
		{
			ans = 0;
			//cout << 1 << endl;
			dfs(x);
			return 1;
		}
	return 0;
}

void bfs()
{
	queue<int>q;
	q.push(a);
	vis[a] = 1;
	while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = 1; i <= 16; ++i)
				{
					if (i % 4 != 0)//right
						{
							int t1 = (x >> i) & 1, t2 = (x >> (i + 1)) & 1;
							if (t1 != t2)
								{
									int tmp = x;
									tmp ^= (1 << i);
									tmp ^= (1 << (i + 1));
									if (!vis[tmp])
										{
											fa[tmp] = x;
											vis[tmp] = 1;
											q.push(tmp);
											num[tmp][1] = (i - 1) / 4 + 1, num[tmp][2] = i % 4 == 0 ? 4 : i % 4, num[tmp][3] = num[tmp][1], num[tmp][4] = num[tmp][2] + 1;
											if (judge(tmp))return;
										}
								}
						}

					if (i % 4 != 1) //left
						{
							int t1 = (x >> i) & 1, t2 = (x >> (i - 1)) & 1;
							if (t1 != t2)
								{
									int tmp = x;
									tmp ^= (1 << i);
									tmp ^= (1 << (i - 1));
									if (!vis[tmp])
										{
											fa[tmp] = x;
											vis[tmp] = 1;
											q.push(tmp);
											num[tmp][1] = (i - 1) / 4 + 1, num[tmp][2] = i % 4 == 0 ? 4 : i % 4, num[tmp][3] = num[tmp][1], num[tmp][4] = num[tmp][2] - 1;
											if (judge(tmp))return;
										}
								}
						}

					if ((i - 1) / 4 != 0) //up
						{
							int t1 = (x >> i) & 1, t2 = (x >> (i - 4)) & 1;
							if (t1 != t2)
								{
									int tmp = x;
									tmp ^= (1 << i);
									tmp ^= (1 << (i - 4));
									if (!vis[tmp])
										{
											fa[tmp] = x;
											vis[tmp] = 1;
											q.push(tmp);
											num[tmp][1] = (i - 1) / 4 + 1, num[tmp][2] = i % 4 == 0 ? 4 : i % 4, num[tmp][3] = num[tmp][1] - 1, num[tmp][4] = num[tmp][2];
											if (judge(tmp))return;
										}
								}

						}
					if ((i - 1) / 4 != 3)//down
						{
							int t1 = (x >> i) & 1, t2 = (x >> (i + 4)) & 1;
							if (t1 != t2)
								{
									int tmp = x;
									tmp ^= (1 << i);
									tmp ^= (1 << (i + 4));
									if (!vis[tmp])
										{
											fa[tmp] = x;
											vis[tmp] = 1;
											q.push(tmp);
											num[tmp][1] = (i - 1) / 4 + 1, num[tmp][2] = i % 4 == 0 ? 4 : i % 4, num[tmp][3] = num[tmp][1] + 1, num[tmp][4] = num[tmp][2];
											if (judge(tmp))return;
										}
								}
						}

				}

		}
}
int main()
{
	char c;
	for (int i = 1; i <= 16; ++i)
		{
			cin >> c;
			a += ((c - '0') << i);
		}
	for (int i = 1; i <= 16; ++i)
		{
			cin >> c;
			b += ((c - '0') << i);
		}
	if (a == b)
		{
			cout << 0 << endl;
			return 0 ;
		}

	bfs();

	return 0;
}
