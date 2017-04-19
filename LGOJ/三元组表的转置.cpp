#define SMax 1024
struct SPNode{
	int i,j;
	int v;
};
struct SPMatrix{
	int mu,nu,tu;//mu:原稀疏矩阵的行数，nu:列数，tu:总非零元素数目 
	SPNode data[SMax+1];//三元组表内的基本元素是SPNode 
};
SPMatrix TransMatrix(SPMatrix A)
{
	SPMatrix B;
	int p,q,col;
	B.mu = A.nu;
	B.nu = A.mu;
	B.tu = A.tu;
	//给定稀疏矩阵的基本参量
	if(B.tu>0){
		q = 1;
		for(col=1;col<A.nu;col++){
			for(p=1;p<A.tu;p++){
				if(A.data[p].j==col)
				{
					B.data[q].i=A.data[p].j;
					B.data[q].j=A.data[p].i;
					B.data[q].v=A.data[p].v;
					q++; 
				}
			}
		}
	} 
	return B;
}
int main()
{
	return 0;
}
