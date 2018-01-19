#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        vector<int> ar(n);
        vector<int> a(n-1);
        for(int i = 0; i < n; i++)
            cin>>ar[i];
        int flag = 1;
        for(int i = 0; i < n-1; i++){
            int x = abs(ar[i]-ar[i+1]);
            if(x < n)
                a[x] = 1;
            else flag = 0;
        }
        for(int i = 1; i < n-1; i++){
            if(a[i] == 0)
                flag = 0;
        }
        cout<<(flag?"Jolly\n":"Not jolly\n");
    }
    return 0;
}
