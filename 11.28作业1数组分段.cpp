//�������̰���㷨�Ӷ��ֲ��ҽ��н����ͬ��Ҳ����ֱ��ʹ�ö�̬�滮���н�� 
#include<iostream>
#include<cstdio>
using namespace std;
//̰���㷨
//�ж�һ�����Ƿ�����ڹ涨�Ķ����ڣ�С�ڵ��ڣ���Ϊ�ֶ�����͵ĵ����ֵ 
int judge(long long int number,int N,long long int array[]){
    //��ʼ�Ķ���Ϊ1����������ô�ֶ�һ����һ����� 
	int count=1;
    long long int sum_array=0;
    for(int i=0;i<N;i++){
        //ʹ��̰���㷨�ĺ��ģ������������һ��һ��������Ͱ��ֻҪ���ԡ�����װ��װ������װΪֹ�� 
		if((sum_array+array[i])>number){//�����ԣ�װ��ð���ˣ��Ϳ�һ���µ�Ͱȥװ 
            count++;
            sum_array=array[i];
        }else{//�����ԣ�װ��ð���ͼ���װ 
            sum_array+=array[i];
        }
    }
    return count;
}
int main(){
    int N,M;
    cin>>N>>M;
    long long int array[N];
    long long int total=0;
    //�����������������˳����� 
	for(int i=0;i<N;i++){
        scanf("%lld",&array[i]);
        total+=array[i];
    }
    long long int max=array[0];
    //��������������� 
    for(int i=1;i<N;i++){
        if(array[i]>=max){
            max=array[i];
        }
    }	
    //�������õ������һ�����������е��������������������ĺ�֮�� 
	//����������ö��ֲ��ҽ��бƽ� 
	long long int low=max;
    long long int high=total;
    long long int middle=0;
    //��ע�⣬����Ƕ��ֲ��ҵ�һ����ʽ�������е�ÿһ����1��1��ȡ�ȷ��Ŷ����ܳ��������˱����׳��֡�time limit eceeded�� 
	while(low<=high){
        middle=(low+high)/2;
        if(judge(middle,N,array)>M){
            low=middle+1;
        }
        if(judge(middle,N,array)<=M){
            high=middle-1;
        }
    }
    //���low������high��˵����������Ĺ��Ƶ��������ߣ�low������Ǹչ������ߵĵ�һ����������ֱ��ѡ��low������� 
	cout<<low; 
    return 0;
}

