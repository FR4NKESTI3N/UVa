#include <iostream>
#include<string>

using namespace std;

int ctr=0;

int main(void){
	string lines;
	while(getline(cin,lines)){
		for(int i=0;i<lines.size();i++){
			if(lines[i]=='"'){
				if(!(ctr%2)){
					ctr++;
					lines[i]='`';
					lines.insert(i+1,"`");
				}
				else{
					ctr++;
					lines[i]='\'';
					lines.insert(i+1,"'");
				}
			}
		}
		cout<<lines<<'\n';
	}
	return 0;	
}