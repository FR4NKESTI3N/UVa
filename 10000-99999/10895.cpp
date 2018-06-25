#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <iterator>

using namespace std;

int main(){
    int m, n, r, temp;
    while(cin >> m){
        cin >> n;
        map<int, vector<pair<int, int>>> list;
        vector<pair<int, int>> pairs;
        for(int i = 0; i < m; ++i){
            cin >> r;
            pairs.assign(r, make_pair(0,0));
            for(int j = 0; j < r; ++j)
                cin >> pairs[j].first;
            for(int j = 0; j < r; ++j)
                cin >> pairs[j].second;
            for(int j = 0; j < r; ++j){
                if(list.find(pairs[j].first) == list.end())
                    list[pairs[j].first] = vector<pair<int, int>> (1,make_pair(i, pairs[j].second));
                else
                    list[pairs[j].first].push_back(make_pair(i, pairs[j].second));
            }
        }
        cout << n << ' ' << m << '\n';
        for(int I = 1; I <= n; ++I){
            r = list[I].size();
            cout<<r;
            for(int i = 0; i < r; ++i)
                cout << ' ' << list[I][i].first + 1;
            cout<<"\n";
            for(int i = 0; i < r; ++i){
                cout << list[I][i].second;
                if(i < r - 1)
                    cout << ' ';
            }
            cout<<"\n";
        }
    }
    return 0;
}
