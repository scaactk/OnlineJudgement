#include<iostream>
int main(){
	int a,b;
    std::cin>>a>>b;
    if(a%(b+1)!=0) std::cout<<"MK"<<std::endl;
    else std::cout<<"JYZ"<<std::endl;
    return 0;
}
