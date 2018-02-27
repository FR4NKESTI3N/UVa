#include <iostream>
#include <stack>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int n;
    while(true){
        scanf("%d", &n);
        if(n == 0)
            break;
        while(true){
            stack<int> s;
            int k = 1, j;
            for(int i = 0; i < n; ++i){
                scanf("%d", &j);
                if(j == 0)
                    break;
                while(s.empty() || s.top() != j){
                    if(k > n)
                        break;
                    s.push(k);
                    ++k;
                }
                if(s.top() == j){
                    s.pop();
                }
            }
            if(j)
                printf("%s\n", s.empty()?"Yes":"No");
            else{
                printf("\n");
                break;
            }
        }
    }
    return 0;
}
