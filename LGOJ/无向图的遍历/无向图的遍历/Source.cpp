#include<iostream>
using namespace std;
struct Graph {
	int vertexs[100];//顶点数组
	int edges[100][100];//邻接矩阵，存储边信息
	int n;
	int e;
};
void create_graph(Graph* G, int n, int e, int* ver, int** side)
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
	int side[100*100][2];
	for (int i = 0; i < n; i++) {
		ver[i] = i + 1;
	}
	for (int i = 0; i < m; i++) {
		cin >> side[i][0] >> side[i][1];
	}
	Graph* G = new Graph();
}