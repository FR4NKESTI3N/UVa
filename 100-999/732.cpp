//To do - Test recusive funtion against a full tree for efficiency. Current time : 0.36 secs

#include <iostream>
#include <stack>
#include <string>

using namespace std;

void printString(string s){
    for(int i = 0; i < s.length() - 1; ++i)
        cout<<s[i]<<' ';
    cout<<s.back()<<'\n';
}

void calculate(string decisions, string s, string substring, string remaining_string, stack<int> stck){
    if(decisions.back() == 'i'){
        if(remaining_string.length() == 0)
            return;
        stck.push(remaining_string[0]);
        remaining_string = remaining_string.substr(1, 999);
    }
    else{
        if(stck.empty())
            return;
        substring += stck.top();
        stck.pop();
    }
    if(substring == s.substr(0, substring.length())){
        if(substring.length() == s.length()){
            printString(decisions);
            return;
        }
        calculate(decisions + 'i', s, substring, remaining_string, stck);
        calculate(decisions + 'o', s, substring, remaining_string, stck);

    }
    else{
        return;
    }
}

int main(){
    string s1,s2;
    while(cin>>s1){
        cout<<"[\n";
        cin>>s2;
        stack<int> temp;
        calculate("i", s2, "", s1, temp);
        cout<<"]\n";
    }
    return 0;
}
