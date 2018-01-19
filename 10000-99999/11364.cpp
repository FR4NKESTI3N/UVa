#include<iostream>
#include<climits>

using namespace std;

int main(void){
	int t,n,temp;
	cin>>t;
	while(t--){
		cin>>n;
		int m=INT_MAX,M=INT_MIN;
		while(n--){
			cin>>temp;
			m=m<temp?m:temp;
			M=M>temp?M:temp;
		}
		cout<<(M-m)*2<<'\n';
	}
	return 0;
}