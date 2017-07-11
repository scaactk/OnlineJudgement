#include<iostream>
using namespace std;
int main()
{
	int arr[100];
	int n;
	cin >> n;
	int x;
	cin >> x;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		if (arr[i] == x)
		{
			cout << i << endl;
			system("pause");
			return 0;//本校OJ，return 1 竟然会报RE....
		}
	}
	cout << -1 << endl;
	system("pause");
	return 0;
}