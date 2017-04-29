#include<iostream>
using namespace std;
struct node{
	struct node* left_child;
	struct node* right_child;
	char data;
};
void create_BiTree1(node* &T)
{
	char ch;
	cin>>ch;
	if(ch=='#'){
		T==NULL;
	}
	else{
		T = new node;
		T->data = ch;
		cout<<T->data<<endl; 
		create_BiTree1(T->left_child);
		create_BiTree1(T->right_child);
	}
}
node* create_BiTree2(node* T)
{
	char ch;
	cin>>ch;
	if(ch=='#'){
		T = NULL;
	}
	else{
		T = new node;
		T->data = ch;
		cout<<T->data<<endl;
		create_BiTree2(T->left_child);
		create_BiTree2(T->right_child);
	}
	return T;
}
void preorder_traversal(node* T)
{
	//递归法先序遍历二叉树
	if (T != NULL) {
		cout << T->data;
		preorder_traversal(T->left_child);
		preorder_traversal(T->right_child);
	}
}
int main()
{
	node* T1;
	node* T2; 
	create_BiTree1(T1);
	create_BiTree2(T2);
	preorder_traversal(T1); 
}
