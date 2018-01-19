#include<iostream>
#include<climits>

using namespace std;

int main(void){
	short t;
	cin>>t;
	long a,b;
	while(t--){
		cin>>a>>b;
		cout<<(a>b?">\n":(a<b?"<\n":"=\n"));
	}
	return 0;
}