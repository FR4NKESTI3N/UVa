#include<iostream>
#include<math.h>

using namespace std;

int main(void){
	short t;
	long long n;
	cin>>t;
	while(t--){
		cin>>n;
		n=(n*63 + 7492)*5 -498;
		cout<<abs((n/10)%10)<<'\n';
	}
	return 0;
}