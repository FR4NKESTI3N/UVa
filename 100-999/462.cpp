//To hell with it
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string S;
    while(cin>>S){
        int points = 0;
        vector<char> s,h,d,c;
        if(S[0]=='A')
            points+=4;
        if(S[0]=='K')
            points+=3;
        if(S[0]=='Q')
            points+=2;
        if(S[0]=='J')
            points+=1;
        if(S[1] == 'S')
            s.push_back(S[0]);
        if(S[1] == 'H')
            h.push_back(S[0]);
        if(S[1] == 'D')
            d.push_back(S[0]);
        if(S[1] == 'C')
            c.push_back(S[0]);
        for(int i = 0; i < 12; i++){
            cin>>S;
            if(S[0]=='A')
                points+=4;
            if(S[0]=='K')
                points+=3;
            if(S[0]=='Q')
                points+=2;
            if(S[0]=='J')
                points+=1;
            if(S[1] == 'S')
                s.push_back(S[0]);
            if(S[1] == 'H')
                h.push_back(S[0]);
            if(S[1] == 'D')
                d.push_back(S[0]);
            if(S[1] == 'C')
                c.push_back(S[0]);
        }
    if(s.size()==2)
        points+=1;
    if(h.size()==2)
        points+=1;
    if(d.size()==2)
        points+=1;
    if(c.size()==2)
        points+=1;
    if(s.size()==0)
        points+=2;
    if(h.size()==0)
        points+=2;
    if(d.size()==0)
        points+=2;
    if(c.size()==0)
        points+=2;

    }
    return 0;
}
