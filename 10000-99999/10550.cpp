#include<iostream>
#include<vector>

using namespace std;

int main(void){
	vector<int> combinations(4,-1), last(4,0);
	while(true){
		cin>>combinations[0]>>combinations[1]>>
			combinations[2]>>combinations[3];
		if(combinations==last)
			break;
		cout<<(120+(combinations[0]-combinations[1]+40)%40+(combinations[2]-combinations[1]+40)%40+(combinations[2]-combinations[3]+40)%40)*9<<'\n';

	}
}