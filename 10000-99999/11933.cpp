#include<iostream>
#include<bitset>

using namespace std;

int main(void){
    int n;
    while(true){
        cin>>n;
        if(n == 0)
            break;
        int a = 0, b = 0, flag = 1;
        for(int i = 0; i <= 31; i++){
            if(n & (1<<i)){
                if(flag){
                    a |= (1<<i);
                    flag = 0;
                }
                else{
                    b |= (1<<i);
                    flag = 1;
                }
            }
        }
        cout<<a<<' '<<b<<'\n';
    }
    return 0;
}
