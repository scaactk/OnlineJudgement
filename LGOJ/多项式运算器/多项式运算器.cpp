#include<iostream>
using namespace std;
struct node{
	int cv;//系数 
	int index;//指数 
	node* next;
};

void create_list(node* head, int fx1)
{
	node* current_node = head;
	for(int i=0;i<fx1;i++){
		node* new_node = new node();
		cin>>new_node->cv;
		cin>>new_node->index;
		new_node->next = NULL; 
		current_node->next = new_node;
		current_node = new_node; 
	}
}

void list_traversal(node* head)
{
	node* t = head->next;
	if(t == NULL){
		cout<<"0";
	}
	while(t){
		cout<<t->cv<<"X^"<<t->index;
		if(t->next){
			if(t->next->cv>0){
				cout<<"+";
			}
		}
		t = t->next;
	}
	cout<<endl;
}

/*void add(node* head1,node* head2)
{
	node* p = head1;
	node* q = head2;
	int sum;
	while(p->next&&q->next){
		if(p->next->index==q->next->index)
		{
			sum = p->next->cv + q->next->cv;
			if(sum){//系数不为零，则把相加的结果放到第一个多项式中 
				p->next->cv = sum;
				p = p->next;
				q = q->next;
			}
			else{//若系数为0则删除节点 
				node* k1 = p->next;
				p->next = p->next->next;
				delete(k1);
				p = p->next;
				q = q->next;
				
			}
		}
		else if(p->next->index > q->next->index) 
		{
			//从老前辈那里学来的思路 
			//免去了插入的步骤 
			node* temp = q->next->next;
			q->next->next = p->next;
			p->next = q->next;
			q->next = temp;
		}
		else if(p->next->index < q->next->index)
		{
			p = p->next;
		} 
	}
}
*/
node* add(node* head1, node* head2)
{
	node* p = head1->next;
	node* q = head2->next;
	node* head3 = new node();
	head3->next = NULL;
	node* ptr = head3;
	int sum;
	node* temp;
	while(p&&q){
		if(p->index == q->index)
		{
			sum = p->cv + q->cv;
			if(sum!=0){
				temp = new node();
				temp->cv = sum;
				temp->index = p->index;
				temp->next = NULL;
				ptr->next = temp;
				ptr = temp;
			}	
			p = p->next;
			q = q->next;
		}
		else if(p->index < q->index){
			node* temp = new node();
			temp->cv = p->cv;
			temp->index = p->index;
			temp->next = NULL;
			ptr->next = temp;
			ptr = temp;
			p = p->next;
		}
		else if(p->index > q->index)
		{
			node* temp = new node();
			temp->cv = q->cv;
			temp->index = q->index;
			temp->next = NULL;
			ptr->next = temp;
			ptr = temp;
			q = q->next;
		}
	}
	while(p){
		temp = new node();
		temp->cv = p->cv;
		temp->index = p->index;
		temp->next = NULL;
		ptr->next = temp;
		ptr = temp;
		p = p->next;
	}
	while(q){
		temp = new node();
		temp->cv = q->cv;
		temp->index = q->index;
		temp->next = NULL;
		ptr->next = temp;
		ptr = temp;
		q = q->next;
	}
	//list_traversal(head3);
	return head3;
} 

node* minu(node* head1, node* head2)
{
	node* p = head1->next;
	node* q = head2->next;
	node* head3 = new node();
	head3->next = NULL;
	node* ptr = head3;
	int sum;
	node* temp;
	while(p&&q){
		if(p->index == q->index)
		{
			sum = p->cv - q->cv;
			if(sum!=0){
				temp = new node();
				temp->cv = sum;
				temp->index = p->index;
				temp->next = NULL;
				ptr->next = temp;
				ptr = temp;
			}	
			p = p->next;
			q = q->next;
		}
		else if(p->index < q->index){
			node* temp = new node();
			temp->cv = p->cv;
			temp->index = p->index;
			temp->next = NULL;
			ptr->next = temp;
			ptr = temp;
			p = p->next;
		}
		else if(p->index > q->index)
		{
			node* temp = new node();
			temp->cv = -1 * q->cv;
			temp->index = q->index;
			temp->next = NULL;
			ptr->next = temp;
			ptr = temp;
			q = q->next;
		}
	}
	while(p){
		temp = new node();
		temp->cv = p->cv;
		temp->index = p->index;
		temp->next = NULL;
		ptr->next = temp;
		ptr = temp;
		p = p->next;
	}
	while(q){
		temp = new node();
		temp->cv = -1 * q->cv;
		temp->index = q->index;
		temp->next = NULL;
		ptr->next = temp;
		ptr = temp;
		q = q->next;
	}
	//list_traversal(head3);
	return head3;
} 

int main(){
	int T = 0;
	cin>>T;
	node* head1 = new node();
	node* head2 = new node();
	//node* head3 = new ndoe();
	for(int t=0;t<T;t++){
		int fx1,fx2;
		cin>>fx1>>fx2;
		create_list(head1,fx1);
		create_list(head2,fx2);
		//list_traversal(head1);
		int Q;
		cin>>Q;
		int type;
		for(int q=0;q<Q;q++){
			cin>>type;
			if(type==1){
				list_traversal(head1);
				list_traversal(head2);
			}
			if(type==2){
				head1 = add(head1,head2); 
			}
			if(type==3){
				head1 = minu(head1,head2);
			}
		}
	}
	return 0;
} 
