#include<iostream>
#include<cmath>
using namespace std;
//fundmental idea£ºusing the algebraic confactor of the determinant makes a recursion
//because two sub-function transfer each other,we need declare them all initially
//otherwise,it will be reduced to the compilation error
int det(int dim,int matrix[6][6]);
int matrixremain(int dim,int i,int matrix[6][6]);
//sub-function1
//target:caculating the value of the determinant
int det(int dim,int matrix[6][6]){
	int M=0,sum=0;
	//ending condition
	if(dim==1){
		return matrix[0][0];
	} else{
		for(int i=0;i<dim;i++){
		    //transfering the sub-fuction2
			M=matrixremain(dim,i,matrix);
		    //the important equation which makes the recursion
			sum+=pow(-1,i+2)*matrix[i][0]*M;
	    }
	}
	return sum;
}

//sub-function2
//target:caculating the algebraic confactor
int matrixremain(int dim,int i,int matrix[6][6]){
	int matrixr[6][6];
	for(int j=0;j<dim;j++){
		//emptifying the first column of the original determinant as the first step to make the algebraic confactor
		for(int k=1;k<dim;k++){
			//"j" is the serial number of the matrix's row
			if(j==i){
				continue;
			}
			if(j<i){
				matrixr[j][k-1]=matrix[j][k];
			}
			if(j>i){
				matrixr[j-1][k-1]=matrix[j][k];
			}
		}
	}
	//transfering the sub-function1
	return det(dim-1,matrixr);
}
int main(){
	int N,output;
	cin>>N;//it shows a N*N matrix
	int matrix[6][6];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>matrix[i][j];//inputs the element of the matrix
		}
	} 
	//transfers sub-function1 to caculate
	output=det(N,matrix);
	cout<<output<<endl;
	return 0;
}
