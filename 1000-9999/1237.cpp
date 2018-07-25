#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <iterator>

using namespace std;
typedef pair<int, int> pii;

struct Compare{
    bool operator()(pii a, pii b){
        return a.first < b.first || a.second < b.second;
    }
};

int main(){
    int t, d, q, l, h, Q;
    string s;
    cin >> t;
    while(t--){
        cin >> d;
        map<pii, string, Compare> tree;
        for(int i = 0; i < d; ++i){
            cin >> s >> l >> h;
            tree.insert(pair<pii, string>(pii(l, h), s));
        }
        cin >> q;
        for(int i = 0; i < q; ++i){
            cin >> Q;
            int count = 0;string ss;
            for(map<pii, string> :: iterator tree_it = tree.begin(); tree_it != tree.end() && count < 2; ++tree_it){
                if((tree_it -> first).first <= Q && (tree_it -> first).second >= Q){
                    ++count;
                    ss = tree_it -> second;
                }
            }
            if(count == 1)
                cout << ss <<'\n';
            else
                cout << "UNDETERMINED\n";
        }
        if(t)
            cout<<'\n';
    }
    return 0;
}
