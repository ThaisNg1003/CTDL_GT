#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long a[n] = {}, b[n];
		for (int i = 0; i < min(n, 3); i++)
			a[i] = 1;
		b[0] = 1;
		for (int i = 1; i < n; i++)
		{
			if (i <= 3)
				a[i] = (a[i] + b[i - 1]);
			else
				a[i] += b[i - 1] - b[i - 4];
			b[i] = b[i - 1] + a[i];
		}
		cout << a[n - 1] << endl;
	}
}