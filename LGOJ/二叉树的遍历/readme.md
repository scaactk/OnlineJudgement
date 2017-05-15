## 描述 
**  以二叉链表为存储结构，实现二叉树的创建、遍历。 **
### 要求：
---
 1.建树的方式为先序遍历序列；
 2.存储结构为二叉链表；
 3.分别输出前序遍历序列（递归实现）、中序遍历序列（非递归）、后序遍历序列（递归）；
 4.OJ提交的程序不要输出菜单或者其他无关内容。
 ---
### 输入 
* 输入共1行，包含整棵二叉树的先序遍历序列，创建树，用“#” 表示结点的左孩子或右孩子为空。
### 输出 
* 输出共3行，分别为前序遍历序列（递归），中序遍历序列（非递归），后序遍历序列（递归），不输出空节点。

---
样例输入1 
``` ABC##DE#G##F###```

---
* 样例输出1 

---
```
ABCDEGF
CBEGDFA
CGEFDBA
```
---

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
	  		cout << p->data;
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
  			p = p->right_child;
  		}
  	}
	}
}
```
---
### 中序遍历
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
