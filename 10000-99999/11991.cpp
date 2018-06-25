#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n, m, temp;
    while(cin >> n){
        map<int, vector<int>> list;
        cin >> m;
        for(int i = 1; i <= n; ++i){
            cin >> temp;
            if(list.find(temp) == list.end())
                list[temp] = vector<int> ({i});
            else
                list[temp].push_back(i);
        }
        int temp2;
        for(int i = 0; i < m; ++i){
            cin >> temp >> temp2;
            if(list[temp2].size() < temp)
                cout<<0;
            else
                cout<<list[temp2][temp - 1];
            cout<<'\n';
        }
    }
    return 0;
}
