#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 110;
//��������
//�����ȶ���
int n;
int a[N];
int b[N];
int k[N];
int h = 1;
void countsort()
{
	int res = 1;//ÿ��һ�Σ�res*10������������
	int d = 1;
	while (d <= h)   //�����ظ�h�μ�������hΪ��λ���ļ�
		{
			memset(k, 0, sizeof(k));
			for (int i = 1; i <= n; ++i)k[a[i]]++;
			for (int i = 1; i <= 100; ++i)k[i] += k[i - 1];
			for (int i = n; i >= 1; --i)b[k[a[i]]--] = a[i];
			for (int i = 1; i <= n; ++i)a[i] = b[i];
			res *= 10;
			d++;
		}
}
int main()
{
	int maxn = -INF;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			maxn = max(a[i], maxn);
		}
	while (maxn / 10)
		{
			h++;//�����λ��
			maxn /= 10;
		}
	countsort();
	for (int i = 1; i <= n; ++i)cout << b[i] << " ";
	return 0;
}
