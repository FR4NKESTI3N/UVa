#include <iostream>
#include <bitset>
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

bitset<3000001> times;

int main(void){
    int n, m, t1, t2, t3;
    while(true){
        bool flag = 0;
        scanf("%d %d",&n,&m);
        if(n == 0 && m == 0)
            break;
        for(int i = 0; i < n; i++){
            scanf("%d %d",&t1,&t2);
            if(!flag){
                for(int j = t1; j < t2; j++)
                    if(times[j] == 1)
                        flag = 1;
                    else
                        times[j] = 1;
            }
        }
        for(int i = 0; i < m; i++){
            scanf("%d %d %d",&t1,&t2,&t3);
            if(!flag){
                while(t1<1000001){
                    if(!flag){
                        for(int j = t1; j < t2; j++)
                            if(times[j] == 1)
                                flag = 1;
                            else
                                times[j] = 1;
                    }
                    t1+=t3;
                    t2+=t3;
                }
            }
        }
        printf("%sCONFLICT\n",(flag?"":"NO ") );
        times.reset();
    }
    return 0;
}
