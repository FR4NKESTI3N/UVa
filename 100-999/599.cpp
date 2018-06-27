#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iterator>
#include <cstdio>

using namespace std;

vector<int> p(26, 0);

int getParent(int x){
    while(true){
        if(x == p[x])
            return x;
        else x = p[x];
    }
}

bool unionFind(int x, int y){
    return getParent(x) == getParent(y);
}

void unionSet(int x, int y){
    if(unionFind(x, y))
        return;
    p[y] = getParent(x);
}

int main(){
    int t;
    string s;
    cin >> t;
    while(t--){
        p.assign(26, 0);
        vector<vector<bool>> E(26, vector<bool> (26, 0));
        vector<bool> V(26, false);
        while(true){
            cin >> s;
            if(s[0] == '*')
                break;
            E[s[1] - 'A'][s[3] - 'A'] = E[s[3] - 'A'][s[1] - 'A'] = 1;
        }
        getline(cin, s);
        getline(cin, s);
        for(int i = 0; i < s.length(); i += 2){
            V[s[i] - 'A'] = true;
        }
        for(int i = 0; i < 26; ++i)
            if(V[i])
                p[i] = i;
        for(int i = 0; i < 26; ++i){
            for(int j = 0; j < 26; ++j){
                if(unionFind(i, j))
                    continue;
                if(E[i][j])
                    unionSet(i, j);
            }
        }
        unordered_map <int, int> trees;
        for(int i = 0; i < 26; ++i){
            if(V[i])
                trees[getParent(i)] = 1;
        }
        int acorns = 0, tree = 0, temp, flag;
        for(unordered_map <int, int> :: iterator it = trees.begin(); it != trees.end(); ++it){
            temp = it -> first, flag = 0;
            for(int i = 0; i < 26; ++i)
                if(E[temp][i]){
                    flag = 1;
                    break;
                }
            if(flag)
                ++tree;
            else ++acorns;
        }
        printf("There are %d tree(s) and %d acorn(s).\n", tree, acorns);
    }
    return 0;
}
