## 二叉树节点的定义:
```
struct Node{
  char data;
  Node* left_child;
  Node* right_child;
};
```
---
## 二叉树的递归遍历
### 递归法先序遍历：
```
void preorder_traversal(Node* T)
{
  if(T!=NULL)
  {
    cout<<T->data;
    preorder_traversal(T->left_child);
    preorder_traversal(T->right_child);
  }
}
```
---
### 递归法中序遍历：
```
void inorder_traversal(Node* T)
{
  if(T!=NULL){
    inorder_traversal(left_child);
    cout<<T->data;
    inorder_traversal(right_child);
  }
}
```
---
### 递归法后序遍历：
```
void postorder_traversal(Node* T)
{
  if(T!=NULL){
    postorder_traversal(left_child);
    postorder_traversal(right_child);
    cout<<T->data;
  }
}
```
---
## 二叉树的非递归遍历：
### 前序遍历
```
void preorder_traversal(Node* T)
{
  Node* p; //一个临时指针p
	Node* stack[100]; //存放节点的栈
	int top = 0;
	if (T != NULL) {
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
}
```
---
