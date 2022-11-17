#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

ll a[N];

vector<int> mul(vector<int>&A, ll b)
{
	vector<int>C;
	ll t = 0;
	for (int i = 0; i <= 500 && (i < (int)A.size() || t); ++i)
		{
			if (i < (int)A.size())t += A[i] * b;
			C.push_back(t % 10);
			t /= 10;
		}
	return C;
}

int main()
{
	int p;
	cin >> p;
	cout << (int)(p * log10(2) + 1) << endl;

	int k = 0;
	int c = 58;
	while (c < p)
		{
			p -= c;

			a[++k] = ((ll)1 << c);
		}
	if (p)a[++k] = ((ll)1 << p);
	vector<int>A;
	A.push_back(1);
	for (int i = 1; i <= k; ++i)
		{
			A = mul(A, a[i]);
		}
	A[0] -= 1;

	int h = 0;
	if ((int)A.size() >= 500)
		for (int i = 499; i >= 0; --i)
			{
				cout << A[i];
				h++;
				if (h == 50)
					{
						cout << endl;
						h = 0;
					}
			}
	else
		{
			for (int i = 1; i <= 500 - (int)A.size(); ++i)
				{
					cout << 0;
					h++;
					if (h == 50)
						{
							cout << endl;
							h = 0;
						}
				}
			for (int i = (int)A.size() - 1; i >= 0; --i)
				{
					cout << A[i];
					h++;
					if (h == 50)
						{
							cout << endl;
							h = 0;
						}
				}
		}

	return 0;
}
