#include<iostream>

using namespace std;

int main(void){
	int k,m,n,x,y;
	while(true){
		cin>>k;
		if(k==0)
			break;
		cin>>m>>n;
		while(k--){
			cin>>x>>y;
			if(x==m || y==n)
				cout<<"divisa\n";
			else if(x>m){
				if(y>n)
					cout<<"NE\n";
				else
					cout<<"SE\n";
			}
			else{
				if(y>n)
					cout<<"NO\n";
				else
					cout<<"SO\n";
			}
		}
	}
	return 0;
}