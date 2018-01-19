#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n, temp;
    while(cin>>n){
        vector<int> a(n + 1, 0), b(n+1,0), c(n,0);
        for(int i = 0; i < (1<<n); i+= 1){
            cin >> temp;
            bitset<32> k(i);
            cout<<k<<' ';
            a[k.count()] += temp;
        }
        cout<<'\n';
        b[0] = a[1];
        b[n] = a[n-1];
        for(int i = 1; i < n; i++){
            b[i] = a[i-1] + a[i+1];
        }
        for(auto i : b)
            cout<<i<<' ';
        cout<<'\n';
        for(int i = 0; i < n; i++){
            c[i] = b[i]+b[i+1];
        }
        cout<<*max_element(c.begin(), c.end())<<'\n';
    }
    return 0;
}
