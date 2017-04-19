#include<iostream>
using namespace std;
struct Node {
	char data;
	Node* left_child;
	Node* right_child;
};
Node* create_Bitree(Node* &T)
{
	//递归法先序建立二叉树
	char ch;
	cin >> ch;
	if (ch == '#') {
		T = NULL;
	}
	else {
		T = new Node;
		T->data = ch;
		create_Bitree(T->left_child);
		create_Bitree(T->right_child);
	}
	return T;
}
void preorder_traversal(Node* T)
{
	//递归法先序遍历二叉树
	if (T != NULL) {
		cout << T->data;
		preorder_traversal(T->left_child);
		preorder_traversal(T->right_child);
	}
}
void inorder_traversal(Node* T)
{
	//非递归法中序遍历二叉树
	Node* p;
	Node* stack[100];
	int top = 0;
	if (T == NULL) {
		return;
	}
	p = T;
	while (!(p == NULL&&top == 0)) {
		while (p != NULL) {
			stack[top] = p;
			top++;
			p = p->left_child;
		}
		if (top <= 0) {
			return;//栈空时结束
		}
		else {
			top--;
			p = stack[top];
			cout << p->data;
			p = p->right_child;
		}
	}
}
void postorder_traversal(Node* T)
{
	//递归法后序遍历二叉树
	if (T != NULL) {
		postorder_traversal(T->left_child);
		postorder_traversal(T->right_child);
		cout << T->data;
	}
}
int main()
{
	Node* T = new Node;
	create_Bitree(T);
	//cout << "T:" << T->data << endl;
	preorder_traversal(T);
	cout << endl;
	inorder_traversal(T);
	cout << endl;
	postorder_traversal(T);
	cout << endl;
	system("pause");
	return 0;
}
