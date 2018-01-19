#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    int n, m;
    while(true){
        cin>>n;
        if(n==0)
            break;
        string s;
        getline(cin, s);
        vector<int> ar;
        for(int i = 0; i < n; i++){
            m = 25;
            getline(cin, s);
            for(auto a : s){
                if(a == 'X')
                    m--;
            }
            ar.push_back(m);
        }
        m = 0;
        n = *min_element(ar.begin(), ar.end());
        for(auto a : ar){
            m += a - n;
        }
        cout<<m<<'\n';
    }
}
