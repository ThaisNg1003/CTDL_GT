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
		int n, k, x, pos;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (x == k)
				pos = i;
		}
		cout << pos + 1 << endl;
	}
}