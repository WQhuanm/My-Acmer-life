#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

int book[N];

vector<int> mul(vector<int>&A, int b)
{
	vector<int>C;
	int t = 0;
	for (int i = 0; i < (int)A.size() || t; ++i)
		{
			if (i < (int)A.size())t += A[i] * b;
			C.push_back(t % 10);
			t /= 10;
		}
	while ((int)C.size() > 1 && C.back() == 0)C.pop_back();
	return C;
}

int main()
{
	int n;
	cin >> n;
	if (n <= 4)
		{
			cout << n << endl;
			cout << n << endl;
			return 0;
		}
	int i = 2;

	while (i < n)
		{
			book[i] = 1;
			n -= i;
			i++;
		}
	book[i] = 1;
	int k = i;
	if (i - n == 1)
		{
			book[2] = 0;
			book[i + 1] = 1;
			k++;
		}
	else
		{
			book[i - n] = 0;
		}

	vector<int>A;
	A.push_back(1);
	for (int i = 2; i <= k; ++i)
		{
			if (book[i])
				A = mul(A, i);
		}
	for (int i = 2; i <= k; ++i)
		{
			if (book[i])
				{
					cout << i;
					if (i == k)cout << endl;
					else cout << ' ';
				}
		}
	for (int i = (int)A.size() - 1; i >= 0; --i)cout << A[i];

	return 0;
}
