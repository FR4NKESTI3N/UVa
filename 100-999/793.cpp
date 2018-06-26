#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class UnionFind{
private:
    vector<int> p, rank;

public:
    UnionFind(int n){
        rank.assign(n, 0);
        p.assign(n, 0);
        for(int i = 0; i < n; ++i)
            p[i] = i;
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
        if(rank[i] > rank[j])
            p[j] = i;
        else
            p[i] = j;
        if(rank[i] == rank[j])
            ++rank[j];
    }
};

int main(){
    int t, n;
    char c;
    int a, b;
    cin >> t;
    while(t--){
        string S;
        int s = 0, uns = 0;
        cin >> n;
        UnionFind set(n + 1);
        getline(cin, S);
        while(true){
            getline(cin, S);
            if(S == "")
                break;
            stringstream ss(S);
            ss >> c >> a >> b;
            if(c == 'c')
                set.unionSet(a, b);
            else{
                if(set.findSet(a) == set.findSet(b))
                    ++s;
                else
                    ++uns;
            }
        }
        cout << s << ',' << uns << '\n';
        if(t)
            cout << '\n';
    }

}
