#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int t, d, k, n;
    string s;
    vector<int> poly;
    cin >> t;
    while(t--){
        cin >> n;
        poly.assign(n + 1, 0);
        for(int i = 0; i <= n; ++i)
            cin >> poly[i];
        cin >> d >> k;
        int D = d;
        int j = 1;
        for(; d < k;){      //could be improved by using sum of AP
            ++j;
            d += D * j;
        }
        long long res = 0;
        for(int i = 0; i <= n; ++i){
            res += poly[i] * pow(j, i);
        }
        cout << res << '\n';
    }
    return 0;
}
