#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 500;

struct node
{
	int jq, t;
} arr[N][N]; //arr[i][j]表示第i工件第j步骤的所在机器jq与时间t

bool tline[30][10000000];//tline[i][]表示机器i的时间轴，时间轴尽量开长一点
int lasttime[30];//表示上一次工件加工的最后时间
int xu[N];//记录给定序列
int now[30];//表示工件目前加工到第几步
int main()
{
	int n, m;
	cin >> m >> n;
	for (int i = 1; i <= n * m; ++i)cin >> xu[i];
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)cin >> arr[i][j].jq;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)cin >> arr[i][j].t;
	for (int i = 1; i <= m * n; ++i)
		{
			int x = xu[i];//x为工件
			int y = ++now[x];//y为步骤
			int s = 0;
			int jq = arr[x][y].jq;
			int t = arr[x][y].t;
			//这个时间没有上限
			for (int j = lasttime[x] + 1;  ; ++j)//每次从上一次这个工件加工的时间开始
				{
					if (!tline[jq][j])//遍历该机器的时间轴，直到找到可以容纳t长度的时间
						{
							s++;
						}
					else s = 0;//每次中断，都要重新开始
					if (s == t)
						{
							lasttime[x] = j;//找到后，把这段时间全部标记为找到，然后就跳出
							for (int k = j - t + 1; k <= j; ++k)tline[jq][k] = 1;
							break;
						}
				}
		}
	int h = -1;
	for (int i = 1; i <= n; ++i)h = max(h, lasttime[i]);//找最长的时间轴
	cout << h << endl;
	return 0;
}

