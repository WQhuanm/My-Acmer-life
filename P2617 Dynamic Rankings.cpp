#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 1e5 + 10;

#define mid (l+((r-l)>>1))

struct tree
{
	int ls, rs;
	int sum;
} t[N * 400];//n*logn*logn空间

int  a[N], b[N << 1], number[N << 1], temp[2][30];
int top, len;//b为离散化数组，len为b长度，number为版本
int n, m;

void update(int x, int l, int r, int w, int &p)
{
	if (!p)p = ++top; //动态开点
	t[p].sum = (t[p].sum + w);
	if (l == r)return;
	if (x <= mid)update(x, l, mid, w, t[p].ls);
	else update(x, mid + 1, r, w, t[p].rs);
}

void pre_update(int x, int w)
{
	int val = lower_bound(b + 1, b + 1 + len, a[x]) - b;
	for (int i = x; i <= n; i += i & -i)update(val, 1, len, w, number[i]);//对原数组a区间[x,n]上版本的每颗主席树进行树状数组维护
}

int kth(int l, int r, int k)
{
	if (l == r)return b[l];
	int sum = 0;//树状数组读取左区间信息
	for (int i = 1; i <= temp[0][0]; ++i)sum -= t[t[temp[0][i]].ls].sum;
	for (int i = 1; i <= temp[1][0]; ++i)sum += t[t[temp[1][i]].ls].sum;

	if (sum >= k)
		{
			for (int i = 1; i <= temp[0][0]; ++i)temp[0][i] = t[temp[0][i]].ls;
			for (int i = 1; i <= temp[1][0]; ++i)temp[1][i] = t[temp[1][i]].ls;
			return kth(l, mid, k);
		}
	else
		{
			for (int i = 1; i <= temp[0][0]; ++i)temp[0][i] = t[temp[0][i]].rs;
			for (int i = 1; i <= temp[1][0]; ++i)temp[1][i] = t[temp[1][i]].rs;
			return kth(mid + 1, r, k - sum);
		}
}

int pre_kth(int l, int r, int k)
{
	temp[0][0] = temp[1][0] = 0;
	for (int i = l - 1; i; i -= i & -i)temp[0][++temp[0][0]] = number[i];
	for (int i = r; i; i -= i & -i)temp[1][++temp[1][0]] = number[i];
	return kth(1, len, k);
}

void mysolve()
{
	for (int i = 1; i <= n; ++i)cin >> a[i], b[++len] = a[i];
	//--此处也要对修改信息预先读入来离散化

	//---
	sort(b + 1, b + 1 + len);
	len = unique(b + 1, b + 1 + len) - b - 1;

	for (int i = 1; i <= n; ++i)pre_update(i, 1);//载入初始区间信息
}

