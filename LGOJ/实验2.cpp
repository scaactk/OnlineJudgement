#include<iostream>
using namespace std;

struct node{
	int data;
	int id;
	node* next;
}; 

void list_traversal(node* head,int n){
	node* current_node = head;
	for(int i=0;i<2*n;i++){
		cout<<current_node->data<<" ";
		current_node = current_node->next; 
	}
	cout<<endl;
} 

int main(){
	int T;
	cin>>T;
	int n,m;
	node* head = new node();
	node* rear = new node();
	for(int t=0;t<T;t++){
		cin>>n;
		cin>>m;
		head->id = 1;
		cin>>(head->data); 
		rear = head;		
		node* temp;
		for(int i=2;i<=n;i++){
			temp = new node(); 
			temp->id = i;
			temp->next = NULL;
			cin>>(temp->data);
			rear->next = temp;
			rear = temp;
		}
		rear->next = head;//³õÊ¼»¯½áÊø
		 
		int sum=n;
		while(sum){
			int num=1;
			while(num<m){
				rear=head;
				head=head->next;
				num++;
			}
			if(sum==n) 
				cout<<(head->id);
			else
			cout<<" "<<(head->id);
			m=head->data;
			sum--;
			node* temp=head;
			head=temp->next;
			rear->next=head;
			delete(temp);
	}
	cout<<endl;
}
return 0;
} 
