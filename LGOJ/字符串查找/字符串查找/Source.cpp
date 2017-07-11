#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n, q;
	cin >> n >> q;
	string  name[30];
	for (int i = 0; i < n; i++)
	{
		cin >> name[i];
	}
	for (int i = 0; i < q; i++)
	{
		string temp;
		cin >> temp;
		int flag = 0;
		for (int j = 0; j < n; j++)
		{
			if (temp == name[j]) 
			{
				flag = 1;
				cout << 1 << endl;
				break;
			}	
		}
		if (flag == 0) {
			cout << 0 << endl;
		}
	}
	system("pause");
	return 0;
}