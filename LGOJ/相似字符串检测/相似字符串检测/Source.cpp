//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	int n;
//	int q;
//	cin >> n >> q;
//	string* dic;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> dic[i];
//	}
//}
#include <iostream>
#include <cmath>
using namespace std;
int check(string a, string b)
{
	int u = 0;
	if (a.length() - b.length() == 0)
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] != b[i])
			{
				u++;
			}
		}
		if (u <= 1)
		{
			return(1);
		}
	}
	else if (a.length() - b.length() == 1)
	{
		for (int i = 0, j = 0; a[i] != '\0' && b[j] != '\0'; i++)
		{
			char x = a[i], y = b[i];
			if (a[i] != b[j])
			{
				u++;
			}
			else {
				j++;
			}
		}
		if (u <= 1)
		{
			return(1);
		}
	}
	else if (b.length() - a.length() == 1)
	{
		for (int i = 0, j = 0; b[i] != '\0' && a[j] != '\0'; i++)
		{
			if (b[i] != a[j])
			{
				u++;
			}
			else {
				j++;
			}
		}
		if (u <= 1)
		{
			return(1);
		}
	}
	return(0);
}


int main()
{
	int	n, q;
	string	arr[20];
	cin >> n >> q;
	int index = 0;
	while (index < n)
	{
		cin >> arr[index];
		index++;
	}
	int s_index = 0;
	while (s_index < q)
	{
		string	t;
		int	ab;
		cin >> t;
		for (int i = 0; i < n; i++)
		{
			ab = arr[i].length() - t.length();
			if (ab <= 1 && ab >= -1)
			{
				if (check(arr[i], t))
				{
					cout << 1 << endl;
					break;
				}
			}
			if (i == n - 1)
			{
				cout << 0 << endl;
			}
		}
		s_index++;
	}
	system("pause");
	return(0);
}


