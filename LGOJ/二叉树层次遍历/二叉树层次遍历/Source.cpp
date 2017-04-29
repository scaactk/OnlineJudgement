#include<iostream>
using namespace std;
struct Node{
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
int get_deepth(Node* T)
{
	int dp, left, right;
	if (!T) {
		return 0;
	}
	left = get_deepth(T->left_child);
	right = get_deepth(T->right_child);
	dp = (left > right ? left : right) + 1;
	return dp;
}
void level_traversal(Node* T,int level)
{
	if (!T || level < 1) {
		return;
	}
	else if (level == 1) {
		cout << T->data;
	}
	else {
		level_traversal(T->left_child, level - 1);
		level_traversal(T->right_child, level - 1);
	}
}
int main()
{
	Node* T = new Node();
	T = create_Bitree();
	int dp = get_deepth(T);
	for (int i = 1; i <= dp; i++) {
		level_traversal(T, i);
	}
	cout << endl;
	system("pause");
	return 0;
}
