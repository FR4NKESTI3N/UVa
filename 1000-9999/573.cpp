#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void){
    float h, u, d, f, k, t;
    while (true) {
        scanf("%f %f %f %f", &h, &u, &d, &f);
        if(h == 0)
            break;
        f /= 100;
        k = 0;
        t = u*f;
        int i = 1;
        while(true){
            k+=u;
            u = max((float)0, u - t);
            if(k > h){
                printf("success on day %d\n", i);
                break;
            }
            k-=d;
            if(k < 0){
                printf("failure on day %d\n", i);
                break;
            }
            i++;
        }
    }
    return 0;
}
