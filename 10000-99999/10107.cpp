#include <cstdio>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int main(){
    vector<long long> arr;
    vector<long long> :: iterator it;
    long long x;
    int i = 0;
    while(cin>>x){
        ++i;
        it = lower_bound(arr.begin(), arr.end(), x);
        arr.insert(it, x);
        if(i & 1)
            printf("%lld\n",arr[i/2]);
        else
            printf("%lld\n",(arr[i/2] + arr[(i/2) - 1])/2);
    }
    return 0;
}
