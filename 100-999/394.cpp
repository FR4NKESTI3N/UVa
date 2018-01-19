#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstdio>

using namespace std;

struct array{
    string name;
    int base_addr, size, dimensions;
    vector<pair<int, int>> bounds;
};

int main(void){
    int n, r;
    cin>>n>>r;
    vector<struct array> ar(n);
    pair<int, int> temp;
    string s;
    for(int i = 0; i < n; ++i){
        cin>> ar[i].name>> ar[i].base_addr>> ar[i].size>> ar[i].dimensions;
        for(int j = 0; j < ar[i].dimensions; ++j){
            cin>>temp.first>>temp.second;
            ar[i].bounds.push_back(temp);
        }
    }
    for(int i = 0; i < r; ++i){
        cin>>s;
        vector<int> indices;
        int addr = 0;
        for(int j = 0; j < n; ++j){
            if(ar[j].name == s){
                int tmp;
                addr+=ar[j].base_addr;
                for(int k = 0; k < ar[j].dimensions; k++){
                    cin>>tmp;
                    indices.push_back(tmp);
                }
                int c = ar[j].size;
                int cur = ar[j].dimensions - 1;
                addr+=c*(indices[cur] - ar[j].bounds[cur].first);
                cur--;
                for(; cur>=0; cur--){
                    c = c*(ar[j].bounds[cur+1].second + 1 - ar[j].bounds[cur+1].first);
                    addr+=c*(indices[cur] - ar[j].bounds[cur].first);
                }
                break;
            }
        }
        printf("%s[", s.c_str());
        for(int k = 0; k < indices.size()-1; ++k)
            printf("%d, ",indices[k]);
        printf("%d] = %d\n",*(indices.end()-1), addr);

    }
    return 0;
}
