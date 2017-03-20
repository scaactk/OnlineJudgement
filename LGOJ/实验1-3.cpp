#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
	int v,e;
	node *next;
};
typedef node *L;
L head1=NULL,head2=NULL;
void creat(L head,int len){
	L rear=head;
	L temp=NULL;
	for(int i=1;i<=len;i++){
		temp=(L)malloc(sizeof(node));
		cin>>(temp->v)>>(temp->e);temp->next=NULL;
		rear->next=temp;
	    rear=temp;
	}
}
void pinrt(L head){
	int i=0;
	L rear=head;
	head=head->next;
	while(head){
		if(head->v==0){
			rear->next=head->next;
			free(head);
			head=rear->next;
			continue;
		}
		if(head->v>0&&i) cout<<"+";
		cout<<(head->v)<<"X^"<<(head->e);
		rear=rear->next;
		head=head->next;
		i=1;
	}
	if(!i){
		cout<<0;
	}
	cout<<endl;
}
void add(L h1,L h2){
	L end=h1->next;
	h1=h1->next;h2=h2->next;
	L ret=(L)malloc(sizeof(node));
	ret->next=NULL;
	L rear3=ret;
	while(h1&&h2){
		if((h1->e)<(h2->e)){
			L temp=(L)malloc(sizeof(node));
			temp->e=h1->e;
			temp->v=h1->v;
			temp->next=NULL;
			rear3->next=temp;
			rear3=temp;
			h1=h1->next;
		}else if((h1->e)>(h2->e)){
			L temp=(L)malloc(sizeof(node));
			temp->e=h2->e;
			temp->v=h2->v;
			temp->next=NULL;
			rear3->next=temp;
			rear3=temp;
			h2=h2->next;
		}else{
			L temp=(L)malloc(sizeof(node));
			temp->e=h1->e;
			temp->v=(h1->v)+(h2->v);
			temp->next=NULL;
			rear3->next=temp;
			rear3=temp;
			h1=h1->next;
			h2=h2->next;
		}
	}
	while(h1){
		L temp=(L)malloc(sizeof(node));
		temp->e=h1->e;
		temp->v=h1->v;
		temp->next=NULL;
		rear3->next=temp;
		rear3=temp;
		h1=h1->next;
	}
	while(h2){
		L temp=(L)malloc(sizeof(node));
		temp->e=h2->e;
		temp->v=h2->v;
		temp->next=NULL;
		rear3->next=temp;
		rear3=temp;
		h2=h2->next;
	}
	while(end){
		L temp=end;
		end=end->next;
		free(temp);
	}
	head1->next=ret->next;
	free(ret);
}
void ok(L head){
	L temp=head->next;
	while(temp){
		(temp->v)=-(temp->v);
		temp=temp->next;
	}
}
int main(){
	int T=0;cin>>T;
	while(T--){
		int len1=0,len2=0;cin>>len1>>len2;
		head1=(L)malloc(sizeof(node));creat(head1,len1);
		//pinrt(head1);
		head2=(L)malloc(sizeof(node));creat(head2,len2);
		//pinrt(head2);
		int q=0;cin>>q;
		while(q--){
			int type=0;
			cin>>type;
			if(type==1){
				pinrt(head1);pinrt(head2);
			}else if(type==2){
				add(head1,head2);
			}else{
               ok(head2);
	           add(head1,head2);
	           ok(head2);
			}
		}
	}
	return 0;
}
