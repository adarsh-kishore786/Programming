#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, k;
		cin >> n >> k;

		if (n == k)
		{
			for (int i = 0; i < n; i++)
				cout << i + 1 << " ";
			cout << endl;
		}
		else
		{
			int a[n];
			if (n % 2 == 1)
			{
				for (int i = 0; i < n; i++)
					a[i] = (i + 1) * pow(-1, i);
			}
			else
			{
				for (int i = 0; i < n; i++)
					a[i] = (i + 1) * pow(-1, i + 1);
			}

			int s = 1, count, diff = 0;
			count = (n % 2 == 0) ? n/2 : n/2 + 1;

			for (int i = 1; i <= n; i++)
			{
				s += a[i];
				if (s > 0)
				{
					if (count < k)
					{
						diff = k - count;
						for (int j = n; j >= 0; j--)
						{
							if (a[j] < 0)
							{
								a[j] *= -1;
								count++;
								if (count == k)
									break;
							}
						}
					}
					else if (count > k)
					{
						diff = count - k;
						for (int j = n; j >= 0; j--)
						{
							if (a[j] > 0)
							{
								a[j] *= -1;
								count--;
								if (count == k)
									break;
							}
						}
					}
				}
			}

			for (int i = 0; i < n; i++)
				cout << a[i] << " ";
			cout << "\n";
		}
	}
}