#include<iostream>
using namespace std;
int end_num[25005];
int start_num[25005];
int start_new[25005];
int end_new[25005];
int start_old[25005];
//交换函数 
void swap(int *a,int *b){
	int c=*b;
	*b=*a;
	*a=c;
}
//快排函数 
void quick_sort(int *p,int n) {
    if (n<=1){
    	return;
    }
    int t=p[n-1],l=0,r=n-2;
    do{
       for (;r>=l;l++){
       	    if(p[l]>t){
       	    	break;
			}
        }
        for(;r>=l;r--){
        	if(p[r]<t){
        		break;
			}
        }
        if(r>=l){
        	swap(&p[l],&p[r]);
		}
    }while(r>=l);
    swap(&p[l],&p[n - 1]);
    quick_sort(&p[0],l);
    quick_sort(&p[l+1],n-l-1);
}
int main(){
	int n=0,count1=0,m=0;
	//输入端 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%d",&start_num[i]);
		scanf("%d",&end_num[i]);
	}
	//以开头为基准对所有区间进行排序 
	for(int i=0;i<n;i++){
		start_old[i]=start_num[i];
	}
	quick_sort(start_num,n);
    start_new[0]=start_num[0];
	for(int i=1;i<n;i++){
		if(start_num[i]!=start_num[i-1]){
			count1++;
			start_new[count1]=start_num[i];
		}
	} 
    //同一开头只保留区间长度最长的区间 
	for(int i=0;i<=count1;i++){
		int max=-2147483647;
		for(int k=0;k<n;k++){
		    if(start_new[i]==start_old[k]){
				if(end_num[k]>max){
					max=end_num[k];
				}
			}
		}
		end_new[i]=max;
	}
	int count=0;
	if(start_new[0]>1){
		cout<<"-1"<<endl;
		return 0;
	}else{
        int st=0,ed=0,j=0;
        while(st<m){
            for(int i=j;i<n;i++){
                if(start_new[i]<=st+1&&end_new[i]>ed){
                    ed=end_new[i];
                    j=i;  
                }
            }
            if(ed==st){
                count=-1;
                break;
            }
            st=ed;
            count++;
        }
	}
	cout<<count<<endl;
	
	
	return 0;
	
}
