#include<iostream>
using namespace std;
int main()
{
	int K=0;
	double sum=0;
	cin>>K;
	for(int n=1;n<=1835422;n++){//1835422是试出来的 
		sum=sum+1.0/n;
		if(sum>K){
			cout<<n<<endl;
			break;
		}
	}
	return 0;
}
