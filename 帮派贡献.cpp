#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int N = 150;

struct node
{
	string name, zw;
	ll xu, cotri, degree, now;
} arr[N];

bool cmp(node x, node k)
{
	if (x.xu != k.xu)
		{
			return x.xu < k.xu;
		}
	else
		{
			if (x.degree != k.degree)
				return x.degree > k.degree;
			else return x.now < k.now;
		}
}

bool cmp1(node x, node y)
{
	if (x.cotri != y.cotri)
		return x.cotri > y.cotri;
	else return x.now < y.now;
}

bool cmp2(node x, node k)
{
	return x.xu < k.xu;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		{
			cin >> arr[i].name >> arr[i].zw >> arr[i].cotri >> arr[i].degree;
			arr[i].now = i;
			if (arr[i].zw == "BangZhu")arr[i].xu = 1;
			else if (arr[i].zw == "FuBangZhu")arr[i].xu = 2;
			else if (arr[i].zw == "HuFa")arr[i].xu = 3;
			else if (arr[i].zw == "ZhangLao")arr[i].xu = 4;
			else if (arr[i].zw == "TangZhu")arr[i].xu = 5;
			else if (arr[i].zw == "JingYing")arr[i].xu = 6;
			else if (arr[i].zw == "BangZhong")arr[i].xu = 7;
		}
	sort(arr + 4, arr + 1 + n, cmp1);//按贡献
	for (int i = 4; i <= n; ++i)
		{

			if (i <= 5)
				arr[i].zw = "HuFa", arr[i].xu = 3;
			else if (i <= 9)arr[i].zw = "ZhangLao", arr[i].xu = 4;
			else if (i <= 16)arr[i].zw = "TangZhu", arr[i].xu = 5;
			else if (i <= 41)arr[i].zw = "JingYing", arr[i].xu = 6;
			else arr[i].zw = "BangZhong", arr[i].xu = 7;
		}
	sort(arr + 1, arr + 1 + n, cmp);//按职位
	for (int i = 1; i <= n; ++i)
		{
			cout << arr[i].name << ' ' << arr[i].zw << ' ' << arr[i].degree << endl;

		}

	return 0;
}
