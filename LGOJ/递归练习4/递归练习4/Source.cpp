#include<iostream>
using namespace std;
int main() {
	int arr[100];
	int temp = 0;
	int i = 0;
	cin >> temp;
	int m = temp;
	int sum = 0;
	for (i = 0; temp != -1; i++) {
		arr[i] = temp;
		sum += temp;
		if (temp > m) {
			m = temp;
		}
		cin >> temp;
	}
	cout << m << endl << i << endl << sum / i << endl;
	system("pause");
	return 0;
}