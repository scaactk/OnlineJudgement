#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
}; 

node* init_node(int value){
	node* head = new node();
	head->data = value;
	head->next = head;
	return head;
} 

void create_list(node* head, int value)
{
	node* current_node = head;
	node* new_node = init_node(value);
	while(current_node->next!=head)
	{
		current_node  = current_node->next;
	}
	current_node->next = new_node;
	new_node->next = head;
}

node* init_list(int* arr,int len){
	node* head = init_node(arr[0]);
	for(int i=1;i<len;i++){
		create_list(head,arr[i]);
	}
	return head;
}

void list_traversal(node* head)
{
	node* current_node = head;
	cout<<head->data<<" ";
	while(current_node->next!=head)
	{
		current_node = current_node->next;
		cout<<current_node->data<<" ";
	}
	cout<<"\n";
}

node* delete_node(node* head, int value)
{
	node* current_node = head;
	node* pre_node; 
	while(current_node->data!=value && current_node->next!=head){
			pre_node = current_node;
			current_node = current_node->next; 
	}
	if(current_node->data==value){
		node* next_node = current_node->next;
		pre_node->next = next_node;
		//node* temp = current_node;
		delete(current_node);
		//return temp;
	}
} 


int main(){
	int n,m;
	cin>>n;
	cin>>m;
	int a[105];
	for(int i=0;i<n;i++){
		a[i] = i+1;
	}

	node* head = init_list(a,n);
	
	int choosed = 0;
	node* point = head;
	node* temp;
	int count = 1;
	while(choosed<n){
		if(count%m==0){
			cout<< point->data<<" ";
			temp = point->next;
			delete_node(head,point->data);
			list_traversal(head);
			point = temp;
			choosed++;
		}
		else{
			point = point->next;
		}
		count++;
	}
	//cout<<head->data<<endl;
}
