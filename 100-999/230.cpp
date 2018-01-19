#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stdio.h>

using namespace std;

struct comparison{
    // template < vector<vector<string>> left>;
    bool operator()(const vector<string>& left, const vector<string>& right){
        int p = left[1].compare(right[1]);
        if(p<0)
            return 1;
        else if(p>0)
            return 0;
        p = left[0].compare(right[0]);
        if(p<0)
            return 1;
        else
            return 0;
    }
};

int main(void){
    vector<vector<string>> book,to_return;
    string s;
    while(true){
        vector<string> k;
        getline(cin,s);
        if(s=="END")
            break;
        string l = "\"";
        int i = 1;
        for(; i < s.length(); i++){
            l.push_back(s[i]);
            if(s[i]=='\"')
                break;
        }
        k.push_back(l);
        l.clear();
        i+=5;
        for(; i < s.length(); i++)
            l.push_back(s[i]);
        k.push_back(l);
        k.push_back("s");
        book.push_back(k);
    }
    // sort(book.begin(),book.end(),[](const vector<vector<string>>* left, const vector<vector<string>>* right){
    //     int p = left[1].compare(right[1]);
    //     if(p<0)
    //         return 1;
    //     else if(p>0)
    //         return 0;
    //     p = left[0].compare(right[0]);
    //     if(p<0)
    //         return 1;
    //     else
    //         return 0;
    // });

    sort(book.begin(),book.end(), comparison());





    // for(int i = 0; i < book.size(); i++){
    //     cout<<book[i][0]<<' '<<book[i][1]<<'\n';
    // }
    while(true){
        getline(cin,s);
        string s1,s2="\"";
        int i = 0;
        if(s=="END")
            break;
        else if(s=="SHELVE")
            s1 ="SHELVE";
        else{
            for(;s[i]!=' '; i++)
                s1.push_back(s[i]);
            i+=2;
            for(;s[i]!='\"'; i++)
                s2.push_back(s[i]);
            s2.push_back('\"');
        }
        // cout<<s1<<' '<<s2<<'\n';
        if(s1=="BORROW"){
            for(int i = 0; i < book.size(); i++){
                if(book[i][0]==s2){
                    book[i][2]="b";
                    // cout<<S<<" b\n";
                    break;
                }
            }
        }
        else if(s1=="RETURN"){
            for(int i = 0; i < book.size(); i++){
                if(book[i][0]==s2){
                    // cout<<i<<" r\n";
                    book[i][2]="r";
                    break;
                }
            }
        }
        if(s1=="SHELVE"){
            // for(int i = 0; i < book.size(); i++){
            //     cout<<book[i][0]<<' '<<book[i][1]<<' '<<book[i][2]<<'\n';
            // }
            int shelved = -1;
            for(int i = 0; i < book.size(); i++){
                if(book[i][2]=="s")
                    shelved = i;
                else if(book[i][2] == "r"){
                    if(shelved == -1)
                        printf("Put %s first\n", book[i][0].c_str());
                    else
                        printf("Put %s after %s\n", book[i][0].c_str(), book[shelved][0].c_str());
                    book[i][2] = "s";
                    shelved = i;
                }
            }
            cout<<"END\n";
        }
        // cout<<"while loop over\n";
    }
    return 0;
}
