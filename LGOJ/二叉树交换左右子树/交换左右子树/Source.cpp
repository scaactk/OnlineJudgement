#include<iostream>
using namespace std;
struct Node {
	char data;
	Node* left_child;
	Node* right_child;
};
Node* create_Bitree()
{
	Node* T = NULL;
	char ch;
	cin >> ch;
	if (ch != '#') {
		T = new Node();
		T->data = ch;
		T->left_child = create_Bitree();
		T->right_child = create_Bitree();
	}
	return T;
}
void inorder_traversal(Node* T)
{
	if (T != NULL) {
		inorder_traversal(T->left_child);
		cout << T->data;
		inorder_traversal(T->right_child);
	}
}
void change_left_right(Node* T)
{
	if (T != NULL) {
		Node* temp = new Node();
		temp = T->left_child;
		T->left_child = T->right_child;
		T->right_child = temp;
		change_left_right(T->left_child);
		change_left_right(T->right_child);
	}
}
int main()
{
	Node* T = create_Bitree();
	change_left_right(T);
	inorder_traversal(T);
	cout << endl;
	system("pause");
	return 0;
}