#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void inc(string &s){

}

int main(){
    unordered_map<string, int> map;
    string s;
    int count = 1;
    s = "a";
    for(int i = 0; i < 26; ++i){
        s[0] = 'a' + i;
        map[s] = count++;
    }
    s = "aa";
    for(int i = 0; i < 26; ++i){
        s[0] = 'a' + i;
        for(int j = i + 1; j < 26; ++j){
            s[1] = 'a' + j;
            map[s] = count++;
        }
    }
    s = "aaa";
    for(int i = 0; i < 26; ++i){
        s[0] = 'a' + i;
        for(int j = i + 1; j < 26; ++j){
            s[1] = 'a' + j;
            for(int k = j + 1; k < 26; ++k){
                s[2] = 'a' + k;
                map[s] = count++;
            }
        }
    }
    s = "aaaa";
    for(int i = 0; i < 26; ++i){
        s[0] = 'a' + i;
        for(int j = i + 1; j < 26; ++j){
            s[1] = 'a' + j;
            for(int k = j + 1; k < 26; ++k){
                s[2] = 'a' + k;
                for(int l = k + 1; l < 26; ++l){
                    s[3] = 'a' + l;
                    map[s] = count++;
                }
            }
        }
    }
    s = "aaaaa";
    for(int i = 0; i < 26; ++i){
        s[0] = 'a' + i;
        for(int j = i + 1; j < 26; ++j){
            s[1] = 'a' + j;
            for(int k = j + 1; k < 26; ++k){
                s[2] = 'a' + k;
                for(int l = k + 1; l < 26; ++l){
                    s[3] = 'a' + l;
                    for(int m = l + 1; m < 26; ++m){
                        s[4] = 'a' + m;
                        map[s] = count++;
                    }
                }
            }
        }
    }
    // cout<<"DONE!\n";
    while(cin >> s){
        cout<<map[s]<<'\n';
    }
}
