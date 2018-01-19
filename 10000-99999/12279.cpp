#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(void){
    int n,tmp;
    for(int i = 1; i<=100; i++){
        cin>>n;
        if(n==0)
            break;
        int bal = 0;
        while(n--){
            cin>>tmp;
            if(tmp == 0)
                bal--;
            else bal++;
        }
        printf("Case %d: %d\n",i,bal );
    }
    return 0;
}
