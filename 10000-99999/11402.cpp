#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;

class SegmentTree{

    /* lazy : 1 = all to 1
    : 2 = all to 0
    : 3 = invert
    */

    int n;
    vi st, lazy;
    string s;

    int left(int i){return i << 1;}
    int right(int i){return (i << 1) + 1;}

    void updateLazy(int p, int val){
        if(lazy[p] == 0)
            lazy[p] = val;
        else if(val == 1)
            lazy[p] = 1;
        else if(val == 2)
            lazy[p] = 2;
        else{
            if(lazy[p] == 1)
                lazy[p] = 2;
            else if(lazy[p] == 2)
                lazy[p] = 1;
            else lazy[p] = 0;
        }
    }

    void build(int p, int L, int R){
        if(L == R){
            st[p] = (s[L] == '1');
            return;
        }
        build(left(p), L, (L + R) >> 1);
        build(right(p),((L + R) >> 1) + 1, R);
        st[p] = st[left(p)] + st[right(p)];
    }

    int rsq(int p, int L, int R, int i, int j){
        if(i > R || j < L)
            return -1;
        if(lazy[p] != 0){
            if(L != R){
                updateLazy(left(p), lazy[p]);
                updateLazy(right(p), lazy[p]);
            }
            if(lazy[p] == 1){
                st[p] = R - L + 1;
            }
            else if(lazy[p] == 2){
                st[p] = 0;
            }
            else
                st[p] = R - L + 1 - st[p];
            lazy[p] = 0;
        }
        if(i <= L && j >= R)
            return st[p];
        int p1 = rsq(left(p), L, (L + R) >> 1, i, j),
            p2 = rsq(right(p),((L + R) >> 1) + 1, R, i, j);
        if(p1 == -1)
            return p2;
        if(p2 == - 1)
            return p1;
        return p1 + p2;
    }

    void updateRange(int p, int L, int R, int i, int j, int val){
        if(lazy[p] != 0){
            if(L != R){
                updateLazy(left(p), lazy[p]);
                updateLazy(right(p), lazy[p]);
            }
            if(lazy[p] == 1){
                st[p] = R - L + 1;
            }
            else if(lazy[p] == 2){
                st[p] = 0;
            }
            else{
                st[p] = R - L + 1 - st[p];
            }
            lazy[p] = 0;
        }
        if(L > R || L > j || R < i)
            return;
        if(L >= i && j >= R){
            if(L != R){
                updateLazy(left(p), val);
                updateLazy(right(p), val);
            }
            if(val == 1)
                st[p] = R - L + 1;
            else if(val == 2)
                st[p] = 0;
            else
                st[p] = R - L + 1 - st[p];
            return;
        }
        updateRange(left(p), L, (L + R) >> 1, i, j, val);
        updateRange(right(p), ((L + R) >> 1) + 1, R, i, j, val);
        st[p] = st[left(p)] + st[right(p)];
    }
public:
    SegmentTree(string s_){
        s = s_;
        n = s.length();
        st.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int rsq(int i, int j){
        return rsq(1, 0, n - 1, i, j);
    }

    void updateRange(int i, int j, int val){
        updateRange(1, 0, n - 1, i, j, val);
    }
};

int main(){
    int t, m, q, n, a, b;
    char c;
    cin >> t;
    for(int a0 = 1; a0 <= t; ++a0){
        cin >> m;
        string s = "", s1;
        while(m--){
            cin >> n >> s1;
            while(n--)
                s += s1;
        }
        n = s.length();
        SegmentTree st(s);
        cin >> q;
        int b0 = 0;
        cout << "Case " << a0 << ':' << '\n';
        for(int aa0 = 1; aa0 <= q; ++aa0){
            cin >> c >> a >> b;
            if(c == 'F'){
                st.updateRange(a, b, 1);
            }
            else if(c == 'E'){
                st.updateRange(a, b, 2);
            }
            else if(c == 'I'){
                st.updateRange(a, b, 3);
            }
            else{
                cout << "Q" << ++b0 << ": " << st.rsq(a, b) << '\n';
            }
        }
    }
    return 0;
}
