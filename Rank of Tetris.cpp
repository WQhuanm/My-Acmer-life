#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e4 + 10;
int head[N], in[N], num, a[N], b[N], n, m, fa[N], flag, ans;
char s[N];
struct node
{
	int next, to;
} edge[N];

void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}

void init()
{
	memset(head, 0, sizeof(head));
	memset(in, 0, sizeof(in));
	for (int i = 0; i < n; ++i)fa[i] = i;//初始父亲为自己
	num = 0;
	flag = 1;//一开始flag为可以，后面0则不确定，-1则不行
	ans = n;//ans表示合并后剩余点的数量
}

int find(int x)
{
	if (fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
}

void mjudge()
{
	queue<int>q;
	int cnt = 0;
	for (int i = 0; i < n; ++i)if (!in[i] && i == fa[i])q.push(i);//首先该点入度为0而且还要是自己就是祖先才存入（所有剩余的点都是祖先，不是祖先的说明被合并了）
	while (!q.empty())
		{
			if ((int)q.size() > 1)flag = 0;//如果同时入度02个以上，说明不明确输出状况了，flag为0，但是不能直接返回，因为矛盾优先度高，必须跑完才知道是否矛盾
			int u = q.front();
			q.pop();
			cnt++;
			for (int i = head[u]; i; i = edge[i].next)
				{
					int v = edge[i].to;
					if (v == u)
						{
							flag = -1;//矛盾直接返回
							return;
						}
					if (--in[v] == 0)q.push(v);
				}
		}
	if (cnt < ans)flag = -1;//最后不是所有剩余点都入度，那么存在环
}

int main()
{
	int x, y;
	while (cin >> n >> m)
		{
			init();//该处初始化
			for (int i = 1; i <= m; ++i)
				{
					cin >> a[i] >> s[i] >> b[i];
					if (s[i] == '=')//先合并操作
						{
							x = find(a[i]), y = find(b[i]);
							if (x != y)fa[x] = y, ans--;//即使数据给重复，我们也不会重复合并，每一次合并都会减少一个点，即使是两个合并点合并成一个点也一样，每次合并，剩余点ans减一
						}
				}
			for (int i = 1; i <= m; ++i)if (s[i] != '=')//再对合并完的点操作
					{
						x = find(a[i]), y = find(b[i]);
						if (s[i] == '>')add(x, y), in[y]++;
						else add(y, x), in[x]++;
					}
			mjudge();
			if (flag == 1)cout << "OK" << endl;
			else if (!flag)cout << "UNCERTAIN" << endl;
			else cout << "CONFLICT" << endl;
		}

	return 0;
}

