#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n, MAX;
    while(cin >> n){
        MAX = 0;
        vector<int> weights((1 << n) + 1), potencies((1 << n) + 1);
        for(int i = 0; i < (1 << n); ++i)
            cin>>weights[i];
        for(int i = 0; i < (1 << n); ++i){
            for(int bit = 0; bit < n; ++bit){
                potencies[i] += weights[i ^ (1 << bit)];
            }
        }
        for(int i = 0; i < (1 << n); ++i){
            for(int bit = 0; bit < n; ++bit){
                MAX = max(MAX, potencies[i] + potencies[(i ^ (1 << bit))]);
            }
        }
        cout<<MAX<<'\n';
    }
    return 0;
}
