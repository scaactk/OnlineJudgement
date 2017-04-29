#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* init_node(int value)
{
    node* head = new node();
    head->data = value;
    head->next = NULL;
    return head;
}
void create_list(node* head,int value)
{
    node* current_node = head;
    node* new_node = init_node(value);
    while(current_node->next!=NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

node* init_list(int* _arr,int len)
{
    node* head = init_node(0);
    for(int i=0;i<len;i++)
    {
        create_list(head,_arr[i]);
    }
    return head;
}

void list_traversal(node* head)
{
    node* current_node = head;
    if(current_node->next==NULL){
    	cout<<"-1"<<endl;
	}
    while(current_node->next!=NULL)
    {
        current_node = current_node->next;
        if(current_node->next!=NULL){
        	cout<<current_node->data<<" ";
		}
		else if(current_node->next==NULL){
			cout<<current_node->data<<endl;
		}
    }
}

void delete_node(node* head, int value)
{
    node* current_node = head;
    node* pre_node; 
    while(current_node->data!=value && current_node->next!=NULL){
        pre_node = current_node;
        current_node = current_node->next;
    }
    if(current_node->data==value){
        node* next_node = current_node->next;
        pre_node->next = next_node;
        delete(current_node);
    }
}

void delete_node_range(node* head,int value1,int value2)
{
	node* current_node = head;
	node* pre_node; 
	while(current_node->next!=NULL){
		pre_node = current_node;
		current_node = current_node->next;
		if(current_node->data>value1 && current_node->data<value2){

			delete_node(head, current_node->data);
			current_node = head;
			//node* next_node = current_node->next;
		    //pre_node->next = next_node;
			//delete(current_node); //删除当前符合条件的node
			//current_node = next_node;//指向被删node的下一个 
			//这里遇到了一个bug: 如果写成 node* current_node = next_node则导致while死循环，待解决 
		}
	}
}

int main()
{
	int T;
	cin>>T;
for(int k=0;k<T;k++){
	node* head;
	int arr[105];
	int length;
	cin>>length; 
	for(int i=0;i<length;i++){
		cin>>arr[i];
	}
	head = init_list(arr,length);//创建链表部分 
	int q;
	cin>>q;
	for(int m=0;m<q;m++){
		int type;
		cin>>type;
		if(type==1){
			list_traversal(head);
		}
		if(type==2){
			int max,min;
		cin>>min>>max; 
		delete_node_range(head,min,max);
		}
	}	
}
return 0;
} 
