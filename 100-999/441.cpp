#include<iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(void){
    short k;
    cin>>k;
    while (true){
        vector<int> ar(k);
        for(int i=0;i<k;i++){
            cin>>ar[i];
        }
        for(int a=0; a<=k-6;a++)
            for(int b=a+1; b<=k-5;b++)
                for(int c=b+1; c<=k-4;c++)
                    for(int d=c+1; d<=k-3;d++)
                        for(int e=d+1; e<=k-2;e++)
                            for(int f=e+1; f<=k-1;f++)
                                printf("%d %d %d %d %d %d\n",ar[a],ar[b],ar[c],ar[d],ar[e],ar[f]);
        cin>>k;
        if(!k)
            break;
        cout<<'\n';
    }
    return 0;
}
