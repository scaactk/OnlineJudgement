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
void preorder_traversal(Node* T) {
	if (T != NULL) {
		cout << T->data;
		preorder_traversal(T->left_child);
		preorder_traversal(T->right_child);
	}
}
int get_deepth(Node* T) {
	int dp, left, right;
	if (!T) {
		return 0;
	}
	left = get_deepth(T->left_child);
	right = get_deepth(T->right_child);
	dp = (left > right ? left : right) + 1;
	return dp;
}
int main()
{
	Node* T;
	T = create_Bitree();
	cout << get_deepth(T) << endl;
	system("pause");
	return 0;
}