#include<iostream>
using namespace std;
//ע��left��right��try�Ⱦ�Ϊc++�еĹؼ�����Ҫʹ�ã��轫����ĸ��д����Ȼ����ᱨ�� 
int number=0;//��¼������
int queen[15]={0};//��¼N���ʺ���ռ�õ��к�
bool Column[15];//c[1]~c[N]��ǰ���Ƿ�ȫ 
bool Left[29];//l[2]~l[2*N]��i+j���Խ����Ƿ�ȫ
bool Right[29];//r[2]~r[2*N](i-j)�Խ����Ƿ�ȫ
void Try(int i,int N,int x,int y){//iΪ������NΪ��������������x��y��Ϊ��������꣬����xΪ�У�yΪ�� 
	for(int j=1;j<=N;j++){
		if((Column[j])&&(Left[i-j+N+1])&&(Right[i+j])&&((i!=x)||(j!=y))){//��i�У���j���ǰ�ȫ�ģ������Խ����ǰ�ȫ�ģ�ͬʱ��Ҫ���ûʺ����һ���㲻��������� 
			//��һ���£�ռ��λ�ã�i��j��
			queen[i]=j; 
			//�޸İ�ȫλ�ã��������ڵ��к������Խ���
			Column[j]=false;
			Left[i-j+N+1]=false;
			Right[i+j]=false;
			//�ڶ����£��ж��Ƿ������N���ʺ�
			if(i<N){//δ����N���ʺ� 
				Try(i+1,N,x,y);//��������һ�� 
			} else{//�Ѿ�����N���ʺ� 
				number++;//��������1 
			}
			//�������£��޸İ�ȫ��־������
			Column[j]=true;
			Left[i-j+N+1]=true;
			Right[i+j]=true; 
		}
	}
}
int main(){
	number=0;//����������
	int N,x,y;
	cin>>N>>x>>y;//����������������������
	for(int i=0;i<N+1;i++){
		Column[i]=true;//��������Ϊ��ȫ 
	} 
	for(int i=0;i<2*N+1;i++){
		Left[i]=Right[i]=true;//�����еĶԽ���Ϊ��ȫ 
	} 
	Try(1,N,x,y);//�ݹ����N���ʺ󣬴ӵ�һ����ʼ��
	cout<<number<<endl;//��������� 
	return 0; 
} 
