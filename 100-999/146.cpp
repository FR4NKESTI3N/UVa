#include<iostream>
#include<string>
#include<algorithm>

int main(){
    std::string s;
    while(true){
        std::cin>>s;
        if(s == "#")
            break;
        if(std::next_permutation(s.begin(), s.end()))
            std::cout<<s<<'\n';
        else
            std::cout<<"No Successor\n";
    }
    return 0;
}
