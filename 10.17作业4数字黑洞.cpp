#include<iostream>
using namespace std;
int main(){
	int n=0,count=0,change1=0,change2=0,n1=0,n2=0,n3=0,n4=0,isprime=0;
	cin>>n;
	do{  //将n进行分解并将分解得的数字进行排序,并求出change1和change2 
	    n1=n/1000;
		n2=(n%1000)/100;
		n3=(n%100)/10;
		n4=n%10;
		if((n1<=n2)&&(n2<=n3)&&(n3<=n4)){
			isprime=1;
		} else if((n1<=n2)&&(n2<=n4)&&(n4<=n3)){
			isprime=2;
		} else if((n1<=n3)&&(n3<=n2)&&(n2<=n4)){
			isprime=3;
		} else if((n1<=n3)&&(n3<=n4)&&(n4<=n2)){
		    isprime=4;
		} else if((n1<=n4)&&(n4<=n2)&&(n2<=n3)){
			isprime=5;
		} else if((n1<=n4)&&(n4<=n3)&&(n3<=n2)){
			isprime=6;
		} else if((n2<=n1)&&(n1<=n3)&&(n3<=n4)){
			isprime=7;
		} else if((n2<=n1)&&(n1<=n4)&&(n4<=n3)){
			isprime=8;
		} else if((n2<=n3)&&(n3<=n1)&&(n1<=n4)){
			isprime=9;
		} else if((n2<=n3)&&(n3<=n4)&&(n4<=n1)){
			isprime=10;
		} else if((n2<=n4)&&(n4<=n1)&&(n1<=n3)){
			isprime=11;
		} else if((n2<=n4)&&(n4<=n3)&&(n3<=n1)){
			isprime=12;
		} else if((n3<=n1)&&(n1<=n2)&&(n2<=n4)){
			isprime=13;
		} else if((n3<=n1)&&(n1<=n4)&&(n4<=n2)){
			isprime=14;
		} else if((n3<=n2)&&(n2<=n1)&&(n1<=n4)){
			isprime=15;
		} else if((n3<=n2)&&(n2<=n4)&&(n4<=n1)){
			isprime=16;
		} else if((n3<=n4)&&(n4<=n1)&&(n1<=n2)){
			isprime=17;
		} else if((n3<=n4)&&(n4<=n2)&&(n2<=n1)){
			isprime=18;
		} else if((n4<=n1)&&(n1<=n2)&&(n2<=n3)){
			isprime=19;
		} else if((n4<=n1)&&(n1<=n3)&&(n3<=n2)){
			isprime=20;
		} else if((n4<=n2)&&(n2<=n1)&&(n1<=n3)){
			isprime=21;
		} else if((n4<=n2)&&(n2<=n3)&&(n3<=n1)){
			isprime=22;
		} else if((n4<=n3)&&(n3<=n1)&&(n1<=n2)){
			isprime=23;
		} else{
			isprime=24;
		}
		//运用了switch-case语句，个人感觉算法的时间复杂度和空间复杂度还有降低的可能，待日后再做尝试 
		switch(isprime){
			case 1:
				change1=1000*n4+100*n3+10*n2+n1;
				change2=1000*n1+100*n2+10*n3+n4;
				break; 
			case 2:
				change1=1000*n3+100*n4+10*n2+n1;
				change2=1000*n1+100*n2+10*n4+n3;
				break; 
			case 3:
				change1=1000*n4+100*n2+10*n3+n1;
				change2=1000*n1+100*n3+10*n2+n4;
				break; 
			case 4:
				change1=1000*n2+100*n4+10*n3+n1;
				change2=1000*n1+100*n3+10*n4+n2;
				break;
			case 5:
				change1=1000*n3+100*n2+10*n4+n1;
				change2=1000*n1+100*n4+10*n2+n3;
				break; 
			case 6:
				change1=1000*n2+100*n3+10*n4+n1;
				change2=1000*n1+100*n4+10*n3+n2;
				break; 
			case 7:
				change1=1000*n4+100*n3+10*n1+n2;
				change2=1000*n2+100*n1+10*n3+n4;
				break; 
			case 8:
				change1=1000*n3+100*n4+10*n1+n2;
				change2=1000*n2+100*n1+10*n4+n3;
				break; 
			case 9:
				change1=1000*n4+100*n1+10*n3+n2;
				change2=1000*n2+100*n3+10*n1+n4;
				break; 
			case 10:
				change1=1000*n1+100*n4+10*n3+n2;
				change2=1000*n2+100*n3+10*n4+n1;
				break; 
			case 11:
				change1=1000*n3+100*n1+10*n4+n2;
				change2=1000*n2+100*n4+10*n1+n3;
				break; 
		    case 12:
		    	change1=1000*n1+100*n3+10*n4+n2;
				change2=1000*n2+100*n4+10*n3+n1;
		    	break; 
		    case 13:
		    	change1=1000*n4+100*n2+10*n1+n3;
				change2=1000*n3+100*n1+10*n2+n4;
		    	break; 
		    case 14:
		    	change1=1000*n2+100*n4+10*n1+n3;
				change2=1000*n3+100*n1+10*n4+n2;
		    	break; 
		    case 15:
		    	change1=1000*n4+100*n1+10*n2+n3;
				change2=1000*n3+100*n2+10*n1+n4;
		    	break; 
		    case 16:
		    	change1=1000*n1+100*n4+10*n2+n3;
				change2=1000*n3+100*n2+10*n4+n1;
		    	break; 
		    case 17:
		    	change1=1000*n2+100*n1+10*n4+n3;
				change2=1000*n3+100*n4+10*n1+n2;
		    	break; 
		    case 18:
		    	change1=1000*n1+100*n2+10*n4+n3;
				change2=1000*n3+100*n4+10*n2+n1;
		    	break; 
		    case 19:
		    	change1=1000*n3+100*n2+10*n1+n4;
				change2=1000*n4+100*n1+10*n2+n3;
		    	break; 
		    case 20:
		    	change1=1000*n2+100*n3+10*n1+n4;
				change2=1000*n4+100*n1+10*n3+n2;
		    	break; 
		    case 21:
		    	change1=1000*n3+100*n1+10*n2+n4;
				change2=1000*n4+100*n2+10*n1+n3;
		    	break; 
		    case 22:
		    	change1=1000*n1+100*n3+10*n2+n4;
				change2=1000*n4+100*n2+10*n3+n1;
		    	break; 
		    case 23:
		    	change1=1000*n2+100*n1+10*n3+n4;
				change2=1000*n4+100*n3+10*n1+n2;
		    	break; 
		    case 24:
		    	change1=1000*n1+100*n2+10*n3+n4;
				change2=1000*n4+100*n3+10*n2+n1;
		    	break; 
		}
		n=change1-change2;
		count++;
	}while(n!=6174);
	cout<<count<<endl;
	return 0;
}
