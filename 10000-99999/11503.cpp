#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility>

using namespace std;

class UnionFind{
private:
    vector<int> p, rank, circle;

public:
    UnionFind(int n){
        rank.assign(n, 0);
        p.assign(n, 0);
        circle.assign(n, 1);
        for(int i = 0; i < n; ++i)
            p[i] = i;
    }
    void makeSet(int x){
        p.push_back(x);
        rank.push_back(0);
        circle.push_back(1);
    }
    int findSet(int x){
        if(x != p[x])
            p[x] = findSet(p[x]);
        return p[x];
    }
    void unionSet(int x, int y){
        int i = findSet(x), j = findSet(y);
        if(i == j)
            return;
        if(rank[i] > rank[j]){
            p[j] = i;
            circle[i] += circle[j];
        }
        else{
            p[i] = j;
            circle[j] += circle[i];
        }
        if(rank[i] == rank[j])
            ++rank[j];
    }
    int getCircle(int x){
        return circle[findSet(x)];
    }
    int getCount(){
        return p.size();
    }
};

int main(){
    int t, n;
    string name1, name2;
    cin >> t;
    while(t--){
        int k = 0;
        cin >> n;
        unordered_map<string, int> map;
        vector<pair<int, int>> edges;
        UnionFind set(0);
        for(int i = 0; i < n; ++i){
            cin >> name1 >> name2;
            int x, y;
            if(map.find(name1) == map.end()){
                map[name1] = k++;
                set.makeSet(map[name1]);
            }
            x = map[name1];
            if(map.find(name2) == map.end()){
                map[name2] = k++;
                set.makeSet(map[name2]);
            }
            y = map[name2];
            set.unionSet(x, y);
            cout << set.getCircle(x) << '\n';
        }
    }
    return 0;
}
