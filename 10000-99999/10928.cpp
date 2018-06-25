#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int t, p, min;
    string s;
    cin >> t;
    while(t--){
        min = 1001;
        cin >> p;
        vector<int> neigh(p + 1, 0);
        neigh[0] = 1001;
        getline(cin, s);
        for(int i = 1; i <= p; ++i){
            getline(cin, s);
            for(auto c : s)
                if(c == ' ')
                    neigh[i]++;
            if(neigh[i] < min)
                min = neigh[i];
        }
        int i = 1;
        for(; i <= p; ++i)                      //bloody presentation error
            if(neigh[i] == min){
                cout << i;
                break;
            }
        ++i;
        for(; i <= p; ++i)
            if(neigh[i] == min)
                cout << ' ' << i;
        cout << '\n';
    }
}
