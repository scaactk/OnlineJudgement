#include<iostream>
using namespace std;
int get_sum(int* arr,int n)
{
	if (n < 1) return 0;
	return arr[n-1] + get_sum(arr,n-1);
}
int get_max(int* arr, int n)
{
	if (n < 1) {
		return -9999;
	}
	return arr[n - 1] > get_max(arr, n - 1) ? arr[n - 1] : get_max(arr, n - 1);
}
int get_average(int* arr, int n,int length)
{
	/*if (n < 1) {
		return 0;
	}
	return arr[n - 1] / length + get_average(arr, n - 1, length);
	*/
	//由于每次都进行除法计算并且取整，计算存在损失
	int sum = get_sum(arr, n);
	return sum / length;
}
int main()
{
	int n;
	cin >> n;
	int arr[100 + 5];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int max = get_max(arr, n);
	cout << max << endl;
	int sum = get_sum(arr, n);
	cout << sum << endl;
	int average = get_average(arr, n, n);
	cout << average << endl;
	//system("pause");
	return 0;
}