#include<iostream>
#include<cstdio>
using namespace std;
#define Max_weight 32767

struct Node {
	int weight;
	int parent;
	int left_child;
	int right_child;
};
struct Hcode {
	char code[10];
	int start;
};
void HufTree(Node ht[], int n)
{
	int M = n;
	int N = M * 2 - 1;
	int m1, m2;//最小的两个权值
	int x1, x2;//权值最小的两个节点在数组中的序号

			   //初始化节点
	for (int i = 0; i < N; i++) {
		ht[i].weight = 0;
		ht[i].parent = -1;
		ht[i].left_child = -1;
		ht[i].right_child = -1;
	}

	//输入每个结点的权值
	for (int i = 0; i < M; i++) {
		cin >> ht[i].weight;
	}

	//建立Huffman_Tree
	//合并n-1次
	for (int i = 0; i < M - 1; i++) {
		m1 = m2 = Max_weight;//寻找两个权值最小的子树
		x1 = x2 = 0;//保存权值最小的子树的下标

					//寻找0 ~ k+i中的两个最小权值
		for (int j = 0; j < M + i; j++) {

			//如果比最小的还要小的话
			if (ht[j].weight < m1 && ht[j].parent == -1)
			{
				//将当前的标记为最小，前一个标记为次小
				m2 = m1;
				x2 = x1;
				m1 = ht[j].weight;
				x1 = j;
			}

			//大于最小值，但小于次小值
			else if (ht[j].weight < m2 && ht[j].parent == -1)
			{
				m2 = ht[j].weight;
				x2 = j;
			}
		}

		//将之前找到的合并成子树
		ht[x1].parent = M + i;
		ht[x2].parent = M + i;
		ht[M + i].weight = ht[x1].weight + ht[x2].weight;
		ht[M + i].left_child = x1;
		ht[M + i].right_child = x2;
	}
}
void show(Node ht[], int n)
{
	for (int i = n; i < 2 * n - 1; i++) {
		cout << ht[i].weight << " " << ht[i].parent << " " << ht[i].left_child << " " << ht[i].right_child << endl;
	}
}
void create_hcode(Node ht[], Hcode hcode[], int n)
{
	int i, f, c;
	Hcode hc;
	for (int i = 0; i < n; i++)
	{
		hc.start = n;
		c = i;
		f = ht[i].parent;
		while (f = -1) //循环直到树根
		{
			if (ht[f].left_child == c) {//处理左孩子结点
				hc.code[hc.start--] = '0';
			}
			else {
				hc.code[hc.start--] = '1';
			}
		}
		hc.start++;//start指向huffman编码最开始的字符
		hcode[i] = hc;
	}
}
int main()
{
	int Q;//操作次数
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int T;
		cin >> T;
		if (T == 0) {
			int n;
			cin >> n;
			Node list[100];
			HufTree(list, n);
			//show(list, n);
		}
		else if (T == 1) {
			char arr1[100];
			gets_s(arr1);
			//encoding(arr1);
		}
		else if (T == 2) {
			char arr2[100];
			gets_s(arr2);
			//decoding(arr2);
		}
	}
	system("pause");
}