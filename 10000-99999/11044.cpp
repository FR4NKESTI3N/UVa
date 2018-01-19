#include<iostream>
#include<math.h>

using namespace std;

int main(void){
	int t,m,n;
	cin>>t;
	while(t--){
		cin>>m>>n;
		cout<<((m)/3)*((n)/3)<<'\n';
	}
	return 0;
}