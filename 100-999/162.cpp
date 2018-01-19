#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    vector<char> cards;
    string a;
    while(true){
        for(int i = 0; i < 52; i++){
            cin>>a;
            if(a == "#")
                break;
            cards.push_back(a[1]);
        }
        for(int i = 51; i >= 0; i++){
            
        }
    }
    return 0;
}
