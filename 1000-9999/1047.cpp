#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bitCount(int x){
    int cnt = 0;
    while(x){
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

int main(){
    int n, nn, m, temp, case_no = 0;
    while(1){
        cin >> n >> nn;
        if(n == 0 && nn == 0)
            break;
        vector<int> customers_served(n, 0);
        for(int i = 0; i < n; ++i)
            cin >> customers_served[i];
        cin >> m;
        int t;
        vector<int> common_service_customers(m);
        vector<int> common_service_towers(m, 0);
        for(int i = 0; i < m; ++i){
            cin >> t;
            for(int j = 0; j < t; ++j){
                cin >> temp;
                common_service_towers[i] |= 1 << (temp - 1);
            }
            cin >> common_service_customers[i];
        }
        int max_cost = 0, max_set = 0;
        for(int subset = 0; subset < (1 << n); ++subset){
            int cost = 0;
            for(int i = 0; i <= n; ++i)
                if(subset & (1 << i))
                    cost += customers_served[i];
            for(int i = 0; i < m; ++i){
                if((subset >= common_service_towers[i]) && ((common_service_towers[i] | subset) == subset)){
                    // cout << (bitCount(common_service_towers[i]) & 1) << ' ' << common_service_towers[i]<<'\n';
                    if(bitCount(common_service_towers[i]) & 1)
                        cost += common_service_customers[i];
                    else
                        cost -= common_service_customers[i];
                }
            }
            if(bitCount(subset) > nn)
                continue;
            if(cost > max_cost){
                max_cost = cost;
                max_set = subset;
            }
        }
        cout << "Case Number  " << (++case_no) << '\n';
        cout << "Number of Customers: " << max_cost << '\n';
        cout << "Locations recommended: ";
        for(int i = 0; (1 << i) <= max_set; ++i)
            if(max_set & (1 << i))
                cout << i + 1 << ' ';
        cout << "\n\n";
    }
    return 0;
}
