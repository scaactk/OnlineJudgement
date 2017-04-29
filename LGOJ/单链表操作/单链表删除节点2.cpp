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

void delete_node(node* head,int value)
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
    else{
    	cout<<"-1"<<endl;
	}
}

int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++){	
		int n;
		cin>>n;
		int arr[105];
		for(int j=0;j<n;j++){
			cin>>arr[j];
		}
		node* h;
		h = init_list(arr,n);	
		int q;
		cin>>q;
		for(int k=0;k<q;k++){
			int type;
			cin>>type;
			if(type==0){
				list_traversal(h);
			}
			if(type==1){
				int x;
				cin>>x;
				delete_node(h,x);
			}
		}
		
	}
} 
