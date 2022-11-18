#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

struct dac
{
	ll a, b;
	bool operator<(const dac&k)const
	{
		return max(k.b, a * b) < max(b, k.a * k.b);//返回真是不交换，所以只有不再满足交换前最小，我才交换
	}
} a[N];

vector<int> mul(vector<int>&A, ll b)//高精度乘法
{
	int t = 0;
	vector<int>C;
	for (int i = 0; i < (int)A.size() || t; ++i)
		{
			if (i < (int)A.size())t += A[i] * b;
			C.push_back(t % 10);
			t /= 10;

		}
	return C;
}

vector<int> dele(vector<int>&A, ll b, int &r)//高精度除法
{
	r = 0;
	vector<int>C;
	for (int i = (int)A.size() - 1; i >= 0; --i)
		{
			r = r * 10 + A[i];
			C.push_back(r / b);
			r %= b;
		}
	reverse(C.begin(), C.end());
	while ((int)C.size() > 1 && C.back() == 0)C.pop_back();
	return C;
}

bool cmp(vector<int>&A, vector<int>&B, int r, int r0)//高精度比较
{
	if ((int)A.size() != (int)B.size())return (int)A.size() >= (int)B.size();
	else
		{
			for (int i = (int)A.size() - 1; i >= 0; --i)return A[i] >= B[i];
		}
	if (r != r0)return r >= r0;
	return 1;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= n; ++i)cin >> a[i].a >> a[i].b;
	sort(a + 1, a + 1 + n);
	vector<int>A;
	vector<int>B;
	B.push_back(0);
	A.push_back(1);
	for (int i = 1; i <= n; ++i)
		{
			int r0 = 0, r;
			A = mul(A, a[i - 1].a);
			auto C = dele(A, a[i].b, r);
			if (!cmp(B, C, r0, r))
				{
					B = C;
				}
		}
	for (int i = (int)B.size() - 1; i >= 0; --i)cout << B[i];
	return 0;
}
