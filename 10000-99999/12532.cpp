#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

pii operator+(pii a, pii b){
    return pii({a.first + b.first, a.second + b.second});
}

pii operator-(pii a, pii b){
    return pii({a.first - b.first, a.second - b.second});
}

class FenwickTree{
    int n;
    vector<int> A;
    vector<pii> ft;
    int LSOne(int i){return i & -i;}

public:
    /*first = -1 count
    second = 0 count
    */
    void Update(int p, int val){
        for(; p <= n; p += LSOne(p)){
            if(val == -1)
                ++ft[p].first;
            else if(val == 0)
                ++ft[p].second;
        }
    }

    void update(int p, int val){
        int old = A[p - 1];
        A[p - 1] = val;
        if(old == val)
            return;
        for(int k = p; k <= n; k += LSOne(k))
            if(old == -1)
                --ft[k].first;
            else if(old == 0)
                --ft[k].second;
        Update(p, val);
    }

    pii rpq(int b){
        pii res = {0, 0};
        for(; b > 0; b -= LSOne(b))
            res = res + ft[b];
        return res;
    }

    int rpq(int a, int b){
        pii res = rpq(b) - rpq(a - 1);
        if(res.second >= 1)
            return 0;
        return (res.first & 1) ? -1 : 1;
    }

    FenwickTree(vector<int> ar){
        n = ar.size();
        A = ar;
        ft.assign(n + 1, pii({0,0}));
        for(int i = 1; i <= n; ++i){
            Update(i, ar[i - 1]);
        }
    }
};

int main(){
    int n, k, l, r;
    char c;
    while(cin >> n){
        cin >> k;
        vector<int> A(n);
        for(int i = 0; i < n; ++i){
            cin >> A[i];
            if(A[i] > 0)
                A[i] = 1;
            else if(A[i] < 0)
                A[i] = -1;
        }
        FenwickTree ft(A);
        for(int i = 0; i < k; ++i){
            cin >> c >> l >> r;
            if(c == 'C'){
                if(r > 0)
                    ft.update(l, 1);
                else if(r < 0)
                    ft.update(l, -1);
                else
                    ft.update(l, 0);
            }
            else{
                int res = ft.rpq(l, r);
                if(res > 0)
                    cout<<'+';
                else if(res < 0)
                    cout<<'-';
                else
                    cout<<'0';
            }
        }
        cout<<'\n';
    }
    return 0;
}
