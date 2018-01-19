#include<iostream>
#include<stdio.h>

using namespace std;

int main(void){
	short t,a,b,c;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a>>b>>c;
		if(a>b){
			if(c>a)
				printf("Case %d: %d\n",i,a);
			else if(b>c)
				printf("Case %d: %d\n",i,b);
			else
				printf("Case %d: %d\n",i,c);
		}
		else{	//b>a
			if(c>b)
				printf("Case %d: %d\n",i,b);
			else if(c>a)
				printf("Case %d: %d\n",i,c);
			else
				printf("Case %d: %d\n",i,a);
		}
	}
	return 0;
}