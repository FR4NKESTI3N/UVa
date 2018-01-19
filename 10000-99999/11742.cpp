#include <iostream>
#include <vector>
#include <pair>

using namespace std;

int main(void){
     short n,m,a,b,c;
     while(true){
         cin>>n>>m;
         vector <vector<int>> ar(m,vector<int> (3));
         if(n==0 && m==0)
            break;
        for(int i=0;i<m;i++){
            cin>>ar[i][0]>>ar[i][1]>>ar[i][2];
            }
        
     }
    return 0;
}
