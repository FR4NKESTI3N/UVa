#include <iostream>
#include <vector>
#include <cstdio>

struct Node{
    int data, left, right;
};

using namespace std;

int main(){
    int s, b, l, r;
    while(true){
        cin>>s>>b;
        if(!s)
            break;
        vector <struct Node> list(s + 2);
        list[0].data = -1;
        list[0].right = 1;
        list[s + 1].data = -1;
        list[s + 1].left = s;
        for(int i = 1; i <= s; ++i){
            list[i].data = i;
            list[i].left = i - 1;
            list[i].right = i + 1;
        }
        for(int i = 0; i < b; ++i){
            scanf("%d %d", &l, &r);
            list[list[l].left].right = list[r].right;
            list[list[r].right].left = list[l].left;
            if(list[list[l].left].data == -1)
                printf("* ");
            else
                printf("%d ", list[list[l].left].data);
            if(list[list[r].right].data == -1)
                printf("*\n");
            else
                printf("%d\n", list[list[r].right].data);
        }
        cout<<"-\n";
    }
    return 0;
}
