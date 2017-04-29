#include<iostream> 
using namespace std;
int list_traversal(int* arr, int length){
	if(length==0){
		cout<<-1<<endl;
		return 0;
	}
	else{
		int i;
		for( i=0;i<length-1;i++){
			cout<<arr[i]<<" ";
		}
		cout<<arr[i];
		cout<<endl;
		return 0;
	}
}
int list_del(int* arr, int length, int del){
	for(int i=0;i<length;i++){
		if(arr[i] == del){
			for(int j=i;j<length;j++){
				arr[j] = arr[j+1];
			}
			arr[length-1] = '\0';
			return 1;
		}
	}
	cout<<-1<<endl;
	return 0;
}
int main(){
	int T;
	cin>>T;
	for(int j=0;j<T;j++){
		int n;
		cin>>n;
		int arr[105];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int q;
		cin>>q;
		for(int i=0;i<q;i++){
			int type;
			cin>>type;
			if(type==0){
				list_traversal(arr,n);
			}
			if(type==1){
				int del;
				cin>>del;
				int a = list_del(arr,n,del);
				if(a==1){
					n--;
				}
			}
		}
	}
	return 0;
}
