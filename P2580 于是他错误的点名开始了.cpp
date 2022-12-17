#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;
const int N = 5e5 + 100;

int num;//跟链式向前星差不多的作用，代替指针
int ch[N][26];//ch[u][k]表示u这个结点，字母为k是否有值（num），有给证明存在这个节点
int cnt[N];//统计每个单词结尾，出现一次标记为1
int main()
{
	int n, m, c;
	string s;
	//存入
	cin >> n;
	for (int i = 1; i <= n; ++i)
		{
			cin >> s;
			int u = 0; //每次u都从根节点开始     //注意，u于num的初始值必须相同，因为两者作用相同，起到类似指针的作用
			for (int j = 0; j < (int)s.size(); ++j)
				{
					c = s[j] - 'a';
					if (!ch[u][c])
						{
							ch[u][c] = ++num;   //没有就新建一只手
						}

					u = ch[u][c]; //深入子节点
				}
			cnt[u] = 1; //记录一个完整单词
		}
	//搜索
	cin >> m;
	for (int i = 1; i <= m; ++i)
		{
			cin >> s;
			int u = 0;
			for (int j = 0; j < (int)s.size(); ++j)
				{
					c = s[j] - 'a';
					if (!ch[u][c])break; //如果这个节点没有值，说明不存在这个单词，直接跳出
					u = ch[u][c]; //有就继续深入
				}
			if (cnt[u] == 1)
				{
					cnt[u] = 2; //记录下次会不会重复访问
					cout << "OK" << endl;
				}
			else if (cnt[u] == 2)cout << "REPEAT" << endl;
			else cout << "WRONG" << endl;
		}
	return 0;
}
