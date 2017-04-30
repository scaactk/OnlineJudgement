#include<iostream>
using namespace std;
int count = 0;//用于记录当前层级的节点个数
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
int level_count(Node* T,int level)
{
	if (!T || level < 1) {
		return 0;
	}
	else if (level == 1) {
		count++;//这里是通过cpp作用域特性实现，可能会存在问题
	}
	else {
		level_count(T->left_child, level - 1);
		level_count(T->right_child, level - 1);
	}
	return count;
}
void bubble_sort(int* a,int dp)
{
	for (int i = 0; i < dp; i++) {
		for (int j = i + 1; j < dp; j++) {
			if (a[i] < a[j]) {
				int temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int get_width(Node* T, int level)
{
	int stack[level+5];
	for (int i = 1; i <= level; i++) {
		count = 0;
		stack[i - 1] = level_count(T, i);
	}
	bubble_sort(stack,level);
	return stack[0];
}
int main()
{
	Node* T;
	T = create_Bitree();
	int dp = get_deepth(T);
	cout << dp <<" ";
	int wd = get_width(T,dp);
	cout<< wd <<endl;
	system("pause");
	return 0;
}
