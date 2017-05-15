#include<iostream>
using namespace std;
struct Graph {
	int vertexs[100];//顶点数组
	int edges[100][100];//邻接矩阵，存储边信息
	int n;
	int e;
};
void create_graph(Graph* G, int n, int e, int* ver, int side[][2])
{
	G->n = n;
	G->e = e;
	for (int i = 0; i < G->n; i++) {
		G->vertexs[i] = ver[i];
	}
	for (int i = 0; i < G->n; i++) {
		for (int j = 0; j < G->n; j++) {
			G->edges[i][j] = 0;
		}
	}
	for (int i = 0; i < G->e; i++) {
		G->edges[side[i][0]][side[i][1]] = 1;
		G->edges[side[i][1]][side[i][0]] = 1;
	}
}
void print_graph(Graph* G)
{
	for (int i = 0; i < G->n; i++)
	{
		cout << G->vertexs[i];
		for (int j = 0; j < G->e; j++)
		{
			cout << " " << G->edges[j];
		}
		cout << endl;
	}
}
void depth_first_search()
{

}
void breadth_first_search()
{

}
int main()
{
	int n, m;
	cin >> n >> m;
	int ver[100];
	int side[10000][2];
	for (int i = 0; i < n; i++) {
		ver[i] = i + 1;
	}
	for (int i = 0; i < m; i++) {
		cin >> side[i][0] >> side[i][1];
		cout << side[i][0] << side[i][1] << endl;
	}
	Graph* G = new Graph();
	create_graph(G, n, m, ver, side);
	print_graph(G);
	system("pause");
	return 0;
}