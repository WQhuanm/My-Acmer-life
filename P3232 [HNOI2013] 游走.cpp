#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define eps 1e-8
const int N = 510;
vector<int>edge[N];
pii b[N*N];
int n, m;
double a[N][N], ans[N];

void print()//打印看目前情况
{
	cout << endl;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m + 1; ++j)cout << a[i][j] << " \n"[j == n + 1];
	cout << endl;
}

int gauss()
{
	int r = 1; //r表示目前处理到第r行

	for (int i = 1; i <= m && r <= n; ++i) //处理列数不超过m列，成功处理的列数也要小于行数（最多n行可处理，你列数再多也没用）
		{
			int mx = r; //mx记录当前处理列最大主元所在行
			for (int j = r + 1; j <= n; ++j)if (fabs(a[j][i] > fabs(a[mx][i])))mx = j; //第r次处理，但是比较的还是目前第i列元素（前面有可能有的列不用处理）
			if (fabs(a[mx][i]) < eps)continue; //最大主元为0
			if (mx != r)for (int j = 1; j <= m + 1; ++j)swap(a[r][j], a[mx][j]); //把主元最大的行提到第r行来处理
			for (int j = 1; j <= n; ++j)if (j != r) //处理不是第r行的其他行
					{
						double tmp = a[j][i] / a[r][i];
						for (int k = r; k <= m + 1; ++k)a[j][k] -= a[r][k] * tmp;
					}
			r++;
//			print();
		}
//	print();
	for (int i = r; i <= n; ++i)if (fabs(a[i][m + 1]) > eps) //存在零行,这里r是未处理的，多加了一次
			{
				return -1;//0行但是b！=0
			}
	if (r <= m)return 0; //存在自由元，有无穷解
	else for (int i = 1; i <= n; ++i)ans[i] = fabs(a[i][m + 1] / a[i][i]) < eps ? 0.00 : a[i][m + 1] / a[i][i]; //防止-0,00出现
	return 1;
}

int an, am;
int deg[N];
double res[N*N];
void mysolve()
{
	cin >> an >> am;
	n = an - 1, m = an - 1 ;
	for (int i = 1; i <= am; ++i)cin >> b[i].first >> b[i].second, edge[b[i].first].push_back(b[i].second), edge[b[i].second].push_back(b[i].first), deg[b[i].first]++, deg[b[i].second]++;
	for (int i = 1; i < an; ++i)
		{
			for (auto v : edge[i])if (v != an)
					a[i][v] = 1.0 / deg[v];
			a[i][i] = -1;
			if (i == 1)a[i][m + 1] = -1;
		}
//	print();
	gauss();
	for (int i = 1; i <= am; ++i)res[i] = ans[b[i].first] / deg[b[i].first] + ans[b[i].second] / deg[b[i].second];
	sort(res + 1, res + am + 1);
	double sum = 0;
	for (int i = 1; i <= am; ++i)sum += (am - i + 1) * res[i];
	printf("%.3lf\n", sum);
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
