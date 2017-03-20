#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
	int v;
	int id;
	node *next;
};
typedef node *L;
L head=NULL,rear=NULL;
void creat();
void ok();
void print();
int n=0,m=0;
int main(){
	int T=0;cin>>T;
	int t=0;
	while(T--){
		cin>>n>>m;
		creat();
		ok();
	}
	return 0;
}
void creat(){
	head=(L)malloc(sizeof(node));
    head->id=1;
    cin>>(head->v);
	rear=head;
	L temp;
	for(int i=2;i<=n;i++){
		temp=(L)malloc(sizeof(node));
		temp->id=i;temp->next=NULL;
		cin>>(temp->v);
		rear->next=temp;
		rear=temp;
	}
	rear->next=head;
}
void print(){
	L h=head;
	for(int i=1;i<=2*n;i++){
		cout<<(h->v)<<" ";
		h=h->next;
	}
}
void ok(){
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
		m=head->v;
		sum--;
		L temp=head;
		head=temp->next;
		rear->next=head;
		free(temp);
		
	}
	cout<<endl;
}
