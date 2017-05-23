#include<iostream>
#include<algorithm>
using namespace std;
int visited[100];
int output[100];//用于格式化输出的数组
int t = 1;//记录已删除的节点数
struct Node {
	int adjvex;//邻接点域
	Node* next = NULL;
};
struct Vertex {//顶点
	int indegree;
	int value;
	Node* first = NULL;
};
struct Algraph{//图
	Vertex adjlist[100];
	int n, e;
};

void create_adjlist(Algraph* g)
{
	for (int i = 1; i <= g->n; i++)
	{
		g->adjlist[i].value = i ;
		g->adjlist[i].indegree = 0;
	}
	int a, b;
	Node* temp;
	for (int i = 1; i <= g->e; i++)
	{
		cin >> a >> b;
		temp = new Node();
		temp->adjvex = b;
		g->adjlist[b].indegree++;
		temp->next = g->adjlist[a].first;
		g->adjlist[a].first = temp;
	}
}
/*
void topological_sort(Algraph* g)
{
	Node* p;
	int top = -1;
	for (int i = 1; i <= g->n; i++)//如果某个顶点的入度为0，则把顶点的入度域改为栈
	{
		if (g->adjlist[i].indegree == 0)
		{
			g->adjlist[i].indegree = top;
			top = i;
		}
	}
	while (top != -1)//如果栈中元素不为空,则表示存在入度为0的顶点
	{
		int j = top;
		top = g->adjlist[top].indegree;
		cout << g->adjlist[j].value << " ";
		p = g->adjlist[j].first;
		while (p)//更改此顶点所有相关边的入度
		{
			int i = p->adjvex;
			g->adjlist[i].indegree--;
			if (g->adjlist[i].indegree == 0)//入度为0继续进栈
			{
				g->adjlist[i].indegree = top;
				top = i;
			}
			p = p->next;
		}
	}
}
*/
void clear(Algraph* g)
{
	int arr[100];
	for (int i = 1; i <= g->n; i++)
	{
		if (g->adjlist[i].indegree == 0 && visited[i] ==0)
		{
			//cout << "t: " << t << endl;
			output[t] = g->adjlist[i].value;
			//cout << output[t] << endl;
			visited[i] = 1;
			t++;
			Node* p = g->adjlist[i].first;
			while (p != NULL)
			{
				g->adjlist[p->adjvex].indegree--;
				p = p->next;
			}
			i = 0;
		}
	}
}
void topological_sort(Algraph* g)
{
	for (int i = 1; i <= g->n; i++)
	{
		visited[i] = 0;//初始化未访问
	}
	
	int flag;
	do {
		flag = 0;
		clear(g);
		for (int i = 1; i <= g->n; i++)
		{
			if (visited[i] != 1)
			{
				flag = 1;
			}
		}
	} while (flag == 1);
	
	for (int i = 1; i <= g->n-1; i++)
	{
		cout << output[i]<<" ";
	}
	cout << output[g->n] << endl;
}
int main()
{
	int m, n;
	cin >> m >> n;
	Algraph* g = new Algraph();
	g->n = m;
	g->e = n;
	create_adjlist(g);
	topological_sort(g);
	system("pause");
	return 0;
}