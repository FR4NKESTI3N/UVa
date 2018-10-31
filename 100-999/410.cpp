#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cmath>

using namespace std;

int main(){
    int s, c;
    int set = 1;
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> c >> s){
        vector<int> mass(2 * c, 0);
        for(int i = 0; i < s; ++i)
            cin >> mass[i];
        cout << "Set #" << set << '\n';
        sort(mass.begin(), mass.end());
        double avg = accumulate(mass.begin(), mass.end(), static_cast<double>(0.0)) / c;
        double X = 0;
        for(int i = 0; i < c; ++i){
            cout << ' ' << i << ":";
            if(mass[i] != 0)
                cout << ' ' << mass[i] << ' ';
            if(mass[2 * c - 1 - i] != 0)
                cout << mass[2 * c - 1 - i];
            cout << '\n';
            X += abs(avg - mass[i] - mass[2 * c - 1 - i]);
        }
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout.precision(5);
        cout << "IMBALANCE = " << X << "\n\n";
        ++set;
    }

    return 0;
}
