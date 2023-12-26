//本题之中，输入和输出是难点，解决问题的过程仅仅只限于遍历和比较
//关键在于对于数据的处理和分配上，这时就要用到数组和字符串了，前者对于数字进行处理，而后者对于字符进行处理 
#include<iostream>
using namespace std;
int main(){
    //输入端，对于三类，两个类型的变量进行输入 （此处之后可以运用结构体，但是现在还没有学到） 
    int N=0;
    cin>>N;
    int month[N];
    int day[N];
    char name[N][20];
    int length[N];
    for(int i=0;i<N;i++){
        cin>>name[i];
        cin>>month[i];
        cin>>day[i];
    }
    //对于生日数据的处理，此方式是运用数组对于数据进行处理的惯用手段，核心为对于数据进行编号，并统计每一个数据出现的次数 
	int count[372]={0};
    for(int k=0;k<N;k++){
        int m=0;
        m=31*(month[k]-1)+day[k]-1;
        count[m]++;
    }
    //对于处理过后的数据的提取，因为用数组方式进行的统计，所以需要遍历进行提取 
	for(int p=0;p<372;p++){
        if((count[p]>1)&&((p+1)%31!=0)){
            cout<<(p+1)/31+1<<" "<<(p+1)%31<<" ";
            //如涉及到数据或字符串的储存与提取，不妨将其利用数组（结构体）进行关联，即拥有相同的序号，之后再运用遍历和if判断将其提取 
			for(int q=0;q<N;q++){
                if((month[q]==(p+1)/31+1)&&(day[q]==(p+1)%31)){
                    cout<<name[q]<<" ";
                }
            }
            cout<<endl;
        }
        //注意算法的漏洞，此处为对于算法的补漏 
		if((count[p]>1)&&((p+1)%31==0)){
            cout<<(p+1)/31<<" "<<31<<" ";
            for(int q=0;q<N;q++){
                if((month[q]==(p+1)/31)&&(day[q]==31)){
                    cout<<name[q]<<" ";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
