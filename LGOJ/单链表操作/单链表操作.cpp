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

void create_list(node* head, int value)
{
	node* current_node = head;
	node* new_node = init_node(value);
	while(current_node->next!=NULL)
	{
		current_node = current_node->next;
	} 
	current_node->next = new_node;
}

node* init_list(int* arr, int len)
{
	node* head = init_node(0);
	for(int i=0;i<len;i++){
		create_list(head, arr[i]);
	}
	return head;
}

void insert_node_beforeVar(node* head, int var, int value)
{
	node* current_node = head;
	node* pre_node;
	while(current_node)
	{
		if(current_node->data == var){
			node* new_node = init_node(value); 
			pre_node->next = new_node;
			new_node->next = current_node;
		}
		pre_node = current_node;
		current_node = current_node->next;
	} 
}

/*node* list_reverse(node* head)
//此方法存在问题，对于头节点的值会造成异常
{
	if(head==NULL||head->next==NULL){
		return head;
	}
	node* next_node = list_reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return next_node;
}*/

void list_reverse(node* head)
{
	if(head->next==NULL)
	{
		;
	}
	else{
		node* temp = head->next->next;
		node* p;
		head->next->next = NULL;
		while(temp!=NULL)
		{
			p = temp;
			temp = temp->next;
			p->next = head->next;
			head->next = p;
		}
	}
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

void delete_same(node* head)
{
	node* out = head->next;
	node* preout = head;
	int flag = 0;
	while(out&&out->next){
		flag = 0;
		node* in = out->next;
		node* pre = out;
		while(in){
			if(out->data == in->data)
			{
				flag = 1;
				pre->next = in->next;
				delete(in);
				in = pre->next;
			}
			else{
				pre = in;
				in = in->next;
			}
		}
		if(flag==1){
			preout->next = out->next; 
			//list_traversal(head);
			delete(out);
			out = preout->next;
		}
		else{
			//list_traversal(head);
			preout = out;
			out = out->next;
		}
	}
}

int main() 
{
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		node* head = new node();
		head->next = NULL;
		int n;
		cin>>n;
		int arr[n+5];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		head = init_list(arr,n);
		list_reverse(head);
		int Q;
		cin>>Q;
		for(int q=0;q<Q;q++){
			int type;
			cin>>type;
			if(type==4){
				list_traversal(head);
			}
			else if(type==1){
				int x,y;
				cin>>x>>y;
				insert_node_beforeVar(head,y,x);
			}
			else if(type==2){
				list_reverse(head);
			}
			else if(type==3){
				delete_same(head);
			} 
		}
	}
}
