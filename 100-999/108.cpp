#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(void){
    int n;
    cin>>n;
    long long MAX = INT_MIN, temp;
    vvi sum_query(n, vi(n,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>sum_query[i][j];
            if(i>0)
                sum_query[i][j]+=sum_query[i-1][j];
            if(j>0)
                sum_query[i][j]+=sum_query[i][j-1];
            if(i > 0 && j > 0)
                sum_query[i][j]-=sum_query[i-1][j-1];
        }
    }
    for(int a = 0; a < n; a++) for(int b = 0; b < n; b++)
        for(int c = a; c < n; c++) for(int d = b; d < n; d++){
            temp = sum_query[c][d]+((a>0 && b>0)?sum_query[a-1][b-1]:0)-((b>0)?sum_query[c][b-1]:0)-((a>0)?sum_query[a-1][d]:0);
            if(temp>MAX)
                MAX=temp;
        }
    cout<<MAX<<'\n';
    return 0;
}
