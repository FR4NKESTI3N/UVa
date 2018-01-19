#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int m,c;
vvi price(20,vi(20,-1));
vvi memo(20,vi(200,-1));

int maxCost(int cur, int g){
    if(cur < 0)
}

int main(void){
    int t,tmp,tmp2;
    cin>>t;
    while(t--){
        cin>>m>>c;
        price = vvi(c);
        memo = vvi(c, vi(m,-1));
        for(int i = 0; i<c;i++){
            cin>>tmp1;
            memo.push_back(vi(c,-1));
            for(int j = 0; j< tmp1; j++){
                cin>>tmp2;
                price[c].push_back(tmp2);
            }
        }

    }
    return 0;
}
