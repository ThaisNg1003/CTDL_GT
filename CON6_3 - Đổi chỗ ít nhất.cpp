#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k, ans = 0;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n - 1; i++)
		{
			k = i;
			for (int j = i + 1; j < n; j++)
				if (a[j] < a[k])
					k = j;
			if (k != i)
				ans++;
			swap(a[k], a[i]);
		}
		cout << ans << endl;
	}
}