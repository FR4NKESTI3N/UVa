#include<iostream>
#include<list>
#include<string>
#include<iterator>
#include<algorithm>
using namespace std;

int main(){
    list<char> processed_str;
    list<char> :: iterator iter;
    string str;
    while(cin>>str){
        int i = 0;
        processed_str.clear();
        iter = processed_str.end();
        for(; i < str.size(); ++i){
            if(str[i] == '['){
                iter = processed_str.begin();
            }
            else if(str[i] == ']'){
                iter = processed_str.end();
            }
            else{
                iter = processed_str.insert(iter, str[i]);
                iter = next(iter);
            }
        }
        for(auto a : processed_str)
            cout<<a;
        cout<<'\n';
    }
    return 0;
}
