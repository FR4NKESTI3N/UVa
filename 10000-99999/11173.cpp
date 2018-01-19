#include <iostream>
#include <bitset>

using namespace std;

int main(void){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int x = 0;
        for(int i = 0; i < n; i++){
            int r = k%(1<<(i+2));
            if(r < 1<<(i+1))
                x|=(k & (1<<i));
            else{
                k ^= (1<<i);
                x|=(k & (1<<i));
            }
        }
        cout<<x<<'\n';
    }
    return 0;
}
