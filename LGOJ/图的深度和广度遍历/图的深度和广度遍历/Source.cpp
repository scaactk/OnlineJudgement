#include<iostream>
using namespace std;
#define MaxVex 100
#define INFINITY 65536
typedef int VertexTpye;
typedef int EdgeType;
int visited[MaxVex];

typedef struct {
	VertexTpye vexs[MaxVex];
	EdgeType arc[MaxVex][MaxVex];
	int numVertexes, numEdges;
}MGraph;

//广度优先遍历所需要的循环队列
typedef struct {
	int data[MaxVex];
	int front, rear;
}Queue;

//初始化队列
void init_queue(Queue* Q)
{
	Q->front = Q->rear = 0;
}

//入队
void enqueue(Queue* Q, int e)
{
	if ((Q->rear + 1) % MaxVex == Q->front)
	{
		return;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MaxVex;
}

//判空
bool check_empty(Queue* Q)
{
	if (Q->front == Q->rear)
	{
		return true;
	}
	else {
		return false;
	}
}

//出队
void dequeue(Queue* Q, int* e)
{
	if (Q->front == Q->rear)
	{
		return;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxVex;
}

//建立图的邻接矩阵
void create_graph(MGraph* G)
{
	cin >> G->numVertexes >> G->numEdges;

	//预置节点值
	for (int i = 0; i < G->numVertexes; i++)
	{
		G->vexs[i] = i + 1;
	}

	//预置邻接矩阵
	for (int i = 0; i < G->numVertexes; i++)
	{
		for (int j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = INFINITY;
		}
	}
	//输入连通点坐标
	for (int i,j,k = 0; k < G->numEdges; k++)
	{
		cin >> i >> j;
		G->arc[i-1][j-1] = 1;
		G->arc[j-1][i-1] = G->arc[i-1][j-1];
	}
}

//输出,测试用
void display_graph(MGraph* G)
{
	for (int i = 0; i < G->numVertexes; i++)
	{
		for (int j = 0; j < G->numVertexes; j++)
		{
			cout << G->arc[i][j];
		}
		cout << endl;
	}
}

//图的深度优先遍历访问一条路
void DFS(MGraph* G, int i, Queue* temp1)
{
	visited[i] = true;
	//cout << G->vexs[i];
	enqueue(temp1, G->vexs[i]);

	for (int j = 0; j < G->numVertexes; j++)
	{
		if (G->arc[i][j] != INFINITY && !visited[j])
		{
			DFS(G, j, temp1);
		}
	}
}

//深度优先搜索访问所有节点
void DFS_traversal(MGraph* G)
{
	Queue temp1;//用于存储访问记录的队列
	init_queue(&temp1);

	for (int i = 0; i < G->numVertexes; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < G->numVertexes; i++)
	{
		if (!visited[i])
		{
			DFS(G, i, &temp1);
		}
	}

	for (int i = 0; i < G->numVertexes-1; i++)
	{
		int output;
		dequeue(&temp1, &output);
		cout << output << " ";
	}
	int output;
	dequeue(&temp1, &output);
	cout << output << endl;
}

//图的广度优先遍历
void BFS_traversal(MGraph* G)
{
	Queue Q;
	init_queue(&Q);
	Queue temp2;//用于存储访问记录的队列
	init_queue(&temp2);

	for (int i = 0; i < G->numVertexes; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < G->numVertexes; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			//cout << G->vexs[i];//输出当前结点，并将其入队
			enqueue(&temp2, G->vexs[i]);
			enqueue(&Q, i);

			while (!check_empty(&Q))
			{
				dequeue(&Q, &i);
				for (int j = 0; j < G->numVertexes; j++)
				{
					if (!visited[j] && G->arc[i][j] != INFINITY)
					{
						visited[j] = true;
						//cout << G->vexs[j];
						enqueue(&temp2, G->vexs[j]);
						enqueue(&Q, j);
					}
				}
			}
		}
	}
	for (int i = 0; i < G->numVertexes - 1; i++)
	{
		int output;
		dequeue(&temp2, &output);
		cout << output << " ";
	}
	int output;
	dequeue(&temp2, &output);
	cout << output << endl;
}
int main()
{
	MGraph G;
	create_graph(&G);
	DFS_traversal(&G);
	BFS_traversal(&G);
	system("pause");
	return 0;
}